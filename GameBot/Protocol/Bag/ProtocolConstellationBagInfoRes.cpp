#include "ProtocolConstellationBagInfoRes.h"
#include "../../Player.h"

CProtocolConstellationBagInfoRes::CProtocolConstellationBagInfoRes(void)
{
#if _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_
	SetProtocolIdResOrSyn(ResConstellationBagInfo);
#endif
}

CProtocolConstellationBagInfoRes::~CProtocolConstellationBagInfoRes(void)
{
}




int CProtocolConstellationBagInfoRes::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	bool bFinish=false;
	int restBytes=m_packageLengthInRes-protocol_header_length;
	//到这里游戏基本加载完成
	m_pPlayer->SetInGameAlready(true);
	m_pPlayer->ReadyForPlaying();
	TRACE_OUTPUT(_T("CProtocolConstellationBagInfoRes 跳过字节:%d\n"),restBytes);
	pStreamBuf->SetHandlePos(orgPos+restBytes);

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
	//bFinish=(pStreamBuf->GetHandlePos()-orgPos)>=restBytes;
	// 	}


EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;
}