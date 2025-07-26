#pragma once
#include "../protocol.h"

class CInfoReqLogin :
	public CProtocol
{
public:
	CInfoReqLogin(void);
	virtual ~CInfoReqLogin(void);


	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);

private:
	STRING loginName;//= 1; //登录账户
	int version;//= 2; //版本号
	INT64 time;//= 3; //登录验证返回的时间戳
	STRING sign;//= 4; //登录验证返回的 sign
	int reconnect;//= 5; //是否重连 1:是 0: 否
	int serverId;//= 6; //服务器Id
	STRING token;//= 7;//验证码


};
