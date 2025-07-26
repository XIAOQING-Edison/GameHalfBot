#include "MessageSenderHelper.h"
#include "../Misc/Misc.h"
#include "../Server.h"
#include "../Client.h"
#include "ThreadLock.h"
#include <assert.h>

CMessageSenderHelper *CMessageSenderHelper::m_pMessageSenderHelperInstance=NULL;

CMessageSenderHelper::CMessageSenderHelper(void)
{
	m_pThreadLock=new CThreadLock;
	SetServer(NULL);
	SetClient(NULL);
}

CMessageSenderHelper::~CMessageSenderHelper(void)
{
	SAFE_DELETE_POINTER(m_pThreadLock);
}



CMessageSenderHelper* CMessageSenderHelper::GetInstance()
{
	if(!CMessageSenderHelper::m_pMessageSenderHelperInstance)
	{
		CMessageSenderHelper::m_pMessageSenderHelperInstance=new CMessageSenderHelper;
	}
	return CMessageSenderHelper::m_pMessageSenderHelperInstance;
}



void CMessageSenderHelper::DeleteInstance()
{
	SAFE_DELETE_POINTER(CMessageSenderHelper::m_pMessageSenderHelperInstance);
}



char* CMessageSenderHelper::CompactData(CBaseMessage *pMsg,int &len)
{
	char *pData=NULL;
	//基础大小，代表包大小，4字节+1字节(sign_byte)，则总包长是5+包体长度
	//包的内容是包长4+flag(4字节0)+原来的包内容
	int totalLength=4+pMsg->GetProtocolBufLength();	//这里需要重新写一个长度
	int packageFlag=0;
	len=totalLength;
	char *pNew=new char[totalLength];
	pData=pNew;
	*(int*)pNew=(totalLength-4);	//包体长度,-4是减去头部4字节
	pNew+=sizeof(int);

	memcpy(pNew,pMsg->GetProtocolBuf(),pMsg->GetProtocolBufLength());

	return pData;
}


//客户端发送
bool CMessageSenderHelper::SendHeartbeatReq(CClient *pClient)
{
	bool ret=true;
	COPYDATASTRUCT cs;
	char *pdata=NULL;
	int len;

	//test
	if(!::IsWindow(pClient->GetMainWindow()))
	{
		pClient->GetPlayer()->InterruptTaskByEmergencyLevel();
		pClient->GetPlayer()->SetQuit(true);
		return ret;
	}

	CBaseMessage *pMsg=CMessageMapList::GetInstance()->GetMessageById(e_cmd_heartbeat_req);
	if(pMsg)
	{
		m_pThreadLock->Lock();
		CMessageHeartBeatReq *pReq=(CMessageHeartBeatReq*)pMsg;
		pReq->MakeHeartBeatMessage(pClient->GetIndex());
		pMsg->Encode(pClient->GetStreamBufEncode());
		pdata=CompactData(pMsg,len);
		m_pThreadLock->UnLock();

		cs.dwData=(DWORD)pClient->GetSelfWindow();	//dwData标识为子窗口
		cs.cbData=len;
		cs.lpData=pdata;
		CMisc::GetInstance()->SendDataToOtherWindow((HWND)pClient->GetMainWindow(),&cs);
		SAFE_DELETE_ARRAY(pdata);
	}
	return ret;
}


bool CMessageSenderHelper::SendHeartbeatRes(int index,int code)
{
	bool ret=true;
	COPYDATASTRUCT cs;
	char *pdata=NULL;
	int len;
	CBaseMessage *pMsg=CMessageMapList::GetInstance()->GetMessageById(e_cmd_heartbeat_res);
	if(pMsg)
	{
		m_pThreadLock->Lock();
		CMessageHeartBeatRes *pReq=(CMessageHeartBeatRes*)pMsg;
		pReq->MakeHeartBeatResMessage(code);
		pMsg->Encode(m_pServer->GetStreamBufWrite());
		pdata=CompactData(pMsg,len);
		m_pThreadLock->UnLock();

		CClient *pClient=m_pServer->GetClientById(index);
		cs.dwData=(DWORD)pClient->GetSelfWindow();
		cs.cbData=len;
		cs.lpData=pdata;
		CMisc::GetInstance()->SendDataToOtherWindow(pClient->GetSelfWindow(),&cs);
		SAFE_DELETE_ARRAY(pdata);
	}
	return ret;
}

