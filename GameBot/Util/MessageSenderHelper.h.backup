#pragma once
#include "../Global/public.h"
#include "../MessageMapList.h"

class CClient;
class CServer;
class CThreadLock;
class CMessageSenderHelper
{
public:
	CMessageSenderHelper(void);
	~CMessageSenderHelper(void);

	void SetServer(CServer *p){m_pServer=p;}
	void SetClient(CClient *p){m_pClient=p;}


	static CMessageSenderHelper *GetInstance();
	static void DeleteInstance();


	char *CompactData(CBaseMessage *pMsg,int &totalLength);


	bool SendHeartbeatReq(CClient *pClient);
	bool SendHeartbeatRes(int index,int code);
	bool SendLoginReq(CClient *pClient);
	bool SendLoginRes(int index,int code);
	bool SendClientStatus(CClient *pClient,int isOnline);	//待定
	bool SendPlayerInfoStatus(CClient *pClient,CInfoPlayerInfoStatus *playerInfo);
	bool SendPlayerTaskStatus(CClient *pClient,STRING &taskName);
	bool SendQuitReq(CClient *pClient);
	bool SendQuitRes(int index,int code);
	bool SendForceQuitRes(int playerIndex);
	bool SendControlClientReq(int playerIndex,int op);
	bool SendDoGameOperationReq(int playerIndex,int gameOperationProtocolId,int paramLength,char *cmdData);
	bool SendToWriteData(CClient *pClient,int type,const STRING &account,char *buf,int len);	//发送到主窗口
private:

	CClient *m_pClient;
	CServer *m_pServer;
	CThreadLock *m_pThreadLock;
	static CMessageSenderHelper *m_pMessageSenderHelperInstance;
};
