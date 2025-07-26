#include "ProtocolBagInfoRes.h"
#include "../../Player.h"

CProtocolBagInfoRes::CProtocolBagInfoRes(void)
{
	SetProtocolIdResOrSyn(ResBagInfo);
}

CProtocolBagInfoRes::~CProtocolBagInfoRes(void)
{
}



int CProtocolBagInfoRes::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	TRACE_OUTPUT(_T("����CProtocolBagInfoRes\n"));

	bool bFinish=false;
	int restBytes=m_packageLengthInRes-protocol_header_length;	//��ȡ�̶����ȵ��ֽھͽ�����
	pStreamBuf->SetHandlePos(orgPos+restBytes);

	OutputDebugStr(_T("----------------CProtocolBagInfoRes----------------\n"));
	if(m_pPlayer)
	{
// 		vector<void*> items=bagInfo.GetItems();
// 		vector<void*> coins=bagInfo.GetCoins();
	}
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	//TRACE_OUTPUT(_T("CProtocolBagInfoRes ��������:%d\n"),handleLength);
	return handleLength;
}
