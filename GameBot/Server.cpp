#include "Server.h"
#include "MessageMapList.h"
#include "./Util/MessageSenderHelper.h"
#include "./Misc/Misc.h"

CServer::CServer(void)
{
// 	Init();
}

CServer::~CServer(void)
{
	SetIsQuit(true);
	
	WakeupToDoTask();
// 	WakeupToHandleMessage();
// 
	SAFE_CLOSE_HANDLE(m_hEvtDoTask);
// 	SAFE_CLOSE_HANDLE(m_hEvtMessageDecode);
// 
	WaitForSingleObject(m_hThreadDoTask,INFINITE);
	SAFE_CLOSE_HANDLE(m_hThreadDoTask);
// 
// 	WaitForSingleObject(m_hThreadMessageHandle,INFINITE);
// 	SAFE_CLOSE_HANDLE(m_hThreadMessageHandle);

	SAFE_DELETE_POINTER(m_pThreadLock);
	SAFE_DELETE_POINTER(m_pStreamBufWrite);
	SAFE_DELETE_POINTER(m_pStreamBufRead);

	ClearClients();
}


void CServer::Init()
{
	SetIsQuit(false);
	m_pThreadLock=new CThreadLock;
	m_pStreamBufWrite=new CStreamReadWrite(E_ENDIAN_TYPE_LITTLE_ENDIAN,1024);
	m_pStreamBufRead=new CStreamReadWrite(E_ENDIAN_TYPE_LITTLE_ENDIAN,1024);

	m_hEvtDoTask=m_hEvtMessageDecode=NULL;
	m_hThreadDoTask=m_hThreadMessageHandle=NULL;

	CreateEvents();
// 	CreateMessageHandleThread();
	CreateTaskThread();

	//SetListCtrl(NULL);
}


void CServer::ClearClients()
{
	vector<CClient*>::iterator it=m_clientList.begin();
	while(it != m_clientList.end())
	{
		CClient *p=(*it);
		SAFE_DELETE_POINTER(p);
		++it;
	}

	m_clientList.clear();
}



CClient *CServer::GetClientByHwnd(HWND hwnd)	//找出客户句柄
{
	CClient *pClient=NULL;
	vector<CClient*>::iterator it=m_clientList.begin();
	while(it != m_clientList.end())
	{
		if((*it)->GetSelfWindow() && (*it)->GetSelfWindow()==hwnd)
		{
			pClient=(*it);
			break;
		}
		++it;
	}

	return pClient;
}


CClient *CServer::GetClientById(int index)
{
	CClient *pClient=NULL;
	if(index>=0 && index<m_clientList.size())
	{
		pClient=m_clientList.at(index);
	}
	else
	{
		//TRACE(_T("取得客户下标:%d超出范围!!!!\n"),index);
	}

	return pClient;
}


int CServer::GetAvailableClientIndex()	//找到一个合适的下标分配
{
	vector<CClient*>::iterator it=m_clientList.begin();
	int index=-1;
	int i=0;
	while(it != m_clientList.end())
	{
		if((*it)->GetIndex()==-1)
		{
			index=i;
			break;
		}
		++it;
		++i;
	}
	return index;
}


void CServer::IncClientLiveTime(int index)
{
	if(index>=0 && index<m_clientList.size())
	{
		CClient *p=GetClientById(index);
		p->IncLiveTime();

	}

}


void CServer::DecClientLiveTime(int index)
{

	if(index>=0 && index<m_clientList.size())
	{
		CClient *p=GetClientById(index);
		p->DecLiveTime();
	}
}


void CServer::DecAllPlayerLiveTime()
{
	for(int i=0;i<m_clientList.size();++i)
	{
		DecClientLiveTime(i);
	}
}


void CServer::AddPlayerToClientList(CPlayer *p)
{
	CClient *client=new CClient;	//实始化客户，这里没有句柄，需要在loginreq里把句柄弄过来
	client->SetPlayer(p);
	m_clientList.push_back(client);
}




