#pragma once
#include "../protocol.h"
#include "InfoRoleSimpleInfo.h"
class CInfoRoleBasic :
	public CProtocol
{
public:
	CInfoRoleBasic(void);
	virtual ~CInfoRoleBasic(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);

	INT64 GetRoleId(){return info.GetRoleId();}
	STRING GetName(){return info.GetName();};
	int GetLevel(){return info.GetLevel();;}
	STRING GetUnionName(){return info.GetUnionName();}	//战盟名字
	int GetTotalFight(){return info.GetTotalFight();}	//战力
	int GetServerId(){return info.GetServerId();}
	int GetMapId(){return info.GetMapId();}
	int GetCareer(){return info.GetCareer();}
	int GetPkMode(){return PKMode;}
	int GetAttributePoint(){return attributePoint;}

	void Reset();

private:
	CInfoRoleSimpleInfo info;// = 1 ;
	int createTime;// = 2; //创角时间 (s)
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_)	|| (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_)\
	||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
	INT64 exp;// = 3;
#elif _GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_
	STRING exp;
#endif
	int attributePoint;// = 4; //可使用點數
	int PKMode;// = 7;
	int dailyOnlineTime;// = 8;//每日在线时长 (s)
	int logoutTime;// = 10;//离线时间戳，秒

#if _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_
#elif _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_
#elif _GAME_VERSION_ == _YONG_HENG_LIAN_MENG_	
#elif _GAME_VERSION_ == _TIAN_SHI_SHEN_YU_
#elif _GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_
#endif
};
