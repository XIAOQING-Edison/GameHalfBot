#include "OtherTaskConfig.h"


//world server
const TCHAR *g_szIsCrossServerCollectSelected=_T("IsCrossServerCollectSelected");

const TCHAR *g_szIsRedHoodSelected=_T("IsRedHoodSelected");
const TCHAR *g_szIsJoinWorldServerFight=_T("IsJoinWorldServerFight");
const TCHAR *g_szIsAutoLegionSignIn=_T("IsAutoLegionSignIn");


//other task
const TCHAR *g_szIsSpaceCorridorSelected=_T("IsSpaceCorridorSelected");
const TCHAR *g_szIsSpecialRoomSelected=_T("IsSpecialRoomSelected");
const TCHAR *g_szIsFastFightSelected=_T("IsFastFightSelected");
const TCHAR *g_szIsCampWarSelected=_T("IsCampWarSelected");
const TCHAR *g_szIsCertificateSelected=_T("IsCertificateSelected");//天使战令
const TCHAR *g_szIsPinkDiamondSelected=_T("IsPinkDiamondSelected");//粉钻福利
const TCHAR *g_szIsHorcruxSelected=_T("IsHorcruxSelected");
const TCHAR *g_szIsOriginalSinSelected=_T("IsOriginalSinSelected");	//原罪XXX
const TCHAR *g_szIsFairyLandSelected=_T("IsFairyLandSelected");	//原罪XXX
const TCHAR *g_szGetFairyLandCount=_T("GetFairyLandCount");
const TCHAR *g_szIsOrcGodBlessSelected=_T("IsOrcGodBlessSelected");







COtherTaskConfig::COtherTaskConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt):CConfig(szFileName,bUseEncryptDecrypt)
{
}

COtherTaskConfig::~COtherTaskConfig(void)
{
}



BOOL COtherTaskConfig::IsCrossServerCollectSelectedFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szIsCrossServerCollectSelected);
}


void COtherTaskConfig::SetCrossServerCollectToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsCrossServerCollectSelected,0,b);
}




BOOL COtherTaskConfig::IsRedHoodSelectedFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szIsRedHoodSelected);
}

void COtherTaskConfig::SetSelectRedHoodToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsRedHoodSelected,0,b);
}




BOOL COtherTaskConfig::IsJoinWorldServerFightFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szIsJoinWorldServerFight);

}

void COtherTaskConfig::SetJoinWorldServerFightToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsJoinWorldServerFight,0,b);

}



BOOL COtherTaskConfig::IsAutoLegionSignInFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szIsAutoLegionSignIn);
	
}

void COtherTaskConfig::SetAutoLegionSignInToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsAutoLegionSignIn,0,b);

}



//other task;
BOOL COtherTaskConfig::IsSpaceCorridorSelectedFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szIsSpaceCorridorSelected);

}

void COtherTaskConfig::SetSelectSpaceCorridorToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsSpaceCorridorSelected,0,b);

}


BOOL COtherTaskConfig::IsSpecialRoomSelectedFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szIsSpecialRoomSelected);

}

void COtherTaskConfig::SetSelectSpecialRoomToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsSpecialRoomSelected,0,b);
}



BOOL COtherTaskConfig::IsFastFightSelectedFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szIsFastFightSelected);

}

void COtherTaskConfig::SetSelectFastFightToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsFastFightSelected,0,b);

}


BOOL COtherTaskConfig::IsCampWarSelectedFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szIsCampWarSelected);

}

void COtherTaskConfig::SetSelectCampWarToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsCampWarSelected,0,b);

}


BOOL COtherTaskConfig::IsCertificateSelectedFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szIsCertificateSelected);

}

void COtherTaskConfig::SetSelectCertificateToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsCertificateSelected,0,b);

}



BOOL COtherTaskConfig::IsPinkDiamondSelectedFromcCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szIsPinkDiamondSelected);

}


void COtherTaskConfig::SetSelectPinkDiamondToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsPinkDiamondSelected,0,b);

}



BOOL COtherTaskConfig::IsHorcruxSelectedFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szIsHorcruxSelected);

}

void COtherTaskConfig::SetSelectHorcruxToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsHorcruxSelected,0,b);

}

BOOL COtherTaskConfig::IsOriginalSinSelectedFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szIsOriginalSinSelected);

}


void COtherTaskConfig::SetSelectOriginalSinToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsOriginalSinSelected,0,b);

}


BOOL COtherTaskConfig::IsFairyLandSelectedFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szIsFairyLandSelected);

}


void COtherTaskConfig::SetSelectFairyLandToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsFairyLandSelected,0,b);

}


int COtherTaskConfig::GetFairyLandCountFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szGetFairyLandCount);

}

void COtherTaskConfig::SetFairyLandCountToCfg(int count)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szGetFairyLandCount,0,count);

}


BOOL COtherTaskConfig::IsOrcGodBlessSelectedFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szIsOrcGodBlessSelected);

}

void COtherTaskConfig::SetSelectOrcGodBlessToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsOrcGodBlessSelected,0,b);

}
