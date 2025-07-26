#include "GameConfig.h"

#include "DailyTaskConfig.h"
#include "BotConfig.h"
#include "AsuramConfig.h"
#include "ConfigSecretary4.h"
#include "ConfigSecretary5.h"

#include "UserConfig.h"
#include "GiftHallConfig.h"
#include "BossConfig.h"
#include "OtherTaskConfig.h"
#include "SystemConfig.h"

#include "NeutralBossConfig.h"
#include "WorldBossConfig.h"
#include "CrossBossConfig.h"

#include "LocalCorpsBossConfig.h"
#include "CrossCorpsBossConfig.h"

#include "BeastBossConfig.h"
#include "BossAssistConfig.h"

#include "ImprintBossConfig.h"

#include "SkillConfig.h"

#include "../FileTools/FileHelper.h"


CGameConfig::CGameConfig(STRING &accountName,bool bUseEncryptDecrypt):CConfig(g_szMainGameCfgName,bUseEncryptDecrypt)
{
	m_userName=accountName;
	m_sectionName=m_userName;
}

//不使用父类的目录构造方法
CGameConfig::CGameConfig(STRING &accountName,bool bUseParentDir,bool bUseEncryptDecrypt):CConfig(_T(""),bUseEncryptDecrypt)	//这里用一个标志来决定是否使用parent目录
{
	m_userName=accountName;
	m_sectionName=m_userName;
}

CGameConfig::~CGameConfig(void)
{
}



vector<STRING> CGameConfig::GetAllSectionNameFromConfig(STRING &fileName)
{
	vector<STRING> result;
	return result;
}



void CGameConfig::InitConfigObjects(const TCHAR *szFileName)
{	
	
}


void CGameConfig::InitConfigObjectsBySetPath(const TCHAR *szFullPath)	//为其它配置对象设定一个全路径
{
	

}

void CGameConfig::DeleteConfigObjects()
{
	
}

void CGameConfig::SetAllObjectSectionNames()
{	
	

}

