#pragma once
#include "bossconfig.h"

class CLocalCorpsBossConfig :
	public CBossConfig
{
public:
	CLocalCorpsBossConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	~CLocalCorpsBossConfig(void);

	BOOL IsLocalCorpsBossSelectedFromCfg();
	void SetIsLocalCorpsBossSelectedToCfg(BOOL b);

	void SetLocalCorpsBossListSelectedToCfg(vector<int> &arr);
	vector<int> GetLocalCorpsBossSelectedListFromCfg();


	
	void Init();
};
