#pragma once
#include "../Global/public.h"

class CCrashHelper
{
public:
	CCrashHelper(void);
	~CCrashHelper(void);


	static LONG WINAPI InstallUnhandleExceptionFilter(PEXCEPTION_POINTERS pExceptionPointers);

	static void SetupExceptionHandler(PEXCEPTION_POINTERS pExceptionPointers);

	static BOOL RestartPrograme(TCHAR *szExePath);
};
