#ifndef _DLL_DUMP_H_
#define _DLL_DUMP_H_
#include "Global/public.h"
typedef void (*CRASH_CALL_BACK)(const TCHAR *szMsg);

//以C方式导出方便使用
#ifdef DLLDUMP_EXPORTS
#define DLLDUMP_API extern "C"__declspec(dllexport)
#else
#define DLLDUMP_API extern "C"__declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"{
	DLLDUMP_API  void SetCallback(void *p);
#endif // cplusplus


#ifdef __cplusplus
}
#endif


#endif // _DLL_DUMP_H_