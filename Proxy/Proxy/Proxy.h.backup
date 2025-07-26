
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PROXY_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PROXY_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//以C方式导出方便使用
#ifdef PROXY_EXPORTS
#define PROXY_API extern "C"__declspec(dllexport)
#else
#define PROXY_API extern "C"__declspec(dllimport)
#endif

#include "Global/public.h"
#include "Global/function.h"

#ifdef __cplusplus
extern "C"{
// 	PROXY_API  CALLBAK_DATA* WINAPI RecvCallback(SOCKET s,char* payload,DWORD payloadLength,DWORD bufLength);
// 	PROXY_API  CALLBAK_DATA* WINAPI SendCallback(SOCKET s,char* payload,DWORD payLoadLength);
#endif // cplusplus




#ifdef __cplusplus
}
#endif // _cplusplus


//导出停止，暂停，开始的接口

#ifdef __cplusplus
extern "C"{
	PROXY_API  void Start();
	PROXY_API  void Quit();
	PROXY_API  void Pause();
	//PROXY_API  void CreateIPCWindowByThread();
#endif // cplusplus


#ifdef __cplusplus
}
#endif // _cplusplus