//客户端发送过来
bool CMessageSenderHelper::SendLoginReq(CClient *pClient)
{
	bool ret=true;
	COPYDATASTRUCT cs;
	char *pdata=NULL;
	int len;
	CBaseMessage *pMsg=CMessageMapList::GetInstance()->GetMessageById(e_cmd_login_req);
	if(pMsg)
	{
		m_pThreadLock->Lock();
		CMessageLoginReq *pReq=(CMessageLoginReq*)pMsg;
		pReq->MakeLoginMessage(pClient->GetIndex());
		pMsg->Encode(pClient->GetStreamBufEncode());
		pdata=CompactData(pMsg,len);
		m_pThreadLock->UnLock();

		//CClient *pClient=m_pServer->GetClientById(playerIndex);
		cs.dwData=(DWORD)pClient->GetSelfWindow();	//dwData标识为子窗口
		cs.cbData=len;
		cs.lpData=pdata;
		CMisc::GetInstance()->SendDataToOtherWindow(pClient->GetMainWindow(),&cs);
		SAFE_DELETE_ARRAY(pdata);
	}
	return ret;
}


bool CMessageSenderHelper::SendLoginRes(int index,int code)
{
	bool ret=true;
	COPYDATASTRUCT cs;
	char *pdata=NULL;
	int len;
	CBaseMessage *pMsg=CMessageMapList::GetInstance()->GetMessageById(e_cmd_login_res);
	if(pMsg)
	{
		m_pThreadLock->Lock();
		CMessageLoginRes *pReq=(CMessageLoginRes*)pMsg;
		pReq->MakeLoginResMessage(index,code);
		pMsg->Encode(m_pServer->GetStreamBufWrite());
		pdata=CompactData(pMsg,len);
		m_pThreadLock->UnLock();

		CClient *pClient=m_pServer->GetClientById(index);
		assert(pClient !=NULL);
		if(pClient)
		{
			cs.dwData=(DWORD)pClient->GetSelfWindow();
			cs.cbData=len;
			cs.lpData=pdata;
			CMisc::GetInstance()->SendDataToOtherWindow(pClient->GetSelfWindow(),&cs);
		}
	
		SAFE_DELETE_ARRAY(pdata);
	}
	return ret;
}


bool CMessageSenderHelper::SendClientStatus(CClient *pClient,int isOnline)	//待定
{
	bool ret=false;
	return ret;
}


bool CMessageSenderHelper::SendPlayerInfoStatus(CClient *pClient,CInfoPlayerInfoStatus *playerInfo)
{
	bool ret=true;
	COPYDATASTRUCT cs;
	char *pdata=NULL;
	int len;

	//test
	if(!::IsWindow(pClient->GetMainWindow()))
	{
		pClient->GetPlayer()->SetQuit(true);
		pClient->GetPlayer()->InterruptTaskByEmergencyLevel();
		return ret;
	}

	CBaseMessage *pMsg=CMessageMapList::GetInstance()->GetMessageById(e_cmd_client_player_info_status);
	if(pMsg)
	{
		m_pThreadLock->Lock();
		CMessageClientPlayerInfoStatus *pReq=(CMessageClientPlayerInfoStatus*)pMsg;
		pReq->MakeClientPlayerInfoStatusMessage(pClient->GetIndex(),playerInfo);
		pMsg->Encode(pClient->GetStreamBufEncode());
		pdata=CompactData(pMsg,len);
		m_pThreadLock->UnLock();

		//CClient *pClient=;m_pServer->GetClientById(index);
		cs.dwData=(DWORD)pClient->GetSelfWindow();	//dwData标识为子窗口
		cs.cbData=len;
		cs.lpData=pdata;
		CMisc::GetInstance()->SendDataToOtherWindow(pClient->GetMainWindow(),&cs);
		SAFE_DELETE_ARRAY(pdata);
	}
	return ret;
}


