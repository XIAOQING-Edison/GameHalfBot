#include "MessageHeartBeatReq.h"

CMessageHeartBeatReq::CMessageHeartBeatReq(void)
{
	SetProtocolId(e_cmd_heartbeat_req);
}

CMessageHeartBeatReq::~CMessageHeartBeatReq(void)
{
}


bool CMessageHeartBeatReq::Encode(CStreamReadWrite *pStreamBuf)
{
	CBaseMessage::Encode(pStreamBuf);
	ResetWritePostion();

	pStreamBuf->WriteShort(GetProtocolId());	//协议ID
	pStreamBuf->WriteFixedInt32(m_playerIndex);
	return true;
}


int CMessageHeartBeatReq::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();
	m_playerIndex=pStreamBuf->ReadFixedInt32();

EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;

}


void CMessageHeartBeatReq::MakeHeartBeatMessage(int playerIndex)
{
	this->m_playerIndex=playerIndex;
}
