#pragma once
#include "commentconfig.h"
#include "ConfigStruct.h"


//��д�ڴ��������
//���ʹ��ڴ������
//д�Ļ�д���ڴ���д�ļ�
class CMemoryConfig :
	public CCommentConfig
{
public:
	CMemoryConfig(void);
	CMemoryConfig(const TCHAR *szFileName,const TCHAR *szComment,bool bUseEncryptDecrypt=true);
	CMemoryConfig(const TCHAR *szPath,const TCHAR *szFileName,int gameVersion,const TCHAR *szComment,bool bUseEncryptDecrypt=true);	//������Լ���ĳ�ض��汾��ini

	virtual ~CMemoryConfig(void);

	int ReadInt(const TCHAR *szSection,const TCHAR *szKey);
	BOOL WriteInt(const TCHAR *szSection,const TCHAR *szKey,int value);
	STRING ReadString(const TCHAR *szSection,const TCHAR *szKey);
	BOOL WriteString(const TCHAR *szSection,const TCHAR *szKey,const TCHAR *szValue);

private:
	BOOL WriteIntToMemory(const TCHAR *szSection,const TCHAR *szKey,int value);
	BOOL WriteIntToFile(const TCHAR *szSection,const TCHAR *szKey,int value);

	BOOL WriteStringToMemory(const TCHAR *szSection,const TCHAR *szKey,int value);
	BOOL WrteiStringToFile(const TCHAR *szSection,const TCHAR *szKey,int value);
private:
	map<STRING,CConfigSection> m_configInMemory;

};
