#pragma once
#include "../protocol.h"

class CProtocolBagInfoRes :
	public CProtocol
{
public:
	CProtocolBagInfoRes(void);
	virtual ~CProtocolBagInfoRes(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);
private:

};
