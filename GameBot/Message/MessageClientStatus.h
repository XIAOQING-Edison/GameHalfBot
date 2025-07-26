#pragma once
#include "basemessage.h"

class CMessageClientStatus :
	public CBaseMessage
{
public:
	CMessageClientStatus(void);
	virtual ~CMessageClientStatus(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf);
	virtual int Decode(CStreamReadWrite *pStreamBuf);

private:
	int m_isOnline;
	//info ...
};
