// CommentConfig.h: interface for the CCommentConfig class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMENTCONFIG_H__E303A2BC_EB77_4D92_ABE8_CAE3AF5068D3__INCLUDED_)
#define AFX_COMMENTCONFIG_H__E303A2BC_EB77_4D92_ABE8_CAE3AF5068D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Config.h"

//��ע���е�config
//m_comment��Ϊ""����Ϊ0�ִ�
class CCommentConfig : public CConfig  
{
public:
	CCommentConfig(const TCHAR *szFileName,const TCHAR *szComment,bool bUseEncrypDecrypt);
	CCommentConfig(const TCHAR *szPath,const TCHAR *szFileName,int gameVersion,const TCHAR *szComment,bool bUseEncrypDecrypt);	//������Լ���ĳ�ض��汾��ini
	~CCommentConfig();

	void SetSectionName(const TCHAR *szName){m_sectionName=szName;}
	const TCHAR *GetSectionName(){return m_sectionName.c_str();}

	BOOL WriteComment();	//д��ͷ��
	const TCHAR* ReadComment();	//���ļ������ע��

	const TCHAR* GetComment(){return m_comment.c_str();}
	void SetComment(const TCHAR *szComment){m_comment=szComment;}

	BOOL WriteIni(const TCHAR *szKey,const TCHAR *szValue);
	STRING ReadIni(const TCHAR *szKey);

	vector<STRING> ReadIniAndGetStringVec(const TCHAR *szKey);	//�ó��ֶβ���ת������vector

	map<STRING,STRING>	GetAllKeyValueBySetionName(const TCHAR *szSection);	//�ֳ�INI�����е�key-value,���map���Զ�����

	vector<pair<STRING,STRING> > GetAllKeyValueBySetionNameNoSorted(const TCHAR *szSection);//��������

private:
	STRING m_sectionName;
	STRING m_comment;
};

#endif // !defined(AFX_COMMENTCONFIG_H__E303A2BC_EB77_4D92_ABE8_CAE3AF5068D3__INCLUDED_)
