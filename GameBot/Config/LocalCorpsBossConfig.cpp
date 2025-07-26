#include "LocalCorpsBossConfig.h"


static TCHAR *g_szLocalCorpsBossList=_T("LocalCorpsBossList");
static TCHAR *g_szIsLocalCorpsBossSelected=_T("IsLocalCorpsBossSelected");
static TCHAR *g_szLocalCorpsBossMaxTimeout=_T("LocalCorpsBossMaxTimeout");
static TCHAR *g_szLocalCorpsBossKillMode=_T("LocalCorpsBossKillMode");


CLocalCorpsBossConfig::CLocalCorpsBossConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt):CBossConfig(szFileName,bUseEncryptDecrypt)
{
	Init();
}

CLocalCorpsBossConfig::~CLocalCorpsBossConfig(void)
{
}


void CLocalCorpsBossConfig::Init()
{
	m_szBossList=g_szLocalCorpsBossList;
	m_szIsBossSelected=g_szIsLocalCorpsBossSelected;
	m_szBossMaxTimeout=g_szLocalCorpsBossMaxTimeout;
	m_szBossKillMode=g_szLocalCorpsBossKillMode;
}

BOOL CLocalCorpsBossConfig::IsLocalCorpsBossSelectedFromCfg()
{
	return CBossConfig::IsBossSelectedFromCfg();
}


void CLocalCorpsBossConfig::SetIsLocalCorpsBossSelectedToCfg(BOOL b)
{
	CBossConfig::SetIsBossSelectedToCfg(b);
}



void CLocalCorpsBossConfig::SetLocalCorpsBossListSelectedToCfg(vector<int> &arr)
{
	CBossConfig::SetBossListSelectedToCfg(arr);

}


vector<int> CLocalCorpsBossConfig::GetLocalCorpsBossSelectedListFromCfg()
{
	return CBossConfig::GetBossSelectedListFromCfg();
}

