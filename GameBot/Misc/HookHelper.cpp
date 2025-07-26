#include "HookHelper.h"
#include "../ProtocolMap.h"
#include "../Player.h"
#include "../FunctionHelper/GameLogicHelper.h"	//用于控制逻辑
#include "../FunctionHelper/SocketHelper.h"	//收发包

#include "../Config/GameConfig.h"
#include "../Config/GiftHallConfig.h"

#include "Misc.h"
#include <time.h>

#define  PACKET_CAPTURE_ON	0	//抓包标记1是抓包

// #include "../libs/mhook64.lib"


CHookHelper *CHookHelper::s_pHookHelperInstance=NULL;

const int g_hook_modify_count=1;	//需要修改的地方

char g_heartBeatRes[]={0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xF4, 0x00, 0x00, 0x08};
char g_heartBeatReq[0xa]={0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0xfb,0xa9};

char g_createRoleReq[]={0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xED, 0x00, 0x00};

char g_loginMapReq[10] = {	0x00, 0x00, 0x00, 0x0A, 0x00, 0x01, 0x87, 0xCD, 0x00, 0x00};//ReqLoginMap

char g_sendLoginReq[0xa]={0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xe9,0x00,0x00};	//跳过第3字节，因为总长可能不一样
char g_recvLoginRes[0xa]={0x00,0x00,0x00,0x23,0x00,0x00,0x03,0xea,0x00,0x00};	

char g_sendChooseRoleReq[]={0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xef,0x00,0x00};	//后面修改
char g_recvChooseRoleRes[]={0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xef,0x00,0x00};	//角色参数

char g_recvEnterGameRes[]={0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xF2,0x00,0x00};	//长度可能会变，进入游戏回应



WORD g_minPort=2000;	//假设需要的端口是要2000以上的才拦截


// char *TestReadFileTest(const TCHAR *szPath,int &fileLength)
// {
// 	STRING strFile=szPath;//_T("d:\\aa.bin");
// 	DWORD dstLength;
// 	DWORD bytesRead;
// 	HANDLE hFileRead=CreateFile(strFile.c_str(),GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_ARCHIVE,NULL);
// 	if(hFileRead==INVALID_HANDLE_VALUE)
// 	{
// 		MessageBox(NULL,_T("Error when open file\n"),_T("Error"),MB_ICONERROR);
// 		return NULL;
// 	}
// 	DWORD sz,szHigh;
// 	sz=GetFileSize(hFileRead,&szHigh);
// 	fileLength=sz;
// 	BYTE *pReadBuf=new BYTE[sz];
// 	ReadFile(hFileRead,pReadBuf,sz,&bytesRead,NULL);
// 
// 	char *data=(char*)pReadBuf;
// 	SAFE_CLOSE_HANDLE(hFileRead);
// 	return data;
// 
// }

bool TestWriteFileTest(const TCHAR *szPath,char *data,int len)
{
	bool ret=false;
	STRING strFile=szPath;//_T("d:\\aa.bin");
	HANDLE hFile=CreateFile(strFile.c_str(),GENERIC_WRITE,FILE_SHARE_READ,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_ARCHIVE,NULL);
	if(hFile==INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL,_T("Error when write file\n"),_T("Error"),MB_ICONERROR);
		return false;
	}
	DWORD bytesWrote;
	ret=WriteFile(hFile,data,len,&bytesWrote,NULL);
	SAFE_CLOSE_HANDLE(hFile);
	return ret;
}


CHookHelper::CHookHelper(void)
{
	SetPlayer(NULL);
	Reset();
	m_pStreamBufRecv=new CStreamReadWrite(E_ENDIAN_TYPE_BIG_ENDIAN,MAX_STACK_BUF_LENGTH);
	m_pStreamBufSend=new CStreamReadWrite(E_ENDIAN_TYPE_BIG_ENDIAN,MAX_STACK_BUF_LENGTH);
	m_pRecvBuf=new char[MAX_STACK_BUF_LENGTH*0x10];	//64k接收缓冲
	m_pSendBuf=new char[MAX_STACK_BUF_LENGTH];	//4k发送缓冲
	m_pTmpRecvBuf=new char[MAX_STACK_BUF_LENGTH*0x10];	//临时接收

}

CHookHelper::~CHookHelper(void)
{
	SAFE_DELETE_ARRAY(m_pSendBuf);
	SAFE_DELETE_ARRAY(m_pRecvBuf);
	SAFE_DELETE_ARRAY(m_pTmpRecvBuf);
	SAFE_DELETE_POINTER(m_pStreamBufRecv);
	SAFE_DELETE_POINTER(m_pStreamBufSend);
}




