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

	pStreamBuf->WriteShort(GetProtocolId());	//Э��ID
	pStreamBuf->WriteFixedInt32(m_gameOperationProtocolId);	//Ҫ�ͻ�ִ�е�protocolId
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

void CMessageDoGameOperationReq::MakeDoGameOperationMessage(int protocolId,int paramLength,char *data)	//Э��id,paramLength�ǲ�������,data�ǲ�������
{
	m_gameOperationProtocolId=protocolId;
	m_paramLength=paramLength;
	memcpy(m_data,data,paramLength);
}