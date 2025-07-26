#include "MessageClientStatus.h"

CMessageClientStatus::CMessageClientStatus(void)
{
	SetProtocolId(e_cmd_client_status);
}

CMessageClientStatus::~CMessageClientStatus(void)
{
}

bool CMessageClientStatus::Encode(CStreamReadWrite *pStreamBuf)
{
	bool ret=false;
	return ret;
}


//这个游戏到这里就是出错
int CMessageClientStatus::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	m_isOnline=pStreamBuf->ReadFixedInt32();

EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;

}



