#pragma once

#include "../Global/public.h"
class CAccountInfo
{
public:
	CAccountInfo(void);
	~CAccountInfo(void);

	void SetAccountName(STRING &name){m_accountName=name;}
	STRING GetAccountName(){return m_accountName;}

	void SetServerId(int id){m_serverId=id;}
	int GetServerId(){return m_serverId;}

	void SetPlatformIndex(int index){m_platformIndex=index;}
	int GetPlatformIndex(){return m_platformIndex;}

	void SetIndex(int index){m_index=index;}
	int GetIndex(){return m_index;}

	void Reset();
private:
	STRING m_accountName;
	int m_serverId;
	int m_platformIndex;
	int m_index;	//在listctrl中的id
	
};
