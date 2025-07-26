#pragma once
#include "config.h"

class CConfigSecretary2 :public CConfig
{
public:
	CConfigSecretary2(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	~CConfigSecretary2(void);

	BOOL IsAutoDemonPlazaSelectedFromCfg();
	BOOL SetIsAutoDemonPlazaSelectedToCfg(BOOL b);

	BOOL IsDemonPlazaAutoComposeTicketFromCfg();
	BOOL SetIsDemonPlazaAutoComposeTicketToCfg(BOOL b);

	BOOL IsDemonPlazaBuyTicketWhenNotEnoughFromCfg();
	BOOL SetIsDemonPlazaBuyTicketWhenNotEnoughToCfg(BOOL b);

	
	BOOL GetDemonPlazaHungUpPointXFromCfg();
	BOOL SetDemonPlazaHungUpPointXToCfg(int x);


	BOOL GetDemonPlazaHungUpPointYFromCfg();
	BOOL SetDemonPlazaHungUpPointYToCfg(int y);


	vector<int> GetDemonPlazaTimeSelectArrayFromCfg();
	BOOL SetDemonPlazaTimeSelectArrayToCfg(vector<int> &timeSels);

};