CHookHelper *CHookHelper::GetInstance()
{
	CHookHelper *pInst=NULL;
	if(!CHookHelper::s_pHookHelperInstance)
	{
		CHookHelper::s_pHookHelperInstance=new CHookHelper;
	}
	pInst=CHookHelper::s_pHookHelperInstance;

	return pInst;

}


void CHookHelper::DeleteInstance()
{
	SAFE_DELETE_POINTER(CHookHelper::s_pHookHelperInstance);
}


void CHookHelper::CheckAndSetSocket(SOCKET s,const char *ip,WORD port)	//设定所需要的socket
{
	
	if(port==GetMainServerPort()&& ip==GetMainServerIp())
	{
		SetMainServerSocket(s);
		m_pPlayer->GetSocketHelper()->SetSocket(s);
	}

	if(port==m_crossServerPort&& ip==GetCrossServerIp())
	{
		SetCrossServerSocket(s);
		//m_pPlayer->GetCrossPlayer()->GetSocketHelper()->SetSocket(s);
	}
}

void CHookHelper::Reset()	//实始化各种变量，这里可能需要外部调用
{
	m_crossServerSocket=INVALID_SOCKET;
	m_crossServerPort=0;
	m_crossServerIp="";

	m_mainServerSocket=INVALID_SOCKET;
	m_mainServerIp="";
	m_mainServerPort=0;

	m_duplicateSocket=INVALID_SOCKET;

	SetHooked(false);

}

void CHookHelper::ResetSocketAndStreamBuf()	//断开时所有东西重置
{
	ResetCrossServerSocket();

	m_mainServerSocket=INVALID_SOCKET;
	m_mainServerIp="";
	m_mainServerPort=0;

	CStreamReadWrite *pStreamBuf=m_pPlayer->GetSocketHelper()->GetStreamBufRead();
	pStreamBuf->SetBufPos(0);
	pStreamBuf->SetHandlePos(0);
	
}

void CHookHelper::ResetCrossServerStreamBuffer()
{
// 	CStreamReadWrite *pStreamBuf=m_pPlayer->GetCrossPlayer()->GetSocketHelper()->GetStreamBufRead();
// 	pStreamBuf->SetBufPos(0);
// 	pStreamBuf->SetHandlePos(0);
}

void CHookHelper::ResetCrossServerSocket()	//退出跨服时重置
{
	m_crossServerSocket=INVALID_SOCKET;
	m_crossServerPort=0;
	m_crossServerIp="";

}

bool CHookHelper::IsInGameServer()
{
	return ((int)m_mainServerSocket>0) || ((int)m_crossServerSocket>0);
}


void CHookHelper::CheckSocketState(SOCKET s)	//检测socket状态
{
	int err = WSAGetLastError();
	bool bNeedReset=false;
	if(err == WSAEWOULDBLOCK)
	{
		return;
	}
	else
	{
		printf("check socket state error:%d\n",err);
		if(s==GetMainServerSocket())
		{
// 			m_pPlayer->SetDisconnectReason(e_disconnect_by_server);
// 			Reset();
			bNeedReset=true;
		}
		else if(s==GetCrossServerSocket() &&s !=INVALID_SOCKET)
		{

		}
	}
	if(bNeedReset)
	{
		m_pPlayer->SetDisconnectReason(e_disconnect_by_server);
		CMisc::GetInstance()->SendMsgToMainHwnd(WM_SELF_HANDLE_MSG,e_msg_type_connect_info,(LPARAM)m_pPlayer);
		Reset();

	}
}



int CHookHelper::HandleRecv(SOCKET s,char *buf,int len,int bufLength,char **newBuf,bool &bIsModify)	//这里会进行修改或解析操作,返回newlen
{
	int newLength=len;
	bool ret=false;
	struct sockaddr_in sa;	//用来getpeer

	int handleLength=0;
	int zeroLen=0;	
	int saLen = sizeof(sa);
	string ip;
	WORD port=0;

	if(!m_pPlayer->IsLoginAlready() && m_pPlayer->IsRoleChosenAlready() && m_pPlayer->IsInGameAlready())	//login=false,其它为true则表示断线了
	{
		if(!getpeername(s,(struct sockaddr *)&sa, &saLen))
		{
			ip=inet_ntoa(sa.sin_addr);
			port=ntohs(sa.sin_port);
		}
		if(GetMainServerIp()==ip && GetMainServerPort()==port)
		{
			TRACE_OUTPUT(_T("Recv获得断线重连socket:%x\n"),s);
			SetMainServerSocket(s);
			m_pPlayer->SetLoginAlready(true);
			m_pPlayer->GetSocketHelper()->SetSocket(s);
		}
		else
		{
			TRACE_OUTPUT(_T("断线后拦截到socket信息---ip:%s,port:%d\n"),GBKToUnicode(ip.c_str()).c_str(),port);
		}
	}

EXT:
	return newLength;
}



