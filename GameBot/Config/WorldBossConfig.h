#pragma once
#include "BossConfig.h"

class CWorldBossConfig :
	public CBossConfig
{
public:
	CWorldBossConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	~CWorldBossConfig(void);

	BOOL IsWorldBossSelectedFromCfg();
	void SetIsWorldBossSelectedToCfg(BOOL b);

	void SetWorldBossListSelectedToCfg(vector<int> &arr);
	vector<int> GetWorldBossSelectedListFromCfg();

	void Init();
};
