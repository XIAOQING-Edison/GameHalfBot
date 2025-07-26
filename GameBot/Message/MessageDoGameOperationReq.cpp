#include "MessageDoGameOperationReq.h"
char g_paramBuf[512];
CMessageDoGameOperationReq::CMessageDoGameOperationReq(void)
{
	m_data=g_paramBuf;
	SetProtocolId(e_cmd_client_do_game_operation_req);
}

CMessageDoGameOperationReq::~CMessageDoGameOperationReq(void)
{
}


bool CMessageDoGameOperationReq::Encode(CStreamReadWrite *pStreamBuf)
{
	CBaseMessage::Encode(pStreamBuf);
	ResetWritePostion();

	pStreamBuf->WriteShort(GetProtocolId());	//协议ID
	pStreamBuf->WriteFixedInt32(m_gameOperationProtocolId);	//要客户执行的protocolId
	pStreamBuf->WriteFixedInt32(m_paramLength);
	pStreamBuf->WriteBytes(m_data,m_paramLength);
	return true;
}


int CMessageDoGameOperationReq::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();
	m_gameOperationProtocolId=pStreamBuf->ReadFixedInt32();
	m_paramLength=pStreamBuf->ReadFixedInt32();
	if(m_paramLength>0)
	{
		char *pData=pStreamBuf->ReadBytes(0,m_paramLength);
		memcpy(m_data,pData,m_paramLength);
	}
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;

}

void CMessageDoGameOperationReq::MakeDoGameOperationMessage(int protocolId,int paramLength,char *data)	//协议id,paramLength是参数长度,data是参数内容
{
	m_gameOperationProtocolId=protocolId;
	m_paramLength=paramLength;
	memcpy(m_data,data,paramLength);
}