#pragma once

#include "SocketHelper.h"	//用来发包用的
#include "../Struct/GameOperation.h"


//逻辑类用来根据任务类型去做操作，例如等待，切换等
class CPlayer;
class CGameConfig;
class CGameLogicHelper
{
	friend class CTestHelper;	//测试
	friend class CBossLogicHelper;	//BOSS
	friend class CTaskLogicHelper;	//任务
public:
	CGameLogicHelper(void);
	~CGameLogicHelper(void);

	bool IsFirstRunning(){return  m_bFirstRunning;}
	void SetIsFirstRunning(bool b){m_bFirstRunning=b;}
	void ResetIsFirstRunning(){SetIsFirstRunning(true);}


	void SetPlayer(CPlayer *p);
	CPlayer *GetPlayer(){return m_pThisPlayer;}

	CGameOperation *GetGameOperation(){return &m_gameOperation;}

	void SetResCode(int code){m_gameOperation.SetResCode(code);}
	int GetResCode(){return m_gameOperation.GetResCode();}
	void ResetResCode(){return m_gameOperation.ResetResCode();}

	void Init();

	//外部给player用的接口
	void DoGameOperaion(int protocolId,int paramLength,char *cmdData,CSocketHelper *pSocketHelper);	//这里根据protocolId来发送某些协议

	//game operation接口

	void ResetMoveSucc(){m_gameOperation.ResetMoveSucc();}
	void SetMoveSucc(bool b){m_gameOperation.SetMoveSucc(b);}
	bool IsMoveSucc(){return m_gameOperation.IsMoveSucc();} //更新目标怪物的属性信息是否成功



	//其它
	bool InterruptTaskByEmergencyLevel();	//中断现时做的东西
	void ResetTaskEmergencyLevel(){m_gameOperation.ResetEmergencyLevel();}

	//任务
	void DoSetPkModeTask(CGameConfig *pCfg,CSocketHelper *pSocketHelper);	//pk模式转换

public:	//其它接口
	void DoTimerTask(CSocketHelper *pSocketHelper);	//做定时任务	//这里主要是做定时发包	
public:	//boss任务

public:	//副本类的操作,现在是副本优先
	
private:	//私有接口，不供外用

	void Test(CSocketHelper *pSocketHelper);


private:
	CPlayer *m_pThisPlayer;
	HANDLE m_hEvtTaskFinished;	//正常情况是等待任务完成，有紧急任务则会跳出去,有状态时是中断或完成
	bool m_bFirstRunning;

	int m_sendErrorCount;	//这个主要统计发送小秘书的错误次数超过一定次数就表示断开了
	CGameOperation m_gameOperation;	//游戏操作类，用来执行一系列发包流程

private:
};
