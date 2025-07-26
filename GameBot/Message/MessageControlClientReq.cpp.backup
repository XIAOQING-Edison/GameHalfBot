#include "MessageControlClientReq.h"

CMessageControlClientReq::CMessageControlClientReq(void)
{
	SetProtocolId(e_cmd_control_client_req);
}

CMessageControlClientReq::~CMessageControlClientReq(void)
{
}


bool CMessageControlClientReq::Encode(CStreamReadWrite *pStreamBuf)
{
	CBaseMessage::Encode(pStreamBuf);
	ResetWritePostion();

	pStreamBuf->WriteShort(GetProtocolId());	//Ð­ÒéID
	pStreamBuf->WriteFixedInt32(m_gameOp);
	return true;
}


int CMessageControlClientReq::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();
	m_gameOp=pStreamBuf->ReadFixedInt32();

EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;

}



void CMessageControlClientReq::MakeControlMessage(int gameOp)
{
	this->m_gameOp=gameOp;
}