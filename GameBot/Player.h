#pragma once
#include "Global/public.h"
#include "Global/Macro.h"	//�궨��
#include "Global/Enums.h"
#include "Msg.h"



// #define _CAI_SHANG_VERSION_	//���̰�,�������趨

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
	bool IsDead(){return GetCurHp()<=0;}	//�Ƿ�������ǣ��ж�hp����
	bool IsRoleListEmpty(){return false;}
	UINT64 GetFirstRoleId(){return 0;}
public:	//�趨/���ظ��ֶ���Ľӿ�
	CClient* GetClient(){return m_pClient;}
	void SetClient(CClient *pClient){m_pClient=pClient;}

	void InitSkillFromConfig();	//��ʼ����������

public:	//��ת�ӿڣ�����skill,task,map�ȵĽӿ�
	//��־
	void SendToWriteLog(const TCHAR *szMsg);	//���͵�������д��־


	//��ɫ�ӿ�:

	//map���
	void SetMapName(STRING &name){m_mapName=name;}
	STRING GetMapName(){return m_mapName;}

	void SetMapId(int id){m_mapId=id;}
	int GetMapId(){return m_mapId;}

	void AddMapToLoadedMapList(int mapId);	//���Ѽ��صĵ�ͼ�Ž�ȥ�б�
	bool IsMapAlreadyLoaded(int mapId);
	void ClearMapLoadLists(){m_loadMapList.clear();}

	//��ͼ���
	void SetDstMapId(int id){m_dstMapId=id;}
	int GetDstMapId(){return m_dstMapId;}
	void LoadMapDataById(int mapId);



	//gameLogic
	void SetRecvUpdateRolePosition(bool b);
	bool IsRecvUpdateRolePosition();
	void SetNeedMakeFakeChangePosMsg(bool b);
	bool IsNeedMakeFakeChangePosMsg();
	bool InterruptTaskByEmergencyLevel();	//�ж���ʱ���Ķ���
	void ResetTaskEmergencyLevel();
	void SetResCode(int code);
	int GetResCode();
	void ResetResCode();

	void SetInstanceZoneState(int st);//����״̬
	void DoGameOperaion(int protocolId,int paramLength,char *cmdData);	//�������protocolId������ĳЩЭ��
	void CheckIsBossSelectedChangeToGrave(void *graveInfo);	//���Ҫ���BOSS�Ƿ��Ѿ�����
	void SetMoveSucc(bool b);
	void UpdateBlockInfo(int x,int y);	//��������״̬

public:
	void SetRoleId(UINT64 roleId){m_roleId=roleId;}	//��ͬ�������һ����������id
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
	STRING GetAccountName();	//�����ж�index��Ч�������ʻ����ƣ����index�ִ���Ϊaccount

	void SetRoleName(const STRING &name){m_roleName=name;}
	STRING GetRoleName(){return m_roleName;}

	//����Ҫ�����������Ϳ�����
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
	
	bool IsRoleMoveToTarget(int x,int y);//{return (m_x==x && m_y==y);}	//�Ƿ񵽴�Ŀ�ĵ�,����������Ҫ�ĳɷ�Χ�ж�-delta+x<x<x+delta,-delta+y<y<y+delta������ʽ

	void SetAttackObjectId(INT64 objId){m_atkObjectId=objId;}
	INT64 GetAttackObjectId(){return m_atkObjectId;}
	void ResetAttackObjectId(){SetAttackObjectId(0);}
	bool IsAttackObjectEmpty(){return GetAttackObjectId()==0;}	//Ҫ�����Ķ���idΪ�գ������ǹ����˻��߶��߲Ż�Ϊtrue

	void SetAttackConfigId(int configId){m_atkConfigId=configId;}
	int GetAttackConfigId(){return m_atkConfigId;}
	void ResetAttackConfigId(){SetAttackConfigId(0);}
	bool IsAttackConfigIdEmpty(){return GetAttackConfigId()==0;}	//Ҫ�����Ķ���idΪ�գ������ǹ����˻��߶��߲Ż�Ϊtrue

	void SetPkMode(int m){m_pkMode=m;}
	int GetPkMode(){return m_pkMode;}
	void ResetPkMode(){SetPkMode(0);}

	void SetValidAttributePoint(int pt){m_validAttributePoint=pt;}
	int GetValidAttributePoint(){return m_validAttributePoint;}

	void SetTalentData(map<int,int> &talent){m_talentData=talent;}
	map<int,int>& GetTalentData(){return m_talentData;}

	void ResetStates();	//����ӣ����ñ��

	INT64 GetDefenceAttr(){return 0;}

	void SetIsTeamLeader(bool b){m_bTeamLeader=b;}
	bool IsTeamLeader(){return m_bTeamLeader;}

	void ResetWhenDisconnected();	//����ʱѬ��ĳЩ���
