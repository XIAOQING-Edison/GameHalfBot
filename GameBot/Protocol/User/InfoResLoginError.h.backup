#pragma once
#include "../protocol.h"

class CInfoResLoginError :
	public CProtocol
{
public:
	CInfoResLoginError(void);
	virtual ~CInfoResLoginError(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);

private:
	int code;// = 1;
	int ext_ClientVersion;// = 2; //拓展参数 客户端版本

};
