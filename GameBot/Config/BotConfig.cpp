#include "BotConfig.h"

TCHAR *g_szIsAutoDemonPlazaSelected=_T("IsAutoDemonPlazaSelected");
TCHAR *g_szIsDemonPlazaAutoComposeTicket=_T("IsDemonPlazaAutoComposeTicket");
TCHAR *g_szIsDemonPlazaBuyTicketWhenNotEnough=_T("IsDemonPlazaBuyTicketWhenNotEnough");
TCHAR *g_szDemonPlazaHungUpPointX=_T("DemonPlazaHungUpPointX");
TCHAR *g_szDemonPlazaHungUpPointY=_T("DemonPlazaHungUpPointY");
TCHAR *g_szDemonPlazaTimeSelected=_T("DemonPlazaTimeSelected");

CConfigSecretary2::CConfigSecretary2(const TCHAR *szFileName,bool bUseEncryptDecrypt):CConfig(szFileName,bUseEncryptDecrypt)
{
}

CConfigSecretary2::~CConfigSecretary2(void)
{
}



BOOL CConfigSecretary2::IsAutoDemonPlazaSelectedFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsAutoDemonPlazaSelected);
}


BOOL CConfigSecretary2::SetIsAutoDemonPlazaSelectedToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsAutoDemonPlazaSelected,FALSE,b);
}



BOOL CConfigSecretary2::IsDemonPlazaAutoComposeTicketFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsDemonPlazaAutoComposeTicket);

}


BOOL CConfigSecretary2::SetIsDemonPlazaAutoComposeTicketToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsDemonPlazaAutoComposeTicket,FALSE,b);

}

BOOL CConfigSecretary2::IsDemonPlazaBuyTicketWhenNotEnoughFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsDemonPlazaBuyTicketWhenNotEnough);

}
BOOL CConfigSecretary2::SetIsDemonPlazaBuyTicketWhenNotEnoughToCfg(BOOL b)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szIsDemonPlazaBuyTicketWhenNotEnough,FALSE,b);

}


BOOL CConfigSecretary2::GetDemonPlazaHungUpPointXFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szDemonPlazaHungUpPointX);
}


BOOL CConfigSecretary2::SetDemonPlazaHungUpPointXToCfg(int x)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szDemonPlazaHungUpPointX,0,x);

}



BOOL CConfigSecretary2::GetDemonPlazaHungUpPointYFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szDemonPlazaHungUpPointY);

}


BOOL CConfigSecretary2::SetDemonPlazaHungUpPointYToCfg(int y)
{
	return CConfig::WriteInt(m_sectionName.c_str(),g_szDemonPlazaHungUpPointY,0,y);

}



vector<int> CConfigSecretary2::GetDemonPlazaTimeSelectArrayFromCfg()
{
	vector<int> result;
	

	return result;
}


BOOL CConfigSecretary2::SetDemonPlazaTimeSelectArrayToCfg(vector<int> &arr)
{
	TCHAR buf[MAX_PATH];
	STRING result;
	
	return CConfig::Write(m_sectionName.c_str(),g_szDemonPlazaTimeSelected,result.c_str());
}