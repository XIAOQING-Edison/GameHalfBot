#pragma once
#include "../protocol.h"
#include "InfoRoleSimpleInfo.h"

class CInfoRoleToOtherInfo :
	public CProtocol
{
public:
	CInfoRoleToOtherInfo(void);
	virtual ~CInfoRoleToOtherInfo(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);
	void Reset();
	UINT64 GetRoleId(){return info.GetRoleId();}

private:

	CInfoRoleSimpleInfo info;//= 1 ;
	int mapId;//= 2; //所在地图
	int line;//= 3; //所在分线
	int hostId;//= 5;
	bool isDel;//= 7;
	INT64 delTime;//= 8;



};
