#include "Client.h"
#include "Msg.h"
#include "Global/Enums.h"
#include "Global/Macro.h"
#include "Player.h"
#include "MessageMapList.h"
#include "Misc/HookHelper.h"
#include "FunctionHelper/GameLogicHelper.h"
#include "FunctionHelper/SocketHelper.h"
#include "Util/MessageSenderHelper.h"

#pragma comment(lib,"StreamReadWrite.lib")

static const TCHAR* g_szMaterialNameArray[]={
	_T("金币"),_T("钻石"),_T("灵魂宝石"),_T("创造宝石"),_T("打造石碎块"),_T("破碎的洛克之羽")
};
CClient::CClient(void)
{
	SetPlayer(NULL);
	SetMainWindow(NULL);
	SetSelfWindow(NULL);
	m_pStreamBufRecv=new CStreamReadWrite(E_ENDIAN_TYPE_LITTLE_ENDIAN,1024);
	m_pStreamBufSend=new CStreamReadWrite(E_ENDIAN_TYPE_LITTLE_ENDIAN,1024);
	SetMessageThreadId(0);
	m_hThreadMessage=NULL;
	m_hThreadTimer=NULL;
	m_liveTime=1;
	SetIndex(-1);	//-1表示无下标
	memset(m_materialData,0,sizeof(m_materialData));
	m_materialCount=0;
}

CClient::~CClient(void)//调试发现dll里面用waitFor时间填大了会死锁，不管线程函数是否已退出都等不到，所以直接terminate
{	
	::PostThreadMessage(m_messageThreadId,WM_QUIT,0,0);
	if(WaitForSingleObject(m_hThreadTimer,50)==WAIT_TIMEOUT)
	{
		TerminateThread(m_hThreadTimer,-1);
	}
	SAFE_CLOSE_HANDLE(m_hThreadTimer);

	
	if(WaitForSingleObject(m_hThreadMessage,50)==WAIT_TIMEOUT)
	{
		TerminateThread(m_hThreadMessage,-1);
	}
	SAFE_CLOSE_HANDLE(m_hThreadMessage);
	SAFE_DELETE_POINTER(m_pStreamBufRecv);
	SAFE_DELETE_POINTER(m_pStreamBufSend);
}


bool CClient::IsPlayerQuit()
{
	if(m_pPlayer)
		return m_pPlayer->IsQuit();
	else
		return true;
}


void  CClient::IncLiveTime()
{
	++m_liveTime;
}

void  CClient::DecLiveTime()
{
	--m_liveTime;
}


bool CClient::CreateMessageThread()
{
	bool ret=false;
	if(!m_hThreadMessage)
	{
		m_hThreadMessage=CreateThread(NULL,0,CClient::ThreadMessage,this,0,&m_messageThreadId);
	}
	TRACE_OUTPUT(_T("---------------Client消息线程句柄:0x%x,id:0x%x------------------\n"),m_hThreadMessage,m_messageThreadId);
	ret=(m_hThreadMessage != NULL);
	return ret;
}


bool  CClient::CreateTimerThread()
{
	bool ret=false;
	DWORD tid;
	if(!m_hThreadTimer)
	{
		m_hThreadTimer=CreateThread(NULL,0,CClient::ThredTimer,this,0,&tid);
	}
	//TRACE_OUTPUT(_T("-----------------Client定时线程句柄:0x%x------------------\n"),m_hThreadTimer);
	ret=(m_hThreadTimer != NULL);
	return ret;
}


bool CClient::DoReadyWork()	//创建线程类
{
	bool ret=false;
	OutputDebugStr(_T("------------Client预备创建消息线程和定时线程------------------\n"));
	ret=CreateMessageThread()&&CreateTimerThread();
	return ret;
}

void CClient::DoActionByCmd(int cmd)
{
	m_pPlayer->GetGameLogicHelper()->DoGameOperaion(cmd,0,NULL,m_pPlayer->GetSocketHelper());
}


void CClient::UpdatePlayerInfoStatus(CInfoPlayerInfoStatus *pInfo)
{
	m_playerStatus=*pInfo;
	if(m_pPlayer)
		m_pPlayer->SetCareer(pInfo->GetJob());

}

void CClient::UpdatePlayerInfoToPlayerInfoStatus()	//将CPlayer里的状态赋值到m_playerInfoStatus里面
{
	if(m_pPlayer)
	{		
		m_playerStatus.SetRoleId(m_pPlayer->GetRoleId());
		m_playerStatus.asuramName=m_pPlayer->GetAsuramName();
		m_playerStatus.roleName=m_pPlayer->GetRoleName();
		m_playerStatus.job=m_pPlayer->GetCareer();
		m_playerStatus.level=m_pPlayer->GetLevel();
		//m_playerStatus.mapName=m_pPlayer->GetMapId();//后面把地图数据整理出来就能得到
		m_playerStatus.taskName=_T("");	//暂时置空 to do..
		m_playerStatus.SetX(m_pPlayer->GetX());
		m_playerStatus.SetY(m_pPlayer->GetY());
	}
}


//用于接收到服务端时设定cmd，再根据cmd类型发送给服务端或做其它操作
 DWORD WINAPI CClient::ThreadMessage(LPVOID p)	//消息线程
 {
	 MSG msg;
	 CClient *pClient=(CClient*)p;

	 //TRACE_OUTPUT(_T("----------------------Client进入MessageThread-----------------------\n"));
	 while (::GetMessage(&msg, NULL, 0, 0))
	 {
		 switch(msg.message)
		 {		
		 case WM_GAME_CONTROL_MSG:
			 pClient->SetCmd(msg.wParam);
			 pClient->DoActionByCmd(pClient->GetCmd());
			 break;
		 default:
			 break;
		 }
	 }
	 TRACE_OUTPUT(_T("----------------------Client退出MessageThread-----------------------\n"));
EXT:
	//ExitThread(0xaa);
	return 0xaa;
 }



 DWORD WINAPI CClient::ThredTimer(LPVOID p)	//定时器线程
 {
	 CClient *pClient=(CClient*)p;
	 int timeInteval=50;
	 //TRACE_OUTPUT(_T("------------------Client进入定时线程----------------------------\n"));
	 CPlayer *player=pClient->GetPlayer();
	 static DWORD tick=0;
	 while(!pClient->IsPlayerQuit())
	 {
		 //send heart beat to server
		if(pClient->IsPlayerQuit())
			break;
		if(player->IsLoginAlready() && player->IsRoleChosenAlready()&& player->IsInGameAlready())
		{
			//先屏蔽掉
			player->GetGameLogicHelper()->DoTimerTask(player->GetSocketHelper());
			//test,间隔发送
			if(tick>0 && tick%20==0)
			{
				CMessageSenderHelper::GetInstance()->SendHeartbeatReq(pClient);
// 				if(pClient->CheckTimeExpired())
// 				{
// 					player->ResetStates();
// 				}
			}
			++tick;
		}
		Sleep(timeInteval);
	 }
	 //TRACE_OUTPUT(_T("------------------Client退出定时线程----------------------------\n"));
	 return 0xbb;
 }