#pragma once
#include "config.h"

class CPlatformConfig :
	public CConfig
{
public:
	CPlatformConfig(bool bUseEncryptDecrypt=true);
	~CPlatformConfig(void);

	STRING GetPlatformNameFromCfg();
	void SetPlatformNameToCfg(STRING &name);

	void SetPlatformId(int id){m_platformId=id;}
	int GetPlatformId(){return m_platformId;}

	TCHAR *GetCfgFileName(){return m_szFileName;}
	void SetCfgFileName(const TCHAR *szFile){m_szFileName=(TCHAR*)szFile;}
private:
	int m_platformId;
	TCHAR *m_szFileName;	//只包含文件名不含路径
	
};