bool CMessageSenderHelper::SendPlayerTaskStatus(CClient *pClient,STRING &taskName)
{
	bool ret=true;
	COPYDATASTRUCT cs;
	char *pdata=NULL;
	int len;
	CBaseMessage *pMsg=CMessageMapList::GetInstance()->GetMessageById(e_cmd_client_player_task_status);
	if(pMsg)
	{
		m_pThreadLock->Lock();
		CMessageClientPlayerTaskStatus *pReq=(CMessageClientPlayerTaskStatus*)pMsg;
		pReq->MakeClientPlayerTaskStatusMessage(pClient->GetIndex(),taskName);
		pMsg->Encode(pClient->GetStreamBufEncode());
		pdata=CompactData(pMsg,len);
		m_pThreadLock->UnLock();

		//CClient *pClient=m_pServer->GetClientById(index);
		cs.dwData=(DWORD)pClient->GetSelfWindow();	//dwData标识为子窗口;
		cs.cbData=len;
		cs.lpData=pdata;
		CMisc::GetInstance()->SendDataToOtherWindow(pClient->GetMainWindow(),&cs);
		SAFE_DELETE_ARRAY(pdata);
	}
	return ret;
}


bool CMessageSenderHelper::SendQuitReq(CClient *pClient)
{
	bool ret=true;
	COPYDATASTRUCT cs;
	char *pdata=NULL;
	int len;
	CBaseMessage *pMsg=CMessageMapList::GetInstance()->GetMessageById(e_cmd_client_quit_req);
	if(pMsg)
	{
		m_pThreadLock->Lock();
		CMessageClientQuitReq *pReq=(CMessageClientQuitReq*)pMsg;
		pReq->MakeClientQuitMessage(pClient->GetIndex());
		pMsg->Encode(pClient->GetStreamBufEncode());
		pdata=CompactData(pMsg,len);
		m_pThreadLock->UnLock();

		//CClient *pClient=m_pServer->GetClientById(playerIndex);
		cs.dwData=(DWORD)pClient->GetSelfWindow();	//dwData标识为子窗口
		cs.cbData=len;
		cs.lpData=pdata;
		CMisc::GetInstance()->SendDataToOtherWindow(pClient->GetMainWindow(),&cs);
		SAFE_DELETE_ARRAY(pdata);
	}
	return ret;
}


bool CMessageSenderHelper::SendQuitRes(int index,int code)
{
	bool ret=true;
	COPYDATASTRUCT cs;
	char *pdata=NULL;
	int len;
	CBaseMessage *pMsg=CMessageMapList::GetInstance()->GetMessageById(e_cmd_client_quit_res);
	if(pMsg)
	{
		m_pThreadLock->Lock();
		CMessageClientQuitRes *pReq=(CMessageClientQuitRes*)pMsg;
		pReq->MakeClientQuitMessage(code);
		pMsg->Encode(m_pServer->GetStreamBufWrite());
		pdata=CompactData(pMsg,len);
		m_pThreadLock->UnLock();

		CClient *pClient=m_pServer->GetClientById(index);
		if(pClient)
		{
			cs.dwData=(DWORD)pClient->GetSelfWindow();
			cs.cbData=len;
			cs.lpData=pdata;
			CMisc::GetInstance()->SendDataToOtherWindow(pClient->GetSelfWindow(),&cs);
		}

		SAFE_DELETE_ARRAY(pdata);
	}
	return ret;
}


bool CMessageSenderHelper::SendForceQuitRes(int playerIndex)
{
	bool ret=true;
	COPYDATASTRUCT cs;
	char *pdata=NULL;
	int len;
	CBaseMessage *pMsg=CMessageMapList::GetInstance()->GetMessageById(e_cmd_client_quit_req);
	if(pMsg)
	{
		m_pThreadLock->Lock();
		CMessageClientQuitRes *pReq=(CMessageClientQuitRes*)pMsg;
		pReq->MakeClientQuitMessage(playerIndex);
		pMsg->Encode(m_pServer->GetStreamBufWrite());
		pdata=CompactData(pMsg,len);
		m_pThreadLock->UnLock();

		CClient *pClient=m_pServer->GetClientById(playerIndex);
		if(pClient)
		{
			cs.dwData=(DWORD)pClient->GetSelfWindow();
			cs.cbData=len;
			cs.lpData=pdata;
			CMisc::GetInstance()->SendDataToOtherWindow(pClient->GetSelfWindow(),&cs);
		}
	
		SAFE_DELETE_ARRAY(pdata);
	}
	return ret;
}


