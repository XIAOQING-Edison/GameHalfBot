#include "DailyTaskConfig.h"



//daily task
TCHAR *g_szIsAutoHungUp=_T("IsAutoHungUp");	//是否自动挂机
TCHAR *g_szAutoHungUpPointX=_T("AutoHungUpPointX");//挂机点x
TCHAR *g_szAutoHungUpPointY=_T("AutoHungUpPointY");//挂机点y
TCHAR *g_szAutoHungUpMapId=_T("AutoHungUpMapId");//挂机点地图id
TCHAR *g_szHungUpMapType=_T("HungUpMapType");	//地图类型
TCHAR *g_szBloodCastleHungUpPointX=_T("BloodCastleHungUpPointX");	//血色挂机点x
TCHAR *g_szBloodCastleHungUpPointY=_T("BloodCastleHungUpPointY");	//血色挂机点y


TCHAR *g_szBloodCastleTimeSelected=_T("BloodCastleTimeSelected");

TCHAR *g_szIsBloodTownSelected=_T("IsBloodTownSelected");
TCHAR *g_szIsBloodTownUseDiamondWhenNotEnoughCoin=_T("IsBloodTownUseDiamondWhenNotEnoughCoin");
TCHAR *g_szIsUseSelfSkillsWhenSeeOtherPlayer=_T("IsUseSelfSkillsWhenSeeOtherPlayer");
TCHAR *g_szIsBloodTownUseExpPotion=_T("IsBloodTownUseExpPotion");
TCHAR *g_szIsBloodTownAutoComposeTicket=_T("IsBloodTownAutoComposeTicket");

TCHAR *g_szIsAutoCounterStrike=_T("IsAutoCounterStrike");
TCHAR *g_szIsAutoCounterStrikeUsingConfigSkills=_T("IsAutoCounterStrikeUsingConfigSkills");
TCHAR *g_szPkMode=_T("PkMode");

CConfigSecretary1::CConfigSecretary1(const TCHAR *szFileName,bool bUseEncryptDecrypt):CConfig(szFileName,bUseEncryptDecrypt)
{

}

CConfigSecretary1::~CConfigSecretary1(void)
{
}



BOOL CConfigSecretary1::IsAutoHungUpFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAutoHungUp);
}

BOOL CConfigSecretary1::SetIsAutoHungUpToCfg(BOOL b)
{
	return (BOOL)CConfig::WriteInt(m_sectionName.c_str(),g_szIsAutoHungUp,FALSE,b);;
}

int CConfigSecretary1::GetAutoHungUpPointXFromCfg()//挂机点x
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szAutoHungUpPointX);
}

BOOL CConfigSecretary1::SetAutoHungUpPointXToCfg(int count)//挂机点x
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szAutoHungUpPointX,FALSE,count);
}	

int CConfigSecretary1::GetAutoHungUpPointYFromCfg()//挂机点y
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szAutoHungUpPointY);
}

BOOL CConfigSecretary1::SetAutoHungUpPointYToCfg(int count)//挂机点y
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szAutoHungUpPointY,FALSE,count);
}


int CConfigSecretary1::GetHungUpMapTypeFromCfg()	//挂机地图类型
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szHungUpMapType);

}

BOOL CConfigSecretary1::SetHungUpMapTypeToCfg(int sel)	//挂机地图类型
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szHungUpMapType,FALSE,sel);

}

int CConfigSecretary1::GetAutoHungUpMapIndexCfg()	//自动领奖
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szAutoHungUpMapId);
}

BOOL CConfigSecretary1::SetAutoHungUpMapIdToCfg(int mapId)	//自动领奖
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szAutoHungUpMapId,FALSE,mapId);
}

vector<int> CConfigSecretary1::GetBloodCastleTimeSelectArrayFromCfg()
{
	vector<int> result;

	return result;
}

BOOL CConfigSecretary1::SetBloodCastleTimeSelectArrayToCfg(vector<int> &arr)
{
	TCHAR buf[MAX_PATH];
	STRING result;
	return CConfig::Write(m_sectionName.c_str(),g_szBloodCastleTimeSelected,result.c_str());

}

BOOL CConfigSecretary1::IsBloodCastleSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsBloodTownSelected);

}

BOOL CConfigSecretary1::SetIsBloodTownSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsBloodTownSelected,FALSE,b);

}

int CConfigSecretary1::GetBloodCastleHungUpPointXFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szBloodCastleHungUpPointX);

}

BOOL CConfigSecretary1::SetBloodCastleHungUpPointXToCfg(int x)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szBloodCastleHungUpPointX,0,x);

}


int CConfigSecretary1::GetBloodCastleHungUpPointYFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szBloodCastleHungUpPointY);

}

BOOL CConfigSecretary1::SetBloodCastleHungUpPointYToCfg(int y)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szBloodCastleHungUpPointY,0,y);

}

BOOL CConfigSecretary1::IsUseSelfSkillsWhenSeeOtherPlayerFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsUseSelfSkillsWhenSeeOtherPlayer);

}


BOOL CConfigSecretary1::SetIsUseSelfSkillsWhenSeeOtherPlayerToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsUseSelfSkillsWhenSeeOtherPlayer,FALSE,b);
}





BOOL CConfigSecretary1::IsBloodTownAutoComposeTicketFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsBloodTownAutoComposeTicket);
}


BOOL CConfigSecretary1::SetIsBloodTownBloodTownAutoComposeTicketToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsBloodTownAutoComposeTicket,FALSE,b);

}


BOOL CConfigSecretary1::IsAutoCounterStrikeFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAutoCounterStrike);

}


BOOL CConfigSecretary1::SetIsAutoCounterStrikeToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAutoCounterStrike,FALSE,b);
}


BOOL CConfigSecretary1::IsAutoCounterStrikeUsingConfigSkillsFromCfg()	//是否使用配置里的技能
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAutoCounterStrikeUsingConfigSkills);

}


BOOL CConfigSecretary1::SetIsAutoCounterStrikeUsingConfigSkillsToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAutoCounterStrikeUsingConfigSkills,FALSE,b);
}

int CConfigSecretary1::GetPkModeFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szPkMode);
}


BOOL CConfigSecretary1::SetPkModeToCfg(int m)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szPkMode,0,m);
}