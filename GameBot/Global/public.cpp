#pragma once
// #include "StdAfx.h"
#include "public.h"
#include<time.h>
#include <CommDlg.h>

const TCHAR *g_szMainGameCfgName=_T("mainGameCfg.dat");
const TCHAR *g_szLogFileName=_T("log.log");
STRING g_exePath;
STRING g_exeName;
STRING g_dllPath;	//全局用的dll本地路径
HWND g_hwndMainDlg=NULL;


const TCHAR *g_szHttps=_T("https");
const TCHAR *g_szHttp=_T("http");

const TCHAR *g_szSharedMemoryName=_T("123456");

const int g_maxCount=5;


/************************************************************************/
/* public path defines herer								             */
/************************************************************************/

const TCHAR *g_szConfigPath=_T("GameConfig\\");
const TCHAR *g_szMapDataPath=_T("MapData\\");
int g_gameVersion=_GAME_VERSION_;	//默认是mu2

#ifdef _M_IX86
const const TCHAR *g_szProxyDllName=_T("Proxy.dll");
#else
const const TCHAR *g_szProxyDllName=_T("Proxy64.dll");
#endif // _M_IX86

#ifdef _M_IX86
const TCHAR *g_szHookDllName=_T("HookDll.dll");
#else
const TCHAR *g_szHookDllName=_T("HookDll64.dll");
#endif // _M_IX86



CThreadLock *g_pThreadRecvLock=new CThreadLock;
CThreadLock *g_pThreadSendLock=new CThreadLock;




/************************************************************************/
/*  public path defines end										         */
/************************************************************************/



string UTF8ToGBK(const std::string& strUTF8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8.c_str(), -1, NULL, 0);
	unsigned short * wszGBK = new unsigned short[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	::MultiByteToWideChar(CP_UTF8, 0, (LPCCH)strUTF8.c_str(), -1, (LPWSTR)wszGBK, len);

	len = WideCharToMultiByte(CP_ACP, 0, (LPCWCH)wszGBK, -1, NULL, 0, NULL, NULL);
	char *szGBK = new char[len + 1];
	memset(szGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, (LPCWCH)wszGBK, -1, szGBK, len, NULL, NULL);
	//strUTF8 = szGBK;  
	std::string strTemp(szGBK);
	delete[]szGBK;
	delete[]wszGBK;
	return strTemp;
}

std::string GBKToUTF8(const std::string& strGBK)
{
	string strOutUTF8 = "";
	WCHAR * str1;
	int n = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, NULL, 0);
	str1 = new WCHAR[n];
	MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, str1, n);
	n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);
	char * str2 = new char[n];
	WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);
	strOutUTF8 = str2;
	delete[]str1;
	str1 = NULL;
	delete[]str2;
	str2 = NULL;
	return strOutUTF8;
}



wstring GBKToUnicode(const char *lpcszString)
{
	int len = strlen(lpcszString);
	int unicodeLen = ::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, NULL, 0);
	wchar_t *pUnicode = new wchar_t[unicodeLen + 1];
	memset(pUnicode, 0, (unicodeLen + 1) *sizeof(wchar_t));
	::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, (LPWSTR)pUnicode, unicodeLen);
	wstring wString = (wchar_t *)pUnicode;
	delete[] pUnicode;
	return wString;
}

string UnicodeToGBK(const wchar_t *lpwcszWString)
{
	char *pElementText;
	int iTextLen;
	// wide char to multi char
	iTextLen = ::WideCharToMultiByte(CP_ACP, 0, lpwcszWString, -1, NULL, 0, NULL, NULL);
	pElementText = new char[iTextLen + 1];
	memset((void *)pElementText, 0, (iTextLen + 1) *sizeof(char));
	::WideCharToMultiByte(CP_ACP, 0, lpwcszWString,-1, pElementText, iTextLen+1, NULL, NULL);
	string strReturn(pElementText);
	delete[] pElementText;
	return strReturn;
}

