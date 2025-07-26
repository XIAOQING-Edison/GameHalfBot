#pragma once
#include "../protocol.h"
//天使之战PC使用，其它版本不使用
//这里只为了登陆完成判断，所以关键的字段没作解析

class CProtocolAllStorageInfoRes :
	public CProtocol
{
public:
	CProtocolAllStorageInfoRes(void);
	virtual ~CProtocolAllStorageInfoRes(void);
	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);
private:
};
