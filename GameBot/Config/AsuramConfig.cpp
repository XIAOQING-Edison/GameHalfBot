#include "AsuramConfig.h"

TCHAR *g_szIsAsuramBossSelected=_T("IsAsuramBossSelected");
TCHAR *g_szIsAsuramBossAutoDice=_T("IsAsuramBossAutoDice");
TCHAR *g_szIsAsuramFeastSelected=_T("IsAsuramFeastSelected");
TCHAR *g_szIsAsuramAutoFete=_T("IsAsuramAutoFete");
TCHAR *g_szAsuramFeastCount=_T("AsuramFeastCount");
TCHAR *g_szIsAsuramTransSelected=_T("IsAsuramTrzansSelected");
TCHAR *g_szIsAutoAcceptAsuramFeast=_T("IsAutoAcceptAsuramFeast");
TCHAR *g_szIsCampWarSelected=_T("IsCampWarSelected");
TCHAR *g_szIsCampWarUseCoinEncourage=_T("IsCampWarUseCoinEncourage");
TCHAR *g_szIsAngelTrialSelected=_T("IsAngelTrialSelected");
TCHAR *g_szIsAngelTrialAutoSweep=_T("IsAngelTrialAutoSweep");
TCHAR *g_szAngelTrialSweepCount=_T("AngelTrialSweepCount");
TCHAR *g_szIsAngelTrialAutoSweepAfterChallengeFailed=_T("IsAngelTrialAutoSweepAfterChallengeFailed");
TCHAR *g_szIsAngelTrialUseAttackSpeedItem=_T("IsAngelTrialUseAttackSpeedItem");
TCHAR *g_szIsLandBossSelected=_T("IsLandBossSelected");
TCHAR *g_szIsLandBossAutoSweep=_T("IsLandBossAutoSweep");
TCHAR *g_szLandBossAutoSweepCount=_T("LandBossAutoSweepCount");
TCHAR *g_szIsLandBossSweepAfterChallengeFailed=_T("IsLandBossSweepAfterChallengeFailed");
TCHAR *g_szIsLandBossUseAttackSpeedItem=_T("IsLandBossUseAttackSpeedItem");



CConfigSecretary3::CConfigSecretary3(const TCHAR *szFileName,bool bUseEncryptDecrypt):CConfig(szFileName,bUseEncryptDecrypt)
{
}

CConfigSecretary3::~CConfigSecretary3(void)
{
}


BOOL CConfigSecretary3::IsAsuramBossSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAsuramBossSelected);
}

BOOL CConfigSecretary3::SetIsAsuramBossSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAsuramBossSelected,FALSE,b);
}


BOOL CConfigSecretary3::IsAsuramBossAutoDiceFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAsuramBossAutoDice);
}

BOOL CConfigSecretary3::SetIsAsuramBossAutoDiceToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAsuramBossAutoDice,FALSE,b);
}




BOOL CConfigSecretary3::IsAsuramFeastSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAsuramFeastSelected);

}
BOOL CConfigSecretary3::SetIsAsuramFeastSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAsuramFeastSelected,FALSE,b);

}

BOOL CConfigSecretary3::IsAsuramAutoFeteFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAsuramAutoFete);

}
BOOL CConfigSecretary3::SetIsAsuramAutoFeteToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAsuramAutoFete,FALSE,b);

}

int CConfigSecretary3::GetAsuramFeastCountFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szAsuramFeastCount);

}
BOOL CConfigSecretary3::SetAsuramFeastCountToCfg(int count)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szAsuramFeastCount,FALSE,count);

}

BOOL CConfigSecretary3::IsAsuramTransSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAsuramTransSelected);

}
BOOL CConfigSecretary3::SetIsAsuramTransSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAsuramTransSelected,FALSE,b);

}

BOOL CConfigSecretary3::IsAutoAcceptAsuramFeastFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAutoAcceptAsuramFeast);

}
BOOL CConfigSecretary3::SetIsAutoAcceptAsuramFeastToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAutoAcceptAsuramFeast,FALSE,b);

}

BOOL CConfigSecretary3::IsCampWarSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsCampWarSelected);

}
BOOL CConfigSecretary3::SetIsCampWarSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsCampWarSelected,FALSE,b);

}

BOOL CConfigSecretary3::IsCampWarUseCoinEncourageFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsCampWarUseCoinEncourage);

}
BOOL CConfigSecretary3::SetIsCampWarUseCoinEncourageToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsCampWarUseCoinEncourage,FALSE,b);

}

BOOL CConfigSecretary3::IsAngelTrialSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAngelTrialSelected);

}
BOOL CConfigSecretary3::SetIsAngelTrialSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAngelTrialSelected,FALSE,b);

}

BOOL CConfigSecretary3::IsAngelTrialAutoSweepFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAngelTrialAutoSweep);

}
BOOL CConfigSecretary3::SetIsAngelTrialAutoSweepToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAngelTrialAutoSweep,FALSE,b);

}

int CConfigSecretary3::GetAngelTrialSweepCountFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szAngelTrialSweepCount);

}
BOOL CConfigSecretary3::SetAngelTrialSweepCountToCfg(int count)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szAngelTrialSweepCount,FALSE,count);

}

BOOL CConfigSecretary3::IsAngelTrialAutoSweepAfterChallengeFailedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAngelTrialAutoSweepAfterChallengeFailed);

}
BOOL CConfigSecretary3::SetIsAngelTrialAutoSweepAfterChallengeFailedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAngelTrialAutoSweepAfterChallengeFailed,FALSE,b);

}

BOOL CConfigSecretary3::IsAngelTrialUseAttackSpeedItemFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAngelTrialUseAttackSpeedItem);

}
BOOL CConfigSecretary3::SetIsAngelTrialUseAttackSpeedItemToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAngelTrialUseAttackSpeedItem,FALSE,b);

}

BOOL CConfigSecretary3::IsLandBossSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsLandBossSelected);

}
BOOL CConfigSecretary3::SetIsLandBossSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsLandBossSelected,FALSE,b);

}

BOOL CConfigSecretary3::IsLandBossAutoSweepFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsLandBossAutoSweep);

}
BOOL CConfigSecretary3::SetIsLandBossAutoSweepToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsLandBossAutoSweep,FALSE,b);

}

int CConfigSecretary3::GetLandBossAutoSweepCountFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szLandBossAutoSweepCount);

}
BOOL CConfigSecretary3::SetLandBossAutoSweepCountToCfg(int count)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szLandBossAutoSweepCount,FALSE,count);

}

BOOL CConfigSecretary3::IsLandBossSweepAfterChallengeFailedFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szIsLandBossSweepAfterChallengeFailed);

}
BOOL CConfigSecretary3::SetIsLandBossSweepAfterChallengeFailedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsLandBossSweepAfterChallengeFailed,FALSE,b);

}

BOOL CConfigSecretary3::IsLandBossUseAttackSpeedItemFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szIsLandBossUseAttackSpeedItem);

}
BOOL CConfigSecretary3::SetIsLandBossUseAttackSpeedItemToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsLandBossUseAttackSpeedItem,FALSE,b);

}
