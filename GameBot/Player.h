#pragma once
#include "Global/public.h"
#include "Global/Macro.h"	//锟疥定锟斤拷
#include "Global/Enums.h"
#include "Msg.h"



// #define _CAI_SHANG_VERSION_	//锟斤拷锟教帮拷,锟斤拷锟斤拷锟斤拷锟借定

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
	bool IsDead(){return GetCurHp()<=0;}	//锟角凤拷锟斤拷锟斤拷锟斤拷牵锟斤拷卸锟絟p锟斤拷锟斤拷
	bool IsRoleListEmpty(){return false;}
	UINT64 GetFirstRoleId(){return 0;}
public:	//锟借定/锟斤拷锟截革拷锟街讹拷锟斤拷慕涌锟
	CClient* GetClient(){return m_pClient;}
	void SetClient(CClient *pClient){m_pClient=pClient;}

	void InitSkillFromConfig();	//锟斤拷始锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷

public:	//锟斤拷转锟接口ｏ拷锟斤拷锟斤拷skill,task,map锟饺的接匡拷
	//锟斤拷志
	void SendToWriteLog(const TCHAR *szMsg);	//锟斤拷锟酵碉拷锟斤拷锟斤拷锟斤拷写锟斤拷志


	//锟斤拷色锟接匡拷:

	//map锟斤拷锟
	void SetMapName(STRING &name){m_mapName=name;}
	STRING GetMapName(){return m_mapName;}

	void SetMapId(int id){m_mapId=id;}
	int GetMapId(){return m_mapId;}

	void AddMapToLoadedMapList(int mapId);	//锟斤拷锟窖硷拷锟截的碉拷图锟脚斤拷去锟叫憋拷
	bool IsMapAlreadyLoaded(int mapId);
	void ClearMapLoadLists(){m_loadMapList.clear();}

	//锟斤拷图锟斤拷锟
	void SetDstMapId(int id){m_dstMapId=id;}
	int GetDstMapId(){return m_dstMapId;}
	void LoadMapDataById(int mapId);



	//gameLogic
	void SetRecvUpdateRolePosition(bool b);
	bool IsRecvUpdateRolePosition();
	void SetNeedMakeFakeChangePosMsg(bool b);
	bool IsNeedMakeFakeChangePosMsg();
	bool InterruptTaskByEmergencyLevel();	//锟叫讹拷锟斤拷时锟斤拷锟侥讹拷锟斤拷
	void ResetTaskEmergencyLevel();
	void SetResCode(int code);
	int GetResCode();
	void ResetResCode();

	void SetInstanceZoneState(int st);//锟斤拷锟斤拷状态
	void DoGameOperaion(int protocolId,int paramLength,char *cmdData);	//锟斤拷锟斤拷锟斤拷锟絧rotocolId锟斤拷锟斤拷锟斤拷某些协锟斤拷
	void CheckIsBossSelectedChangeToGrave(void *graveInfo);	//锟斤拷锟揭锟斤拷锟紹OSS锟角凤拷锟窖撅拷锟斤拷锟斤拷
	void SetMoveSucc(bool b);
	void UpdateBlockInfo(int x,int y);	//锟斤拷锟斤拷锟斤拷锟斤拷状态

