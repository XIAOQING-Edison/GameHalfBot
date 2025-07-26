#include "ProtocolGetRoleListRes.h"
#include "../../Player.h"

CProtocolGetRoleListRes::CProtocolGetRoleListRes(void)
{
	SetProtocolIdResOrSyn(ResGetRoleList);
}

CProtocolGetRoleListRes::~CProtocolGetRoleListRes(void)
{
}


//到这里就只剩下包体直接解析了，没有头部信息或者其它flag
int CProtocolGetRoleListRes::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	TRACE_OUTPUT(_T("解析CProtocolGetRoleListRes\n"));
	int restBytes=m_packageLengthInRes-protocol_header_length;
	
	infoResGetRoleList.SetPackageLengthInRes(restBytes);
	infoResGetRoleList.Decode(pStreamBuf);
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;
}