wstring UTF8ToUnicode(const char *lpcszString)
{
	int len = strlen(lpcszString);
	int unicodeLen = ::MultiByteToWideChar(CP_UTF8, 0, lpcszString, -1, NULL, 0);
	wchar_t *pUnicode;
	pUnicode = new wchar_t[unicodeLen + 1];
	memset((void *)pUnicode, 0, (unicodeLen + 1) *sizeof(wchar_t));
	::MultiByteToWideChar(CP_UTF8, 0, lpcszString, -1, (LPWSTR)pUnicode, unicodeLen);
	wstring wstrReturn(pUnicode);
	delete[] pUnicode;
	return wstrReturn;
}

string UnicodeToUTF8(const wchar_t *lpwcszWString)
{
	char *pElementText;
	int iTextLen = ::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, NULL, 0, NULL, NULL);
	pElementText = new char[iTextLen + 1];
	memset((void *)pElementText, 0, (iTextLen + 1) *sizeof(char));
	::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, pElementText, iTextLen, NULL, NULL);
	string strReturn(pElementText);
	delete[] pElementText;
	return strReturn;
}




//////////////////////////////////////////////////////////////////////////
STRING GetCurrentAppPath()	//取得当前EXE运行目录
{
	return GetModuleFolderPath(NULL);

}

STRING GetCurrentDllModuleFolderPath()	//取得当前dll运行目录
{
	STRING path;
	HMODULE hMod=GetCurrentModuleHandle();
	if(hMod)
	{
		if(g_dllPath.empty())
		{
			g_dllPath=GetModuleFolderPath(hMod);
		}
		path=g_dllPath;
	}
	
	return path;
}

STRING GetCurrentDllModuleParentPath()	//取得当前DLL的父路径
{
	STRING dllPath=GetCurrentDllModuleFolderPath();
	STRING parentPath;
	int pos;
	dllPath.erase(dllPath.length()-1);	//去除最后一个'\\'
	pos=dllPath.rfind(_T("\\"));
	parentPath=dllPath.substr(0,pos+1);
	return parentPath;
}

STRING GetModuleFullPath(HMODULE hMod)	//取得当前模块的全路径
{
	STRING result;
	TCHAR  path[MAX_PATH+1];

	memset(path,0,sizeof(path));
	GetModuleFileName(hMod,path,MAX_PATH);
	result=path;
	int pos = result.rfind('\\');
	if(pos !=string::npos)
	{
		result=result.substr(0,pos+1);
	}
	return result;

}

STRING GetModuleFolderPath(HMODULE hMod)//取得当前模块的目录路径
{
	STRING result;
	TCHAR  path[MAX_PATH+1];
	memset(path,0,sizeof(path));
	GetModuleFileName(hMod,path,MAX_PATH);
	result=path;
	int pos = result.rfind('\\');
	if(pos !=string::npos)
	{
		result=result.substr(0,pos+1);
	}
	return result;
}

HMODULE GetCurrentModuleHandle()	//取得当前模块基址
{
	MEMORY_BASIC_INFORMATION mbi;
	return ((::VirtualQuery(GetCurrentModuleHandle, &mbi, sizeof(mbi)) != 0) ? (HMODULE)mbi.AllocationBase : NULL);
}


////////////////////////////////stringfunction begin//////////////////////////////////////////




bool InitSocketLib()	//初始化sockect库
{
	int ret=0;
	WSADATA wsadata;
	ret=WSAStartup(MAKEWORD(1, 1), &wsadata);
	if(ret!=0)
	{
		TRACE_OUTPUT(_T("WSAStartup failed,error %x\n"),WSAGetLastError());
	}
	return !ret;
}



bool CleanupSocketLib()	//清理socket库
{
	int ret=WSACleanup();
	if(ret!=0)
	{
		TRACE_OUTPUT(_T("WSACleanup failed,error %x\n"),WSAGetLastError());
	}
	return !ret;
}




/////////////////////////////////url functions end/////////////////////////////////////////

/////////////////////////////////ip function end/////////////////////////////////////////

///////////////////////////////////杂项///////////////////////////////////////


void TRACE_OUTPUT(LPCTSTR szFormat, ... )
{
#if 0
	printf("%s",szFormat);
#endif
}

