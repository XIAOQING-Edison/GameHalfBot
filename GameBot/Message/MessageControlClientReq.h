#pragma once
#include "basemessage.h"

class CMessageControlClientReq :
	public CBaseMessage
{
public:
	CMessageControlClientReq(void);
	virtual ~CMessageControlClientReq(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf);
	virtual int Decode(CStreamReadWrite *pStreamBuf);

	void MakeControlMessage(int gameOp);	//

	int GetGameControlOp(){return m_gameOp;}
private:
	int m_gameOp;
};
