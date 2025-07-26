#pragma once
#include "config.h"


class CSystemConfig :
	public CConfig
{
public:
	CSystemConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	~CSystemConfig(void);

	//system
	BOOL IsXiaoHaoFromCfg();
	void SetXiaoHaoToCfg(BOOL b);


	int GetMinutesToReloginWhenLogoutByOtherFromCfg();
	void SetMinutesToReloginWhenLogoutByOtherToCfg(int mins);

	int GetMinutesToReloginWhenLogoutByDisconnectFromCfg();
	void SetMinutesToReloginWhenLogoutByDisconnectToCfg(int mins);

	int GetBindModeFromCfg();
	void SetBindModeToCfg(int mode);

	int GetReviveTypeFromCfg();
	void SetReviveTypeToCfg(int mode);

	int GetLoadMapMaxWaitSecondsFromCfg();	//����������Ϸ��Сʱ
	void SetLoadMapMaxWaitSecondsToCfg(int seconds);

};
