#pragma once
#include "basemessage.h"

class CMessageClientQuitRes :
	public CBaseMessage
{
public:
	CMessageClientQuitRes(void);
	virtual ~CMessageClientQuitRes(void);


	virtual bool Encode(CStreamReadWrite *pStreamBuf);
	virtual int Decode(CStreamReadWrite *pStreamBuf);


	void MakeClientQuitMessage(int code);

	int GetCode(){return m_resCode;}
private:
	int m_resCode;
};
