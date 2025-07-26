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

	//ֻ��mall���سɹ��������ɽ��ղ��ݸ�ֵ
// 	SetLoadMallSucc(true);	//test
// 
// 	ResetLoadMailSucc();
// 	ResetLoadSkillsSucc();
// 	ResetLoadMissionsSucc();
// 	ResetLoadAchievementSucc();
//  	ResetLoadMallSucc();

	m_hEvtOperationFinished=NULL;
	m_hEvtOperationFinished=CreateEvent(NULL,FALSE,FALSE,NULL);	//�Զ��ָ����ź�״̬
	
}


bool CGameOperation::InterruptOperationByEmergencyLevel(E_EMERGENCY_LEVEL lv)
{
	SetEmergencyLevel(lv);
	return InterruptCurrentOperation();
}





////////////////////////////////��������//////////////////////////////////////////

bool CGameOperation::RecvPacketAndUpdateInfo(int times,CSocketHelper *pSocketHelper)	//���ղ��������ݣ�times�Ǵ���
{
	bool ret=true;
	while(times--)
	{
		Sleep(50);
	}
EXT:
	return ret;
}


E_OPERATION_RESULT CGameOperation::SetPkMode(int mode,CSocketHelper *pSocketHelper)	//pkģʽת��
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
