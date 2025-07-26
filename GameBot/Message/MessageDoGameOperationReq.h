#pragma once
#include "basemessage.h"

class CMessageDoGameOperationReq :
	public CBaseMessage
{
public:
	CMessageDoGameOperationReq(void);
	virtual ~CMessageDoGameOperationReq(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf);
	virtual int Decode(CStreamReadWrite *pStreamBuf);

	void MakeDoGameOperationMessage(int protocolId,int paramLength,char *data);	//协议id,paramLength是参数长度,data是参数内容

	int GetGameOperationProtocolId(){return m_gameOperationProtocolId;}
	int GetParamLength(){return m_paramLength;}
	char *GetCmdData(){return m_data;}
private:
	int m_gameOperationProtocolId;
	int m_paramLength;
	char *m_data;	//这里默认的缓冲就可了


};
