#include "MessageMapList.h"


#include "./Message/InfoPlayerInfoStatus.h"

CMessageMapList *CMessageMapList::m_pMessageListInstance=NULL;
CMessageMapList::CMessageMapList(void)
{
}

CMessageMapList::~CMessageMapList(void)
{
	ClearAllMessage();
}


CMessageMapList *CMessageMapList::GetInstance()
{
	if(!CMessageMapList::m_pMessageListInstance)
	{
		m_pMessageListInstance=new CMessageMapList;
	}
	return m_pMessageListInstance;
}


void CMessageMapList::DeleteInstance()
{
	SAFE_DELETE_POINTER(m_pMessageListInstance);
}


bool CMessageMapList::InitMessageList()	//初始化通信
{
	bool ret=true;
	CBaseMessage *pMsg=NULL;

	pMsg=new CMessageClientPlayerInfoStatus;
	AddToMessageMapList(pMsg);

	pMsg=new CMessageClientQuitReq;
	AddToMessageMapList(pMsg);

	pMsg=new CMessageClientQuitRes;
	AddToMessageMapList(pMsg);

	pMsg=new CMessageClientStatus;
	AddToMessageMapList(pMsg);

	pMsg=new CMessageHeartBeatReq;
	AddToMessageMapList(pMsg);

	pMsg=new CMessageHeartBeatRes;
	AddToMessageMapList(pMsg);

	pMsg=new CMessageLoginReq;
	AddToMessageMapList(pMsg);

	pMsg=new CMessageLoginRes;
	AddToMessageMapList(pMsg);

	pMsg=new CMessageClientPlayerTaskStatus;
	AddToMessageMapList(pMsg);


	pMsg=new CInfoPlayerInfoStatus;
	AddToMessageMapList(pMsg);

	pMsg=new CMessageControlClientReq;
	AddToMessageMapList(pMsg);

	pMsg=new CMessageDoGameOperationReq;
	AddToMessageMapList(pMsg);

	pMsg=new CMessageWriteText;
	AddToMessageMapList(pMsg);

	return ret;
}




void CMessageMapList::AddToMessageMapList(CBaseMessage *pMsg)
{
	m_messageMap.insert(make_pair(pMsg->GetProtocolId(),pMsg));
}


CBaseMessage *CMessageMapList::GetMessageById(int id)
{
	CBaseMessage *pMsg=NULL;
	map<int,CBaseMessage*>::iterator it=m_messageMap.find(id);
	if(it != m_messageMap.end())
	{
		pMsg=it->second;
	}
	return pMsg;
}


void CMessageMapList::ClearAllMessage()
{
	map<int,CBaseMessage*>::iterator it=m_messageMap.begin();
	while(it != m_messageMap.end())
	{
		CBaseMessage *p=it->second;
		SAFE_DELETE_POINTER(p);
		++it;
	}
}