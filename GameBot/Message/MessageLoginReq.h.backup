#pragma once
#include "basemessage.h"

class CMessageLoginReq :
	public CBaseMessage
{
public:
	CMessageLoginReq(void);
	virtual ~CMessageLoginReq(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf);
	virtual int Decode(CStreamReadWrite *pStreamBuf);

	void MakeLoginMessage(int playerIndex);
	int GetPlayerIndex(){return  m_playerIndex;}

private:
	int m_playerIndex;
};
