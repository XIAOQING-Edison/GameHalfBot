#pragma once
#include "bossconfig.h"

class CCrossCorpsBossConfig :
	public CBossConfig
{
public:
	CCrossCorpsBossConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	~CCrossCorpsBossConfig(void);

	BOOL IsCrossCorpsBossSelectedFromCfg();
	void SetIsCrossCorpsBossSelectedToCfg(BOOL b);

	void SetCrossCorpsBossListSelectedToCfg(vector<int> &arr);
	vector<int> GetCrossCorpsBossSelectedListFromCfg();


	void Init();
};