int CHookHelper::HandleSend(SOCKET s,char *buf,int len,char **newBuf,bool &bIsModify)	//这里会修改发送操作,返回newlen
{
	int newLength=len;
	struct sockaddr_in sa;	//用来getpeer
	int zeroLen=0;	
	int saLen = sizeof(sa);
	string ip;
	WORD port=0;
	const char cmpBuf[]={0x00,0x00,0x00,0x0a};

	if(!m_pPlayer->IsLoginAlready() && len<0xff )	//还没找到登陆包时,假定登陆包总是小于0xff字节
	{
// 		TRACE_OUTPUT(_T("Hook发包内容:%s\n"),HexArrayToString(buf,len).c_str());
		if(m_pPlayer->IsRoleChosenAlready() && m_pPlayer->IsInGameAlready())	//login=false,其它为true则表示断线了
		{
			if(!getpeername(s,(struct sockaddr *)&sa, &saLen))
			{
				ip=inet_ntoa(sa.sin_addr);
				port=ntohs(sa.sin_port);
			}
			if(GetMainServerIp()==ip && GetMainServerPort()==port)
			{
				//TRACE_OUTPUT(_T("Hook断线重连发包内容:%s\n"),HexArrayToString(buf,len).c_str());
				TRACE_OUTPUT(_T("获得断线重连socket:%x\n"),s);
				SetMainServerSocket(s);
				m_pPlayer->SetLoginAlready(true);
				m_pPlayer->GetSocketHelper()->SetSocket(s);
			}
		}
		else if(CHookHelper::GetInstance()->CheckIsSendLoginMessage(buf,len))
		{
			//发送登陆，把登陆参数取出来
			m_pPlayer->SetLoginAlready(false);
			m_pPlayer->SetChooseRoleAlreay(false);
			m_pPlayer->SetInGameAlready(false);
			TRACE_OUTPUT(_T("检测到发送登陆包,socket:0x%x\n"),s);
			CHookHelper::GetInstance()->SetMainServerSocket(s);
// 			if(CHookHelper::GetInstance()->DuplicateSocket(s) && CHookHelper::GetInstance()->CreateDuplicateSocket())//duplicate socket也发不出来
// 			{
// 				m_pPlayer->GetSocketHelper()->SetSocket(m_duplicateSocket);
// 				m_pPlayer->GetSocketHelper()->SetSocketOptBlock(true);
// 			}
// 			else
			{
				//test
// 				int nNetTimeout=10;//10ms，
// 				//设置发送超时
// 				setsockopt(s,SOL_SOCKET,SO_SNDTIMEO,(char *)&nNetTimeout,sizeof(int));
				m_pPlayer->GetSocketHelper()->SetSocket(s);
			}


			if(!getpeername(s,(struct sockaddr *)&sa, &saLen))
			{
				ip=inet_ntoa(sa.sin_addr);
				port=ntohs(sa.sin_port);
			}
			else
			{
				TRACE_OUTPUT(_T("取得ip对应信息socket发生错误,代码:%x\n"),WSAGetLastError());
				goto EXT;
			}

		}
	
	}
	else if(GetMainServerSocket()==s)	//抓发包时打开
	{

	}
	else
	{
	}
	
EXT:
	return newLength;
}



bool CHookHelper::IsSameMainGameSocket(SOCKET s)	//是否是主socket,这里是登陆用的socket
{
	return IsMainSocketValid() && (GetMainServerSocket()==s);
}


bool CHookHelper::CheckIsSendLoginMessage(const char *data,int len)	//检查是否是登陆包
{
	bool ret=false;
	m_pStreamBufSend->SetBufPos(0);
	m_pStreamBufSend->SetHandlePos(0);
	m_pStreamBufSend->CopyBufAndLength((char*)data,len);
	int packageLength=m_pStreamBufSend->ReadFixedInt32();	//4字节固定长度
	int cmpLen1=3;	//比较前3字节
	int cmpLen2=sizeof(g_sendLoginReq)-cmpLen1-1;	//跳过长度某个字节		
	//TRACE_OUTPUT(_T("Hook发包成功!长度:%d,数据:%s\n"),len,HexArrayToString(data,len).c_str());
	if(packageLength<0xff && len<0xff)
	{
// 		TRACE_OUTPUT(_T("检测游戏发包在合法范围,长度:%d\n"),packageLength);
		if(memcmp(g_sendLoginReq,data,cmpLen1)==0&& memcmp(data+cmpLen1+1,g_sendLoginReq+cmpLen1+1,cmpLen2)==0)
		{
// 			TRACE_OUTPUT(_T("检测游戏里的登陆发包数据:%s\n"),HexArrayToString(data,len).c_str());
			ret=true;
		}

	}

	return ret;
}

