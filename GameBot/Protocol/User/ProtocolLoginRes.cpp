#include "ProtocolLoginRes.h"
#include "../../Player.h"

CProtocolLoginRes::CProtocolLoginRes(void)
{
	SetProtocolIdResOrSyn(ResLoginUser);
}

CProtocolLoginRes::~CProtocolLoginRes(void)
{
}



//到这里就只剩下包体直接解析了，没有头部信息或者其它flag
int CProtocolLoginRes::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	bool bFinish=false;
	int restBytes=m_packageLengthInRes-protocol_header_length;
	int objLength=0;

	TRACE_OUTPUT(_T("解析login Res\n"));
	//TRACE_OUTPUT(_T("login Res内容:%s\n"),HexArrayToString(pStreamBuf->GetBufHead()+orgPos,restBytes).c_str());
	//pStreamBuf->SetHandlePos(orgPos+restBytes);	//test
	while(!bFinish)
	{
		DWORD fieldFlag=pStreamBuf->ReadRawVarInt32();
		switch(fieldFlag>>3)
		{
		case 1:
			m_openServerTime=pStreamBuf->ReadRawVarInt64();
			break;
		case 2:
			m_combineServerTime=pStreamBuf->ReadRawVarInt64();
			break;
		case 3:
			m_serverCurTime=pStreamBuf->ReadRawVarInt64();
			break;
		case 4:
			m_bNeedInviteCode=pStreamBuf->ReadUnsignedByte();
			break;
		case 5:
			{

			}
			break;
		case 6:
			{
#if (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_) ||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
				{
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);	
				}
#elif (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_)
#elif (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_)
#elif _GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_
#endif
			}
			break;
		default:
			break;
		}

		bFinish=(pStreamBuf->GetHandlePos()-orgPos)>=restBytes;
	}
	TRACE_OUTPUT(_T("open:%I64d,combind:%I64d,current:%I64d\n"),m_openServerTime,m_combineServerTime,m_serverCurTime);
	if(m_pPlayer)
	{
		m_pPlayer->SetLoginAlready(true);
	}

EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;
}