#include "CrossBossConfig.h"


static TCHAR *g_szCrossBossList=_T("CrossBossList");
static TCHAR *g_szIsCrossBossSelected=_T("IsCrossBossSelected");
static TCHAR *g_szCrossBossMaxTimeout=_T("CrossBossMaxTimeout");
static TCHAR *g_szCrossBossKillMode=_T("CrossBossKillMode");

CCrossBossConfig::CCrossBossConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt):CBossConfig(szFileName,bUseEncryptDecrypt)
{
	Init();
}

CCrossBossConfig::~CCrossBossConfig(void)
{
}


void CCrossBossConfig::Init()
{
	m_szIsBossSelected=g_szIsCrossBossSelected;
	m_szBossList=g_szCrossBossList;
	m_szBossMaxTimeout=g_szCrossBossMaxTimeout;
	m_szBossKillMode=g_szCrossBossKillMode;
}




BOOL CCrossBossConfig::IsCrossBossSelectedFromCfg()
{
	return CBossConfig::IsBossSelectedFromCfg();
}


void CCrossBossConfig::SetIsCrossBossSelectedToCfg(BOOL b)
{
	CBossConfig::SetIsBossSelectedToCfg(b);
}



void CCrossBossConfig::SetCrossBossListSelectedToCfg(vector<int> &arr)
{
	CBossConfig::SetBossListSelectedToCfg(arr);

}


vector<int> CCrossBossConfig::GetCrossBossSelectedListFromCfg()
{
	return CBossConfig::GetBossSelectedListFromCfg();
}


