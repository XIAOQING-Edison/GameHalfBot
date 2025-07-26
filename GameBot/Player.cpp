#include "Player.h"
#include "Msg.h"
#include "Misc/Misc.h"
#include "FunctionHelper/GameLogicHelper.h"
#include "FunctionHelper/SocketHelper.h"
CPlayer::CPlayer(void)
{
	Init();
}

CPlayer::~CPlayer(void)
{
	CloseObjectWhenQuit();
}

void CPlayer::Init()
{
	SetQuit(false);	//默认不退出

	SetClient(NULL);
	SetCareer(-1);
	SetX(0);
	SetY(0);
	SetLevel(0);
	SetVipLevel(0);	//会员等级

	SetCurHp(-1);
	SetMaxHp(-1);
	SetCurMp(-1);
	SetMaxMp(-1);
	SetMaxShield(0);
	SetCurShield(0);
	SetCurComboValue(0);
	SetMaxComboValue(1);
	ResetAttackerId();	//初定无玩家攻击自身

	SetPlayerIndex(-1);	//初始为无下标


	SetTotalBattleScore(0);
	SetValidAttributePoint(0);	//

	ResetStates();
	
	m_pGameLogicHelper=new CGameLogicHelper;
	m_pSocketHelper=new CSocketHelper;
	m_pGameLogicHelper->SetPlayer(this);
	m_pSocketHelper->SetPlayer(this);
	m_hThreadPlay=NULL;
	//SetStop(false);	//默认不暂停
	SetStop(true);	//这里先暂停状态
// #endif
}



void CPlayer::CloseObjectWhenQuit()
{	

}

STRING CPlayer::GetAccountName()	//这里判断index有效并且无帐户名称，则把index字串作为account
{
	STRING result;
	TCHAR buf[64];
	if(m_accountName.length()==0 && m_index !=-1)
	{
		_stprintf(buf,_T("%d"),m_index+1);
		m_accountName=buf;
	}
	return m_accountName;
}

//重置某些状态，后面可能会集中写到这里再调用
void CPlayer::ResetStates()
{
	STRING defString;
	SetLoginAlready(false);
	SetChooseRoleAlreay(false);
	SetInGameAlready(false);
	ResetPkMode();
}


void CPlayer::SetLoginAlready(bool b)
{
	DWORD tmpState=(DWORD)m_state;
	if(b)
	{
		SET_BIT(tmpState,e_player_state_logined);
	}
	else
	{
		CLR_BIT(tmpState,e_player_state_logined);
	}
	m_state=(E_PLAYER_STATE)tmpState;
}


void CPlayer::SetInGameAlready(bool b)
{
	DWORD tmpState=(DWORD)m_state;
	if(b)
	{
		SET_BIT(tmpState,e_player_state_in_game_already);
	}
	else
	{
		CLR_BIT(tmpState,e_player_state_in_game_already);
	}
	m_state=(E_PLAYER_STATE)tmpState;
}


void CPlayer::SetChooseRoleAlreay(bool b)
{
	DWORD tmpState=(DWORD)m_state;
	if(b)
	{
		SET_BIT(tmpState,e_player_state_role_chosen);
	}
	else
	{
		CLR_BIT(tmpState,e_player_state_role_chosen);
	}
	m_state=(E_PLAYER_STATE)tmpState;
}


bool CPlayer::IsLoginAlready()
{
	return IS_BIT_SET(m_state,(int)e_player_state_logined);
}


bool CPlayer::IsInGameAlready()
{
	return IS_BIT_SET(m_state,e_player_state_in_game_already);
}


bool CPlayer::IsRoleChosenAlready()
{
	return IS_BIT_SET(m_state,e_player_state_role_chosen);
}



bool CPlayer::ReadyForPlaying()	//准备创建任务线程
{
	bool ret=false;
	TRACE_OUTPUT(_T("-----------------CPlayer准备创建玩家线程--------------------\n"));
	ret=CreatePlayThread();	//玩的线程;
	return ret;
}


bool CPlayer::CreatePlayThread()	//玩的线程，处理任务
{
	DWORD tid;
	if(!m_hThreadPlay)
	{
		m_hThreadPlay=CreateThread(NULL,0,CPlayer::ThreadProcessTask,this,0,&tid);
	}
	return (m_hThreadPlay!=NULL);
}




void CPlayer::InitSkillFromConfig()	//初始化技能配置
{

}


///////////////////////////////////gameLogic///////////////////////////////////////
bool CPlayer::InterruptTaskByEmergencyLevel(){return m_pGameLogicHelper->InterruptTaskByEmergencyLevel();}	//中断现时做的东西
void CPlayer::ResetTaskEmergencyLevel(){m_pGameLogicHelper->ResetTaskEmergencyLevel();}
void CPlayer::SetResCode(int code){m_pGameLogicHelper->SetResCode(code);}
int	CPlayer::GetResCode(){return m_pGameLogicHelper->GetResCode();}
void CPlayer::ResetResCode(){m_pGameLogicHelper->ResetResCode();}
void CPlayer::SetMoveSucc(bool b){m_pGameLogicHelper->SetMoveSucc(b);}

/////////////////////////////////地图相关接口/////////////////////////////////////////


DWORD WINAPI CPlayer::ThreadProcessTask(LPVOID p)
{
	DWORD ret=0;
	CPlayer *player=(CPlayer*)p;
	CGameLogicHelper *pLogicHelper=player->GetGameLogicHelper();
	player->InitSkillFromConfig();	//初始化技能配置
	TRACE_OUTPUT(_T("---------------------CPlayer玩家线程进入!!!!!!----------------------\n"));
	while(!player->IsQuit())
	{
		Sleep(1000);
	}
	TRACE_OUTPUT(_T("--------------------CPlayer玩家线程退出!!!!!!------------------------\n"));
	return ret;
}
