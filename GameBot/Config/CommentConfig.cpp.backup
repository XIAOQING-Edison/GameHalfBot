// CommentConfig.cpp: implementation of the CCommentConfig class.
//
//////////////////////////////////////////////////////////////////////

#include "CommentConfig.h"

#include "../FileTools/FileHelper.h"

// #ifdef _DEBUG
// #undef THIS_FILE
// static char THIS_FILE[]=__FILE__;
// #define new DEBUG_NEW
// #endif


const TCHAR *g_szDefSectionName=_T("bugs");

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCommentConfig::CCommentConfig(const TCHAR *szFileName,const TCHAR *szComment,bool bUseEncrypDecrypt):CConfig(szFileName,bUseEncrypDecrypt)
{
	SetSectionName(g_szDefSectionName);
	SetComment(szComment);
}

//这个用以加载某特定版本的ini
CCommentConfig::CCommentConfig(const TCHAR *szPath,const TCHAR *szFileName,int gameVersion,const TCHAR *szComment,bool bUseEncrypDecrypt):CConfig(szPath,szFileName,gameVersion,
																														   bUseEncrypDecrypt)
{
	SetSectionName(g_szDefSectionName);
	SetComment(szComment);
}


CCommentConfig::~CCommentConfig()
{

}



BOOL CCommentConfig::WriteComment()	//写到头里
{
	BOOL ret=TRUE;
	STRING str=_T(";")+m_comment+_T("\r\n");
	string strWrite;
	DWORD dwWrite=str.length();
	DWORD dwHaveWrote=0;
	CFileHelper::GetInstance()->LockFile(m_bUseEncryptDecrypt);
	CFileHelper::GetInstance()->DecryptFile(m_fileName.c_str(),m_bUseEncryptDecrypt);
	HANDLE hFile=CreateFile(m_fileName.c_str(),GENERIC_WRITE,FILE_SHARE_READ,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_ARCHIVE,NULL);
	if(hFile==INVALID_HANDLE_VALUE)
	{
		printf("open file %s failed,error:%d\n",m_fileName.c_str(),GetLastError());
		ret=FALSE;
		goto EXT;
	}
#ifdef _UNICODE
	strWrite=UnicodeToGBK(str.c_str());
	dwWrite=strWrite.length();
	WriteFile(hFile,strWrite.c_str(),dwWrite,&dwHaveWrote,NULL);
#else
	WriteFile(hFile,str.c_str(),dwWrite,&dwHaveWrote,NULL);
#endif
	SAFE_CLOSE_HANDLE(hFile);
EXT:
	CFileHelper::GetInstance()->EncryptFile(m_fileName.c_str(),m_bUseEncryptDecrypt);
	CFileHelper::GetInstance()->UnlockFile(m_bUseEncryptDecrypt);
	return ret;
}


const TCHAR* CCommentConfig::ReadComment()	//从文件里读出注释
{
	TCHAR buf[256];
	memset(buf,0,sizeof(buf));
	DWORD dwRead=sizeof(buf)-1;
	DWORD dwHaveRead=0;
	CFileHelper::GetInstance()->LockFile(m_bUseEncryptDecrypt);
	CFileHelper::GetInstance()->DecryptFile(m_fileName.c_str(),m_bUseEncryptDecrypt);
	HANDLE hFile=CreateFile(m_fileName.c_str(),GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_ARCHIVE,NULL);
	STRING readStr;
	STRING::size_type pos;
	if(hFile==INVALID_HANDLE_VALUE)
	{
		printf("open file %s failed,error:%d\n",m_fileName.c_str(),GetLastError());
		m_comment=_T("");
		goto EXT;
	}
	ReadFile(hFile,buf,dwRead,&dwHaveRead,NULL);
	SAFE_CLOSE_HANDLE(hFile);

	readStr=buf;
	pos=readStr.find(_T("\r\n"));
	if(pos!=STRING::npos)
	{
		m_comment=readStr.substr(1,pos);	//去掉最前面的";"
	}
	else
	{
		printf("can't find return chars....\n");
		m_comment=_T("");
	}
EXT:
	CFileHelper::GetInstance()->EncryptFile(m_fileName.c_str(),m_bUseEncryptDecrypt);
	CFileHelper::GetInstance()->UnlockFile(m_bUseEncryptDecrypt);
	return m_comment.c_str();

}


BOOL CCommentConfig::WriteIni(const TCHAR *szKey,const TCHAR *szValue)
{
	return CConfig::Write(m_sectionName.c_str(),szKey,szValue);
}


STRING CCommentConfig::ReadIni(const TCHAR *szKey)
{
	return CConfig::Read(m_sectionName.c_str(),szKey);
}

	

vector<STRING> CCommentConfig::ReadIniAndGetStringVec(const TCHAR *szKey)
{
	vector<STRING> result;
	STRING strValue=ReadIni(szKey);

	if(strValue.length()!=0 &&result.size()==0)
	{
		printf("can not find result by:%s\n",szKey);
	}
	return result;
}



map<STRING,STRING>	CCommentConfig::GetAllKeyValueBySetionName(const TCHAR *szSection)
{
	map<STRING,STRING> result;
	CFileHelper::GetInstance()->LockFile(m_bUseEncryptDecrypt);
	CFileHelper::GetInstance()->DecryptFile(m_fileName.c_str(),m_bUseEncryptDecrypt);
	HANDLE hFile=CreateFile(m_fileName.c_str(),GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,
		NULL);

	DWORD high=0;
	DWORD size=0;

	TCHAR szKey[1024]={0};	//存放临时的key-value

	if(hFile==INVALID_HANDLE_VALUE)
	{
		printf("create ini file error:%d\n",GetLastError());
		goto EXT;
	}
	SAFE_CLOSE_HANDLE(hFile);
EXT:
	CFileHelper::GetInstance()->EncryptFile(m_fileName.c_str(),m_bUseEncryptDecrypt);
	CFileHelper::GetInstance()->UnlockFile(m_bUseEncryptDecrypt);
	return result;
}




vector<pair<STRING,STRING> > CCommentConfig::GetAllKeyValueBySetionNameNoSorted(const TCHAR *szSection)//不会排序
{
	vector<pair<STRING,STRING> > result;
	CFileHelper::GetInstance()->LockFile(m_bUseEncryptDecrypt);
	CFileHelper::GetInstance()->DecryptFile(m_fileName.c_str(),m_bUseEncryptDecrypt);
EXT:
	CFileHelper::GetInstance()->EncryptFile(m_fileName.c_str(),m_bUseEncryptDecrypt);
	CFileHelper::GetInstance()->UnlockFile(m_bUseEncryptDecrypt);
	return result;
}