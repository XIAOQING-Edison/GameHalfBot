#include "InfoResLoginUser.h"

CInfoResLoginUser::CInfoResLoginUser(void)
{
}

CInfoResLoginUser::~CInfoResLoginUser(void)
{
}


int CInfoResLoginUser::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	TRACE_OUTPUT(_T("解析CInfoResLoginUser\n"));

	bool bFinish=false;
	//int count=0,maxCount=4;
	int restBytes=m_packageLengthInRes;	//读取固定长度的字节就解析完
	while(!bFinish)
	{
		DWORD fieldFlag=pStreamBuf->ReadRawVarInt32();
		switch(fieldFlag>>3)
		{
		case 1:
			openServerTime=pStreamBuf->ReadRawVarInt64();
			break;
		case 2:
			combineServerTime=pStreamBuf->ReadRawVarInt64();
			break;
		case 3:
			serverCurTime=pStreamBuf->ReadRawVarInt64();
			break;
		case 4:
			needInviteCode=pStreamBuf->ReadUnsignedByte();
			break;
		default:
			break;
		}
		bFinish=(pStreamBuf->GetHandlePos()-orgPos)>=restBytes;
	}

EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	TRACE_OUTPUT(_T("CInfoResLoginUser 解析长度:%d\n"),handleLength);
	return handleLength;
}