public:
	void SetRoleId(UINT64 roleId){m_roleId=roleId;}	//锟斤拷同锟斤拷锟斤拷锟斤拷锟揭伙拷锟斤拷锟斤拷锟斤拷锟斤拷锟絠d
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
	STRING GetAccountName();	//锟斤拷锟斤拷锟叫讹拷index锟斤拷效锟斤拷锟斤拷锟斤拷锟绞伙拷锟斤拷锟狡ｏ拷锟斤拷锟絠ndex锟街达拷锟斤拷为account

	void SetRoleName(const STRING &name){m_roleName=name;}
	STRING GetRoleName(){return m_roleName;}

	//锟斤拷锟斤拷要锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟酵匡拷锟斤拷锟斤拷
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
	
	bool IsRoleMoveToTarget(int x,int y);//{return (m_x==x && m_y==y);}	//锟角否到达拷目锟侥碉拷,锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷要锟侥成凤拷围锟叫讹拷-delta+x<x<x+delta,-delta+y<y<y+delta锟斤拷锟斤拷锟斤拷式

	void SetAttackObjectId(INT64 objId){m_atkObjectId=objId;}
	INT64 GetAttackObjectId(){return m_atkObjectId;}
	void ResetAttackObjectId(){SetAttackObjectId(0);}
	bool IsAttackObjectEmpty(){return GetAttackObjectId()==0;}	//要锟斤拷锟斤拷锟侥讹拷锟斤拷id为锟秸ｏ拷锟斤拷锟斤拷锟角癸拷锟斤拷锟剿伙拷锟竭讹拷锟竭才伙拷为true

	void SetAttackConfigId(int configId){m_atkConfigId=configId;}
	int GetAttackConfigId(){return m_atkConfigId;}
	void ResetAttackConfigId(){SetAttackConfigId(0);}
	bool IsAttackConfigIdEmpty(){return GetAttackConfigId()==0;}	//要锟斤拷锟斤拷锟侥讹拷锟斤拷id为锟秸ｏ拷锟斤拷锟斤拷锟角癸拷锟斤拷锟剿伙拷锟竭讹拷锟竭才伙拷为true

	void SetPkMode(int m){m_pkMode=m;}
	int GetPkMode(){return m_pkMode;}
	void ResetPkMode(){SetPkMode(0);}

	void SetValidAttributePoint(int pt){m_validAttributePoint=pt;}
	int GetValidAttributePoint(){return m_validAttributePoint;}

	void SetTalentData(map<int,int> &talent){m_talentData=talent;}
	map<int,int>& GetTalentData(){return m_talentData;}

	void ResetStates();	//锟斤拷锟斤拷樱锟斤拷锟斤拷帽锟斤拷

	INT64 GetDefenceAttr(){return 0;}

	void SetIsTeamLeader(bool b){m_bTeamLeader=b;}
	bool IsTeamLeader(){return m_bTeamLeader;}

	void ResetWhenDisconnected();	//锟斤拷锟斤拷时熏锟斤拷某些锟斤拷锟
private:	//锟斤拷锟斤拷私锟叫接口ｏ拷锟斤拷要锟斤拷锟斤拷锟侥承╋拷锟斤拷锟侥讹拷锟襟，达拷锟斤拷锟斤拷锟竭伙拷锟截匡拷锟斤拷戏时锟斤拷锟斤拷锟絙uff锟叫憋拷锟斤拷skill锟叫憋拷,锟斤拷锟斤拷锟斤拷锟斤拷斜锟斤拷锟斤拷锟斤拷斜锟斤拷锟絥pc锟叫憋拷锟斤拷
	void ClearSomeLists();	//
	void ClearSkillList();
	void ClearNpcList();
	void ClearBuffList();

public:	//锟借定锟斤拷锟斤拷状态
	void SetLoginAlready(bool b);
	void SetInGameAlready(bool b);
	void SetChooseRoleAlreay(bool b);
	
	CSocketHelper *GetSocketHelper(){return m_pSocketHelper;}
	CGameLogicHelper *GetGameLogicHelper(){return m_pGameLogicHelper;}
public:
	bool ReadyForPlaying();	//准锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟竭筹拷
	bool CreatePlayThread();	//锟斤拷锟斤拷叱蹋锟斤拷锟斤拷锟斤拷锟斤拷锟
	static DWORD WINAPI ThreadProcessTask(LPVOID p);
