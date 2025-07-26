#include "NeutralBossConfig.h"

static TCHAR *g_szNeutralBossList=_T("NeutralBossList");
static TCHAR *g_szIsNeutralBossSelected=_T("IsNeutralBossSelected");
static TCHAR *g_szNeutralBossMaxTimeout=_T("NeutralBossMaxTimeout");
static TCHAR *g_szNeutralBossKillMode=_T("NeutralBossKillMode");

CNeutralBossConfig::CNeutralBossConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt):CBossConfig(szFileName,bUseEncryptDecrypt)
{
	Init();
}

CNeutralBossConfig::~CNeutralBossConfig(void)
{
}


void CNeutralBossConfig::Init()
{
	m_szBossList=g_szNeutralBossList;
	m_szIsBossSelected=g_szIsNeutralBossSelected;
	m_szBossMaxTimeout=g_szNeutralBossMaxTimeout;
	m_szBossKillMode=g_szNeutralBossKillMode;
}

BOOL CNeutralBossConfig::IsNeutralBossSelectedFromCfg()
{
	return CBossConfig::IsBossSelectedFromCfg();
}


void CNeutralBossConfig::SetIsNeutralBossSelectedToCfg(BOOL b)
{
	CBossConfig::SetIsBossSelectedToCfg(b);
}



void CNeutralBossConfig::SetNeutralBossListSelectedToCfg(vector<int> &arr)
{
	CBossConfig::SetBossListSelectedToCfg(arr);

}


vector<int> CNeutralBossConfig::GetNeutralBossSelectedListFromCfg()
{
	return CBossConfig::GetBossSelectedListFromCfg();
}


