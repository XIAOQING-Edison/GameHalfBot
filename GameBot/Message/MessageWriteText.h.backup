#pragma once
#include "basemessage.h"

//此类主要是发送到主窗口进行写文件
//最大一次写1k
class CMessageWriteText :
	public CBaseMessage
{
public:
	CMessageWriteText(void);
	virtual ~CMessageWriteText(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf);
	virtual int Decode(CStreamReadWrite *pStreamBuf);

	int GetType(){return m_type;}
	char *GetBuffer(){return (char*)m_buf;}
	STRING GetAccountName(){return m_accountName;}
	int GetLength(){return m_length;}
	void MakeWriteDataMessage(int type,const STRING &account,const char *szBuf,int bufSize);

private:
	void Init();
private:
	int m_type;
	int m_length;
	char m_buf[MAX_STACK_BUF_LENGTH];
	int m_playerIndex;
	STRING m_accountName;
};
