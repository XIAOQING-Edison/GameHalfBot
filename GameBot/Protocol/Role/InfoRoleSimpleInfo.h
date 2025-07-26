#pragma once
#include "../protocol.h"
class CInfoRoleSimpleInfo :
	public CProtocol
{
public:
	CInfoRoleSimpleInfo(void);
	virtual ~CInfoRoleSimpleInfo(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);

	INT64 GetRoleId(){return roleId;}
	STRING GetName(){return name;};
	int GetLevel(){return level;}
	INT64 GetUnionId(){return unionId;}
	STRING GetUnionName(){return unionName;}	//战盟名字
	int GetTotalFight(){return fight;}	//战力
	int GetServerId(){return serverId;}
	int GetMapId(){return mapId;}
	int GetCareer(){return career;}

	void Reset();
private:
	INT64 roleId;// = 1; //角色ID
	STRING name;// = 2; //名称
	int level;// = 3; //等级
	int career;// = 4; //职业
	int sex;// = 5; //性别
	bool online;// = 6; //在线
	INT64 unionId;// = 7; //战盟Id
	STRING unionName;// = 8; //战盟名字
	int unionPosition;// = 10; //战盟职位
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) ||(_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_)\
	||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
	int fight;// = 11; //角色战力
#elif _GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_
	INT64 fight;// = 11; //角色战力
#endif
	STRING appear;// = 12; //当前时装
	int equipScore;// = 13; //装备评分
	int unionLevel;// = 14; //战盟等级
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) ||(_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_)
#elif (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||(_GAME_VERSION_	== _TIAN_SHI_ZHI_ZHAN_MOBILE_)\
	||(_GAME_VERSION_	== _TIAN_SHI_ZHI_ZHAN_PC_)
	int badgeLevel;// = 15; //战盟臂章等级
#endif
	int notoriety;// = 16;//恶名值
	int redLevel;// = 17;//红名等级 1无赖 2恶人 3魔头
	int createTime;// = 18;//創建時間
	bool hasShield;// = 19;//是否开启护盾系统
	int serverId;// = 20;//区服id
	int unionCamp;// = 21;
	int mapId;// = 22;//当前地图id
	int hostId;// = 23;
#if _GAME_VERSION_	== _TIAN_SHI_ZHI_ZHAN_MOBILE_
#elif _GAME_VERSION_	== _TIAN_SHI_ZHI_ZHAN_PC_
	int charm;// = 24;//魅力值
	int unionBadgeIntensify;// = 25;//战盟臂章强化等级
	int stageId;//= 26; // 3v3段位
	int killCount;//= 27; // 悬赏功能-击杀人数
	bool showRankAppear;//= 28; // 是否展示排行榜外观
	int dawankaLevel;//= 29;//大玩咖等级
	int skillInstanceFloor;//= 30;//技能副本最高层
#endif


};
