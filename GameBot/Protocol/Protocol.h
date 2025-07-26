#pragma once
#include "../Global/public.h"
#include "../MemoryStream/StreamReadWrite.h"
#include "ProtocolValue.h"

const int protocol_header_length=4+4+2;//最小为10字节:length+sign(4字节0)+protocolId(2字节)




class CPlayer;
class CProtocol
{
public:
	CProtocol(void);
	virtual ~CProtocol(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf){m_pProtocolEncodeStreamBuf=pStreamBuf;return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf){return 0;}


	virtual void Clone(CProtocol **p);	//用虚函数来返回子类对象,这里的指针需要手动释放

	void Init();
	BYTE *GetProtocolBuf(){return (BYTE*)m_pProtocolEncodeStreamBuf->GetBufHead();}
	int GetProtocolBufLength(){return m_pProtocolEncodeStreamBuf->GetCurWritePostion();}

	BYTE *GetEncodeBufLength(int &len){len=GetProtocolBufLength();return GetProtocolBuf();}

	void SetProtocolIdReq(DWORD id){m_protocolIdReq=id;}
	DWORD GetProtocolIdReq(){return m_protocolIdReq;}


	void SetProtocolIdResOrSyn(DWORD id){m_protocolIdResOrSyn=id;}
	DWORD GetProtocolIdResOrSyn(){return m_protocolIdResOrSyn;}
	
	int DecodeFirst(CStreamReadWrite *pStreamBuf);	//先解码出长度,protocolId这类,返回协议长度


	void SetCurrentPlayer(CPlayer *p){m_pPlayer=p;}

	void ResetWritePostion(){m_pProtocolEncodeStreamBuf->ResetCurWritePosition();}

public:
	//特定协议
public:
	void SetPackageLengthInRes(int len){m_packageLengthInRes=len;}
protected:
	CPlayer *m_pPlayer;
	DWORD m_protocolIdReq;	//请求的protocolId,用作发送
	DWORD m_protocolIdResOrSyn;	//得到的protocolId,接收后才判断是否是res或syn这两类响应
	CStreamReadWrite *m_pProtocolEncodeStreamBuf;
	int m_packageLengthInRes;	//回应时得到的实际长度

};
