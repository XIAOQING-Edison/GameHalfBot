#include "MessageClientPlayerTaskStatus.h"
//#include "../Server.h"

CMessageClientPlayerTaskStatus::CMessageClientPlayerTaskStatus(void)
{
	SetProtocolId(e_cmd_client_player_task_status);
}

CMessageClientPlayerTaskStatus::~CMessageClientPlayerTaskStatus(void)
{
}




bool CMessageClientPlayerTaskStatus::Encode(CStreamReadWrite *pStreamBuf)
{
	CBaseMessage::Encode(pStreamBuf);
	ResetWritePostion();

	pStreamBuf->WriteShort(GetProtocolId());	//协议ID
	pStreamBuf->WriteFixedInt32(m_index);
	pStreamBuf->WriteBigString(m_taskStatus.c_str());
	return true;
}


//这个游戏到这里就是出错
int CMessageClientPlayerTaskStatus::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	m_index=pStreamBuf->ReadFixedInt32();
	m_taskStatus=pStreamBuf->ReadBigString();

	if(m_pServer)
	{
// 		m_pServer->HandleMessage(this);
	}
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;

}


void CMessageClientPlayerTaskStatus::MakeClientPlayerTaskStatusMessage(int index,STRING &task)
{
	this->m_taskStatus=task;
	this->m_index=index;
}