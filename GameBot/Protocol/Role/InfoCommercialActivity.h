#pragma once
#include "../protocol.h"
#include "../Commerce/ProtocolGetCommercialActivityInfoRes.h"
// 商业化活动
class CInfoCommercialActivity :
	public CProtocol
{
public:
	CInfoCommercialActivity(void);
	virtual ~CInfoCommercialActivity(void);


	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);
private:
	void Reset();
private:
	CProtocolGetCommercialActivityInfoRes divineCostumeInfo;// = 1;
};
