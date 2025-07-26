#pragma once


#include "../Global/public.h"
#include "../FunctionHelper/SocketHelper.h"

// #include "../Util/CopyHelper.h"
// #include "../Util/ComposeHelper.h"
// 

//指示当前的任务id
enum E_TASK_ID{
	e_task_id_none=-1,		//无任务的话会在刷怪点刷材料
	e_task_id_demon_plaza=0,	//恶魔广场
	e_task_id_blood_town		//血色城堡
};


//程序中的任务是一系列操作的组合,每个函数是一个功能，每个功能需要时间完成，就是需要等待

class CPlayer;

class CGameOperation
{
public:
	CGameOperation(void);
	~CGameOperation(void);

	void SetPlayer(CPlayer *p){m_pThisPlayer=p;}
	CPlayer *GetPlayer(){return m_pThisPlayer;}


	void Init();	//初始化事件变量
	
	void ResetResCode();
	void SetResCode(int state){m_gameResCode=state;}
	int GetResCode(){return m_gameResCode;}


	void ResetConnectToGameServer(){SetConnectToGameServer(false);}
	void SetConnectToGameServer(bool b){m_bConnectToGameServer=b;}
	bool IsConnectToGameServer(){return m_bConnectToGameServer;}


// 	void ResetHasGetOfflineExp(){SetHasGetOfflineExp(false);}
// 	void SetHasGetOfflineExp(bool b){m_bGetOfflineExp=b;}
// 	bool HasGetOfflineExp(){return m_bGetOfflineExp;}

// 	void ResetHasGetAward(){SetHasGetAward(false);}
// 	void SetHasGetAward(bool b){m_bGetAward=b;}
// 	bool HasGetAward(){return m_bGetAward;}
// 
// 	void ResetLoadItemsSucc(){SetLoadItemsSucc(false);}
// 	void SetLoadItemsSucc(bool b){m_bItemsLoadSucc=b;}
// 	bool IsLoadItemsSucc(){return m_bItemsLoadSucc;}
// 
// 	void ResetLoadMailSucc(){SetLoadMailSucc(false);}
// 	void SetLoadMailSucc(bool b){m_bMailLoadSucc=b;}
// 	bool IsLoadMailSucc(){return m_bMailLoadSucc;}
// 
// 	void ResetLoadSkillsSucc(){SetLoadSkillsSucc(false);}
// 	void SetLoadSkillsSucc(bool b){m_bSkillsLoadSucc=b;}
// 	bool IsLoadSkillsSucc(){return m_bSkillsLoadSucc;}
// 
// 	void ResetLoadMissionsSucc(){SetLoadMissionsSucc(false);}
// 	void SetLoadMissionsSucc(bool b){m_bMissionsLoadSucc=b;}
// 	bool IsLoadMissionsSucc(){return m_bMissionsLoadSucc;}
// 
// 	void ResetLoadMallSucc(){SetLoadMallSucc(false);}
// 	void SetLoadMallSucc(bool b){m_bMallLoadSucc=b;}
// 	bool IsLoadMallSucc(){return m_bMallLoadSucc;}
// 
// 	void ResetLoadAchievementSucc(){SetLoadAchievementSucc(false);}
// 	void SetLoadAchievementSucc(bool b){m_bAchievementLoadSucc=b;}
// 	bool IsLoadAchievementSucc(){return m_bAchievementLoadSucc;}
// 

	void ResetRecvUpdateRolePosition(){SetRecvUpdateRolePosition(false);}
	void SetRecvUpdateRolePosition(bool b){m_bRecvUpdateRolePosition=b;}
	bool IsRecvUpdateRolePosition(){return m_bRecvUpdateRolePosition;}

	void ResetNeedMakeFakeChangePosMsg(){SetNeedMakeFakeChangePosMsg(false);}
	void SetNeedMakeFakeChangePosMsg(bool b){m_bNeedMakeFakeChangePosMsg=b;}
	bool IsNeedMakeFakeChangePosMsg(){return m_bNeedMakeFakeChangePosMsg;} //更新目标怪物的属性信息是否成功

	void ResetUpdateTargetMonsterStatusSucc(){SetUpdateTargetMonsterStatusSucc(false);}
	void SetUpdateTargetMonsterStatusSucc(bool b){m_bUpdateTargetMonsterStatusSucc=b;}
	bool IsUpdateTargetMonsterStatusSucc(){return m_bUpdateTargetMonsterStatusSucc;} //更新目标怪物的属性信息是否成功

