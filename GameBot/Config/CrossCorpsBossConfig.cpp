#include "CrossCorpsBossConfig.h"


static TCHAR *g_szCrossCorpsBossList=_T("CrossCorpsBossList");
static TCHAR *g_szIsCrossCorpsBossSelected=_T("IsCrossCorpsBossSelected");
static TCHAR *g_szCrossCorpsBossMaxTimeout=_T("CrossCorpsBossMaxTimeout");
static TCHAR *g_szCrossCorpsBossKillMode=_T("CrossCorpsBossKillMode");


CCrossCorpsBossConfig::CCrossCorpsBossConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt):CBossConfig(szFileName,bUseEncryptDecrypt)
{
	Init();
}

CCrossCorpsBossConfig::~CCrossCorpsBossConfig(void)
{
}


void CCrossCorpsBossConfig::Init()
{
	m_szBossList=g_szCrossCorpsBossList;
	m_szIsBossSelected=g_szIsCrossCorpsBossSelected;
	m_szBossMaxTimeout=g_szCrossCorpsBossMaxTimeout;
	m_szBossKillMode=g_szCrossCorpsBossKillMode;
}

BOOL CCrossCorpsBossConfig::IsCrossCorpsBossSelectedFromCfg()
{
	return CBossConfig::IsBossSelectedFromCfg();
}


void CCrossCorpsBossConfig::SetIsCrossCorpsBossSelectedToCfg(BOOL b)
{
	CBossConfig::SetIsBossSelectedToCfg(b);
}



void CCrossCorpsBossConfig::SetCrossCorpsBossListSelectedToCfg(vector<int> &arr)
{
	CBossConfig::SetBossListSelectedToCfg(arr);

}


vector<int> CCrossCorpsBossConfig::GetCrossCorpsBossSelectedListFromCfg()
{
	return CBossConfig::GetBossSelectedListFromCfg();
}
