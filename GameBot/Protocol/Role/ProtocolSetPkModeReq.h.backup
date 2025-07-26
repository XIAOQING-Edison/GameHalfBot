#pragma once
#include "../protocol.h"

class CProtocolSetPkModeReq :
	public CProtocol
{
public:
	CProtocolSetPkModeReq(void);
	virtual ~CProtocolSetPkModeReq(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf);
	virtual int Decode(CStreamReadWrite *pStreamBuf){return 0;}

	void MakePkModeMessage(int m);
private:
	int m_pkMode;
};