int CServer::UpdateClientHwnd(HWND hClient,int index)
{
	CClient *pClient=GetClientById(index);
	if(pClient)
	{
		pClient->SetSelfWindow(hClient);
	}
	else
	{
		if(index==-1)	//测试，这里没分配就给0
		{
			index=GetAvailableClientIndex();
			if(index !=-1)
			{
				TRACE_OUTPUT(_T("分配客户id:%d\n"),index);
				pClient=GetClientById(index);
				pClient->SetSelfWindow(hClient);
			}
			else
			{
				TRACE_OUTPUT(_T("找不到可用的客户id,可能数量已满!!\n"));
			}
		}
	}
	return index;
}


void CServer::DeleteClient(int index)
{
	CClient *p=NULL;
	m_pThreadLock->Lock();
	if(index>=0 && index<m_clientList.size())
	{
		p=GetClientById(index);
		SAFE_DELETE_POINTER(p);
		m_clientList.erase(m_clientList.begin()+index);
	}
	else
	{
		//TRACE(_T("删除客户下标:%d超出范围!!!!\n"),index);
	}
	m_pThreadLock->UnLock();
}



void CServer::DecodeMessage(HWND hClient,char *data,int len)
{
	m_pStreamBufRead->CopyBufAndLength(data,len);
	CBaseMessage msg;
	msg.DecodeFirst(m_pStreamBufRead);
	CBaseMessage *pMsg=CMessageMapList::GetInstance()->GetMessageById(msg.GetProtocolId());
	if(pMsg)
	{
		pMsg->Decode(m_pStreamBufRead);
		HandleMessage(hClient,pMsg);
	}
	else
	{
		
		//TRACE(_T("找不到消息id:%d的消息类型!!!!\n"));
	}
	m_pStreamBufRead->SetBufPos(0);
	m_pStreamBufRead->SetHandlePos(0);
}


void CServer::HandleMessage(HWND hClient,CBaseMessage *pMessage)
{
	int msgId=pMessage->GetProtocolId();
	CMessageHeartBeatRes *pHeartbeatRes=(CMessageHeartBeatRes*)pMessage;
	CMessageHeartBeatReq *pHeartbeatReq=(CMessageHeartBeatReq*)pMessage;
	CMessageLoginReq *pLoginReq=(CMessageLoginReq*)pMessage;
	CMessageLoginRes *pLoginRes=(CMessageLoginRes*)pMessage;
	CMessageClientPlayerInfoStatus *pPlayerInfoStatus=(CMessageClientPlayerInfoStatus*)pMessage;
	CMessageClientPlayerTaskStatus *pPlayerTaskStatus=(CMessageClientPlayerTaskStatus*)pMessage;
	CMessageClientQuitReq *pQuitReq=(CMessageClientQuitReq*)pMessage;
	CMessageClientQuitRes *pQuitRes=(CMessageClientQuitRes*)pMessage;
	CMessageWriteText *pWriteData=(CMessageWriteText*)pMessage;
// 	CMessageClientForceQuitRes *pForceQuitRes=NULL;
	int playerIndex=-1;
	CClient *pClient=GetClientByHwnd(hClient);
	if(pClient)
	{
		playerIndex=pClient->GetIndex();
	}



	switch(msgId)
	{
	case e_cmd_heartbeat_req:
		playerIndex=pLoginReq->GetPlayerIndex();	
		if(!pClient)
		{
			//没找到就分配一个id给它
			playerIndex=UpdateClientHwnd(hClient,playerIndex);
			pClient=GetClientById(playerIndex);
			pClient->SetIndex(playerIndex);
		}
		if(pClient)
		{
			playerIndex=pClient->GetIndex();
			CMessageSenderHelper::GetInstance()->SendHeartbeatRes(playerIndex,0);
		}
		break;	
	case e_cmd_heartbeat_res:
		IncClientLiveTime(playerIndex);
		break;
	case e_cmd_login_req:
		playerIndex=pLoginReq->GetPlayerIndex();
		if(!pClient)
		{
			playerIndex=UpdateClientHwnd(hClient,playerIndex);
			pClient=GetClientById(playerIndex);
			pClient->SetIndex(playerIndex);
		}
		if(pClient)
		{
// 			pClient=GetClientByHwnd(hClient);
// 			playerIndex=pClient->GetPlayer()->GetPlayerIndex();
			CMessageSenderHelper::GetInstance()->SendLoginRes(pClient->GetIndex(),0);
		}
		break;
	case e_cmd_login_res:
		IncClientLiveTime(playerIndex);
		break;	
	case e_cmd_client_status:
		break;	
	case e_cmd_client_player_info_status:
		playerIndex=pPlayerInfoStatus->GetPlayerIndex();
		if(!pClient)
		{
			playerIndex=UpdateClientHwnd(hClient,playerIndex);
			pClient=GetClientById(playerIndex);
			pClient->SetIndex(playerIndex);
		}
		IncClientLiveTime(playerIndex);
		//在这里把信息更新到listctrl
		if(pClient)
		{
			pClient->UpdatePlayerInfoStatus(pPlayerInfoStatus->GetPlayerInfoStatus());
			CMisc::GetInstance()->SendUpdatePlayerStatusToMainHwnd((LPARAM)pClient);
		}
		break;
	case e_cmd_client_player_task_status:
		playerIndex=pPlayerTaskStatus->GetPlayerIndex();
		if(!pClient)
		{
			playerIndex=UpdateClientHwnd(hClient,playerIndex);	
			pClient=GetClientById(playerIndex);
			pClient->SetIndex(playerIndex);
		}
		IncClientLiveTime(playerIndex);
		//在这里把信息更新到listctrl
		if(pClient)
		{
			pClient->GetPlayerStatus()->taskName=pPlayerTaskStatus->GetTaskStaus();
			CMisc::GetInstance()->SendUpdatePlayerStatusToMainHwnd((LPARAM)pClient);
		}
		break;	
	case e_cmd_client_quit_req:
		playerIndex=pQuitReq->GetPlayerIndex();
		CMessageSenderHelper::GetInstance()->SendQuitRes(playerIndex,0);
		break;	
	case e_cmd_client_quit_res:
		DeleteClient(playerIndex);
		break;
	case e_cmd_write_text:
		SendToMainWindowToWriteText(pWriteData->GetType(),pWriteData->GetAccountName(),pWriteData->GetBuffer(),pWriteData->GetLength());
		break;
	case e_cmd_client_report_detail:
		{
		}
		break;
	default:
		printf("unhandle cmd:%d\n",msgId);
		break;
	}

	printf("消息来自客户:%d,cmd:%d\n",playerIndex,pMessage->GetProtocolId());

}


