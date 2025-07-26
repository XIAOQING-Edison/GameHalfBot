#include "MessageClientQuitRes.h"

CMessageClientQuitRes::CMessageClientQuitRes(void)
{
	SetProtocolId(e_cmd_client_quit_res);
}

CMessageClientQuitRes::~CMessageClientQuitRes(void)
{
}


bool CMessageClientQuitRes::Encode(CStreamReadWrite *pStreamBuf)
{
	CBaseMessage::Encode(pStreamBuf);
	ResetWritePostion();

	pStreamBuf->WriteShort(GetProtocolId());	//协议ID
	pStreamBuf->WriteFixedInt32(m_resCode);
	return true;
}


//这个游戏到这里就是出错
int CMessageClientQuitRes::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	m_resCode=pStreamBuf->ReadFixedInt32();
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;

}


void CMessageClientQuitRes::MakeClientQuitMessage(int code)
{
	this->m_resCode=code;
}