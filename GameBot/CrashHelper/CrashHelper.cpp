#include "CrashHelper.h"
#include <dbghelp.h>
#include <shellapi.h>
#include <shlobj.h>

#include "../Misc/Misc.h"


#pragma warning(disable:4996)

#ifdef _M_IX86
#pragma comment(lib,"dbghelp.lib")
#else
#pragma comment(lib,"dbghelp64.lib")
#endif // _IMX_86

#ifndef MiniDumpWithThreadInfo
#define MiniDumpWithThreadInfo	0x00001000
#endif

CCrashHelper::CCrashHelper(void)
{
}

CCrashHelper::~CCrashHelper(void)
{
}



LONG WINAPI CCrashHelper::InstallUnhandleExceptionFilter(PEXCEPTION_POINTERS pExceptionPointers)
{
	SetupExceptionHandler(pExceptionPointers);
	return EXCEPTION_CONTINUE_EXECUTION;
}



void CCrashHelper::SetupExceptionHandler(PEXCEPTION_POINTERS pExceptionPointers)
{
	
}


//重启程序
BOOL CCrashHelper::RestartPrograme(TCHAR *szExePath)
{
	BOOL ret=FALSE;

	return ret;
}
