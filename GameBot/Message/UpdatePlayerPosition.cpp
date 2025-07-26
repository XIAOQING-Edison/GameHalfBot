#include "UpdatePlayerPosition.h"

CUpdatePlayerPosition::CUpdatePlayerPosition(void)
{
	SetProtocolId(e_cmd_info_player_position);
}

CUpdatePlayerPosition::~CUpdatePlayerPosition(void)
{
}



void CUpdatePlayerPosition::Reset()
{
	x=y=0;
}



bool CUpdatePlayerPosition::Encode(CByteUtil *pStreamBuf)
{
	CBaseMessage::Encode(pStreamBuf);
	ResetWritePostion();

	pStreamBuf->WriteShort(GetProtocolId());	//协议ID
	pStreamBuf->WriteFixedInt32(x);
	pStreamBuf->WriteFixedInt32(y);
	return true;
}


int CUpdatePlayerPosition::Decode(CByteUtil *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	Reset();

	x=pStreamBuf->ReadFixedInt32();
	y=pStreamBuf->ReadFixedInt32();
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;
}
