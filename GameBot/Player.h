#pragma once
#include "Global/public.h"
#include "Global/Macro.h"	// 宏定义
#include "Global/Enums.h"
#include "Msg.h"



// #define _CAI_SHANG_VERSION_	// 彩商版本，用于彩商定制

class CSocketHelper;
class CGameLogicHelper;
class CClient;
class CPlayer
{
public:
	CPlayer(void);
	virtual ~CPlayer(void);
	void Init();

	void CloseObjectWhenQuit();


	bool IsLoginAlready();
	bool IsInGameAlready();
	bool IsRoleChosenAlready();
	bool IsDead(){return GetCurHp()<=0;}	// 是否死亡，判断当前血量
	bool IsRoleListEmpty(){return false;}
	UINT64 GetFirstRoleId(){return 0;}
public:	// 定义/获取游戏相关的接口
	CClient* GetClient(){return m_pClient;}
	void SetClient(CClient *pClient){m_pClient=pClient;}

	void InitSkillFromConfig();	// 初始化技能配置

public:	// 游戏接口，用于skill,task,map等接口
	// 日志
	void SendToWriteLog(const TCHAR *szMsg);	// 发送到日志窗口写日志


	// 角色接口:

	// 地图相关
	void SetMapName(STRING &name){m_mapName=name;}
	STRING GetMapName(){return m_mapName;}

	void SetMapId(int id){m_mapId=id;}
	int GetMapId(){return m_mapId;}

	void AddMapToLoadedMapList(int mapId);	// 添加已加载的地图到地图列表
	bool IsMapAlreadyLoaded(int mapId);
	void ClearMapLoadLists(){m_loadMapList.clear();}

	// 目标地图
	void SetDstMapId(int id){m_dstMapId=id;}
	int GetDstMapId(){return m_dstMapId;}
	void LoadMapDataById(int mapId);



	// 游戏逻辑
	void SetRecvUpdateRolePosition(bool b);
	bool IsRecvUpdateRolePosition();
	void SetNeedMakeFakeChangePosMsg(bool b);
	bool IsNeedMakeFakeChangePosMsg();
	bool InterruptTaskByEmergencyLevel();	// 紧急情况下中断任务
	void ResetTaskEmergencyLevel();
	void SetResCode(int code);
	int GetResCode();
	void ResetResCode();

	void SetInstanceZoneState(int st);// 副本状态
	void DoGameOperaion(int protocolId,int paramLength,char *cmdData);	// 执行游戏操作，根据protocolId执行某些协议
	void CheckIsBossSelectedChangeToGrave(void *graveInfo);	// 检查是否选择BOSS切换到墓地
	void SetMoveSucc(bool b);
	void UpdateBlockInfo(int x,int y);	// 更新阻挡状态

public:
	void SetRoleId(UINT64 roleId){m_roleId=roleId;}	// 设置角色唯一ID
	UINT64 GetRoleId(){return m_roleId;}

	void SetAttackerId(UINT64 roleId){m_attackerId=roleId;}
	UINT64 GetAttackerId(){return m_attackerId;}
	void ResetAttackerId(){SetAttackerId(0);}

	void SetQuit(bool b){m_bQuit=b;}
	bool IsQuit(){return m_bQuit;}

	void SetStop(bool b){m_bStop=b;}
	bool IsStop(){return m_bStop;}

	int GetPlayerIndex(){return m_index;}
	void SetPlayerIndex(int i){m_index=i;}

	void SetAccountName(const STRING &account){m_accountName=account;}
	STRING GetAccountName();	// 根据index获取account，如果index无效则返回account

	void SetRoleName(const STRING &name){m_roleName=name;}
	STRING GetRoleName(){return m_roleName;}

	// 角色重要坐标相关接口
	int GetX(){return m_x;}
	int GetY(){return m_y;}

	void SetX(int x){m_x=x;}
	void SetY(int y){m_y=y;}

	void SetCurHp(INT64 hp){m_currentHp=hp;}
	INT64 GetCurHp(){return m_currentHp;}
	void SetMaxHp(INT64 hp){m_maxHp;}
	
	void SetCurMp(int mp){m_currentMp=mp;}
	int GetCurMp(){return m_currentMp;}
	void SetMaxMp(int mp){m_maxMp=mp;}

	void SetCurShield(INT64 shield){m_curShield=shield;}
	INT64 GetCurShield(){return m_curShield;}
	void SetMaxShield(INT64 shield){m_maxShield=shield;}

	void SetCurComboValue(INT64 combo){m_curComboValue=combo;}
	INT64 GetCurComboValue(){return m_curComboValue;}
	void SetMaxComboValue(INT64 combo){m_maxComboValue=combo;}


	void SetAsuramName(STRING &name){m_asuramName=name;}
	STRING GetAsuramName(){return m_asuramName;}

	void SetAsuramId(UINT64 asuramId){m_asuramId=asuramId;}
	UINT64 GetAsuramId(){return m_asuramId;}

	void SetTeamId(UINT64 teamId){m_teamId=teamId;}
	UINT64 GetTeamId(){return m_teamId;}

	void SetTotalBattleScore(INT64 score){m_totalBattleScore=score;}
	INT64 GetTotalBattleScore(){return m_totalBattleScore;}

	void SetCareer(int career){m_career=career;}
	int GetCareer(){return m_career;}

	void SetMapLine(int line){m_mapLine=line;}
	int GetMapLine(){return m_mapLine;}

	void SetLevel(int lv){m_level=lv;}
	int GetLevel(){return m_level;}

