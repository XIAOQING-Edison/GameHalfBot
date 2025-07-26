#include "GiftHallConfig.h"

const TCHAR *g_szAutoActivityTask=_T("autoActivityTask");
const TCHAR *g_szAutoSignIn=_T("autoSignIn");
const TCHAR *g_szAutoTreasureHole=_T("autoTreasureHole");
const TCHAR *g_szAutoGetOnlineReward=_T("autoOnlineReward");
const TCHAR *g_szAutGetOfflineExp=_T("autoGetOfflineExp");
const TCHAR *g_szGetOfflineExpType=_T("getOfflineExpType");
const TCHAR *g_szAutoComposeTicket=_T("AutoComposeTicket");
const TCHAR *g_szAutoRecycleEquipment=_T("AutoRecycleEquipment");
const TCHAR *g_szRecycleEquipmentStar=_T("RecycleEquipmentStar");
const TCHAR *g_szRecycleEquipmentStepLv=_T("RecycleEquipmentStepLv");
const TCHAR *g_szAutoSendGetVipMemberInfo=_T("utoSendGetVipMemberInfo");	//自动发送会员消息
const TCHAR *g_szAutoGetAcivitityReward=_T("AutoGetAcivitityReward");
const TCHAR *g_szAutoReadMail=_T("AutoReadMail");
const TCHAR *g_szAutoDeleteReadMail=_T("AutoDeleteReadMail");
const TCHAR *g_szAutoUpdateMagicNeclear=_T("AutoUpdateMagicNeclear");
const TCHAR *g_szAutoTidyBag=_T("AutoTidyBag");


CGiftHallConfig::CGiftHallConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt):CConfig(szFileName,bUseEncryptDecrypt)
{

}

CGiftHallConfig::~CGiftHallConfig(void)
{
}




BOOL CGiftHallConfig::IsAutoSignInFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szAutoSignIn);
}


void CGiftHallConfig::SetAutoSignInToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szAutoSignIn,0,b);
}


BOOL CGiftHallConfig::IsAutoTreasureHoleFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szAutoTreasureHole);
}


void CGiftHallConfig::SetAutoTreasureHoleToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szAutoTreasureHole,0,b);
}


BOOL CGiftHallConfig::IsAutoActivityTaskFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szAutoActivityTask);
}


void CGiftHallConfig::SetAutoActivityTaskToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szAutoActivityTask,0,b);
}



BOOL CGiftHallConfig::IsAutoOnlineRewardFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szAutoGetOnlineReward);
}


void CGiftHallConfig::SetAutoOnlineRewardToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szAutoGetOnlineReward,0,b);
}



BOOL CGiftHallConfig::IsAutoOfflineExpFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szAutGetOfflineExp);
}


void CGiftHallConfig::SetAutoOfflineExpToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szAutGetOfflineExp,0,b);
}



int CGiftHallConfig::GetOfflineExpTypeFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szGetOfflineExpType);

}


void CGiftHallConfig::SetOfflineExpTypeToCfg(int type)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szGetOfflineExpType,0,type);

}


BOOL CGiftHallConfig::IsAutoComposeTicketFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szAutoComposeTicket);
}


void CGiftHallConfig::SetAutoComposeTickeToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szAutoComposeTicket,FALSE,b);
}


BOOL CGiftHallConfig::IsAutoRecycleEquipmentFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szAutoRecycleEquipment);

}


void CGiftHallConfig::SetAutoRecycleEquipmentToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szAutoRecycleEquipment,FALSE,b);

}


int CGiftHallConfig::GetRecycleEquipmentStarFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szRecycleEquipmentStar);
}


void CGiftHallConfig::SetRecycleEquipmentStarToCfg(int star)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szRecycleEquipmentStar,0,star);

}

int CGiftHallConfig::GetRecycleEquipmentStepLvFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szRecycleEquipmentStepLv);
}


void CGiftHallConfig::SetRecycleEquipmentStepLvToCfg(int stepLv)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szRecycleEquipmentStepLv,0,stepLv);
}


BOOL CGiftHallConfig::IsAutoSendGetVipMemberInfoFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szAutoSendGetVipMemberInfo);

}

void CGiftHallConfig::SetIsAutoSendGetVipMemberInfoToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szAutoSendGetVipMemberInfo,FALSE,b);

}


BOOL CGiftHallConfig::IsAutoActivityGetRewardFromCfg()	//自动活跃度奖励领取
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szAutoGetAcivitityReward);

}

void CGiftHallConfig::SetIsAutoAcitivityGetRewardToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szAutoGetAcivitityReward,FALSE,b);
}


BOOL CGiftHallConfig::IsAutoReadMailFromCfg()	//自动读取邮件
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szAutoReadMail);
}


void CGiftHallConfig::SetIsAutoReadMailToCfg(BOOL b)
{	
	CConfig::WriteInt(m_sectionName.c_str(),g_szAutoReadMail,FALSE,b);
}

BOOL CGiftHallConfig::IsAutoDeleteReadMailFromCfg()	//自动删除已读邮件
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szAutoDeleteReadMail);
}


void CGiftHallConfig::SetIsAutoDeleteReadMailToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szAutoDeleteReadMail,FALSE,b);
}


BOOL CGiftHallConfig::IsAutoUpdateMagicNuclearFromCfg()	//自动魔核充能
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szAutoUpdateMagicNeclear);
}


void CGiftHallConfig::SetIsAutoUpdateMagicNuclearToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szAutoUpdateMagicNeclear,FALSE,b);
}


BOOL CGiftHallConfig::IsAutoTidyBagFromCfg()	//自动整理背包
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szAutoTidyBag);
}


void CGiftHallConfig::SetIsAutoTidyBagToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szAutoTidyBag,FALSE,b);
}