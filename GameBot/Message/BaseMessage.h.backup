#pragma once

#include "../Global/public.h"
#include "../MemoryStream/StreamReadWrite.h"
#include "../Global/Enums.h"
class CPlayer;	//client need this
class CServer;	//server need this
class CBaseMessage
{
public:
	CBaseMessage(void);
	virtual ~CBaseMessage(void);

	

	virtual bool Encode(CStreamReadWrite *pStreamBuf){m_pProtocolEncodeStreamBuf=pStreamBuf;return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf){return 0;}

	void Init();
	BYTE *GetProtocolBuf(){return (BYTE*)m_pProtocolEncodeStreamBuf->GetBufHead();}
	int GetProtocolBufLength(){return m_pProtocolEncodeStreamBuf->GetCurWritePostion();}

	BYTE *GetEncodeBufLength(int &len){len=GetProtocolBufLength();return GetProtocolBuf();}

	void SetProtocolId(WORD id){m_protocolId=id;}
	WORD GetProtocolId(){return m_protocolId&0xffff;}



	int DecodeFirst(CStreamReadWrite *pStreamBuf);	//先解码出长度,protocolId这类,返回协议长度


	//void SetCurrentPlayer(CPlayer *p){m_pPlayer=p;}
	void SetCurrentServer(CServer *p){m_pServer=p;}

	void ResetWritePostion(){m_pProtocolEncodeStreamBuf->ResetCurWritePosition();}

	CBaseMessage *ReadBean(CStreamReadWrite *pStreamBuf);
	void WriteBean(CStreamReadWrite *pStreamBuf,CBaseMessage *pMsg);
public:

protected:
	CServer *m_pServer;
	
	WORD m_protocolId;	//请求的protocolId,用作发送
	CStreamReadWrite *m_pProtocolEncodeStreamBuf;

};