	void SetVipLevel(int lv){m_vipLevel=lv;}
	int GetVipLevel(){return m_vipLevel;}
	bool IsVipLevelEnough(){return m_vipLevel>=300;}

	void SetAttributes(map<int,INT64> &attributes){m_attributes=attributes;}
	map<int,INT64>& GetAttributes(){return m_attributes;}
	INT64 GetAttribute(int attrEnum){return m_attributes[attrEnum];}

	void SetDisconnectReason(E_DISCONNECT_ERROR_REASON reason){m_disconnErrorReson=reason;}
	E_DISCONNECT_ERROR_REASON GetDisconnectReason(){return m_disconnErrorReson;}
	
	bool IsRoleMoveToTarget(int x,int y);//{return (m_x==x && m_y==y);}	// 是否到达目标坐标，这里需要完成范围判断-delta+x<x<x+delta,-delta+y<y<y+delta这种形式

	void SetAttackObjectId(INT64 objId){m_atkObjectId=objId;}
	INT64 GetAttackObjectId(){return m_atkObjectId;}
	void ResetAttackObjectId(){SetAttackObjectId(0);}
	bool IsAttackObjectEmpty(){return GetAttackObjectId()==0;}	// 要攻击的目标id为空，则攻击对象为空，返回true

	void SetAttackConfigId(int configId){m_atkConfigId=configId;}
	int GetAttackConfigId(){return m_atkConfigId;}
	void ResetAttackConfigId(){SetAttackConfigId(0);}
	bool IsAttackConfigIdEmpty(){return GetAttackConfigId()==0;}	// 要攻击的目标id为空，则攻击对象为空，返回true

	void SetPkMode(int m){m_pkMode=m;}
	int GetPkMode(){return m_pkMode;}
	void ResetPkMode(){SetPkMode(0);}

	void SetValidAttributePoint(int pt){m_validAttributePoint=pt;}
	int GetValidAttributePoint(){return m_validAttributePoint;}

	void SetTalentData(map<int,int> &talent){m_talentData=talent;}
	map<int,int>& GetTalentData(){return m_talentData;}

	void ResetStates();	// 重置所有状态

	INT64 GetDefenceAttr(){return 0;}

	void SetIsTeamLeader(bool b){m_bTeamLeader=b;}
	bool IsTeamLeader(){return m_bTeamLeader;}

	void ResetWhenDisconnected();	// 断开时重置某些状态
private:	// 私有接口，主要用于继承，用于游戏时的buff状态和skill状态，以及npc状态
	void ClearSomeLists();	//
	void ClearSkillList();
	void ClearNpcList();
	void ClearBuffList();

public:	// 定义游戏状态
	void SetLoginAlready(bool b);
	void SetInGameAlready(bool b);
	void SetChooseRoleAlreay(bool b);
	
	CSocketHelper *GetSocketHelper(){return m_pSocketHelper;}
	CGameLogicHelper *GetGameLogicHelper(){return m_pGameLogicHelper;}
public:
	bool ReadyForPlaying();	// 准备开始游戏
	bool CreatePlayThread();	// 创建游戏线程
	static DWORD WINAPI ThreadProcessTask(LPVOID p);
private:	// 游戏相关的成员变量
	int m_index;	// 玩家索引，用于界面显示
	CSocketHelper *m_pSocketHelper;	// 网络通信助手
	CGameLogicHelper *m_pGameLogicHelper;	// 游戏逻辑助手
	STRING m_accountName;		// 为彩商版本将账号系统

	STRING m_asuramName;	// 阿修罗名称

	STRING m_mapName;	// 直接显示的地图名
	STRING m_roleName;	// 角色名称
	E_PLAYER_STATE m_state;
private:

	// 游戏相关的角色相关的游戏相关的数据，这里定义几个重要的角色相关的数据
	UINT64 m_asuramId;	// 阿修罗id
	UINT64 m_roleId;	// 角色唯一id
	INT64 m_totalBattleScore;	// 总战力
	INT64 m_offlineTime;	// 离线时间

	INT64 m_atkObjectId;	// 攻击某个目标的对象id
	UINT64 m_teamId;	// 队伍唯一id，没有队伍为0

	int m_atkConfigId;	// 要攻击的某个配置

	INT64 m_currentHp;	// 当前血量
	INT64 m_maxHp;	// 最大血量
	int m_currentMp;// 当前魔值
	int m_maxMp;	// 最大魔值

	int m_curShield;	// PVP护盾
	int m_maxShield;	// 最大护盾
	int m_curComboValue;	// 当前连击值
	int m_maxComboValue;	// 最大连击值

	INT64 m_attackerId;	// 攻击我的玩家ID

	int m_x;
	int m_y;

	int m_level;
	int m_vipLevel;	// 会员等级，mu2使用

	int m_career;	// 职业，主要用于转职
	int m_mapLine;	// 当前地图线路

	int m_mapId;	// 角色当前地图ID
	int m_dstMapId;	// 目标某个地图id，用于寻路

	int m_pkMode;	// pk模式
	int m_validAttributePoint;	// 剩余属性点

	E_DISCONNECT_ERROR_REASON m_disconnErrorReson;

	map<int,INT64> m_attributes;	// 属性


	CClient *m_pClient;	// 客户端信息，用于网络通信
	HANDLE m_hThreadPlay;	// 线程句柄

	vector<STRING> m_loadMapList;
	
	vector<int> m_stoneLight;	// 每个副本的石头

	map<int,int> m_talentData;	// 天赋数据

	bool m_bTeamLeader;	// 是否是队长，用于boss，队员等

	bool m_bQuit;
	bool m_bStop;	// 是否停止
private:
};
