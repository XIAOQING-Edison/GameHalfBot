#pragma once
#include "BossConfig.h"

class CNeutralBossConfig :
	public CBossConfig
{
public:
	CNeutralBossConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	~CNeutralBossConfig(void);

	BOOL IsNeutralBossSelectedFromCfg();
	void SetIsNeutralBossSelectedToCfg(BOOL b);

	void SetNeutralBossListSelectedToCfg(vector<int> &arr);
	vector<int> GetNeutralBossSelectedListFromCfg();

	void Init();
};