private:	//����˽�нӿڣ���Ҫ�����ĳЩ����Ķ��󣬴������߻��ؿ���Ϸʱ�����buff�б���skill�б�,��������б������б���npc�б���
	void ClearSomeLists();	//
	void ClearSkillList();
	void ClearNpcList();
	void ClearBuffList();

public:	//�趨����״̬
	void SetLoginAlready(bool b);
	void SetInGameAlready(bool b);
	void SetChooseRoleAlreay(bool b);
	
	CSocketHelper *GetSocketHelper(){return m_pSocketHelper;}
	CGameLogicHelper *GetGameLogicHelper(){return m_pGameLogicHelper;}
public:
	bool ReadyForPlaying();	//׼�����������߳�
	bool CreatePlayThread();	//����̣߳���������
	static DWORD WINAPI ThreadProcessTask(LPVOID p);
private:	//���ָ�������
	int m_index;	//����±�,�����ڽ�������ʾ�Ͳ���
	CSocketHelper *m_pSocketHelper;	//��������
	CGameLogicHelper *m_pGameLogicHelper;	//�߼���
	STRING m_accountName;		//Ϊ�˷��㽫�ʻ���������ϵ����

	STRING m_asuramName;	//����ʹ��ս������

	STRING m_mapName;	//ֱ����ʾ��ͼ��
	STRING m_roleName;	//��ɫ����
	E_PLAYER_STATE m_state;
private:

	//���ϵ������ǵ���ɫ���õ��������Ƕ��ɫ,�����⼸�������ݲ���
	UINT64 m_asuramId;	//ս��id
	UINT64 m_roleId;	//�������е�Ψһid
	INT64 m_totalBattleScore;	//��ս��
	INT64 m_offlineTime;	//����ʱ��

	INT64 m_atkObjectId;	//������ĳһ��Ŀ���id
	UINT64 m_teamId;	//���ڶ����id,û�о���0

	int m_atkConfigId;	//Ҫ������ĳһ�����

	INT64 m_currentHp;	//��ʱѪ��
	INT64 m_maxHp;	//���Ѫ��
	int m_currentMp;//��ʱħֵ
	int m_maxMp;	//���ħֵ

	int m_curShield;	//PVP�еĻ���
	int m_maxShield;	//��󻤶�
	int m_curComboValue;	//������ֵ
	int m_maxComboValue;	//����ۻ���������ֵ

	INT64 m_attackerId;	//��ĳ��ҹ���ʱ��ID

	int m_x;
	int m_y;

	int m_level;
	int m_vipLevel;	//��Ա�ȼ�,mu2ʹ��

	int m_career;	//������Ҫ�õ����ģ���Ϊ��תְ
	int m_mapLine;	//�ڵ�ͼ�ڼ���

	int m_mapId;	//��ɫ���ڵ�ͼID
	int m_dstMapId;	//�л���ĳ��ͼid,�������

	int m_pkMode;	//pkģʽ
	int m_validAttributePoint;	//����ʣ���

	E_DISCONNECT_ERROR_REASON m_disconnErrorReson;

	map<int,INT64> m_attributes;	//����


	CClient *m_pClient;	//��������Ϣ�����������
	HANDLE m_hThreadPlay;	//�߳̾��

	vector<STRING> m_loadMapList;
	
	vector<int> m_stoneLight;	//ÿ���汾����

	map<int,int> m_talentData;	//����ʹ��

	bool m_bTeamLeader;	//�Ƿ����,��Ӹ������,��boss,��Ա�������

	bool m_bQuit;
	bool m_bStop;	//�Ƿ���ͣ
private:
};
