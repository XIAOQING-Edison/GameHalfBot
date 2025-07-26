#include "Injector.h"
#include "WPEXUtily.h"
#include <TLHELP32.H>

CInjector::CInjector(E_INJECT_TYPE type)
{
	m_injectType=type;
	m_bInjectSucc=false;
	m_pidSelect=-1;
}

CInjector::~CInjector(void)
{

}

DWORD CInjector::FindTargetProcessPid(LPCTSTR lpszProcess)
{
	DWORD dwRet = -1;  
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);  
	PROCESSENTRY32 pe32;  
	pe32.dwSize = sizeof( PROCESSENTRY32 );  
	Process32First(hSnapshot, &pe32);  
	do
	{  
		if(lstrcmpi(pe32.szExeFile, lpszProcess) == 0 )  
		{  
			dwRet = pe32.th32ProcessID;
			break;  
		}  
	} 
	while (Process32Next(hSnapshot, &pe32));  
	CloseHandle( hSnapshot );  
	return dwRet;  
}


SIZE_T CInjector::GetTargetProcessDllBase(DWORD pid,LPCTSTR szDllName)
{
	SIZE_T dwRet = 0;  
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);  
	MODULEENTRY32 me32;
	me32.dwSize = sizeof(MODULEENTRY32);  
	if(hSnapshot==INVALID_HANDLE_VALUE)
	{
		TRACE_OUTPUT(_T("create tool help failed %x\n"),GetLastError());
		return dwRet;
	}
	if(!Module32First(hSnapshot, &me32))
	{
		TRACE_OUTPUT(_T("Module32First failed %x\n"),GetLastError());
		goto EXT;
	}
	do
	{  
		if(lstrcmpi(me32.szModule, szDllName) == 0 )  
		{
			dwRet=(SIZE_T)me32.modBaseAddr;
			break;  
		}  
	} 
	while(Module32Next(hSnapshot, &me32));
EXT:
	CloseHandle( hSnapshot );  
	return dwRet;  
}


bool CInjector::EnableDebugPrivilege()	//提权
{
	return EnablePrivilege(SE_DEBUG_NAME);

}


bool CInjector::DoInjectByMethodType(DWORD dwPID, LPCTSTR lpszDllName,bool bFreeDll)	//ntcreatthread or createremotethread
{
	bool ret=false;
	TCHAR buf[MAX_PATH];
	if ( !GetFileAttributes( lpszDllName ) ==-1)
	{
		return ret;
	}

	if ( !EnablePrivilege( SE_DEBUG_NAME ) )
	{
		return ret;
	}

	BOOL bRet = FALSE;
	HANDLE hPro =::OpenProcess( PROCESS_ALL_ACCESS, FALSE, dwPID );

	if( NULL == hPro )
	{
		return ret;
	}

	LPVOID pszLibFileRemote = NULL;
	BOOL bSucc=FALSE;
	
	// 向目标进程地址空间写入DLL名称  
	SIZE_T dwSize, dwWritten;  
	dwSize  = ( _tcslen( lpszDllName ) + 1 ) * sizeof( TCHAR );
	pszLibFileRemote = VirtualAllocEx( hPro, NULL, dwSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

	if ( pszLibFileRemote == NULL )
	{
		goto EXT;
	}

	SIZE_T bytesWritten;
	if (!WriteProcessMemory( hPro, pszLibFileRemote, (PVOID)lpszDllName, dwSize, &dwWritten ) )
	{
		goto EXT;
	}
	else
	{
		if (dwWritten != dwSize )  
		{  
			TRACE_OUTPUT(_T("WriteProcessMemory 已写入与实际写入不一致!错误: %x\n"),GetLastError());
			goto EXT;
		}
	}

#ifdef _UNICODE
#define LOAD_LIBRARY_STRING ("LoadLibraryW")
#else
#define LOAD_LIBRARY_STRING ("LoadLibraryA")
#endif

#ifdef _UNICODE
#define FREE_LIBRARY_STRING ("FreeLibraryW")
#else
#define FREE_LIBRARY_STRING ("FreeLibraryA")
#endif


	//ASLR,在VISTA后面的系统，系统DLL基砋是随机变化的，不像xp以前是固定的，这里参考了
	//remoteDll的做法
	HMODULE hKernel32Local=LoadLibrary(_T("kernel32.dll"));
	SIZE_T targetKernel32=GetTargetProcessDllBase(dwPID,_T("kernel32.dll"));
	if(!targetKernel32)
	{
		TRACE_OUTPUT(_T("get target kernel32 base addr failed\n"));
		return ret;
	}

	SIZE_T localLoadLib32=0;
	if(bFreeDll)
	{
		localLoadLib32=(SIZE_T)GetProcAddress(hKernel32Local,FREE_LIBRARY_STRING);
	}
	else
	{
		localLoadLib32=(SIZE_T)GetProcAddress(hKernel32Local,LOAD_LIBRARY_STRING);
	}
	SIZE_T targetLoadLib32=localLoadLib32+(SIZE_T)hKernel32Local-targetKernel32;
	DWORD dwID; 
	PTHREAD_START_ROUTINE pfnThreadRtn = (PTHREAD_START_ROUTINE )targetLoadLib32;

	if ( pfnThreadRtn == NULL )
	{
		TRACE_OUTPUT(_T("get targetLoad Library addr 失败!错误:%x\n"),GetLastError());
		goto EXT;
	}

	switch(m_injectType)
	{
	case e_inject_remote_thread:
		bSucc=InjectByCreateRemoteThread(hPro,pfnThreadRtn,pszLibFileRemote,bFreeDll);
		break;
	}

	ret=bSucc;
	
EXT:
	if (pszLibFileRemote != NULL )
	{
		VirtualFreeEx( hPro, pszLibFileRemote, 0, MEM_RELEASE );
		pszLibFileRemote = NULL;
	}

	if (NULL != hPro )
	{
		::CloseHandle( hPro );
		hPro = NULL;
	}


	return ret;
}


bool CInjector::InjectByCreateRemoteThread(HANDLE hProcess, LPTHREAD_START_ROUTINE  lpThreadProc, LPVOID lpDllName,bool bFreeDll)	//普通远程线程
{
	bool ret=false;
	HANDLE hThread = NULL;
	FARPROC pFunc = NULL;
	DWORD tid;
	hThread = CreateRemoteThread( hProcess, NULL, NULL, lpThreadProc, lpDllName, 0, &tid );
	if ( hThread == NULL )
	{
		return ret;
	}
	
	if(WaitForSingleObject(hThread,1000)==WAIT_TIMEOUT)
	{
		OutputDebugString( _T( "等待CreateRemoteThread返回超时!" ) );
		ret=false;
	}
	else
	{
		ret=true;
	}
	if (hThread != NULL )
	{
		CloseHandle( hThread );
		hThread = NULL;
	}
	return ret;

}