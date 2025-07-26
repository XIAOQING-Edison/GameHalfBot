#include "MemoryConfig.h"

CMemoryConfig::CMemoryConfig(const TCHAR *szFileName,const TCHAR *szComment,bool bUseEncryptDecrypt):CCommentConfig(szFileName,szComment,bUseEncryptDecrypt)
{
}


CMemoryConfig::CMemoryConfig(const TCHAR *szPath,const TCHAR *szFileName,int gameVersion,const TCHAR *szComment,bool bUseEncryptDecrypt):
				CCommentConfig(szPath,szFileName,gameVersion,szComment,bUseEncryptDecrypt)//这个用以加载某特定版本的ini
{

}


CMemoryConfig::~CMemoryConfig(void)
{
}
