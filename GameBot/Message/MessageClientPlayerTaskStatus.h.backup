#pragma once
#include "basemessage.h"

class CMessageClientPlayerTaskStatus :
	public CBaseMessage
{
public:
	CMessageClientPlayerTaskStatus(void);
	virtual ~CMessageClientPlayerTaskStatus(void);


	virtual bool Encode(CStreamReadWrite *pStreamBuf);
	virtual int Decode(CStreamReadWrite *pStreamBuf);

	void MakeClientPlayerTaskStatusMessage(int index,STRING &task);

	STRING GetTaskStaus(){return m_taskStatus;}
	int GetPlayerIndex(){return m_index;}
private:
	STRING m_taskStatus;	//任务状态只是个字符
	int m_index;
};
