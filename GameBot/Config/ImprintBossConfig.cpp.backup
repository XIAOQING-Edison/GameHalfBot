#include "ImprintBossConfig.h"


static TCHAR *g_szImprintBossList=_T("ImprintBossList");
static TCHAR *g_szIsImprintBossSelected=_T("IsImprintBossSelected");


CImprintBossConfig::CImprintBossConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt):CBossConfig(szFileName,bUseEncryptDecrypt)
{
	Init();
}

CImprintBossConfig::~CImprintBossConfig(void)
{
}


void CImprintBossConfig::Init()
{
	m_szBossList=g_szImprintBossList;
	m_szIsBossSelected=g_szIsImprintBossSelected;
}

BOOL CImprintBossConfig::IsImprintBossSelectedFromCfg()
{
	return CBossConfig::IsBossSelectedFromCfg();
}


void CImprintBossConfig::SetIsImprintBossSelectedToCfg(BOOL b)
{
	CBossConfig::SetIsBossSelectedToCfg(b);
}



void CImprintBossConfig::SetImprintBossListSelectedToCfg(vector<int> &arr)
{
	CBossConfig::SetBossListSelectedToCfg(arr);

}


vector<int> CImprintBossConfig::GetImprintBossSelectedListFromCfg()
{
	return CBossConfig::GetBossSelectedListFromCfg();
}


