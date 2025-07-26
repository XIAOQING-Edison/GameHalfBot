#pragma once
#include "basemessage.h"

class CMessageHeartBeatRes :
	public CBaseMessage
{
public:
	CMessageHeartBeatRes(void);
	virtual ~CMessageHeartBeatRes(void);
	

	virtual bool Encode(CStreamReadWrite *pStreamBuf);
	virtual int Decode(CStreamReadWrite *pStreamBuf);

	void MakeHeartBeatResMessage(int code);

	int GetCode(){return m_code;}
private:
	int m_code;
};
