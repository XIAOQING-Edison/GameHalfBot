#pragma once
#include "basemessage.h"

class CMessageClientQuitReq :
	public CBaseMessage
{
public:
	CMessageClientQuitReq(void);
	virtual ~CMessageClientQuitReq(void);


	virtual bool Encode(CStreamReadWrite *pStreamBuf);
	virtual int Decode(CStreamReadWrite *pStreamBuf);

	void MakeClientQuitMessage(int playerIndex);
	int GetPlayerIndex(){return m_playerIndex;}
private:
	int m_playerIndex;
};
