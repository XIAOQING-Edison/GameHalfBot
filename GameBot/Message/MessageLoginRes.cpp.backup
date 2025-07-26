#include "MessageLoginRes.h"

CMessageLoginRes::CMessageLoginRes(void)
{
	SetProtocolId(e_cmd_login_res);
}

CMessageLoginRes::~CMessageLoginRes(void)
{
}


bool CMessageLoginRes::Encode(CStreamReadWrite *pStreamBuf)
{
	CBaseMessage::Encode(pStreamBuf);
	ResetWritePostion();

	pStreamBuf->WriteShort(GetProtocolId());	//协议ID
	pStreamBuf->WriteFixedInt32(m_assignedId);
	pStreamBuf->WriteFixedInt32(m_resCode);
	return true;
}


//这个游戏到这里就是出错
int CMessageLoginRes::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	m_assignedId=pStreamBuf->ReadFixedInt32();
	m_resCode=pStreamBuf->ReadFixedInt32();

EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;

}



void CMessageLoginRes::MakeLoginResMessage(int index,int code)
{
	this->m_assignedId=index;
	this->m_resCode=code;
}