//写日志
void CServer::SendToMainWindowToWriteLog(const STRING &account,char *msg,int len)	//写日志
{
	_GAME_LOG_MSG_ logMsg;
	logMsg.accountName=account;
	memcpy(logMsg.msgBuf,msg,len);
	CMisc::GetInstance()->SendWriteLogMsgToMainHwnd((LPARAM)&logMsg);

}

//根据type来决定写什么
void CServer::SendToMainWindowToWriteText(int type,const STRING &account,char *msg,int len)
{
	if(type==e_write_data_type_log)
	{
		SendToMainWindowToWriteLog(account,msg,len);
	}
	else
	{
		TRACE_OUTPUT(_T("收到要写文件却没找到处理这类型:%d的函数~~~~\n"),type);
	}
}



//执行
bool CServer::ExecuteClientApp(const TCHAR *szAppName,TCHAR *szCommandLine)	//执行
{
	bool ret=false;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	memset(&si,0,sizeof(STARTUPINFO));
	memset(&pi,0,sizeof(PROCESS_INFORMATION));

	ret=CreateProcess(szAppName,szCommandLine,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
	if(!ret)
	{
		//TRACE(_T("创建进程失败!!代号:%x\n"),GetLastError());
	}
	return ret;
}



void CServer::SendQuitMessageToClients()
{
	vector<CClient*>::iterator it=m_clientList.begin();
	while(it != m_clientList.end())
	{
		CClient *p=*it;
		CMessageClientQuitRes *pQuitRes=(CMessageClientQuitRes*)CMessageMapList::GetInstance()->GetMessageById(e_cmd_client_quit_res);
		pQuitRes->Encode(m_pStreamBufWrite);
		CMessageSenderHelper::GetInstance()->SendQuitRes(p->GetIndex(),0);
		//::SendMessage(p->GetSelfWindow(),WM_CLOSE,0,0);
		++it;
	}
}



void CServer::CopyMsgToStreamRead(HWND hClient,char *data,int len)
{
	m_pStreamBufRead->WriteFixedInt32((int)hClient);
	m_pStreamBufRead->CopyBufAndLength(data,len);
}


void CServer::Decode()	//解码消息
{
	char *data=NULL;
	m_pThreadLock->Lock();
	HWND hClient=(HWND)m_pStreamBufRead->ReadFixedInt32();
	data=(char*)m_pStreamBufRead->GetBufHead()+m_pStreamBufRead->GetHandlePos();
	int len=m_pStreamBufRead->GetRestBytesLength();
	DecodeMessage(hClient,data,len);
	m_pThreadLock->UnLock();
}


void CServer::CreateEvents()	//创建事件变量
{
	if(!m_hEvtDoTask)
	{
		m_hEvtDoTask=::CreateEvent(NULL,FALSE,FALSE,NULL);
	}
// 	if(!m_hEvtMessageDecode)
// 	{
// 		m_hEvtMessageDecode=::CreateEvent(NULL,FALSE,FALSE,NULL);
// 	}
}



bool CServer::CreateMessageHandleThread()//创建消息处理线程
{
	bool ret=false;
	DWORD tid;
	if(!m_hThreadMessageHandle)
	{
		m_hThreadMessageHandle=CreateThread(NULL,0,CServer::ThreadMessageHandle,this,0,&tid);
	}
	ret=(m_hThreadMessageHandle!=NULL);
	return ret;
}


bool CServer::CreateTaskThread()	//创建任务线程
{
	bool ret=false;
	DWORD tid;
	if(!m_hThreadDoTask)
	{
		m_hThreadDoTask=CreateThread(NULL,0,CServer::ThreadTask,this,0,&tid);
	}
	ret=(m_hThreadDoTask!=NULL);
	return ret;
}


bool CServer::RunClientApp()
{
	bool ret=true;
// 	TCHAR cmdLine[MAX_PATH];	//糁
// 
// 	for(int i=0;i<m_pListPlayers->GetItemCount();++i)
// 	{	
// 		if(m_pListPlayers->GetCheck(i))
// 		{
// 			_stprintf(cmdLine,_T("-%d -%d -%s"),CMisc::GetInstance()->GetHwndMain(),i,m_pListPlayers->GetItemText(i,0));
// 			ExecuteClientApp(m_appPath.c_str(),cmdLine);
// 		}
// 		else
// 		{
// 			ret=false;
// 		}
// 	}
	return ret;

}



void CServer::CheckClientExist()	//检测客户端是否还存在
{
	vector<CClient*>::iterator it=m_clientList.begin();
	while(it != m_clientList.end())
	{
		CClient *p=*it;
		if(!::IsWindow(p->GetSelfWindow()))
		{
			p->SetIndex(-1);
		}
		++it;
	}
}



/////////////////////////////////以下是线程函数/////////////////////////////////////////

DWORD WINAPI CServer::ThreadHeartBeat(LPVOID p)
{
	DWORD ret=0;
	CServer *pServer=(CServer*)p;
	while(!pServer->IsQuit())
	{
		pServer->DecAllPlayerLiveTime();
		Sleep(5000);
	}
	return ret;
}



DWORD WINAPI CServer::ThreadMessageHandle(LPVOID p)
{
	DWORD ret=0;
	CServer *pServer=(CServer*)p;
	HANDLE hEvt=pServer->GetEvtMessageHandle();
	printf("消息处理线程启动!!\n");
	while(!pServer->IsQuit())
	{
		::WaitForSingleObject(hEvt,INFINITE);
		if(pServer->IsQuit())
		{
			break;
		}
		pServer->Decode();
	}
	printf("消息处理线程结束!!\n");
	return ret;
}


DWORD WINAPI CServer::ThreadTask(LPVOID p)
{
	DWORD ret=0;
	CServer *pServer=(CServer*)p;
	HANDLE hEvt=pServer->GetEvtTask();
	TRACE_OUTPUT(_T("任务处理线程启动!!\n"));
	while(!pServer->IsQuit())
	{
		//::WaitForSingleObject(hEvt,INFINITE);
		if(pServer->IsQuit())
		{
			break;
		}
		//pServer->RunClientApp();
		pServer->CheckClientExist();	//定时检测客户端有效性
		Sleep(500);
	}

	TRACE_OUTPUT(_T("任务处理线程结束!!\n"));
	return ret;
}