#include "MessageClientQuitReq.h"

CMessageClientQuitReq::CMessageClientQuitReq(void)
{
	SetProtocolId(e_cmd_client_quit_req);
}

CMessageClientQuitReq::~CMessageClientQuitReq(void)
{
}


bool CMessageClientQuitReq::Encode(CStreamReadWrite *pStreamBuf)
{
	CBaseMessage::Encode(pStreamBuf);
	ResetWritePostion();

	pStreamBuf->WriteShort(GetProtocolId());	//协议ID
	pStreamBuf->WriteFixedInt32(m_playerIndex);
	return true;
}


int CMessageClientQuitReq::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();
	m_playerIndex=pStreamBuf->ReadFixedInt32();

EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;

}



void CMessageClientQuitReq::MakeClientQuitMessage(int playerIndex)
{
	this->m_playerIndex=playerIndex;
}