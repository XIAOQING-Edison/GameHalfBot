#pragma once
#include "../protocol.h"
#include "InfoResGetRoleList.h"
class CProtocolGetRoleListRes :
	public CProtocol
{
public:
	CProtocolGetRoleListRes(void);
	virtual ~CProtocolGetRoleListRes(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);

private:
	CInfoResGetRoleList infoResGetRoleList;	//交由这个decode
};
