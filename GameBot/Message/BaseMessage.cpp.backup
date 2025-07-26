#include "BaseMessage.h"
#include "../MessageMapList.h"


CBaseMessage::CBaseMessage(void)
{
	SetCurrentServer(NULL);
	Init();
}

CBaseMessage::~CBaseMessage(void)
{
}


void CBaseMessage::Init()
{
	m_pProtocolEncodeStreamBuf=NULL;
	SetProtocolId(0);
}



int CBaseMessage::DecodeFirst(CStreamReadWrite *pStreamBuf)	//先解码出长度,protocolId这类,返回协议长度
{
	int orgHandlePos=pStreamBuf->GetHandlePos();	//最初的位置存起来，后面长度不够时就再
	int packageLen=0;
	int protocolId=0;
	int minLen=0;	//包结构是4字节长度+4字节0+2字节协议ID,包的总长度是包长度+4字节
	int packageFlag;//4字节0我命令为packageFlag

	packageLen=pStreamBuf->ReadFixedInt32();
	//TRACE_OUTPUT(_T("解码得包长:%d\n"),packageLen);
	if((packageLen+minLen)<=pStreamBuf->GetRestBytesLength())
	{

		protocolId=(WORD)pStreamBuf->ReadShort()&0xffff;
		//TRACE_OUTPUT(_T("解码得协议id:%d\n"),protocolId);
		SetProtocolId(protocolId);
	}
	else
	{
		//包需要的长度大于接收长度，则需要继续接收
		TRACE_OUTPUT(_T("所需包长大于接收的长度，继续接收!!!\n"));
		pStreamBuf->SetHandlePos(orgHandlePos);
		packageLen=0;
	}

	return packageLen;
}


CBaseMessage *CBaseMessage::ReadBean(CStreamReadWrite *pStreamBuf)
{
	CBaseMessage *pMsg=NULL;
	int id=pStreamBuf->ReadShort();
	pMsg=CMessageMapList::GetInstance()->GetMessageById(id);
	if(pMsg)
	{
		pMsg->Decode(pStreamBuf);
	}
	return pMsg;
}


void CBaseMessage::WriteBean(CStreamReadWrite *pStreamBuf,CBaseMessage *pMsg)
{
	//int len=0;
	CStreamReadWrite tempBuf(E_ENDIAN_TYPE_LITTLE_ENDIAN,512);

	pMsg->Encode(&tempBuf);
	int len=pMsg->GetProtocolBufLength();
	int sizeofProtocolId=sizeof(WORD);	//这里协议ID固定2字节

	pStreamBuf->WriteShort(pMsg->GetProtocolId());//ID
	pStreamBuf->WriteBytes((char*)tempBuf.GetBufHead()+sizeofProtocolId,len-sizeofProtocolId);//直接写内容,略过4字节ID

	//return len;
}