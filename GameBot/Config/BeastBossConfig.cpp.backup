#include "BeastBossConfig.h"


static TCHAR *g_szBeastBossList=_T("BeastBossList");
static TCHAR *g_szIsBeastBossSelected=_T("IsBeastBossSelected");
static TCHAR *g_szBeastBossMaxTimeout=_T("BeastBossMaxTimeout");


CBeastBossConfig::CBeastBossConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt):CBossConfig(szFileName,bUseEncryptDecrypt)
{
	Init();
}

CBeastBossConfig::~CBeastBossConfig(void)
{
}


void CBeastBossConfig::Init()
{
	m_szIsBossSelected=g_szIsBeastBossSelected;
	m_szBossList=g_szBeastBossList;
	m_szBossMaxTimeout=g_szBeastBossMaxTimeout;

}




BOOL CBeastBossConfig::IsBeastBossSelectedFromCfg()
{
	return CBossConfig::IsBossSelectedFromCfg();
}


void CBeastBossConfig::SetIsBeastBossSelectedToCfg(BOOL b)
{
	CBossConfig::SetIsBossSelectedToCfg(b);
}



void CBeastBossConfig::SetBeastBossListSelectedToCfg(vector<int> &arr)
{
	CBossConfig::SetBossListSelectedToCfg(arr);

}


vector<int> CBeastBossConfig::GetBeastBossSelectedListFromCfg()
{
	return CBossConfig::GetBossSelectedListFromCfg();
}
