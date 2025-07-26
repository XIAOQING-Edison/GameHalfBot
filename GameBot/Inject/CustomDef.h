#pragma once
#include <windows.h>
#include <assert.h>
#include <tchar.h>
#include <WINSOCK2.H>

static const int LEFTFRAMEWIDTH = 270;
static const int FUNCNAMELEN = 50;
static const TCHAR* CLIENT_WNDCLASSNAME = _T( "WPEX_CLIENT_WNDCLASS_%u" );
enum WPEX_STATUS {WPEX_START, WPEX_STOP};

static const int WM_DLLDATA = WM_USER + 100;
static const int WM_STARTWPEX = WM_USER + 101;
static const int WM_STOPWPEX = WM_USER + 102;

struct SOCKETDATA
{
	BOOL bSend;
    DWORD cbSize;
    DWORD dwPID;
    SOCKET s;
    WSAPROTOCOL_INFO WSAProtocloInfo;
    sockaddr_in srcsockaddr;
    sockaddr_in destsockaddr;
    TCHAR sFuncName[FUNCNAMELEN];
    DWORD dwDataLen;
    BYTE lpData[1];
};

enum SENDMODEL
{
	SEND_BY_CONBINUOUSLY,	// 持续发送
	SEND_BY_TIMES			// 按次发送
};

enum SENDTYPE
{
	SEND_BY_RAWSOCKET,		// 使用原始SOCKET发送
	SEND_BY_NEWSOCKET		// 使用新SOCKET发送
};

//需要显示的某个函数，使能就显示，不使能就不显示
#define SHOW_FLAG	(1<<0)	//默认是send
#define SHOW_SEND_FLAG	SHOW_FLAG
#define SHOW_RECV_FLAG	(1<<1)
#define SHOW_SEND_TO_FLAG	(1<<2)
#define SHOW_RECV_FROM_FLAG	(1<<3)
#define SHOW_WSA_SEND_FLAG	(1<<4)
#define SHOW_WSA_RECV_FLAG	(1<<5)
#define SHOW_WSA_SEND_TO_FLAG	(1<<6)
#define SHOW_WSA_RECV_FROM_FLAG	(1<<7)