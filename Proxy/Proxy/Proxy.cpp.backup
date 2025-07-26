// Proxy.cpp : 定义 DLL 应用程序的导出函数。
//
#include "Proxy.h"


#include "Util/MessageSenderHelper.h"



#include "Misc/HookHelper.h"	//封包型需要这个东西
#include "Misc/Misc.h"
#include "Util/ShareMemory.h"
#include "FileTools/FileHelper.h"
#include "ProtocolMap.h"
#include "Player.h"
#include "Client.h"	//用来向主窗口发送消息
#include "IPCWindow/IPCWindow.h"
#include "CrashHelper/CrashHelper.h"
#pragma comment(lib,"ws2_32.lib")

CALLBAK_DATA g_recvCallback;
CALLBAK_DATA g_sendCallback;

//全局对象
CPlayer *g_pPlayer=NULL;
CShareMemory *g_pShareMemory=NULL;
CClient *g_pClient=NULL;
HWND g_IPCWindow= NULL;	//通讯窗口
HHOOK g_msgHook=NULL;	//消息钩子
DWORD WINAPI ThreadCreateIPCWindow(LPVOID p);	//函数声明

#ifdef __cplusplus
extern "C"{
	PROXY_API  CALLBAK_DATA* WINAPI RecvCallback(SOCKET s,char* payload,DWORD payloadLength,DWORD bufLength)
	{
		bool bIsModify=false;	//这里调用类的修改来决定是否修改
		//暂时不作修改
		//将包内容放到接收缓冲区处理
		//是已找到需要的socket才处理

		if(CHookHelper::GetInstance()->IsSameMainGameSocket(s))
		{
			//TRACE_OUTPUT(_T("Hook收包长度:%d\n"),payloadLength);
			//TRACE_OUTPUT(_T("Hook收包内容:%s\n"),HexArrayToString(payLoad,payloadLength).c_str());
			g_recvCallback.newPayloadLength=CHookHelper::GetInstance()->HandleRecv(s,payload,payloadLength,bufLength,&g_recvCallback.newPayload,bIsModify);
		}
		if(!bIsModify)
		{
			return NULL;
		}
		//TRACE_OUTPUT(_T("接收包被修改了!!内容:%s\n"),HexArrayToString(g_recvCallback.newPayload,g_recvCallback.newPayloadLength).c_str());
		return &g_recvCallback;
	}


	//一般这里用作截取登陆包来获得使用哪个socket来发送
	PROXY_API  CALLBAK_DATA* WINAPI SendCallback(SOCKET s,char* payload,DWORD payLoadLength)
	{
		bool bIsModify=false;	//这里调用类的修改来决定是否修改
		//暂时不作修改处理
		//将包数据放到socketHelper里判断包内容
		if(payLoadLength>0)
		{
			g_sendCallback.newPayloadLength=CHookHelper::GetInstance()->HandleSend(s,payload,payLoadLength,&g_sendCallback.newPayload,bIsModify);		
		}
		
		if(!bIsModify)
			return NULL;
		//TRACE_OUTPUT(_T("发送包被修改了!!内容:%s\n"),HexArrayToString(g_sendCallback.newPayload,g_sendCallback.newPayloadLength).c_str());
		return &g_sendCallback;
	}
#endif // cplusplus




#ifdef __cplusplus
}
#endif // _cplusplus

#ifdef __cplusplus
extern "C"{

PROXY_API void Start()	//开始或继续
{
	if(g_pPlayer)
		g_pPlayer->SetStop(false);
}

PROXY_API void Quit()	//退出
{
	if(g_pPlayer)
		g_pPlayer->SetQuit(true);
}

PROXY_API void Pause()	//暂停
{
	if(g_pPlayer)
		g_pPlayer->SetStop(true);
}

PROXY_API void CreateIPCWindowByThread()
{
	HANDLE hThread;
	DWORD tid;
	HANDLE hModule=GetCurrentModuleHandle();
	hThread=CreateThread(NULL,0,ThreadCreateIPCWindow,hModule,0,&tid);
	CloseHandle(hThread);
}

#endif // cplusplus

#ifdef __cplusplus
}
#endif // _cplusplus

void InitGlobalObjects()
{
	//SetUnhandledExceptionFilter(CCrashHelper::InstallUnhandleExceptionFilter);
	g_pPlayer=new CPlayer;
	g_pShareMemory=new CShareMemory(512,false);
	g_pShareMemory->CreateShareMemory(g_szSharedMemoryName);
	g_pClient=new CClient;
	g_pClient->SetPlayer(g_pPlayer);

	g_pPlayer->SetClient(g_pClient);
}


void DeleteGlobalObjects()
{	
	Quit();
	delete g_pClient;
	delete g_pPlayer;
	delete g_pShareMemory;
}


BOOL InitObjects()
{
	InitGlobalObjects();

	HWND hwndMain;
	g_pShareMemory->ReadShreadMemoryByOffset((char*)&hwndMain,0,sizeof(HWND));
	g_pClient->SetMainWindow(hwndMain);	//获得主窗口句柄

	int count;
	g_pShareMemory->ReadShreadMemoryByOffset((char*)&count,1*sizeof(int),sizeof(int));
// 	if(count != g_maxCount)
// 	{
// 		//TRACE_OUTPUT(_T("职业:%d和%d不符合?????????????????\n"),g_maxCount,count);
// 		return FALSE;
// 	}
// 
// 	if(g_pClient->CheckTimeExpired())
// 	{
// 		return FALSE;
// 	}
// 
	CFileHelper::GetInstance();
	CProtocolMap::GetInstance()->InitProtocolMap();	//协议
	CHookHelper::GetInstance()->SetPlayer(g_pPlayer);	//设定玩家指针
	CMisc::GetInstance()->SetHwndMain(hwndMain);	//设定主控窗口

	CMessageMapList::GetInstance()->InitMessageList();
	CMessageSenderHelper::GetInstance();	//进程通信
	return TRUE;
}


