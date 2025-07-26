#pragma once
#include "config.h"

class CUserConfig :public CConfig
{
public:
	CUserConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	~CUserConfig(void);


	void SetUserNameToCfg(STRING &user);
	STRING GetUserNameFromCfg();

	void SetPasswordToCfg(STRING &pass);
	STRING GetPasswordFromCfg();

	void SetPlatformIdToCfg(int plat);
	int GetPlatformIdFromCfg();

	void SetServerIdToCfg(int id);
	int GetServerIdFromCfg();

	void SetCookieToCfg(STRING &cookie);
	STRING GetCookieFromCfg();

	BOOL IsUseCookieFromCfg();
	void SetIsUseCookieToCfg(BOOL b);

	BOOL IsChosenToStartFromCfg();
	void SetIsChosenToStartToCfg(BOOL b);

};
