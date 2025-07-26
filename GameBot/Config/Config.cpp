// Config.cpp: implementation of the CConfig class.
//
//////////////////////////////////////////////////////////////////////
#include "Config.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#define BUF_SIZE 1024*4
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConfig::CConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt)
{
	STRING fullFineMame=GetCurrentDllModuleFolderPath()+g_szConfigPath+szFileName;
	//GetCurrentAppPath()+g_szConfigPath+szFileName;
	m_fileName=fullFineMame;
	m_bUseEncryptDecrypt=bUseEncryptDecrypt;
	//m_fileName.Format("%s"),szFileName);
}


CConfig::CConfig(const TCHAR *szPath,const TCHAR *szFileName,int gameVersion,bool bUseEncryptDecrypt)	//这个用以加载某特定版本的ini
{
	TCHAR buf[MAX_PATH];
	_stprintf(buf,_T("%s%d\\%s%s"),szPath,gameVersion,g_szConfigPath,szFileName);//game version
	m_fileName=buf;
	m_bUseEncryptDecrypt=bUseEncryptDecrypt;
}

CConfig::~CConfig()
{

}


STRING CConfig::Read(const TCHAR *szSection,const TCHAR *szKey,const TCHAR *szDefault,const TCHAR *szRetBuf,DWORD sz)
{
	STRING str;
	STRING lpDefault(_T(""));
	CFileHelper::GetInstance()->LockFile(m_bUseEncryptDecrypt);
	CFileHelper::GetInstance()->DecryptFile(m_fileName.c_str(),m_bUseEncryptDecrypt);
	if(sz==0)
	{
		sz=BUF_SIZE;
	}
	str.resize(sz);
	::GetPrivateProfileString(szSection,szKey,lpDefault.c_str(),(LPTSTR)str.c_str(),sz,m_fileName.c_str());
	str.resize(_tcslen(str.c_str()));
	CFileHelper::GetInstance()->EncryptFile(m_fileName.c_str(),m_bUseEncryptDecrypt);
	CFileHelper::GetInstance()->UnlockFile(m_bUseEncryptDecrypt);
	return str;
}



BOOL CConfig::Write(const TCHAR *szSection,const TCHAR *szKey,const TCHAR *szValue)
{
	BOOL ret=FALSE;	
	CFileHelper::GetInstance()->LockFile(m_bUseEncryptDecrypt);
	CFileHelper::GetInstance()->DecryptFile(m_fileName.c_str(),m_bUseEncryptDecrypt);
	ret=::WritePrivateProfileString(szSection,szKey,szValue,m_fileName.c_str());
	CFileHelper::GetInstance()->EncryptFile(m_fileName.c_str(),m_bUseEncryptDecrypt);
	CFileHelper::GetInstance()->UnlockFile(m_bUseEncryptDecrypt);
	return ret;
}



UINT CConfig::ReadInt(const TCHAR *szSection,const TCHAR *szKey,UINT def)
{
	BOOL ret=FALSE;	
	CFileHelper::GetInstance()->LockFile(m_bUseEncryptDecrypt);
	CFileHelper::GetInstance()->DecryptFile(m_fileName.c_str(),m_bUseEncryptDecrypt);
	ret=::GetPrivateProfileInt(szSection,szKey,def,m_fileName.c_str());
	CFileHelper::GetInstance()->EncryptFile(m_fileName.c_str(),m_bUseEncryptDecrypt);
	CFileHelper::GetInstance()->UnlockFile(m_bUseEncryptDecrypt);
	return ret;
}



BOOL CConfig::WriteInt(const TCHAR *szSection,const TCHAR *szKey,UINT def,UINT value)
{
	TCHAR szValue[MAX_PATH];
	BOOL ret=FALSE;
	memset(szValue,0,sizeof(szValue));
	_stprintf(szValue,_T("%d"),value);
	CFileHelper::GetInstance()->LockFile(m_bUseEncryptDecrypt);
	CFileHelper::GetInstance()->DecryptFile(m_fileName.c_str(),m_bUseEncryptDecrypt);
	ret=::WritePrivateProfileString(szSection,szKey,szValue,m_fileName.c_str());
	CFileHelper::GetInstance()->EncryptFile(m_fileName.c_str(),m_bUseEncryptDecrypt);
	CFileHelper::GetInstance()->UnlockFile(m_bUseEncryptDecrypt);
	return ret;
}


vector<int> CConfig::ReadIntArray(const TCHAR* szSection,const TCHAR *szKey)	//读int数组
{
	vector<int> result;
	STRING strList=CConfig::Read(szSection,szKey);

	return result;
}


BOOL CConfig::WriteIntArray(const TCHAR *szSection,const TCHAR *szKey,vector<int> &arr)	//写int数组
{
	TCHAR buf[MAX_PATH];
	STRING result;
	return CConfig::Write(szSection,szKey,result.c_str());
}