#pragma once
#include "bossconfig.h"


class CCrossBossConfig :
	public CBossConfig
{
public:
	CCrossBossConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	~CCrossBossConfig(void);

	BOOL IsCrossBossSelectedFromCfg();
	void SetIsCrossBossSelectedToCfg(BOOL b);

	void SetCrossBossListSelectedToCfg(vector<int> &arr);
	vector<int> GetCrossBossSelectedListFromCfg();

	void Init();
};
