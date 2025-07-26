#pragma once
#include "config.h"

class CSkillConfig :
	public CConfig
{
public:
	CSkillConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	virtual ~CSkillConfig(void);

	void Init();

	void SetSkillListSelectedToCfg(vector<int> &arr);
	vector<int> GetSkillSelectedListFromCfg();

	int GetJobSkillTypeFromCfg();
	void SetJobSkillTypeToCfg(int job);

	int GetSkillTargetXFromCfg();
	void SetSkillTargetXToCfg(int x);

	int GetSkillTargetYFromCfg();
	void SetSkillTargetYToCfg(int y);

	int GetSkillSendIntervalFromCfg();
	void SetSkillSendIntervalToCfg(int intval);
private:
	TCHAR *m_szSkillList;	//skill列表字段,会在初始化赋值
	TCHAR *m_szJobType;	//选择的职业类型
	TCHAR *g_szTargetX;	//x坐标
	TCHAR *g_szTargetY;	//y坐标

};
