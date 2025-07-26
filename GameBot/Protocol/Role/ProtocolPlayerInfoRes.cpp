#include "ProtocolPlayerInfoRes.h"
#include "../../Player.h"
#include "../../Client.h"
#include "../../Util/MessageSenderHelper.h"

CProtocolPlayerInfoRes::CProtocolPlayerInfoRes(void)
{
	SetProtocolIdResOrSyn(ResPlayerInfo);
}

CProtocolPlayerInfoRes::~CProtocolPlayerInfoRes(void)
{
}


int CProtocolPlayerInfoRes::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	int restBytes=m_packageLengthInRes-protocol_header_length;
	TRACE_OUTPUT(_T("解析CProtocolPlayerInfoRes\n"),restBytes);
	
// 	TRACE_OUTPUT(_T("Player info res跳过字节:%d\n"),restBytes);
// 	pStreamBuf->SetHandlePos(orgPos+restBytes);	//未完成解析时直接跳过


	playerInfo.SetPackageLengthInRes(restBytes);
	playerInfo.Decode(pStreamBuf);
	if(m_pPlayer)
	{

		m_pPlayer->SetRoleId(playerInfo.GetRoleId());
		m_pPlayer->SetRoleName(playerInfo.GetName());
		m_pPlayer->SetCareer(playerInfo.GetCareer());
		m_pPlayer->SetLevel(playerInfo.GetLevel());
		m_pPlayer->SetAsuramName(playerInfo.GetUnionName());
		m_pPlayer->SetTotalBattleScore(playerInfo.GetTotalFight());
		m_pPlayer->SetPkMode(playerInfo.GetPkMode());

#if (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_)
#endif
		TRACE_OUTPUT(_T("更新角色信息----\n"));

#if (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_) ||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_) /*||()*/
		
#else

#endif
		CClient *pClient=m_pPlayer->GetClient();
		if(pClient)
		{
			pClient->UpdatePlayerInfoToPlayerInfoStatus();	//更新状态
			CMessageSenderHelper::GetInstance()->SendPlayerInfoStatus(pClient,pClient->GetPlayerStatus());
		}
	}
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;
}