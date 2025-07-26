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

	int UpdateClientHwnd(HWND hClient,int index);	//����һ��������±꣬���������·���Ҳ�������������

	void DeleteClient(int index);
	
	void ClearClients();

	void SendToMainWindowToWriteText(int type,const STRING &account,char *msg,int len);	//����type������дʲô
	void SendToMainWindowToWriteLog(const STRING &account,char *msg,int len);	//д��־
	void SendToUpdateReportData(int index,int *data,int count);	//��������

	CClient *GetClientById(int index);	//ȡ�ö�Ӧ�±���ʺŽ�ɫָ��
	int GetAvailableClientIndex();	//�ҵ�һ�����ʵ��±����

	CClient *GetClientByHwnd(HWND hwnd);	//�ҳ��ͻ����

	void DecAllPlayerLiveTime();

	void IncClientLiveTime(int index);
	void DecClientLiveTime(int index);

	void DecodeMessage(HWND hClient,char *data,int len);

	void HandleMessage(HWND hClient,CBaseMessage *pMsg);

	static DWORD WINAPI ThreadHeartBeat(LPVOID p);

	bool ExecuteClientApp(const TCHAR *szAppName,TCHAR *szCommandLine);	//ִ��

	CStreamReadWrite *GetStreamBufWrite(){return m_pStreamBufWrite;}
	CStreamReadWrite *GetStreamBufRead(){return m_pStreamBufRead;}

	void SendQuitMessageToClients();

	void CopyMsgToStreamRead(HWND hClient,char *data,int len);

	static DWORD WINAPI ThreadMessageHandle(LPVOID p);	//������Ϣ���߳�
	static DWORD WINAPI ThreadTask(LPVOID p);	//ִ��������߳�

	void WakeupToHandleMessage(){SetEvent(m_hEvtMessageDecode);}
	void WakeupToDoTask(){SetEvent(m_hEvtDoTask);}

	void CreateEvents();	//�����¼�����
	bool CreateMessageHandleThread();//������Ϣ�����߳�
	bool CreateTaskThread();	//���������߳�

	HANDLE GetEvtTask(){return m_hEvtDoTask;}
	HANDLE GetEvtMessageHandle(){return m_hEvtMessageDecode;}

	void Decode();	//������Ϣ

	void Init();

	void SetExeFullPath(STRING &path){m_appPath=path;}
	//void SetListCtrl(CListCtrl *pList){m_pListPlayers=pList;}
private:
	void CheckClientExist();	//���ͻ����Ƿ񻹴���

	bool RunClientApp();

private:
	vector<CClient*> m_clientList;
	CThreadLock *m_pThreadLock;
	CThreadLock *m_pThreadDataLock;	//������������cserver���ڲ�����
	CStreamReadWrite *m_pStreamBufWrite;
	CStreamReadWrite *m_pStreamBufRead;
	HANDLE m_hEvtMessageDecode;
	HANDLE m_hEvtDoTask;

	HANDLE m_hThreadDoTask;
	HANDLE m_hThreadMessageHandle;
	bool m_bQuit;

// 	vector<int> m_runAppIndexs;	//��Ҫ������APP�±������
	STRING m_appPath;	//�趨·��
	//CListCtrl *m_pListPlayers;	//��ҿؼ�

};
