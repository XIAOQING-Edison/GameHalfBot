#include "SystemConfig.h"


const int g_defDisconnetLogoutByOtherMin=3;	//玩家从另一个地方登陆，重连时间
const int g_defDisconnectByServerMin=1;	//服务器连接断开

//system
const TCHAR *g_szIsXiaoHao=_T("IsXiaoHao");
const TCHAR *g_szGetMinutesToReloginWhenLogoutByOther=_T("GetMinutesToReloginWhenLogoutByOther");
const TCHAR *g_szGetMinutesToReloginWhenLogoutWhenDisconnect=_T("GetMinutesToReloginWhenLogoutWhenDisconnect");

const TCHAR *g_szBindMode=_T("bindMode");
const TCHAR *g_szLoadMapMaxWaitSeconds=_T("LoadMapMaxWaitSeconds");

const TCHAR *g_szReviveType=_T("reviveType");

CSystemConfig::CSystemConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt):CConfig(szFileName,bUseEncryptDecrypt)
{

}

CSystemConfig::~CSystemConfig(void)
{
}



BOOL CSystemConfig::IsXiaoHaoFromCfg()
{
	return (BOOL)CConfig::ReadInt(m_sectionName.c_str(),g_szIsXiaoHao);
}


void CSystemConfig::SetXiaoHaoToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szIsXiaoHao,0,b);
}



int CSystemConfig::GetMinutesToReloginWhenLogoutByOtherFromCfg()
{
	UINT defValue=g_defDisconnetLogoutByOtherMin;
	return CConfig::ReadInt(m_sectionName.c_str(),g_szGetMinutesToReloginWhenLogoutByOther,defValue);
}


void CSystemConfig::SetMinutesToReloginWhenLogoutByOtherToCfg(int mins)
{
// 	UINT defValue=g_defDisconnetLogoutByOtherMin;
	CConfig::WriteInt(m_sectionName.c_str(),g_szGetMinutesToReloginWhenLogoutByOther,0,mins);
}



int CSystemConfig::GetMinutesToReloginWhenLogoutByDisconnectFromCfg()
{
	UINT defValue=g_defDisconnectByServerMin;
	return CConfig::ReadInt(m_sectionName.c_str(),g_szGetMinutesToReloginWhenLogoutWhenDisconnect,defValue);
}


void CSystemConfig::SetMinutesToReloginWhenLogoutByDisconnectToCfg(int mins)
{
// 	UINT defValue=g_defDisconnectByServerMin;
	CConfig::WriteInt(m_sectionName.c_str(),g_szGetMinutesToReloginWhenLogoutWhenDisconnect,0,mins);
}


int CSystemConfig::GetReviveTypeFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szReviveType);
}


void CSystemConfig::SetReviveTypeToCfg(int type)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szReviveType,0,type);

}



int CSystemConfig::GetBindModeFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szBindMode);

}


void CSystemConfig::SetBindModeToCfg(int mode)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szBindMode,0,mode);

}



int CSystemConfig::GetLoadMapMaxWaitSecondsFromCfg()	//重新连接游戏的小时
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szLoadMapMaxWaitSeconds,3);

}

void CSystemConfig::SetLoadMapMaxWaitSecondsToCfg(int seconds)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szLoadMapMaxWaitSeconds,3,seconds);

}

