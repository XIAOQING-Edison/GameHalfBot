#include "MessageReportDetail.h"

CMessageReportDetail::CMessageReportDetail(void)
{
	SetProtocolId(e_cmd_client_report_detail);
}

CMessageReportDetail::~CMessageReportDetail(void)
{
}



bool CMessageReportDetail::Encode(CStreamReadWrite *pStreamBuf)
{
	CBaseMessage::Encode(pStreamBuf);
	ResetWritePostion();

	pStreamBuf->WriteShort(GetProtocolId());	//协议ID
	int count=e_report_rev-e_report_coin;
	pStreamBuf->WriteFixedInt32(m_playerIndex);
	for(int i=0;i<count;++i)
	{
		pStreamBuf->WriteFixedInt64(m_reportData[i]);
	}
	return true;
}


//这个游戏到这里就是出错
int CMessageReportDetail::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	int count=e_report_rev-e_report_coin;
	m_playerIndex=pStreamBuf->ReadFixedInt32();
	for(int i=0;i<count;++i)
	{
		m_reportData[i]=pStreamBuf->ReadFixedInt64();
	}

	if(m_pServer)
	{
		// 		m_pServer->HandleMessage(this);
	}
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;

}


void CMessageReportDetail::MakeReportDetailMessage(int playerIndex,INT64 *arr,int count)
{
	this->m_playerIndex=playerIndex;
	memcpy(m_reportData,arr,count*sizeof(INT64));
}
