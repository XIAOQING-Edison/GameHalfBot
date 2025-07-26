#pragma once
#include "basemessage.h"
#include "InfoPlayerInfoStatus.h"
class CMessageClientPlayerInfoStatus :
	public CBaseMessage
{
public:
	CMessageClientPlayerInfoStatus(void);
	virtual ~CMessageClientPlayerInfoStatus(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf);
	virtual int Decode(CStreamReadWrite *pStreamBuf);

	CInfoPlayerInfoStatus *GetPlayerInfoStatus(){return &m_playerInfoStatus;}

	void MakeClientPlayerInfoStatusMessage(int index,CInfoPlayerInfoStatus *pInfo);
	int GetPlayerIndex(){return m_index;}
private:
	CInfoPlayerInfoStatus m_playerInfoStatus;
	int m_index;

};
