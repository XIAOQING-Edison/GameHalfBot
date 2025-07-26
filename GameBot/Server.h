#pragma once

#include "./Global/public.h"
#include "Player.h"
#include "./Util/ThreadLock.h"
#include "./Message/BaseMessage.h"
#include "Client.h"

class CServer
{
public:
	CServer(void);
	~CServer(void);

	void SetIsQuit(bool b){m_bQuit=b;}
	bool IsQuit(){return m_bQuit;}


	void AddPlayerToClientList(CPlayer *p);

	int UpdateClientHwnd(HWND hClient,int index);	//返回一个分配的下标，可能是重新分配也可能是用申请的

	void DeleteClient(int index);
	
	void ClearClients();

	void SendToMainWindowToWriteText(int type,const STRING &account,char *msg,int len);	//根据type来决定写什么
	void SendToMainWindowToWriteLog(const STRING &account,char *msg,int len);	//写日志
	void SendToUpdateReportData(int index,int *data,int count);	//更新数据

	CClient *GetClientById(int index);	//取得对应下标的帐号角色指针
	int GetAvailableClientIndex();	//找到一个合适的下标分配

	CClient *GetClientByHwnd(HWND hwnd);	//找出客户句柄

	void DecAllPlayerLiveTime();

	void IncClientLiveTime(int index);
	void DecClientLiveTime(int index);

	void DecodeMessage(HWND hClient,char *data,int len);

	void HandleMessage(HWND hClient,CBaseMessage *pMsg);

	static DWORD WINAPI ThreadHeartBeat(LPVOID p);

	bool ExecuteClientApp(const TCHAR *szAppName,TCHAR *szCommandLine);	//执行

	CStreamReadWrite *GetStreamBufWrite(){return m_pStreamBufWrite;}
	CStreamReadWrite *GetStreamBufRead(){return m_pStreamBufRead;}

	void SendQuitMessageToClients();

	void CopyMsgToStreamRead(HWND hClient,char *data,int len);

	static DWORD WINAPI ThreadMessageHandle(LPVOID p);	//处理消息的线程
	static DWORD WINAPI ThreadTask(LPVOID p);	//执行任务的线程

	void WakeupToHandleMessage(){SetEvent(m_hEvtMessageDecode);}
	void WakeupToDoTask(){SetEvent(m_hEvtDoTask);}

	void CreateEvents();	//创建事件变量
	bool CreateMessageHandleThread();//创建消息处理线程
	bool CreateTaskThread();	//创建任务线程

	HANDLE GetEvtTask(){return m_hEvtDoTask;}
	HANDLE GetEvtMessageHandle(){return m_hEvtMessageDecode;}

	void Decode();	//解码消息

	void Init();

	void SetExeFullPath(STRING &path){m_appPath=path;}
	//void SetListCtrl(CListCtrl *pList){m_pListPlayers=pList;}
private:
	void CheckClientExist();	//检测客户端是否还存在

	bool RunClientApp();

private:
	vector<CClient*> m_clientList;
	CThreadLock *m_pThreadLock;
	CThreadLock *m_pThreadDataLock;	//这里用来保护cserver的内部变量
	CStreamReadWrite *m_pStreamBufWrite;
	CStreamReadWrite *m_pStreamBufRead;
	HANDLE m_hEvtMessageDecode;
	HANDLE m_hEvtDoTask;

	HANDLE m_hThreadDoTask;
	HANDLE m_hThreadMessageHandle;
	bool m_bQuit;

// 	vector<int> m_runAppIndexs;	//将要启动的APP下标存下来
	STRING m_appPath;	//设定路径
	//CListCtrl *m_pListPlayers;	//玩家控件

};
