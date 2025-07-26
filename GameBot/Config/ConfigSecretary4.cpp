#include "ConfigSecretary4.h"


TCHAR *g_szIsBlackMarshSelected=_T("IsBlackMarshSelected");
TCHAR *g_szBlackMarshAttr=_T("BlackMarshAttr");
TCHAR *g_szBlackMarshChallengeTimes=_T("BlackMarshChallengeTimes");
TCHAR *g_szBlackMarshHour=_T("BlackMarshHour");
TCHAR *g_szBlackMarshMinute=_T("BlackMarshMinute");
TCHAR *g_szIsBlackMarshBuyTicketWhenNotEnough=_T("IsBlackMarshBuyTicketWhenNotEnough");
TCHAR *g_szBlackMarshMonsterLevel=_T("BlackMarshMonsterLevel");
TCHAR *g_szIsPetIslandSelected=_T("IsPetIslandSelected");
TCHAR *g_szPetIslandChallengeCount=_T("PetIslandChallengeCount");
TCHAR *g_szPetIslandCatchMode=_T("PetIslandCatchMode");
TCHAR *g_szIsPetIslandBuyTicketWhenNotEnough=_T("IsPetIslandBuyTicketWhenNotEnough");
TCHAR *g_szIsFairLandSelected=_T("IsFairLandSelected");
TCHAR *g_szFairLandChallengeCount=_T("FairLandChallengeCount");
TCHAR *g_szIsFairLandBuyTicketWhenNotEnough=_T("IsFairLandBuyTicketWhenNotEnough");
TCHAR *g_szIsAsuramBountyTaskSelected=_T("IsAsuramBountyTaskSelected");
TCHAR *g_szIsAsuramItemDonate=_T("IsAsuramItemDonate");
TCHAR *g_szIsAsuramShopNereusSelected=_T("IsAsuramShopNereusSelected");
TCHAR *g_szIsAsuramShopGemStoneTicketSelected=_T("IsAsuramShopGemStoneTicketSelected");
TCHAR *g_szIsAsuramShopFairlandTicketSelected=_T("IsAsuramShopFairlandTicketSelected");
TCHAR *g_szIsAsuramShopLostMapSelected=_T("IsAsuramShopLostMapSelected");


CConfigSecretary4::CConfigSecretary4(const TCHAR *szFileName,bool bUseEncryptDecrypt):CConfig(szFileName,bUseEncryptDecrypt)
{
}

CConfigSecretary4::~CConfigSecretary4(void)
{
}


BOOL CConfigSecretary4::IsBlackMarshSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsBlackMarshSelected);
}


BOOL CConfigSecretary4::SetIsBlackMarshSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsBlackMarshSelected,FALSE,b);
}

int CConfigSecretary4::GetBlackMarshAttrFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szBlackMarshAttr);

}
BOOL CConfigSecretary4::SetBlackMarshAttrToCfg(int attr)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szBlackMarshAttr,FALSE,attr);

}

int CConfigSecretary4::GetBlackMarshChallengeTimesFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szBlackMarshChallengeTimes);

}
BOOL CConfigSecretary4::SetBlackMarshChallengeTimesToCfg(int times)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szBlackMarshChallengeTimes,FALSE,times);

}

int CConfigSecretary4::GetBlackMarshHourFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szBlackMarshHour);

}
BOOL CConfigSecretary4::SetBlackMarshHourToCfg(int hour)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szBlackMarshHour,FALSE,hour);

}

int CConfigSecretary4::GetBlackMarshMinuteFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szBlackMarshMinute);

}

BOOL CConfigSecretary4::SetBlackMarshMinuteToCfg(int minutes)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szBlackMarshMinute,FALSE,minutes);

}

BOOL CConfigSecretary4::IsBlackMarshBuyTicketWhenNotEnoughFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsBlackMarshBuyTicketWhenNotEnough);

}
BOOL CConfigSecretary4::SetIsBlackMarshBuyTicketWhenNotEnoughToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsBlackMarshBuyTicketWhenNotEnough,FALSE,b);

}


