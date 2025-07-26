#include "PlatformConfig.h"

const TCHAR *g_szPlatformCfgName=_T("Platform.cfg");

CPlatformConfig::CPlatformConfig(bool bUseEncryptDecrypt):CConfig(g_szPlatformCfgName,bUseEncryptDecrypt)
{
	SetCfgFileName(g_szPlatformCfgName);
	SetPlatformId(-1);	//none platform
}

CPlatformConfig::~CPlatformConfig(void)
{
}



STRING CPlatformConfig::GetPlatformNameFromCfg()
{
	TCHAR buf[MAX_PATH];
	_stprintf(buf,_T("%d"),GetPlatformId());
	return CConfig::Read(g_szDefSectionName,buf);
}


void CPlatformConfig::SetPlatformNameToCfg(STRING &name)
{
	TCHAR buf[MAX_PATH];
	_stprintf(buf,_T("%d"),GetPlatformId());
	if(GetPlatformId() !=-1)
	{
		CConfig::Write(g_szDefSectionName,buf,name.c_str());
	}
}