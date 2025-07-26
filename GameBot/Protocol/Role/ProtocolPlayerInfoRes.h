#pragma once
#include "../protocol.h"
#include "InfoPlayerInfo.h"	//先试这个
class CProtocolPlayerInfoRes :
	public CProtocol
{
public:
	CProtocolPlayerInfoRes(void);
	virtual ~CProtocolPlayerInfoRes(void);


	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);

private:
	CInfoPlayerInfo playerInfo;
};