//创建线程建立窗口
BOOL CreateIPCWindow(HINSTANCE hInst)
{
	STRING clsName=_T("MUEditor");
	STRING title=_T("MyMuEditor");	

	g_IPCWindow=CreateMessageWindow(hInst,title,clsName,100,100);

	g_pClient->SetSelfWindow(g_IPCWindow);
	if(!g_IPCWindow)
	{
		TRACE_OUTPUT(_T("创建窗口失败!错误号:%d\n"),GetLastError());
	}
	else
	{
		TRACE_OUTPUT(_T("发送到主窗口\n"));
		::SendMessage(g_IPCWindow,WM_SELF_HANDLE_MSG,0,0);
	}
	return MessageLoop(hInst);
}


DWORD WINAPI ThreadCreateIPCWindow(LPVOID p)
{
	CreateIPCWindow((HINSTANCE)p);
	return 0;
}

BOOL DeleteIPCWindow()
{
	if(g_IPCWindow)
		::SendMessage(g_IPCWindow,WM_DESTROY,0,0);
	return FALSE;
}


BOOL ClearObjects()
{
	DeleteGlobalObjects();

	CMessageMapList::DeleteInstance();
	CMessageSenderHelper::DeleteInstance();
	CMisc::DeleteInstance();
	CHookHelper::DeleteInstance();
	CProtocolMap::DeleteInstance();	
	CFileHelper::DeleteInstance();

	return TRUE;
}




BOOL APIENTRY DllMain( HMODULE hModule,
					  DWORD  ul_reason_for_call,
					  LPVOID lpReserved
					  )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		InitObjects();
		CreateIPCWindowByThread();
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
// 		TRACE_OUTPUT(_T("DLL_PROCESS_DETACH\n"));
		DeleteIPCWindow();
		ClearObjects();
		break;
	}
	return TRUE;
}




HWND CreateMessageWindow(HMODULE hModule,STRING &title,STRING &szClassName,int w,int h)
{
	HWND hwnd=NULL;
	HINSTANCE hInst=(HINSTANCE)hModule;
	if(!RegisterMessageWindow(hModule,szClassName))
	{
		TRACE_OUTPUT(_T("注册窗口失败!!错误:%d\n"),GetLastError());
		return false;
	}
	hwnd = CreateWindow(szClassName.c_str(),title.c_str(),
		WS_EX_APPWINDOW|WS_POPUP,CW_USEDEFAULT,CW_USEDEFAULT,w,h,NULL,NULL,hInst,NULL);


	//显示并更新窗口 
	ShowWindow(hwnd,SW_SHOW);
	UpdateWindow(hwnd);
	return hwnd;
	
}


bool RegisterMessageWindow(HINSTANCE hInst,STRING &szClassName)
{
	WNDCLASS       wndclass;
	//设计窗口类
	wndclass.style          = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc    = WndProc;
	wndclass.cbClsExtra     = 0;
	wndclass.cbWndExtra     = 0;
	wndclass.hInstance      = hInst;
	wndclass.hIcon          = LoadIcon(NULL,IDI_APPLICATION);
	wndclass.hCursor        = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground  = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName   = NULL;
	wndclass.lpszClassName  = szClassName.c_str();

	//注册窗口
	if(!RegisterClass(&wndclass))
	{
		return false;
	}

	return true;
}

bool UnRegisterWindow(HINSTANCE hInst)
{
	bool ret=false;
	STRING clsName=_T("MUEditor");
	UnregisterClass(clsName.c_str(),hInst);
	return ret;
}

WPARAM MessageLoop(HINSTANCE hInst)
{
	MSG msg;
	TRACE_OUTPUT(_T("进入消息循环\n"));
	while(GetMessage(&msg, NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//UnRegisterWindow(hInst);
	return msg.wParam;

}



LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC         hdc;
	PAINTSTRUCT ps;
	RECT        rect;
	COPYDATASTRUCT *pCopyData;	//COPY DATA消息这个主要结构
	switch(message)
	{
	case WM_CREATE:
		//TRACE_OUTPUT(_T("收到创建消息!\n"));
		return 0;
	case WM_SELF_HANDLE_MSG:	//这个是自己定义的消息，创建完成就发送这个消息
		//TRACE_OUTPUT(_T("收到自定义消息\n"));
		CMessageSenderHelper::GetInstance()->SendLoginReq(g_pClient);
		return 0;
	case WM_PAINT:
		{
			hdc = BeginPaint(hwnd,&ps);
			GetClientRect(hwnd, &rect);
			DrawText(hdc, TEXT("PC微端助手"), -1, &rect, DT_SINGLELINE|DT_CENTER|DT_VCENTER);
			EndPaint(hwnd,&ps);
			return 0;
		}
		return 0;
	case WM_COPYDATA:
		pCopyData =(COPYDATASTRUCT*)lParam;
		if (pCopyData != NULL)
		{
			g_pClient->DoReadyWork();
			::PostThreadMessage(g_pClient->GetMessageThreadId(),WM_GAME_CONTROL_MSG,1314,0);
		}
		return 0;
	case WM_CLOSE:
		//TRACE_OUTPUT(_T("收到关闭消息\n"));
		return 0;
		break;
	case WM_DESTROY:
		//TRACE_OUTPUT(_T("收到销毁消息\n"));
		PostQuitMessage(0);
		return 0;
	default:
		break;
	}

	return DefWindowProc(hwnd,message,wParam,lParam);

}
