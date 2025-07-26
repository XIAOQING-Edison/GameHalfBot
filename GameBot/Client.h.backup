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

	bool DoReadyWork();	//创建线程类

	int GetIndex(){return m_index;}
	void SetIndex(int index){m_index=index;}

	CInfoPlayerInfoStatus *GetPlayerStatus(){return &m_playerStatus;}
	STRING GetTaskStatus(){return m_playerStatus.taskName;}

	void UpdatePlayerInfoStatus(CInfoPlayerInfoStatus *pInfo);
	void UpdatePlayerInfoToPlayerInfoStatus();	//将CPlayer里的状态赋值到m_playerInfoStatus里面
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

	static DWORD WINAPI ThreadMessage(LPVOID p);	//消息线程
	static DWORD WINAPI ThredTimer(LPVOID p);	//定时器线程
private:
	HWND m_hMainControlWin;	//主控,客户端与他通信的。后面可换成socket
	HWND m_hSelfWin;	//自身的句柄
	CPlayer *m_pPlayer;
	CStreamReadWrite *m_pStreamBufRecv;
	CStreamReadWrite *m_pStreamBufSend;
	HANDLE m_hThreadMessage;
	int m_cmd;	//现时命令
	DWORD m_messageThreadId;

	HANDLE m_hThreadTimer;

	int m_liveTime;
	int m_index;	//下标用于客户端用于控制

	CInfoPlayerInfoStatus m_playerStatus;	//测试用的信息
	INT64 m_materialData[64];	//材料详情
	int m_materialCount;	//要显示的材料数
	STRING m_taskStatus;	//测试用

};
