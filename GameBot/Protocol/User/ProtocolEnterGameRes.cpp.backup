#include "ProtocolEnterGameRes.h"
#include "../../Player.h"

CProtocolEnterGameRes::CProtocolEnterGameRes(void)
{
	SetProtocolIdResOrSyn(ResEnterGame);
}

CProtocolEnterGameRes::~CProtocolEnterGameRes(void)
{
}




int CProtocolEnterGameRes::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();
	

	//m_pPlayer->SetInGameAlready(true);	//收到这个消息认为已进入游戏,收到这个协议但资源还在加载中，这里只将角色选择为true,in game要另外判断
	m_pPlayer->SetChooseRoleAlreay(true);	//这里一起处理角色选择状态
	//m_pPlayer->ReadyForPlaying();	//进入游戏后开启player线程
	TRACE_OUTPUT(_T("解析Enter game res\n"));

	bool bFinish=false;
	int restBytes=m_packageLengthInRes-protocol_header_length;
	int objLength=0;
	while(!bFinish)
	{
		DWORD fieldFlag=pStreamBuf->ReadRawVarInt32();
		switch(fieldFlag>>3)
		{
		case 1:
			m_roleId=pStreamBuf->ReadRawVarInt64();
			break;
		case 2:
			m_strRoleId=pStreamBuf->ReadVarIntString();
// 			objLength=pStreamBuf->ReadRawVarInt32();
// 			pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);

			break;
		case 3:
			m_serverTime=pStreamBuf->ReadRawVarInt64();
			break;
		case 4:
#if _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_
#elif (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_)
#elif (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_)
#elif _GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_
			timeZone=pStreamBuf->ReadRawVarInt32();//=4;//时区
#endif
			break;
		default:
			break;
		}
		bFinish=(pStreamBuf->GetHandlePos()-orgPos)>=restBytes;
	}
	//TRACE_OUTPUT(_T("GameEnterRes strRoleId:%s,serverTime:%I64d\n"),m_strRoleId.c_str(),m_serverTime);
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	TRACE_OUTPUT(_T("GameEnterRes 解析长度:%d\n"),handleLength);
	return handleLength;
}