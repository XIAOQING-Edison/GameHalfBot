#pragma once
#include <TlHelp32.h>
#include "../Global/public.h"
#pragma comment(lib,"Ws2_32.lib")

struct NtCreateThreadExBuffer
{
    ULONG Size;
    ULONG Unknown1;
    ULONG Unknown2;
    PULONG Unknown3;
    ULONG Unknown4;
    ULONG Unknown5;
    ULONG Unknown6;
    PULONG Unknown7;
    ULONG Unknown8;
};


//32位和64位有不同
#ifdef _M_IX86
typedef DWORD( WINAPI *PFNTCREATETHREADEX )(
	PHANDLE hThread, ACCESS_MASK DesiredAccess, LPVOID ObjectAttributes, HANDLE ProcessHandle, LPTHREAD_START_ROUTINE lpStartAddress,
	LPVOID lpParameter, BOOL CreateSuspended, ULONG StackZeroBits, ULONG SizeOfStackCommit, ULONG SizeOfStackReserve, NtCreateThreadExBuffer* lpBytesBuffer );
#else
typedef DWORD(WINAPI * PFNTCREATETHREADEX)(   
	PHANDLE ThreadHandle,ACCESS_MASK DesiredAccess,LPVOID ObjectAttributes,HANDLE ProcessHandle,LPTHREAD_START_ROUTINE lpStartAddress,   
	LPVOID lpParameter,ULONG CreateThreadFlags,SIZE_T ZeroBits,SIZE_T StackSize,SIZE_T MaximumStackSize,PVOID AttributeList);
#endif // _M_IX86

