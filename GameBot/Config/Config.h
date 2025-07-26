// Config.h: interface for the CConfig class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONFIG_H__27360483_F360_4C71_B1D2_42DCF73BB510__INCLUDED_)
#define AFX_CONFIG_H__27360483_F360_4C71_B1D2_42DCF73BB510__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../Global/public.h"
#include "../FileTools/FileHelper.h"
class CConfig  
{
public:
	CConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	CConfig(const TCHAR *szPath,const TCHAR *szFileName,int gameVersion,bool bUseEncryptDecrypt=true);	//锟斤拷锟斤拷锟斤拷约锟斤拷锟侥筹拷囟锟斤拷姹撅拷锟絠ni
	~CConfig();

	STRING GetFullPath(){return m_fileName;}//锟斤拷锟斤拷全路锟斤拷
	void SetFullPath(const TCHAR *szFullPath){m_fileName=szFullPath;}	//锟借定全路锟斤拷锟斤拷为锟剿凤拷锟斤拷使锟斤拷
	STRING Read(const TCHAR *szSection,const TCHAR *szKey,const TCHAR *szDefault=_T(""),const TCHAR *szRetBuf=_T(""),DWORD sz=0);
	BOOL	Write(const TCHAR *szSection,const TCHAR *szKey,const TCHAR *szValue);
	UINT	ReadInt(const TCHAR *szSection,const TCHAR *szKey,UINT def=0);
	BOOL	WriteInt(const TCHAR *szSection,const TCHAR *szKey,UINT def,UINT value);

	vector<int> ReadIntArray(const TCHAR* szSection,const TCHAR *szKey);	//锟斤拷int锟斤拷锟斤拷
	BOOL WriteIntArray(const TCHAR *szSection,const TCHAR *szKey,vector<int> &arr);	//写int锟斤拷锟斤拷

	void SetSectionName(const TCHAR *szSection){m_sectionName=szSection;}
	STRING GetSectionName(){return m_sectionName;}
protected:
	STRING m_fileName;
	STRING m_sectionName;
	bool m_bUseEncryptDecrypt;	//锟角凤拷使锟斤拷
};

#endif // !defined(AFX_CONFIG_H__27360483_F360_4C71_B1D2_42DCF73BB510__INCLUDED_)
