#include "BossAssistConfig.h"

static TCHAR *g_szIsBeastBossOnlyAssistSelfMaxCount=_T("IsBeastBossOnlyAssistSelfMaxCount");
static TCHAR *g_szBeastBossAssistMaxTimeout=_T("BeastBossAssistMaxTimeout");
static TCHAR *g_szIsBeastBossAutoSendAssist=_T("IsBeastBossAutoSendAssist");
static TCHAR *g_szIsBeastBossAssistAutoSendAssist=_T("IsBeastBossAssistAutoSendAssist");
static TCHAR *g_szIsBeastBossAutoAssistOther=_T("IsBeastBossAutoAssistOther");


static TCHAR *g_szIsCorpsBossOnlyAssistSelfMaxCount=_T("IsCorpsBossOnlyAssistSelfMaxCount");
static TCHAR *g_szCorpsBossAssistMaxTimeout=_T("CorpsBossAssistMaxTimeout");
static TCHAR *g_szIsCorpsBossAutoSendAssist=_T("IsCorpsBossAutoSendAssist");
static TCHAR *g_szIsCorpsBossAssistAutoSendAssist=_T("IsCorpsBossAssistAutoSendAssist");
static TCHAR *g_szIsCorpsBossAutoAssistOther=_T("IsCorpsBossAutoAssistOther");

CBossAssistConfig::CBossAssistConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt):CConfig(szFileName,bUseEncryptDecrypt)
{
	
}

CBossAssistConfig::~CBossAssistConfig(void)
{
}


BOOL CBossAssistConfig::IsBeastBossAutoAssistOtherFromCfg()	//是否自动协助他人
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsBeastBossAutoAssistOther);

}


void CBossAssistConfig::SetIsBeastBossAutoAssistOtherToCfg(BOOL b)	//
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsBeastBossAutoAssistOther,FALSE,b);
}



BOOL CBossAssistConfig::IsBeastBossOnlyAssistSelfMaxCountFromCfg()	//是否达到最大次数就不协助，默认是都协助
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsBeastBossOnlyAssistSelfMaxCount);
}


void CBossAssistConfig::SetIsBeastBossOnlyAssistSelfMaxCountToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsBeastBossOnlyAssistSelfMaxCount,FALSE,b);
}

BOOL CBossAssistConfig::IsBeastBossAutoSendAssistFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsBeastBossAutoSendAssist);
}


void CBossAssistConfig::SetIsBeastBossAutoSendAssistToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsBeastBossAutoSendAssist,FALSE,b);

}


int CBossAssistConfig::GetBeastBossAssistMaxTimeoutFromCfg()	//兽神最大协助超时
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szBeastBossAssistMaxTimeout,5);
}

void CBossAssistConfig::SetBeastBossAssistMaxTimeoutToCfg(int timeout)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szBeastBossAssistMaxTimeout,5,timeout);
}


BOOL CBossAssistConfig::IsBeastBossAssistAutoSendAssistFromCfg()	//兽神协助自动发送求协助
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsBeastBossAssistAutoSendAssist);

}


void CBossAssistConfig::SetIsBeastBossAssistAutoSendAssistToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsBeastBossAssistAutoSendAssist,FALSE,b);

}

//军团
BOOL CBossAssistConfig::IsCorpsBossAutoSendAssistFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsCorpsBossAutoSendAssist);

}


void CBossAssistConfig::SetIsCorpsBossAutoSendAssistToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsCorpsBossAutoSendAssist,FALSE,b);

}

BOOL CBossAssistConfig::IsCorpsBossOnlyAssistSelfMaxCountFromCfg()	//是否达到最大次数就不协助，默认是都协助
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsCorpsBossOnlyAssistSelfMaxCount);

}


void CBossAssistConfig::SetIsCorpsBossOnlyAssistSelfMaxCountToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsCorpsBossOnlyAssistSelfMaxCount,FALSE,b);
}


BOOL CBossAssistConfig::IsCorpsBossAssistAutoSendAssistFromCfg()	//军团协助自动发送求协助
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsCorpsBossAssistAutoSendAssist);

}



int CBossAssistConfig::GetCorpsBossAssistMaxTimeoutFromCfg()	//军团最大协助超时
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szCorpsBossAssistMaxTimeout,5);

}


void CBossAssistConfig::SetCorpsBossAssistMaxTimeoutToCfg(int timeout)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szCorpsBossAssistMaxTimeout,5,timeout);

}

void CBossAssistConfig::SetIsCorpsBossAssistAutoSendAssistToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsCorpsBossAssistAutoSendAssist,FALSE,b);

}


BOOL CBossAssistConfig::IsCorpsBossAutoAssistOtherFromCfg()	//是否自动协助他人
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsCorpsBossAutoAssistOther);
}


void CBossAssistConfig::SetIsCorpsBossAutoAssistOtherToCfg(BOOL b)	//
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsCorpsBossAutoAssistOther,FALSE,b);

}
