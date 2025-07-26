#pragma once
#include "bossconfig.h"

class CImprintBossConfig :
	public CBossConfig
{
public:
	CImprintBossConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	~CImprintBossConfig(void);

	BOOL IsImprintBossSelectedFromCfg();
	void SetIsImprintBossSelectedToCfg(BOOL b);

	void SetImprintBossListSelectedToCfg(vector<int> &arr);
	vector<int> GetImprintBossSelectedListFromCfg();

	void Init();
};
