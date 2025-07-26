#include "MessageLoginReq.h"

CMessageLoginReq::CMessageLoginReq(void)
{
	SetProtocolId(e_cmd_login_req);
}

CMessageLoginReq::~CMessageLoginReq(void)
{
}



bool CMessageLoginReq::Encode(CStreamReadWrite *pStreamBuf)
{
	CBaseMessage::Encode(pStreamBuf);
	ResetWritePostion();

	pStreamBuf->WriteShort(GetProtocolId());	//Ð­ÒéID
	pStreamBuf->WriteFixedInt32(m_playerIndex);
	return true;
}


int CMessageLoginReq::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();
	
	m_playerIndex=pStreamBuf->ReadFixedInt32();
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;

}


void CMessageLoginReq::MakeLoginMessage(int playerIndex)
{
	this->m_playerIndex=playerIndex;
}