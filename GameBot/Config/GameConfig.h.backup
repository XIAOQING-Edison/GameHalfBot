#pragma once
#include "config.h"

class CBossConfig;
class CConfigSecretary1;
class CConfigSecretary2;
class CConfigSecretary3;
class CConfigSecretary4;
class CConfigSecretary5;

class CGiftHallConfig;
class COtherTaskConfig;
class CSystemConfig;
class CUserConfig;

class CNeutralBossConfig;
class CWorldBossConfig;
class CCrossBossConfig;
class CLocalCorpsBossConfig;
class CCrossCorpsBossConfig;
class CBeastBossConfig;
class CBossAssistConfig;
class CSkillConfig;
class CImprintBossConfig;

class CGameConfig :public CConfig
{
public:
	CGameConfig(STRING &accountName,bool bUseEncryptDecrypt);
	CGameConfig(STRING &accountName,bool bUseParentDir,bool bUseEncryptDecrypt);	//这里用一个标志来决定是否使用parent目录
	~CGameConfig(void);
	
	void SetUserName(STRING &user){m_userName=user;m_sectionName=user;}


	vector<STRING> GetAllSectionNameFromConfig(STRING &fileName);

	void InitConfigObjects(const TCHAR *szFileName);
	void InitConfigObjectsBySetPath(const TCHAR *szFullPath);	//为其它配置对象设定一个全路径

	void DeleteConfigObjects();

	STRING GetFullFilePath(){return m_fileName;}


	CConfigSecretary1 *GetConfigSecretary1(){return m_pConfigSecreatry1;}
	CConfigSecretary2 *GetConfigSecretary2(){return m_pConfigSecretary2;}
	CConfigSecretary3 *GetConfigSecretary3(){return m_pConfigSecretary3;}
	CConfigSecretary4 *GetConfigSecretary4(){return m_pConfigSecretary4;}
	CConfigSecretary5 *GetConfigSecretary5(){return m_pConfigSecretary5;}



	COtherTaskConfig *GetOtherTaskConfig(){return m_pOtherTaskConfig;}
	CSystemConfig *GetSystemConfig(){return m_pSystemConfig;}
	CGiftHallConfig *GetGiftHallConfig(){return m_pGiftHallConfig;}
	CBossConfig *GetBossConfig(){return m_pBossConfig;}
	CUserConfig *GetUserConfig(){return m_pUserConfig;}

	CNeutralBossConfig *GetNeutralBossConfig(){return m_pNeutralBossConfig;}
	CWorldBossConfig *GetWorldBossConfig(){return m_pWorldBossConfig;}
	CCrossBossConfig *GetCrossBossConfig(){return m_pCrossBossConfig;}
	CLocalCorpsBossConfig *GetLocalCorpsBossConfig(){return m_pLocalCorpsBossConfig;}
	CCrossCorpsBossConfig *GetCrossCorpsBossConfig(){return m_pCrossCorpsBossConfig;}
	CBeastBossConfig *GetBeastBossConfig(){return m_pBeastBossConfig;}

	CBossAssistConfig *GetBossAssistConfig(){return m_pBossAssistConfig;}

	CSkillConfig *GetSkillConfig(){return m_pSkillConfig;}

	void SetAllObjectSectionNames();


private:
	STRING m_userName;	//作为sectionName
	CConfigSecretary1 *m_pConfigSecreatry1;
	CConfigSecretary2 *m_pConfigSecretary2;
	CConfigSecretary3 *m_pConfigSecretary3;
	CConfigSecretary4 *m_pConfigSecretary4;
	CConfigSecretary5 *m_pConfigSecretary5;


	CUserConfig *m_pUserConfig;
	COtherTaskConfig *m_pOtherTaskConfig;
	CSystemConfig *m_pSystemConfig;
	CGiftHallConfig *m_pGiftHallConfig;
	CBossConfig *m_pBossConfig;
	
	CNeutralBossConfig *m_pNeutralBossConfig;
	CWorldBossConfig *m_pWorldBossConfig;
	CCrossBossConfig *m_pCrossBossConfig;
	CLocalCorpsBossConfig *m_pLocalCorpsBossConfig;
	CCrossCorpsBossConfig *m_pCrossCorpsBossConfig;
	CBeastBossConfig *m_pBeastBossConfig;

	CBossAssistConfig *m_pBossAssistConfig;
	CImprintBossConfig *m_pImprintBossConfig;
	CSkillConfig *m_pSkillConfig;
};