private:	//锟斤拷锟街革拷锟斤拷锟斤拷锟斤拷
	int m_index;	//锟斤拷锟斤拷卤锟,锟斤拷锟斤拷锟节斤拷锟斤拷锟斤拷锟斤拷示锟酵诧拷锟斤拷
	CSocketHelper *m_pSocketHelper;	//锟斤拷锟斤拷锟斤拷锟斤拷
	CGameLogicHelper *m_pGameLogicHelper;	//锟竭硷拷锟斤拷
	STRING m_accountName;		//为锟剿凤拷锟姐将锟绞伙拷锟斤拷锟斤拷锟斤拷锟斤拷系锟斤拷锟斤拷

	STRING m_asuramName;	//锟斤拷锟斤拷使锟斤拷战锟斤拷锟斤拷锟斤拷

	STRING m_mapName;	//直锟斤拷锟斤拷示锟斤拷图锟斤拷
	STRING m_roleName;	//锟斤拷色锟斤拷锟斤拷
	E_PLAYER_STATE m_state;
private:

	//锟斤拷锟较碉拷锟斤拷锟斤拷锟角碉拷锟斤拷色锟斤拷锟矫碉拷锟斤拷锟斤拷锟斤拷锟角讹拷锟缴,锟斤拷锟斤拷锟解几锟斤拷锟斤拷锟斤拷锟捷诧拷锟斤拷
	UINT64 m_asuramId;	//战锟斤拷id
	UINT64 m_roleId;	//锟斤拷锟斤拷锟斤拷锟叫碉拷唯一id
	INT64 m_totalBattleScore;	//锟斤拷战锟斤拷
	INT64 m_offlineTime;	//锟斤拷锟斤拷时锟斤拷

	INT64 m_atkObjectId;	//锟斤拷锟斤拷锟斤拷某一锟斤拷目锟斤拷锟絠d
	UINT64 m_teamId;	//锟斤拷锟节讹拷锟斤拷锟絠d,没锟叫撅拷锟斤拷0

	int m_atkConfigId;	//要锟斤拷锟斤拷锟斤拷某一锟斤拷锟斤拷锟

	INT64 m_currentHp;	//锟斤拷时血锟斤拷
	INT64 m_maxHp;	//锟斤拷锟窖锟斤拷
	int m_currentMp;//锟斤拷时魔值
	int m_maxMp;	//锟斤拷锟侥е

	int m_curShield;	//PVP锟叫的伙拷锟斤拷
	int m_maxShield;	//锟斤拷蠡ざ锟
	int m_curComboValue;	//锟斤拷锟斤拷锟斤拷值
	int m_maxComboValue;	//锟斤拷锟斤拷刍锟斤拷锟斤拷锟斤拷锟斤拷锟街

	INT64 m_attackerId;	//锟斤拷某锟斤拷夜锟斤拷锟绞憋拷锟絀D

	int m_x;
	int m_y;

	int m_level;
	int m_vipLevel;	//锟斤拷员锟饺硷拷,mu2使锟斤拷

	int m_career;	//锟斤拷锟斤拷锟斤拷要锟矫碉拷锟斤拷锟侥ｏ拷锟斤拷为锟斤拷转职
	int m_mapLine;	//锟节碉拷图锟节硷拷锟斤拷

	int m_mapId;	//锟斤拷色锟斤拷锟节碉拷图ID
	int m_dstMapId;	//锟叫伙拷锟斤拷某锟斤拷图id,锟斤拷锟斤拷锟斤拷锟

	int m_pkMode;	//pk模式
	int m_validAttributePoint;	//锟斤拷锟斤拷剩锟斤拷锟

	E_DISCONNECT_ERROR_REASON m_disconnErrorReson;

	map<int,INT64> m_attributes;	//锟斤拷锟斤拷


	CClient *m_pClient;	//锟斤拷锟斤拷锟斤拷锟斤拷息锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟
	HANDLE m_hThreadPlay;	//锟竭程撅拷锟

	vector<STRING> m_loadMapList;
	
	vector<int> m_stoneLight;	//每锟斤拷锟芥本锟斤拷锟斤拷

	map<int,int> m_talentData;	//锟斤拷锟斤拷使锟斤拷

	bool m_bTeamLeader;	//锟角凤拷锟斤拷锟,锟斤拷痈锟斤拷锟斤拷锟斤拷,锟斤拷boss,锟斤拷员锟斤拷锟斤拷锟斤拷锟

	bool m_bQuit;
	bool m_bStop;	//锟角凤拷锟斤拷停
private:
};
