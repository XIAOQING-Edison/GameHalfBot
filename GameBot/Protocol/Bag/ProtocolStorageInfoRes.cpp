#include "ProtocolStorageInfoRes.h"
#include "../../Player.h"

CProtocolStorageInfoRes::CProtocolStorageInfoRes(void)
{
	SetProtocolIdResOrSyn(ResStorageInfo);
}

CProtocolStorageInfoRes::~CProtocolStorageInfoRes(void)
{
}




int CProtocolStorageInfoRes::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	bool bFinish=false;
	int restBytes=m_packageLengthInRes-protocol_header_length;
	//到这里游戏基本加载完成
	m_pPlayer->SetInGameAlready(true);
	m_pPlayer->ReadyForPlaying();
	
	OutputDebugStr(_T("------------CProtocolStorageInfoRes----------------------\n"));
	pStreamBuf->SetHandlePos(orgPos+restBytes);

	int count=0;
	// 	while(!bFinish)
	// 	{
	// 		DWORD fieldFlag=pStreamBuf->ReadRawVarInt32();
	// 		switch(fieldFlag>>3)
	// 		{
	// 		case 1:
	// 			m_skillId=pStreamBuf->ReadRawVarint32();
	// 			break;
	// 		case 2:
	// 			m_sourceId=pStreamBuf->ReadRawVarint64();
	// 			break;
	// 		case 3:
	// 			m_targetId=pStreamBuf->ReadRawVarint64();
	// 			break;
	// 		case 4:
	// 			m_sourceX=pStreamBuf->ReadRawVarint32();
	// 			break;
	// 		case 5:
	// 			m_sourceY=pStreamBuf->ReadRawVarint32();
	// 			break;
	// 		case 6:
	// 			break;
	// 		case 7:
	// 			break;
	// 		case 8:
	// 			m_targetId=pStreamBuf->ReadRawVarint64();
	// 			break;
	// 		case 7:
	// 			m_targetId=pStreamBuf->ReadRawVarint64();
	// 			break;
	// 		default:
	// 			break;
	// 		}
	// 		bFinish=(count>=maxCount);
	// 	}


EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;
}