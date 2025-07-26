#pragma once
#include "basemessage.h"

class CMessageLoginRes :
	public CBaseMessage
{
public:
	CMessageLoginRes(void);
	virtual ~CMessageLoginRes(void);


	virtual bool Encode(CStreamReadWrite *pStreamBuf);
	virtual int Decode(CStreamReadWrite *pStreamBuf);

	void MakeLoginResMessage(int index,int code);

	int GetResCode(){return m_resCode;}
	int GetAssignedIndex(){return m_assignedId;}

private:
	int m_resCode;
	int m_assignedId;	//分配得到的id
};