int CConfigSecretary4::GetBlackMarshMonsterLevelFromCfg()
{

	return CConfig::ReadInt(m_sectionName.c_str(),g_szBlackMarshMonsterLevel);


}


BOOL CConfigSecretary4::SetBlackMarshMonsterLevelToCfg(int lv)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szBlackMarshMonsterLevel,FALSE,lv);

}



BOOL CConfigSecretary4::IsPetIslandSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsPetIslandSelected);

}
BOOL CConfigSecretary4::SetIsPetIslandSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsPetIslandSelected,FALSE,b);

}

int CConfigSecretary4::GetPetIslandChallengeCountFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szPetIslandChallengeCount);

}
BOOL CConfigSecretary4::SetPetIslandChallengeCountToCfg(int count)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szPetIslandChallengeCount,FALSE,count);

}

int CConfigSecretary4::GetPetIslandCatchModeFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szPetIslandCatchMode);

}
BOOL CConfigSecretary4::SetPetIslandCatchModeToCfg(int mode)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szPetIslandCatchMode,FALSE,mode);

}

BOOL CConfigSecretary4::IsPetIslandBuyTicketWhenNotEnough()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsPetIslandBuyTicketWhenNotEnough);
}
BOOL CConfigSecretary4::SetIsPetIslandBuyTicketWhenNotEnough(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsPetIslandBuyTicketWhenNotEnough,FALSE,b);
}

BOOL CConfigSecretary4::IsFairLandSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsFairLandSelected);

}
BOOL CConfigSecretary4::SetIsFairLandSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsFairLandSelected,FALSE,b);

}

int CConfigSecretary4::GetFairLandChallengeCountFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szFairLandChallengeCount);

}
BOOL CConfigSecretary4::SetFairLandChallengeCountToCfg(int count)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szFairLandChallengeCount,FALSE,count);

}

BOOL CConfigSecretary4::IsFairLandBuyTicketWhenNotEnoughFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsFairLandBuyTicketWhenNotEnough);

}
BOOL CConfigSecretary4::SetIsFairLandBuyTicketWhenNotEnoughToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsFairLandBuyTicketWhenNotEnough,FALSE,b);

}

BOOL CConfigSecretary4::IsAsuramBountyTaskSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAsuramBountyTaskSelected);

}
BOOL CConfigSecretary4::SetIsAsuramBountyTaskSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAsuramBountyTaskSelected,FALSE,b);

}



BOOL CConfigSecretary4::IsAsuramItemDonateFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAsuramItemDonate);

}


BOOL CConfigSecretary4::SetIsAsuramItemDonateToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAsuramItemDonate,FALSE,b);

}



BOOL CConfigSecretary4::IsAsuramShopNereusSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAsuramShopNereusSelected);

}
BOOL CConfigSecretary4::SetIsAsuramShopNereusSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAsuramShopNereusSelected,FALSE,b);

}

BOOL CConfigSecretary4::IsAsuramShopGemStoneTicketSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAsuramShopGemStoneTicketSelected);

}
BOOL CConfigSecretary4::SetisAsuramShopGemStoneTicketSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAsuramShopGemStoneTicketSelected,FALSE,b);

}

BOOL CConfigSecretary4::IsAsuramShopFairlandTicketSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAsuramShopFairlandTicketSelected);

}
BOOL CConfigSecretary4::SetIsAsuramShopFairlandTicketSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAsuramShopFairlandTicketSelected,FALSE,b);

}

BOOL CConfigSecretary4::IsAsuramShopLostMapSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAsuramShopLostMapSelected);

}
BOOL CConfigSecretary4::SetIsAsuramShhopLostMapSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAsuramShopLostMapSelected,FALSE,b);

}