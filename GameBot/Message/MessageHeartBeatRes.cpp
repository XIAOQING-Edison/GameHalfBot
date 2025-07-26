#include "MessageHeartBeatRes.h"
// #include "../Server.h"



CMessageHeartBeatRes::CMessageHeartBeatRes(void)
{
	SetProtocolId(e_cmd_heartbeat_res);
}

CMessageHeartBeatRes::~CMessageHeartBeatRes(void)
{
}



//服务端编码
bool CMessageHeartBeatRes::Encode(CStreamReadWrite *pStreamBuf)
{
	CBaseMessage::Encode(pStreamBuf);
	ResetWritePostion();

	pStreamBuf->WriteShort(GetProtocolId());	//协议ID
	pStreamBuf->WriteFixedInt32(m_code);
	return true;
}


//这个游戏到这里就是出错
int CMessageHeartBeatRes::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	m_code=pStreamBuf->ReadFixedInt32();

EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;

}




void CMessageHeartBeatRes::MakeHeartBeatResMessage(int code)
{
	this->m_code=code;
}

