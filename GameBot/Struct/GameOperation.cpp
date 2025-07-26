#include "GameOperation.h"
#include "../Player.h"
#include "../Misc/Misc.h"
#include "../Config/GameConfig.h"
#include "../Config/BotConfig.h"
#include "../Config/SystemConfig.h"
#include "../Config/GiftHallConfig.h"

#define BARRIER_VALUE 1
CGameOperation::CGameOperation(void)
{
	Init();
}

CGameOperation::~CGameOperation(void)
{
	SAFE_CLOSE_HANDLE(m_hEvtOperationFinished);
}

void CGameOperation::ResetResCode()
{
	SetResCode(-1);
}


void CGameOperation::Init()
{
	SetPlayer(NULL);
	ResetResCode();
	ResetConnectToGameServer();
	ResetEmergencyLevel();
// 	ResetLoadItemsSucc();

	//只设mall加载成功，其它由接收部份赋值
// 	SetLoadMallSucc(true);	//test
// 
// 	ResetLoadMailSucc();
// 	ResetLoadSkillsSucc();
// 	ResetLoadMissionsSucc();
// 	ResetLoadAchievementSucc();
//  	ResetLoadMallSucc();

	m_hEvtOperationFinished=NULL;
	m_hEvtOperationFinished=CreateEvent(NULL,FALSE,FALSE,NULL);	//自动恢复无信号状态
	
}


bool CGameOperation::InterruptOperationByEmergencyLevel(E_EMERGENCY_LEVEL lv)
{
	SetEmergencyLevel(lv);
	return InterruptCurrentOperation();
}





////////////////////////////////真正功能//////////////////////////////////////////

bool CGameOperation::RecvPacketAndUpdateInfo(int times,CSocketHelper *pSocketHelper)	//接收并处理数据，times是次数
{
	bool ret=true;
	while(times--)
	{
		Sleep(50);
	}
EXT:
	return ret;
}


E_OPERATION_RESULT CGameOperation::SetPkMode(int mode,CSocketHelper *pSocketHelper)	//pk模式转换
{
	int tryTimes=5;
	bool bFinish=false;
	E_OPERATION_RESULT opResult=e_operation_result_finished;
		
	pSocketHelper->SendSetPkMode(mode);
	while(!bFinish && tryTimes--)
	{
		bFinish=GetEmergencyLevel()==e_emergency_level_emergency || m_pThisPlayer->GetPkMode() == mode;
		Sleep(100);
		if(GetEmergencyLevel()==e_emergency_level_emergency)
			opResult=e_operation_result_interrupt;
	}	
	return opResult;

}