typedef struct _CLIENT_ID {
	HANDLE UniqueProcess;
	HANDLE UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

//这里还不知道32和64是否有区别
typedef DWORD(NTAPI * pfnRtlCreateUserThread)(
	IN HANDLE ProcessHandle,
	IN PSECURITY_DESCRIPTOR SecurityDescriptor OPTIONAL,
	IN BOOLEAN CreateSuspended,
	IN ULONG StackZeroBits OPTIONAL,
	IN SIZE_T StackReserve OPTIONAL,
	IN SIZE_T StackCommit OPTIONAL,
	IN PTHREAD_START_ROUTINE StartAddress,
	IN PVOID Parameter OPTIONAL,
	OUT PHANDLE ThreadHandle OPTIONAL,
	OUT PCLIENT_ID ClientId OPTIONAL);


BOOL IsVistaOrLater()
{
    OSVERSIONINFO osvi;
    ZeroMemory( &osvi, sizeof( OSVERSIONINFO ) );
    osvi.dwOSVersionInfoSize = sizeof( OSVERSIONINFO );
    GetVersionEx( &osvi );
    if ( osvi.dwMajorVersion >= 6 )
        return TRUE;
    return FALSE;
}

BOOL MyCreateRemoteThread( HANDLE hProcess, LPTHREAD_START_ROUTINE  lpThreadProc, LPVOID lpDllName )
{
    HANDLE hThread = NULL;
    FARPROC pFunc = NULL;
	//test，先不用ntcreateThread
    if ( IsVistaOrLater() &&FALSE) //NT6.0以后，有大牛用OD进行调试跟进发现最终调用的事ntdll.NtCreateThreadEx函数进行创建远程线程
    {
        pFunc = GetProcAddress( GetModuleHandle( _TEXT( "ntdll.dll" ) ), "NtCreateThreadEx" );
        if ( pFunc == NULL )
        {
            OutputDebugString( _TEXT( "获取NtCreateThreadEx地址失败!" ) );
            return FALSE;
        }
        __try
        {
            ( ( PFNTCREATETHREADEX )pFunc )( &hThread,
                                             0x1FFFFF,
                                             NULL,
                                             hProcess,
                                             lpThreadProc,
                                             lpDllName,
                                             FALSE,
                                             NULL,
                                             NULL,
                                             NULL,
                                             NULL );
        }
        __finally
        {
        
        }
        if ( hThread == NULL )
        {
            OutputDebugString( _TEXT( "调用NtCreateThreadEx失败!" ) );
            return FALSE;
        }
        
    }
    else
    {
        hThread = CreateRemoteThread( hProcess, NULL, NULL, lpThreadProc, lpDllName, 0, NULL );
        if ( hThread == NULL )
        {
            return FALSE;
        }
    }
    if ( WAIT_TIMEOUT == WaitForSingleObject( hThread, INFINITE ) )
    {
        OutputDebugString( _TEXT( "等待超时!" ) );
        return FALSE;
    }
    CloseHandle( hThread );
    return TRUE;
}

BOOL EnablePrivilege( LPCTSTR PrivilegeName )
{
    HANDLE tokenhandle;
    TOKEN_PRIVILEGES tp;
    tp.PrivilegeCount = 1;
    tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    
    if ( !OpenProcessToken( GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &tokenhandle ) )
    {
        return FALSE;
    }
    
    if ( !LookupPrivilegeValue( NULL, PrivilegeName, &tp.Privileges[0].Luid ) )
    {
        CloseHandle( tokenhandle );
        return FALSE;
    }
    
    if ( !AdjustTokenPrivileges( tokenhandle, FALSE, &tp, sizeof( tp ), NULL, NULL ) )
    {
        CloseHandle( tokenhandle );
        return FALSE;
    }
    
    CloseHandle( tokenhandle );
    return TRUE;
}

BOOL InjectDll( DWORD dwPID, LPCTSTR lpszDllName )
{
	TCHAR buf[MAX_PATH];
    if ( !GetFileAttributes( lpszDllName ) ==-1)
    {
        return FALSE;
    }
    
    if ( !EnablePrivilege( SE_DEBUG_NAME ) )
    {
        return FALSE;
    }
    
    BOOL bRet = FALSE;
    HANDLE hPro =::OpenProcess( PROCESS_ALL_ACCESS, FALSE, dwPID );
    
    if ( NULL == hPro )
    {
        return FALSE;
    }
    
    LPVOID pszLibFileRemote = NULL;
    HANDLE hRemoteThread = NULL;
    BOOL bSucc=FALSE;
    __try
    {
        int cb  = ( _tcslen( lpszDllName ) + 1 ) * sizeof( TCHAR );
        pszLibFileRemote = VirtualAllocEx( hPro, NULL, cb, MEM_COMMIT, PAGE_READWRITE );
        
        if ( pszLibFileRemote == NULL )
        {
            return FALSE;
        }
        
		SIZE_T bytesWritten;
        if ( !WriteProcessMemory( hPro, pszLibFileRemote, ( PVOID ) lpszDllName, cb, &bytesWritten ) )
        {
            return FALSE;
        }

		//test
		//_stprintf(buf,_TEXT("要写入:%d字节，已写入:%d字节"),cb,bytesWritten);
		//MessageBox(NULL,buf,_TEXT("Info"),MB_OK);
        
#ifdef _UNICODE
#define Libaray ("LoadLibraryW")
#else
#define Libaray ("LoadLibraryA")
#endif
        PTHREAD_START_ROUTINE pfnThreadRtn = ( PTHREAD_START_ROUTINE )GetProcAddress( GetModuleHandle( _TEXT( "Kernel32" ) ), Libaray );
        
        if ( pfnThreadRtn == NULL )
        {
            return FALSE;
        }
        
        //        hRemoteThread = ::CreateRemoteThread( hPro, NULL, 0, pfnThreadRtn, pszLibFileRemote, 0, NULL );
        
        bSucc = MyCreateRemoteThread( hPro, pfnThreadRtn, pszLibFileRemote );
        
        if ( bSucc == FALSE )
        {
            return FALSE;
        }
        
        //WaitForSingleObject( hRemoteThread, INFINITE );
        //return TRUE;
    }
    __finally
    {
        if (hRemoteThread  != NULL )
        {
            CloseHandle( hRemoteThread );
            hRemoteThread = NULL;
        }
        
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
    }
    
    return bSucc;
}

BOOL UnInjectDll( DWORD dwPID, LPCTSTR lpszDllName )
{
    if ( !EnablePrivilege( SE_DEBUG_NAME ) )
    {
        return FALSE;
    }
    
    BOOL bRet = FALSE;
    HANDLE hPro =::OpenProcess( PROCESS_ALL_ACCESS, FALSE, dwPID );
    
    if (NULL == hPro )
    {
        return FALSE;
    }
    
    HANDLE hthSnapshot = NULL;
    HANDLE hThread = NULL;
    
    __try
    {
        // Grab a new snapshot of the process
        hthSnapshot = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, dwPID );
        
        if ( hthSnapshot == NULL )
        {
            return FALSE;
        }
        
        // Get the HMODULE of the desired library
        MODULEENTRY32 me = { sizeof( me ) };
        BOOL fFound = FALSE;
        BOOL fMoreMods = Module32First( hthSnapshot, &me );
        
        for ( ; fMoreMods; fMoreMods = Module32Next( hthSnapshot, &me ) )
        {
            fFound = ( _tcscmp( me.szModule,  lpszDllName ) == 0 ) ||
                     ( _tcscmp( me.szExePath, lpszDllName ) == 0 );
                     
            if ( fFound ) break;
        }
        
        if ( !fFound )
        {
            return FALSE;
        }
        
        // Get the real address of LoadLibraryW in Kernel32.dll
        PTHREAD_START_ROUTINE pfnThreadRtn = ( PTHREAD_START_ROUTINE )GetProcAddress(GetModuleHandle(_TEXT( "Kernel32" ) ), "FreeLibrary" );
        if ( pfnThreadRtn == NULL )
        {
            return FALSE;
        }
        
        // Create a remote thread that calls LoadLibraryW(DLLPathname)
        BOOL bInject = MyCreateRemoteThread( hPro, pfnThreadRtn, me.modBaseAddr );
        if ( bInject == FALSE )
        {
            return FALSE;
        }
        //         hThread = ::CreateRemoteThread( hPro, NULL, 0, pfnThreadRtn, me.modBaseAddr, 0, NULL );
        //
        //         if ( hThread == NULL )
        //         {
        //             return FALSE;
        //         }
        
        // Wait for the remote thread to terminate
        //WaitForSingleObject( hThread, INFINITE );
        return TRUE;
    }
    __finally   // Now we can clean everything up
    {
        if ( hThread != NULL )
        {
            CloseHandle( hThread );
            hThread = NULL;
        }
        
        if ( hthSnapshot != NULL )
        {
            CloseHandle( hthSnapshot );
            hThread = NULL;
        }
        
        if ( NULL != hPro )
        {
            ::CloseHandle( hPro );
            hPro = NULL;
        }
    }
    
    return FALSE;
}


wchar_t* AnsiToUnicode( const char* szStr )
{
    int nLen = MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, szStr, -1, NULL, 0 );
    if ( nLen == 0 )
    {
        return NULL;
    }
    wchar_t* pResult = new wchar_t[nLen];
    MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, szStr, -1, pResult, nLen );
    return pResult;
}


char* UnicodeToAnsi( const wchar_t* szStr )
{
    int nLen = WideCharToMultiByte( CP_ACP, 0, szStr, -1, NULL, 0, NULL, NULL );
    if ( nLen == 0 )
    {
        return NULL;
    }
    char* pResult = new char[nLen];
    WideCharToMultiByte( CP_ACP, 0, szStr, -1, pResult, nLen, NULL, NULL );
    return pResult;
}
