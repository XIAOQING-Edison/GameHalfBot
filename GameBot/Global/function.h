#ifndef _FUNCTION_H_
#define _FUNCTION_H_
typedef struct _CALLBACK_DATA{
	char *newPayload;
	DWORD newPayloadLength;
}CALLBAK_DATA;

typedef CALLBAK_DATA* (WINAPI *RECVCALLBACKFUNC)(SOCKET s,char* payLoad,DWORD payLoadLength,DWORD bufLength);	//������Ҫ���㲻�ܳ���bufLength������ĳ���
typedef CALLBAK_DATA* (WINAPI *SENDCALLBACKFUNC)(SOCKET s,char* payLoad,DWORD payLoadLength);


#endif // _FUNCTION_H_
