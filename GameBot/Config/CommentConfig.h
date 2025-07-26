// CommentConfig.h: interface for the CCommentConfig class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMENTCONFIG_H__E303A2BC_EB77_4D92_ABE8_CAE3AF5068D3__INCLUDED_)
#define AFX_COMMENTCONFIG_H__E303A2BC_EB77_4D92_ABE8_CAE3AF5068D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Config.h"

//带注释行的config
//m_comment可为""长度为0字串
class CCommentConfig : public CConfig  
{
public:
	CCommentConfig(const TCHAR *szFileName,const TCHAR *szComment,bool bUseEncrypDecrypt);
	CCommentConfig(const TCHAR *szPath,const TCHAR *szFileName,int gameVersion,const TCHAR *szComment,bool bUseEncrypDecrypt);	//这个用以加载某特定版本的ini
	~CCommentConfig();

	void SetSectionName(const TCHAR *szName){m_sectionName=szName;}
	const TCHAR *GetSectionName(){return m_sectionName.c_str();}

	BOOL WriteComment();	//写到头里
	const TCHAR* ReadComment();	//从文件里读出注释

	const TCHAR* GetComment(){return m_comment.c_str();}
	void SetComment(const TCHAR *szComment){m_comment=szComment;}

	BOOL WriteIni(const TCHAR *szKey,const TCHAR *szValue);
	STRING ReadIni(const TCHAR *szKey);

	vector<STRING> ReadIniAndGetStringVec(const TCHAR *szKey);	//拿出字段并且转换成了vector

	map<STRING,STRING>	GetAllKeyValueBySetionName(const TCHAR *szSection);	//分出INI里所有的key-value,这个map会自动排序

	vector<pair<STRING,STRING> > GetAllKeyValueBySetionNameNoSorted(const TCHAR *szSection);//不会排序

private:
	STRING m_sectionName;
	STRING m_comment;
};

#endif // !defined(AFX_COMMENTCONFIG_H__E303A2BC_EB77_4D92_ABE8_CAE3AF5068D3__INCLUDED_)
