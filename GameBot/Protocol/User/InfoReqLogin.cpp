#include "InfoReqLogin.h"

CInfoReqLogin::CInfoReqLogin(void)
{
}

CInfoReqLogin::~CInfoReqLogin(void)
{
}

//这个带req的应该不需要decode
//到这里就只剩下包体直接解析了，没有头部信息或者其它flag
int CInfoReqLogin::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	TRACE_OUTPUT(_T("解析CInfoReqLogin\n"));


EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	//TRACE_OUTPUT(_T("CInfoReqLogin 解析长度:%d\n"),handleLength);
	return handleLength;
}