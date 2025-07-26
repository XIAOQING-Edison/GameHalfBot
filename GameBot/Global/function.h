#ifndef _FUNCTION_H_
#define _FUNCTION_H_
typedef struct _CALLBACK_DATA{
	char *newPayload;
	DWORD newPayloadLength;
}CALLBAK_DATA;

typedef CALLBAK_DATA* (WINAPI *RECVCALLBACKFUNC)(SOCKET s,char* payLoad,DWORD payLoadLength,DWORD bufLength);	//里面需要计算不能超过bufLength所代表的长度
typedef CALLBAK_DATA* (WINAPI *SENDCALLBACKFUNC)(SOCKET s,char* payLoad,DWORD payLoadLength);


#endif // _FUNCTION_H_
