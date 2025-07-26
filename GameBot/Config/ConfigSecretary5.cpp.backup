#include "ConfigSecretary5.h"


TCHAR *g_szIsAutoExchangeEquipSandToGlory=_T("IsAutoExchangeEquipSandToGlory");
TCHAR *g_szExchangeEquipSandCount=_T("ExchangeEquipSandCount");
TCHAR *g_szIsSpaceCorridorSelected=_T("IsSpaceCorridorSelected");
TCHAR *g_szSpaceCorridorBuyExtraTimes=_T("SpaceCorridorBuyExtraTimes");
TCHAR *g_szIsDemonStrongHoldSelected=_T("IsDemonStrongHoldSelected");
TCHAR *g_szIsDemonStrongHoldOneKeyGetTreasure=_T("IsDemonStrongHoldOneKeyGetTreasure");
TCHAR *g_szIsAsuramLeagueBossSelected=_T("IsAsuramLeagueBossSelected");
TCHAR *g_szAsuramLeagueBossBuyExtraTimes=_T("AsuramLeagueBossBuyExtraTimes");
TCHAR *g_szIsAsuramLeagueBossAutoShareMonsterChallenge=_T("IsAsuramLeagueBossAutoShareMonsterChalleng");
TCHAR *g_szIsAsuramLeagueBossAutoExchangeTreasure=_T("IsAsuramLeagueBossAutoExchangeTreasur");
TCHAR *g_szIsAutoMeceneryDispathSelected=_T("IsAutoMeceneryDispathSelected");
TCHAR *g_szMeceneryDispathStarLevel=_T("MeceneryDispathStarLevel");
TCHAR *g_szIsMeceneryDispathContinueWhenNoUnits=_T("IsMeceneryDispathContinueWhenNoUnits");
TCHAR *g_szIsMeceneryDispathAutoDoTask=_T("IsMeceneryDispathAutoDoTask");
TCHAR *g_szIsMeceneryDispathAutoBuyHandCemecery=_T("IsMeceneryDispathAutoBuyHandCemecery");

CConfigSecretary5::CConfigSecretary5(const TCHAR *szFileName,bool bUseEncryptDecrypt):CConfig(szFileName,bUseEncryptDecrypt)
{
}

CConfigSecretary5::~CConfigSecretary5(void)
{
}




BOOL CConfigSecretary5::IsAutoExchangeEquipSandToGloryFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAutoExchangeEquipSandToGlory);
}


BOOL CConfigSecretary5::SetIsAutoExchangeEquipSandToGloryToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAutoExchangeEquipSandToGlory,FALSE,b);
}


int CConfigSecretary5::GetExchangeEquipSandCountFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szExchangeEquipSandCount);

}


BOOL CConfigSecretary5::SetExchangeEquipSandCountToCfg(int count)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szExchangeEquipSandCount,FALSE,count);

}




BOOL CConfigSecretary5::IsSpaceCorridorSelectedFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szIsSpaceCorridorSelected);

}


BOOL CConfigSecretary5::SetIsSpaceCorridorSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsSpaceCorridorSelected,FALSE,b);

}


int CConfigSecretary5::GetSpaceCorridorBuyExtraTimesFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szSpaceCorridorBuyExtraTimes);

}


BOOL CConfigSecretary5::SetSpaceCorridorBuyExtraTimesToCfg(int times)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szSpaceCorridorBuyExtraTimes,FALSE,times);

}



BOOL CConfigSecretary5::IsDemonStrongHoldSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsDemonStrongHoldSelected);

}

BOOL CConfigSecretary5::SetIsDemonStrongHoldSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsDemonStrongHoldSelected,FALSE,b);

}


BOOL  CConfigSecretary5::IsDemonStrongHoldOneKeyGetTreasureFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsDemonStrongHoldOneKeyGetTreasure);

}


BOOL  CConfigSecretary5::SetIsDemonStrongHoldOneKeyGetTreasureToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsDemonStrongHoldOneKeyGetTreasure,FALSE,b);

}





BOOL CConfigSecretary5::IsAsuramLeagueBossSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAsuramLeagueBossSelected);

}
BOOL CConfigSecretary5::SetIsAsuramLeagueBossSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAsuramLeagueBossSelected,FALSE,b);

}



int CConfigSecretary5::GetAsuramLeagueBossBuyExtraTimesFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szAsuramLeagueBossBuyExtraTimes);

}


BOOL CConfigSecretary5::SetAsuramLeagueBossBuyExtraTimesToCfg(int count)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szAsuramLeagueBossBuyExtraTimes,FALSE,count);

}



BOOL CConfigSecretary5::IsAsuramLeagueBossAutoShareMonsterChallengeFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAsuramLeagueBossAutoShareMonsterChallenge);

}


BOOL CConfigSecretary5::SetIsAsuramLeagueBossAutoShareMonsterChallengeToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAsuramLeagueBossAutoShareMonsterChallenge,FALSE,b);

}



BOOL CConfigSecretary5::IsAsuramLeagueBossAutoExchangeTreasureFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAsuramLeagueBossAutoExchangeTreasure);

}


BOOL CConfigSecretary5::SetIsAsuramLeagueBossAutoExchangeTreasureToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAsuramLeagueBossAutoExchangeTreasure,FALSE,b);

}



BOOL CConfigSecretary5::IsAutoMeceneryDispathSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAutoMeceneryDispathSelected);

}


BOOL CConfigSecretary5::SetIsAutoMeceneryDispathSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAutoMeceneryDispathSelected,FALSE,b);

}



int CConfigSecretary5::GetMeceneryDispathStarLevelFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szMeceneryDispathStarLevel);

}


BOOL CConfigSecretary5::SetMeceneryDispathStarLevelToCfg(int level)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szMeceneryDispathStarLevel,FALSE,level);

}



BOOL CConfigSecretary5::IsMeceneryDispathContinueWhenNoUnitsFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsMeceneryDispathContinueWhenNoUnits);

}


BOOL CConfigSecretary5::SetIsMeceneryDispathContinueWhenNoUnitsToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsMeceneryDispathContinueWhenNoUnits,FALSE,b);

}


BOOL CConfigSecretary5::IsMeceneryDispathAutoDoTaskFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsMeceneryDispathAutoDoTask);

}

BOOL CConfigSecretary5::SetIsMeceneryDispathAutoDoTaskToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsMeceneryDispathAutoDoTask,FALSE,b);

}


BOOL CConfigSecretary5::IsMeceneryDispathAutoBuyHandCemeceryFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsMeceneryDispathAutoBuyHandCemecery);

}

BOOL CConfigSecretary5::SetIsMeceneryDispathAutoBuyHandCemeceryToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsMeceneryDispathAutoBuyHandCemecery,FALSE,b);

}