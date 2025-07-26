#include "WorldBossConfig.h"


static TCHAR *g_szWorldBossList=_T("WorldBossList");
static TCHAR *g_szIsWorldBossSelected=_T("IsWorldBossSelected");
static TCHAR *g_szWorldBossMaxTimout=_T("WorldBossMaxTimout");
static TCHAR *g_szWorldBossKillMode=_T("WorldBossKillMode");


CWorldBossConfig::CWorldBossConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt):CBossConfig(szFileName,bUseEncryptDecrypt)
{
	Init();
}

CWorldBossConfig::~CWorldBossConfig(void)
{
}


void CWorldBossConfig::Init()
{
	m_szIsBossSelected=g_szIsWorldBossSelected;
	m_szBossList=g_szWorldBossList;
	m_szBossMaxTimeout=g_szWorldBossMaxTimout;
	m_szBossKillMode=g_szWorldBossKillMode;
}




BOOL CWorldBossConfig::IsWorldBossSelectedFromCfg()
{
	return CBossConfig::IsBossSelectedFromCfg();
}


void CWorldBossConfig::SetIsWorldBossSelectedToCfg(BOOL b)
{
	CBossConfig::SetIsBossSelectedToCfg(b);
}



void CWorldBossConfig::SetWorldBossListSelectedToCfg(vector<int> &arr)
{
	CBossConfig::SetBossListSelectedToCfg(arr);

}


vector<int> CWorldBossConfig::GetWorldBossSelectedListFromCfg()
{
	return CBossConfig::GetBossSelectedListFromCfg();
}


