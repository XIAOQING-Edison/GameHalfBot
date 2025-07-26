#pragma once
#include "../protocol.h"

class CInfoResLoginUser :
	public CProtocol
{
public:
	CInfoResLoginUser(void);
	virtual ~CInfoResLoginUser(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);

private:
	INT64 openServerTime;// = 1; //开服时间
	INT64 combineServerTime;// = 2; //合服时间
	INT64 serverCurTime;// = 3; //服务器当前时间
	bool needInviteCode;// = 4; //需要输入邀请码

};
