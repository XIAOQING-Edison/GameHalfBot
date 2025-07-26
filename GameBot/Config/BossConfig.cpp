#include "BossConfig.h"



CBossConfig::CBossConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt):CConfig(szFileName,bUseEncryptDecrypt)
{
	Init();
}

CBossConfig::~CBossConfig(void)
{
}

void CBossConfig::Init()
{
	m_szBossList=m_szIsBossSelected=NULL;
	m_szBossMaxTimeout=NULL;
	m_szBossKillMode=NULL;
}



BOOL CBossConfig::IsBossSelectedFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),m_szIsBossSelected);

}


void CBossConfig::SetIsBossSelectedToCfg(BOOL b)
{
	CConfig::WriteInt(m_sectionName.c_str(),m_szIsBossSelected,0,b);
}



void CBossConfig::SetBossListSelectedToCfg(vector<int> &arr)
{
	TCHAR buf[MAX_PATH];
	STRING result;
	CConfig::Write(m_sectionName.c_str(),m_szBossList,result.c_str());

}


vector<int> CBossConfig::GetBossSelectedListFromCfg()
{
	vector<int> result;
	STRING strList=CConfig::Read(m_sectionName.c_str(),m_szBossList);
	return result;

}

void CBossConfig::SetBossMaxTimeoutToCfg(int minutes)
{
	CConfig::WriteInt(m_sectionName.c_str(),m_szBossMaxTimeout,5,minutes);

}


int CBossConfig::GetBossMaxTimeoutFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),m_szBossMaxTimeout,5);
}


void CBossConfig::SetBossKillModeToCfg(int mode)	//手动或自动模式
{
	CConfig::WriteInt(m_sectionName.c_str(),m_szBossKillMode,0,mode);

}


int CBossConfig::GetBossKillModeFromCfg()	//手动或自动模式
{
	return CConfig::ReadInt(m_sectionName.c_str(),m_szBossKillMode,0);

}
