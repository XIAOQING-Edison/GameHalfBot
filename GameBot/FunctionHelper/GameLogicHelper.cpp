#include "GameLogicHelper.h"
#include "../Player.h"
#include "../Config/CommentConfig.h"	//for find taskInfo and so on
#include "../Config/GameConfig.h"
#include "../Config/UserConfig.h"
#include "../Config/BotConfig.h"
#include "../Config/SystemConfig.h"
#include "../Config/DailyTaskConfig.h"
#include "../Config/GiftHallConfig.h"

#include "../Config/SkillConfig.h"	//技能配置


#include "../Misc/Misc.h"		//for some calculate
#include "../Client.h"

//#define _CHAT_VERSION_	//喊话需要建立这个标记

//以下是skills选择定义,下标

// static const int g_skillWarrior[]={};
// static const int g_skillArch[]={};
// static const int g_skillWitch[]={};

CGameLogicHelper::CGameLogicHelper(void)
{
	Init();
}

CGameLogicHelper::~CGameLogicHelper(void)
{
	
}


void CGameLogicHelper::Init()
{
	SetPlayer(NULL);
	ResetIsFirstRunning();
	m_hEvtTaskFinished=NULL;
	m_hEvtTaskFinished=CreateEvent(NULL,FALSE,FALSE,NULL);//自动恢复无信号状态

}


void CGameLogicHelper::SetPlayer(CPlayer *p)
{
	m_pThisPlayer=p;
	m_gameOperation.SetPlayer(p);
}




bool CGameLogicHelper::InterruptTaskByEmergencyLevel()
{
	E_EMERGENCY_LEVEL lv=e_emergency_level_emergency;
	m_gameOperation.SetEmergencyLevel(lv);
	return true;
}



void CGameLogicHelper::DoTimerTask(CSocketHelper *pSocketHelper)	//做定时任务	//这里主要是做定时发包
{
	
}




void CGameLogicHelper::DoSetPkModeTask(CGameConfig *pCfg,CSocketHelper *pSocketHelper)	//pk模式转换
{
	CConfigSecretary1 *pConfigFun1=pCfg->GetConfigSecretary1();
	
	int pkMode=1;
	m_gameOperation.SetPkMode(pkMode,pSocketHelper);
	Sleep(1000);
}




///////////////////////////////外部接口调用协议///////////////////////////////////////////
void CGameLogicHelper::DoGameOperaion(int protocolId,int paramLength,char *cmdData,CSocketHelper *pSocketHelper)	//这里根据protocolId来发送某些协议
{
	if(protocolId==1314)
	{
		CGameConfig cfg(m_pThisPlayer->GetAccountName(),true,false);	//使用上一层目录作为主配置
		OutputDebugStr(_T("hhhhhhhhhhhhhhhhh\n"));
		DoSetPkModeTask(&cfg,pSocketHelper);
	}

}




////////////////////////////////测试功能//////////////////////////////////////////
void CGameLogicHelper::Test(CSocketHelper *pSocketHelper)
{
}