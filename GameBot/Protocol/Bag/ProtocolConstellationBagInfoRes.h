#pragma once
#include "../protocol.h"

//天使之战使用，其它版本不使用
//这里只为了登陆完成判断，所以关键的字段没作解析
class CProtocolConstellationBagInfoRes :
	public CProtocol
{
public:
	CProtocolConstellationBagInfoRes(void);
	virtual ~CProtocolConstellationBagInfoRes(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);
private:

};
