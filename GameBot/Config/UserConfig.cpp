#include "UserConfig.h"



const TCHAR *g_szUserNameKey=_T("user");
const TCHAR *g_szPasswordKey=_T("password");
const TCHAR *g_szPlatformIndexKey=_T("platformIndex");
const TCHAR *g_szPlatformNameKey=_T("platformName");
const TCHAR *g_szServerIdKey=_T("serverId");
const TCHAR *g_szGameIdKey=_T("gameId");	//‘›Œ¥”√
const TCHAR *g_szUserCookie=_T("cookie");
const TCHAR *g_szIsUseCookie=_T("isUseCookie");
const TCHAR *g_szIsChosenToStart=_T("isChosenToStart");



CUserConfig::CUserConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt):CConfig(szFileName,bUseEncryptDecrypt)
{
}

CUserConfig::~CUserConfig(void)
{
}


void CUserConfig::SetUserNameToCfg(STRING &user)
{
	m_sectionName=user;
	CConfig::Write(m_sectionName.c_str(),g_szUserNameKey,user.c_str());
}


STRING CUserConfig::GetUserNameFromCfg()
{
	STRING res=CConfig::Read(m_sectionName.c_str(),g_szUserNameKey);
	if(res.length()==0)
	{
		res=m_sectionName;
	}
	return res;
}



void CUserConfig::SetPasswordToCfg(STRING &pass)
{
	CConfig::Write(m_sectionName.c_str(),g_szPasswordKey,pass.c_str());

}


STRING CUserConfig::GetPasswordFromCfg()
{
	STRING res=CConfig::Read(m_sectionName.c_str(),g_szPasswordKey);
	return res;
}


void CUserConfig::SetPlatformIdToCfg(int plat)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szPlatformIndexKey,0,plat);
}


int CUserConfig::GetPlatformIdFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szPlatformIndexKey);
}



void CUserConfig::SetServerIdToCfg(int id)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szServerIdKey,0,id);
}


int CUserConfig::GetServerIdFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szServerIdKey);
}



void CUserConfig::SetCookieToCfg(STRING &cookie)
{
	CConfig::Write(m_sectionName.c_str(),g_szUserCookie,cookie.c_str());	
}


STRING CUserConfig::GetCookieFromCfg()
{
	return CConfig::Read(m_sectionName.c_str(),g_szUserCookie);
}


BOOL CUserConfig::IsUseCookieFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsUseCookie);

}



void CUserConfig::SetIsUseCookieToCfg(BOOL b)
{	
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsUseCookie,0,b);
}


BOOL CUserConfig::IsChosenToStartFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsChosenToStart);

}


void CUserConfig::SetIsChosenToStartToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsChosenToStart,0,b);

}