	void ResetMoveSucc(){SetMoveSucc(true);}
	void SetMoveSucc(bool b){m_bMoveSucc=b;}
	bool IsMoveSucc(){return m_bMoveSucc;} //更新目标怪物的属性信息是否成功


	void SetMaxWaitTime(int maxTime){m_maxWaitTime=maxTime;}
	int GetMaxWaitTime(){return m_maxWaitTime;}


	DWORD WaitForOperationComplete(){return WaitForSingleObject(m_hEvtOperationFinished,GetMaxWaitTime());}
	BOOL InterruptCurrentOperation(){return SetEvent(m_hEvtOperationFinished);}	//从当前等待状态中唤醒,跳出当前操作

	bool InterruptOperationByEmergencyLevel(E_EMERGENCY_LEVEL lv);


	void SetEmergencyLevel(E_EMERGENCY_LEVEL lv){m_emergencyLevel=lv;}
	E_EMERGENCY_LEVEL GetEmergencyLevel(){return m_emergencyLevel;}
	void ResetEmergencyLevel(){SetEmergencyLevel(e_emergency_level_none);}	//默认无紧急状态

	void SetCurTaskId(int id){m_curTaskId=id;}
	

public:	//其它接口
	bool IsInSafeArea(int x,int y){return false;}


	//基本游戏里的操作
public://operation,这里把一个完整的功能当做一个操作(operation),例如走到目的地并打怪，走到目的地采集等


	E_OPERATION_RESULT SetPkMode(int mode,CSocketHelper *pSocketHelper);	//pk模式转换

	//单个角色移动或使用技能




private://其它辅助对象
	
	CPlayer *m_pThisPlayer;

	bool RecvPacketAndUpdateInfo(int times,CSocketHelper *pSocketHelper);	//接收并处理数据，times是次数，以及延时一下时间
private:
	HANDLE m_hEvtOperationFinished;	//正常情况下是会等待这个事件完成,紧急情况下会唤醒并跳出某些函数执行另一个更紧急的
	E_EMERGENCY_LEVEL m_emergencyLevel;	//中断当前执行的函数去执行下一个操作
	
	int m_gameResCode;	//这里从接收的res里得到的state赋给变量
	int m_maxWaitTime;	//最大等待时间
	int m_curTaskId;	//当前的任务ID
	int m_nextTaskId;	//下一个任务ID(这里先把可接受的处理完，当前任务收到misson_change完成时会收到下一个可接受的任务ID)

	INT64 m_atkSpriteId;	//设定当前的怪物ID,这游戏是64位的ID，所以用int64,一般是打BOSS或者PK某个玩家
	int m_atkConfigId;	//设定这个主要是容易找BOSS或特定类型的怪

	int m_curInstanceZoneState;//当前副本状态,1,2--准备，3--运行，4--停止,5--结束

	bool m_bFinished;	//任务是否在等待时间前完成,可在接收checkcount==需要的checkcount,时设为finish
	bool m_bCurTaskFinished;	//是否当前任务完成

	bool m_bRecvUpdateRolePosition;	//是否到达指定地点
	bool m_bNeedMakeFakeChangePosMsg;	//是否需要伪造位置改变
	bool m_bUpdateTargetMonsterStatusSucc;	//更新目标怪物的属性信息是否成功

	bool m_bConnectToGameServer;	//是否已连接到游戏服务器
// 	bool m_bSign;	//是否已签到
// 	bool m_bGetOfflineExp;	//是否已取得离线经验
// 	bool m_bGetAward;	//是否已取得其它奖赏

	//下面的信息需要在登陆后接收完成再进行其它操作
// 	bool m_bItemsLoadSucc;	//是否装备信息，包括背包或仓库都已成功处理
// 	bool m_bSkillsLoadSucc;	//是否技能加载完毕
// 	bool m_bMallLoadSucc;	//商城是否加载完毕
// 	bool m_bMissionsLoadSucc;	//任务是否加载完毕
// 	bool m_bAchievementLoadSucc;	//成就是否加载完毕
// 	bool m_bMailLoadSucc;	//是否收到邮件信息//函数后面加，这里先加需要处理的属性

	bool m_bChangeMapSucc;	//是否收到changeMapRes
	bool m_bLoginMapSucc;	//是否收到loginMapres
	bool m_bMoveSucc;	//是否移动成功

};