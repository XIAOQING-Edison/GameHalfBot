#pragma once
#include "basemessage.h"

class CMessageHeartBeatReq :
	public CBaseMessage
{
public:
	CMessageHeartBeatReq(void);
	virtual ~CMessageHeartBeatReq(void);


	virtual bool Encode(CStreamReadWrite *pStreamBuf);
	virtual int Decode(CStreamReadWrite *pStreamBuf);

	void SetBytesLength(int len){m_bytesLength=len;}
	int GetBytesLength(){return m_bytesLength;}

	void MakeHeartBeatMessage(int playerIndex);
private:
	int m_playerIndex;
	char m_reserveBytes[64];	//后面
	int m_bytesLength;	//后面


};