bool CMessageSenderHelper::SendControlClientReq(int playerIndex,int op)
{
	bool ret=true;
	COPYDATASTRUCT cs;
	char *pdata=NULL;
	int len;
	CBaseMessage *pMsg=CMessageMapList::GetInstance()->GetMessageById(e_cmd_control_client_req);
	if(pMsg)
	{
		m_pThreadLock->Lock();
		CMessageControlClientReq *pReq=(CMessageControlClientReq*)pMsg;
		pReq->MakeControlMessage(op);
		pMsg->Encode(m_pServer->GetStreamBufWrite());
		pdata=CompactData(pMsg,len);
		m_pThreadLock->UnLock();

		CClient *pClient=m_pServer->GetClientById(playerIndex);
		if(pClient)
		{
			cs.dwData=(DWORD)pClient->GetSelfWindow();
			cs.cbData=len;
			cs.lpData=pdata;
			CMisc::GetInstance()->SendDataToOtherWindow(pClient->GetSelfWindow(),&cs);
		}

		SAFE_DELETE_ARRAY(pdata);
	}
	return ret;
}


//发送到子窗口
bool CMessageSenderHelper::SendDoGameOperationReq(int playerIndex,int gameOperationProtocolId,int paramLength,char *cmdData)
{
	bool ret=true;
	COPYDATASTRUCT cs;
	char *pdata=NULL;
	int len;
	CBaseMessage *pMsg=CMessageMapList::GetInstance()->GetMessageById(e_cmd_client_do_game_operation_req);
	if(pMsg)
	{
		m_pThreadLock->Lock();
		CMessageDoGameOperationReq *pReq=(CMessageDoGameOperationReq*)pMsg;
		pReq->MakeDoGameOperationMessage(gameOperationProtocolId,paramLength,cmdData);
		pMsg->Encode(m_pServer->GetStreamBufWrite());
		pdata=CompactData(pMsg,len);
		m_pThreadLock->UnLock();

		CClient *pClient=m_pServer->GetClientById(playerIndex);
		if(pClient)
		{
			cs.dwData=(DWORD)pClient->GetSelfWindow();
			cs.cbData=len;
			cs.lpData=pdata;
			CMisc::GetInstance()->SendDataToOtherWindow(pClient->GetSelfWindow(),&cs);
		}

		SAFE_DELETE_ARRAY(pdata);
	}
	return ret;
}


//发送到主窗口的
bool CMessageSenderHelper::SendToWriteData(CClient *pClient,int type,const STRING &account,char *buf,int len)
{
	bool ret=true;
	COPYDATASTRUCT cs;
	char *pdata=NULL;
	CBaseMessage *pMsg=CMessageMapList::GetInstance()->GetMessageById(e_cmd_write_text);
	if(pMsg)
	{		
		m_pThreadLock->Lock();
		CMessageWriteText *pReq=(CMessageWriteText*)pMsg;
		pReq->MakeWriteDataMessage(type,account,buf,len);
		pMsg->Encode(pClient->GetStreamBufEncode());	//客户端要用自己的发送缓冲
		pdata=CompactData(pMsg,len);
		m_pThreadLock->UnLock();

		if(pClient)
		{
			cs.dwData=(DWORD)pClient->GetSelfWindow();
			cs.cbData=len;
			cs.lpData=pdata;
			CMisc::GetInstance()->SendDataToOtherWindow(pClient->GetMainWindow(),&cs);	//主窗口
		}

		SAFE_DELETE_ARRAY(pdata);
	}
	return ret;
}
