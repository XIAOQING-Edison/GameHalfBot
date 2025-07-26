#pragma once

#include "./Global/public.h"
#include "./Message/BaseMessage.h"

#include "./Message/MessageClientPlayerInfoStatus.h"
#include "./Message/MessageClientQuitReq.h"
#include "./Message/MessageClientQuitRes.h"
#include "./Message/MessageClientStatus.h"
#include "./Message/MessageHeartBeatReq.h"
#include "./Message/MessageHeartBeatRes.h"
#include "./Message/MessageLoginReq.h"
#include "./Message/MessageLoginRes.h"
#include "./Message/MessageClientPlayerTaskStatus.h"
#include "./Message/MessageControlClientReq.h"	//控制客户端
#include "./Message/MessageDoGameOperationReq.h"	//控制发送协议
#include "./Message/MessageWriteText.h"	//写文件
class CMessageMapList
{
public:
	CMessageMapList(void);
	~CMessageMapList(void);

	bool InitMessageList();	//初始化通信
	void AddToMessageMapList(CBaseMessage *pMsg);

	CBaseMessage *GetMessageById(int id);

	void ClearAllMessage();


	static CMessageMapList *GetInstance();
	static void DeleteInstance();
private:
	map<int,CBaseMessage*> m_messageMap;
	static CMessageMapList *m_pMessageListInstance;
};
