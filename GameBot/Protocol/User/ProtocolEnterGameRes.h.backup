#pragma once
#include "../protocol.h"

class CProtocolEnterGameRes :
	public CProtocol
{
public:
	CProtocolEnterGameRes(void);
	virtual ~CProtocolEnterGameRes(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);

private:
	STRING m_strRoleId;	//1,string
	UINT64 m_roleId;	//2,int64
	UINT64 m_serverTime;	//3.serverTime;

};
