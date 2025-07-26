#pragma once
#include "config.h"

class CGlobalConfig :
	public CConfig
{
public:
	CGlobalConfig(bool bUseEncryptDecrypt=true);
	virtual ~CGlobalConfig(void);

	void SetHotKeyStructStartToCfg(void *keyStruct);	//
	void GetHotKeyStructStartFromCfg(void *keyStruct);

	void SetHotKeyStructPauseToCfg(void *keyStruct);	//
	void GetHotKeyStructPauseFromCfg(void *keyStruct);

private:
	void ReadHotKeyStructFromCfgInternal(void *keyStruct,const TCHAR *szKeyName);
	void WriteHotKeyStructToCfgInternal(void *keyStruct,const TCHAR *szKeyName);
};
