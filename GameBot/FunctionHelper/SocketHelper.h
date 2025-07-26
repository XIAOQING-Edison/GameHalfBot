#pragma once
#include "../Global/public.h"
#include "../ProtocolMap.h"


#include "../MemoryStream/StreamReadWrite.h"	//用来代替原来的字节读取


#include<WinSock.h>
#include <WinSock2.h>

#pragma comment(lib,"ws2_32.lib")
class CPlayer;

//#define USE_WSS_SOCKET	//使能WSS

#define  USE_SOCKET_NON_BLOCK	//是否使用阻塞的socket,定义了这个会使能ioctl

class CSocketHelper
{
public:
	CSocketHelper(void);
	~CSocketHelper(void);

	void CloseAllObjects();

	void Init();

	void ResetWebSocket();
public:	//get /sets
	void SetPlayer(CPlayer *p){m_pThisPlayer=p;}
	CPlayer *GetPlayer(){return m_pThisPlayer;}

	bool IsPlayerQuit();

// 	void GotoMainGameUrl(){m_webLoginHelper.GotoMainGameUrl();}

	CStreamReadWrite *GetStreamBufRead(){return m_pStreamBufRecv;}
	CStreamReadWrite *GetStreamBufWrite(){return m_pStreamBufEncode;}



public://test
	void SetCaptureNow(bool b){m_bCaptureNow=b;}
	bool IsCaptureNow(){return m_bCaptureNow;}
private:
	//是否定时抓包的标志
	bool m_bCaptureNow;
public:
	//普通socket
	void SetSocket(SOCKET s){m_playerSocket=s;}	//把游戏socket复制下来
	SOCKET GetSocket(){return m_playerSocket;}

	bool SetSocketOptBlock(bool bNonBlock);	//设定socket是否阻塞

public:	//其它类接口
		
	void ClosePlayerSocket(){SAFE_CLOSE_SOCKET(m_playerSocket);}
public:


public:	//send functions
	bool SendSetPkMode(int mode);	//设定pk模式
	//bool Send
public://收发包用的函数
	bool SendData(char *pData,int totalLength);	//这里循环调用send直到发送完成

	char *CompactData(CProtocol *p,int &len);	//这里计算protocol原始长度，在发送这前计算总长度和加入sign_byte

	bool ReceiveServerMessage();	//用于接收服务器返回的数据包

public://static functions;

	static DWORD WINAPI ThreadProcessTask(LPVOID pParam);	//用于读取并处理任务的线程

private:	//辅助类对象

private:
	SOCKET m_playerSocket;	//普通socket
	short m_port;

	CPlayer *m_pThisPlayer;	//当前角色
private:	//各种线程，事件对象
// 	HANDLE m_hEvtPlay;
	// 	HANDLE m_hEvtRecv;	//收到消息再唤醒接收线程
	HANDLE m_hThreadPlay;
	HANDLE m_hThreadRecv;
private:
	CStreamReadWrite *m_pStreamBufRecv;	//用来处理接收
	CStreamReadWrite *m_pStreamBufEncode;	//用来编码协议

};
