#pragma once
#include "bossconfig.h"


class CBeastBossConfig :
	public CBossConfig
{
public:
	CBeastBossConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	~CBeastBossConfig(void);

	BOOL IsBeastBossSelectedFromCfg();
	void SetIsBeastBossSelectedToCfg(BOOL b);

	void SetBeastBossListSelectedToCfg(vector<int> &arr);
	vector<int> GetBeastBossSelectedListFromCfg();


	void Init();
};
