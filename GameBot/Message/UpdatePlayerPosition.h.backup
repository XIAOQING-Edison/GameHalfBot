#pragma once
#include "basemessage.h"

class CUpdatePlayerPosition :
	public CBaseMessage
{
public:
	CUpdatePlayerPosition(void);
	virtual ~CUpdatePlayerPosition(void);
	virtual bool Encode(CByteUtil *pStreamBuf);
	virtual int Decode(CByteUtil *pStreamBuf);

	void Reset();

private:
	int x;	//当前坐标x
	int y;	//汉前坐标y
};
