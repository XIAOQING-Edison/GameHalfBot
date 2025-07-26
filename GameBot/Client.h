#pragma once

#include "./Global/public.h"
#include "./MemoryStream/StreamReadWrite.h"
#include "./Message/InfoPlayerInfoStatus.h"
class CPlayer;
class CItemGrid;
class CCurrency;
class CClient
{
public:
	CClient(void);
	~CClient(void);

	void SetPlayer(CPlayer *p){m_pPlayer=p;}
	CPlayer *GetPlayer(){return m_pPlayer;}

// 	void ResetBufWritePosition(){m_pStreamBufSend->SetHandlePos(0);m_pStreamBufSend->SetBufPos(0);}

	void SetMainWindow(HWND hMain){m_hMainControlWin=hMain;}
	HWND GetMainWindow(){return m_hMainControlWin;}

	void SetSelfWindow(HWND hwnd){m_hSelfWin=hwnd;}
	HWND GetSelfWindow(){return m_hSelfWin;}

	bool DoReadyWork();	//�����߳���

	int GetIndex(){return m_index;}
	void SetIndex(int index){m_index=index;}

	CInfoPlayerInfoStatus *GetPlayerStatus(){return &m_playerStatus;}
	STRING GetTaskStatus(){return m_playerStatus.taskName;}

	void UpdatePlayerInfoStatus(CInfoPlayerInfoStatus *pInfo);
	void UpdatePlayerInfoToPlayerInfoStatus();	//��CPlayer���״̬��ֵ��m_playerInfoStatus����
	DWORD GetMessageThreadId(){return m_messageThreadId;}

	CStreamReadWrite *GetStreamBufEncode(){return m_pStreamBufSend;}
	bool IsPlayerQuit();

	void IncLiveTime();
	void DecLiveTime();

	int GetLiveTime(){return m_liveTime;}	
private:	

	bool CreateMessageThread();
	bool CreateTimerThread();

	void SetCmd(int cmd){m_cmd=cmd;}
	int GetCmd(){return m_cmd;}

	void SetMessageThreadId(DWORD id){m_messageThreadId=id;}

	void DoActionByCmd(int cmd);

	void AssignPlayerIsTeamLeader();

	static DWORD WINAPI ThreadMessage(LPVOID p);	//��Ϣ�߳�
	static DWORD WINAPI ThredTimer(LPVOID p);	//��ʱ���߳�
private:
	HWND m_hMainControlWin;	//����,�ͻ�������ͨ�ŵġ�����ɻ���socket
	HWND m_hSelfWin;	//����ľ��
	CPlayer *m_pPlayer;
	CStreamReadWrite *m_pStreamBufRecv;
	CStreamReadWrite *m_pStreamBufSend;
	HANDLE m_hThreadMessage;
	int m_cmd;	//��ʱ����
	DWORD m_messageThreadId;

	HANDLE m_hThreadTimer;

	int m_liveTime;
	int m_index;	//�±����ڿͻ������ڿ���

	CInfoPlayerInfoStatus m_playerStatus;	//�����õ���Ϣ
	INT64 m_materialData[64];	//��������
	int m_materialCount;	//Ҫ��ʾ�Ĳ�����
	STRING m_taskStatus;	//������

};
