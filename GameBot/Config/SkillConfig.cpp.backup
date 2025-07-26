#include "SkillConfig.h"
static TCHAR *g_szKeyzSkillList=_T("SkillList");
static TCHAR *g_szKeyJobSkill=_T("JobSkill");
static TCHAR *g_szKeySkillTargetX=_T("SkillTargetX");
static TCHAR *g_szKeySkillTargetY=_T("SkillTargetY");
static TCHAR *g_szKeySkillSendInterval=_T("SkillSendInterval");


CSkillConfig::CSkillConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt):CConfig(szFileName,bUseEncryptDecrypt)
{
	Init();
}

CSkillConfig::~CSkillConfig(void)
{
}


void CSkillConfig::Init()
{
	m_sectionName=g_szDefSectionName;
	m_szSkillList=g_szKeyzSkillList;
	m_szJobType=g_szKeyJobSkill;

}


void CSkillConfig::SetSkillListSelectedToCfg(vector<int> &arr)
{
	TCHAR buf[MAX_PATH];
	STRING result;
	vector<int>::iterator it=arr.begin();
	while(it != arr.end())
	{
		_stprintf(buf,_T("%d,"),*it);
		result+=buf;
		++it;
	}
	if(result.length()>0)
	{
		result.erase(result.length()-1,1);
	}
	CConfig::Write(m_sectionName.c_str(),m_szSkillList,result.c_str());

}


vector<int> CSkillConfig::GetSkillSelectedListFromCfg()
{
	vector<int> result;
	STRING strList=CConfig::Read(m_sectionName.c_str(),m_szSkillList);
	

	return result;

}

int CSkillConfig::GetJobSkillTypeFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szKeyJobSkill);
}


void CSkillConfig::SetJobSkillTypeToCfg(int job)
{

	CConfig::WriteInt(m_sectionName.c_str(),g_szKeyJobSkill,0,job);
}




int CSkillConfig::GetSkillTargetXFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szKeySkillTargetX);

}

void CSkillConfig::SetSkillTargetXToCfg(int x)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szKeySkillTargetX,0,x);

}

int CSkillConfig::GetSkillTargetYFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szKeySkillTargetY);

}

void CSkillConfig::SetSkillTargetYToCfg(int y)
{
	CConfig::WriteInt(m_sectionName.c_str(),g_szKeySkillTargetY,0,y);

}


int CSkillConfig::GetSkillSendIntervalFromCfg()
{
	return CConfig::ReadInt(m_sectionName.c_str(),g_szKeySkillSendInterval);

}


void CSkillConfig::SetSkillSendIntervalToCfg(int intval)
{
	int def=0;
	CConfig::WriteInt(m_sectionName.c_str(),g_szKeySkillSendInterval,def,intval);

}