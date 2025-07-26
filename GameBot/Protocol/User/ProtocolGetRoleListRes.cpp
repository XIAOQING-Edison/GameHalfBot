#include "ProtocolGetRoleListRes.h"
#include "../../Player.h"

CProtocolGetRoleListRes::CProtocolGetRoleListRes(void)
{
	SetProtocolIdResOrSyn(ResGetRoleList);
}

CProtocolGetRoleListRes::~CProtocolGetRoleListRes(void)
{
}


//�������ֻʣ�°���ֱ�ӽ����ˣ�û��ͷ����Ϣ��������flag
int CProtocolGetRoleListRes::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	TRACE_OUTPUT(_T("����CProtocolGetRoleListRes\n"));
	int restBytes=m_packageLengthInRes-protocol_header_length;
	
	infoResGetRoleList.SetPackageLengthInRes(restBytes);
	infoResGetRoleList.Decode(pStreamBuf);
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;
}
