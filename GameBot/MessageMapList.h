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
#include "./Message/MessageControlClientReq.h"	//���ƿͻ���
#include "./Message/MessageDoGameOperationReq.h"	//���Ʒ���Э��
#include "./Message/MessageWriteText.h"	//д�ļ�
class CMessageMapList
{
public:
	CMessageMapList(void);
	~CMessageMapList(void);

	bool InitMessageList();	//��ʼ��ͨ��
	void AddToMessageMapList(CBaseMessage *pMsg);

	CBaseMessage *GetMessageById(int id);

	void ClearAllMessage();


	static CMessageMapList *GetInstance();
	static void DeleteInstance();
private:
	map<int,CBaseMessage*> m_messageMap;
	static CMessageMapList *m_pMessageListInstance;
};
