#include "InfoResLoginError.h"

CInfoResLoginError::CInfoResLoginError(void)
{
}

CInfoResLoginError::~CInfoResLoginError(void)
{
}



int CInfoResLoginError::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	TRACE_OUTPUT(_T("解析CInfoResLoginError\n"));
	int count=0;

	// 	bool bFinish=false;
	// 	int restBytes=m_packageLengthInRes;
	// 	while(!bFinish)
	// 	{
	// 		DWORD fieldFlag=pStreamBuf->ReadRawVarInt32();
	// 		switch(fieldFlag>>3)
	// 		{
	// 		case 1:
	// 			m_openServerTime=pStreamBuf->ReadRawVarint64();
	// 			break;
	// 		case 2:
	// 			m_combineServerTime=pStreamBuf->ReadRawVarint64();
	// 			break;
	// 		case 3:
	// 			m_serverCurTime=pStreamBuf->ReadRawVarint64();
	// 			break;
	// 		default:
	// 			break;
	// 		}
	// 		bFinish=(count>=maxCount);
	// 	}

EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	//TRACE_OUTPUT(_T("CInfoResLoginError 解析长度:%d\n"),handleLength);
	return handleLength;
}