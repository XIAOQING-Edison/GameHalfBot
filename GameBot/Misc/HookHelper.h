#pragma once
#include "../Global/public.h"
#include "../MemoryStream/StreamReadWrite.h"
class CPlayer;
class CProtocol;
//封包型的才需要这个类，脱机不需要
//需要修改一次的包放在这里
enum E_MODIFY_PACKAGE_INDEX
{
	e_modify_package_secretary_time=0,	//小秘书时间
};


class CHookHelper
{
public:
	CHookHelper(void);
	~CHookHelper(void);

	void SetPlayer(CPlayer *p){m_pPlayer=p;}
	CPlayer *GetPlayer(){return m_pPlayer;}

	bool IsInGameServer();

	static CHookHelper *GetInstance();
	static void DeleteInstance();

	bool IsMainSocketValid(){return (GetMainServerSocket()!=INVALID_SOCKET);}

	void SetMainServerIp(const char *ip){m_mainServerIp=ip;}
	string GetMainServerIp(){return m_mainServerIp;}

	void SetMainServerPort(WORD port){m_mainServerPort=port;}
	WORD GetMainServerPort(){return m_mainServerPort;}

	void SetCrossServerIp(const char *ip){m_crossServerIp=ip;}
	string GetCrossServerIp(){return m_crossServerIp;}

	void SetCrossServerPort(WORD port){m_crossServerPort=port;}
	WORD GetCrossServerPort(){return m_crossServerPort;}


	void SetMainServerSocket(SOCKET s){m_mainServerSocket=s;}
	SOCKET GetMainServerSocket(){return m_mainServerSocket;}


	void SetCrossServerSocket(SOCKET s){m_crossServerSocket=s;}
	SOCKET GetCrossServerSocket(){return m_crossServerSocket;}


	void Reset();	//实始化各种变量，这里可能需要外部调用
	
	bool IsHooked(){return m_bHooked;}
	void SetHooked(bool b){m_bHooked=b;}

	//------------试验性修改,开始
	//发送的修改
	int ModifyRecycleItemMessage(const char *data,int len,char **newBuf,bool &bModify);	//修改发送回收消息,返回新长度,newBuf返回新buf
	int CheckIsSendVipMemberInfoMessage(const char *data,int len,char **newBuf,bool &bModify);	//如果未满足条件而发送获取vip会员信息就修改为其它东西
	int CheckAndModifyCreateRoleMessage(const char *data,int len,char **newBuf,bool &bModify);	//修改创建角色数据

	//接收的修改,所有修改的函数都不能超过bufLength!!!!!
	//-------------试验性修改，结束


	//注意!!里面修改的长度不能超过bufLength,否则引发崩溃
	int HandleRecv(SOCKET s,char *buf,int len,int bufLength,char **newBuf,bool &bIsModify);	//这里会进行修改或解析操作,返回newlen,bisModify=true时就是修改了返回

	int HandleSend(SOCKET s,char *buf,int len,char **newBuf,bool &bIsModify);	//这里会修改发送操作,返回newlen

	int DecodeBuffer(SOCKET s,char *buf,int len);

	void ResetCrossServerStreamBuffer();	//重置

	void ResetCrossServerSocket();	//退出跨服时重置

	void ResetSocketAndStreamBuf();	//断开时所有东西重置

	void CheckSocketState(SOCKET s);	//检测socket状态

	bool IsMainGameRedirectUrl(STRING &url);	//是否是主游戏URL
	
	void CheckAndSetSocket(SOCKET s,const char *ip,WORD port);	//设定所需要的socket

	//检查send数据
	bool CheckIsSendLoginMessage(const char *data,int len);	//检查是否是登陆包
	bool CheckSendChooseRoleMessage(const char *data,int len);//检查发送的角色选择包

	bool IsSameMainGameSocket(SOCKET s);	//是否是主socket,这里是登陆用的socket
private:
	int MakeNewRecvData(CProtocol *pProtocol,char **newBuf,int preLength,const char *orgRecvData,int orgRecvLength);	//生成一个new recv data,返回新长度
	char *GetRecvBuf(){return m_pRecvBuf;}
	char *GetSendBuf(){return m_pSendBuf;}
private:
	SOCKET m_mainServerSocket;
	SOCKET m_crossServerSocket;
	SOCKET m_duplicateSocket;	//复制过来的sockect
	CPlayer *m_pPlayer;
	string m_mainServerIp;
	WORD m_mainServerPort;
	string m_crossServerIp;
	WORD m_crossServerPort;

	static CHookHelper *s_pHookHelperInstance;
	CStreamReadWrite *m_pStreamBufRecv;
	CStreamReadWrite *m_pStreamBufSend;
	char *m_pRecvBuf;	//修改接收的缓冲
	char *m_pSendBuf;	//修改发送的缓冲
	char *m_pTmpRecvBuf;	//临时存放修改后的缓冲

	WSAPROTOCOL_INFO m_duplicateSocketInfo;	//用来存要复制的socket信息

	bool m_bHooked;	//是否已挂钩
	bool m_bSecetaryWorkFine;	//小秘书工作是否正常
};
