#include "MessageClientPlayerInfoStatus.h"
// #include "../Server.h"

CMessageClientPlayerInfoStatus::CMessageClientPlayerInfoStatus(void)
{
	SetProtocolId(e_cmd_client_player_info_status);
}

CMessageClientPlayerInfoStatus::~CMessageClientPlayerInfoStatus(void)
{
}


bool CMessageClientPlayerInfoStatus::Encode(CStreamReadWrite *pStreamBuf)
{
	CBaseMessage::Encode(pStreamBuf);
	ResetWritePostion();

	pStreamBuf->WriteShort(GetProtocolId());	//协议ID
	WriteBean(pStreamBuf,&m_playerInfoStatus);
	//test
	//TRACE_OUTPUT(_T("编码客户玩家数据:%s\n"),HexArrayToString(pStreamBuf->GetBufHead(),pStreamBuf->GetCurWritePostion()).c_str());
	return true;
}


//这个游戏到这里就是出错
int CMessageClientPlayerInfoStatus::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();
	CInfoPlayerInfoStatus *pInfo=(CInfoPlayerInfoStatus*)ReadBean(pStreamBuf);
	if(pInfo)
	{
		m_playerInfoStatus=*pInfo;
	}
	else
	{
		printf("read player info status failed,get null pointer!\n");
	}
// 	if(m_pServer)
// 	{
// 		m_pServer->HandleMessage(m_playerIndex,this);
// 	}
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;

}



void CMessageClientPlayerInfoStatus::MakeClientPlayerInfoStatusMessage(int index,CInfoPlayerInfoStatus *pInfo)
{
	this->m_playerInfoStatus=*(pInfo);
	this->m_index=index;
}