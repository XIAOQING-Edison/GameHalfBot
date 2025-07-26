#include "FileHelper.h"

const TCHAR *g_szMutexName=_T("FileMutex");


CFileHelper *CFileHelper::s_pFileHelperInstance=NULL;

CFileHelper::CFileHelper(void)
{
	m_pMutex=new CProcessMutex;
	m_pMutex->CreateProcessMutex(FALSE,g_szMutexName);
}

CFileHelper::~CFileHelper(void)
{
	SAFE_DELETE_POINTER(m_pMutex);
}



CFileHelper *CFileHelper::GetInstance()
{
	if(!CFileHelper::s_pFileHelperInstance)
	{
		CFileHelper::s_pFileHelperInstance=new CFileHelper;
	}
	return CFileHelper::s_pFileHelperInstance;
}


void CFileHelper::DeleteInstance()
{
	SAFE_DELETE_POINTER(s_pFileHelperInstance);
}




bool CFileHelper::EncryptFile(const TCHAR *szFileName,bool bEncrypt)
{
	bool ret=true;
	HANDLE hFile=NULL;	
	char *pBuf=NULL;

#ifdef ACTIVE_ENCRYPT
	//m_pThreadLock->Lock();
	if(bEncrypt)
	{
		hFile=CreateFile(szFileName,GENERIC_READ |GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
		DWORD sz,szHigh;
		DWORD bytesRead;
		if(hFile==INVALID_HANDLE_VALUE)
		{
			hFile=NULL;
			ret=false;
			TRACE_OUTPUT(_T("encrypt file create error:%x\n"),GetLastError());
			goto EXT;
		}

		sz=GetFileSize(hFile,&szHigh);
		if(sz>0)
		{
			LONG moveHight=0;
			pBuf=new char[sz];
			ReadFile(hFile,pBuf,sz,&bytesRead,NULL);
			SetFilePointer(hFile,0,&moveHight,FILE_BEGIN);
			m_encryptMethod.Reset();
			m_encryptMethod.EncryptData(pBuf,bytesRead);
			WriteFile(hFile,pBuf,bytesRead,&sz,NULL);
		}

	}
#endif // ACTIVE_ENCRYPT

EXT:
	SAFE_CLOSE_HANDLE(hFile);
	SAFE_DELETE_ARRAY(pBuf);

	return ret;
}



bool CFileHelper::DecryptFile(const TCHAR *szFileName,bool bDecrypt)
{
	bool ret=true;
	HANDLE hFile=NULL;	
	char *pBuf=NULL;
#ifdef ACTIVE_ENCRYPT
	//m_pThreadLock->Lock();
	if(bDecrypt)
	{
		hFile=CreateFile(szFileName,GENERIC_READ | GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
		DWORD sz,szHigh;
		DWORD bytesRead;
		if(hFile==INVALID_HANDLE_VALUE)
		{
			ret=false;
			hFile=NULL;
			TRACE_OUTPUT(_T("decrypt file create error:%x\n"),GetLastError());
			goto EXT;
		}

		sz=GetFileSize(hFile,&szHigh);
		if(sz>0)
		{
			LONG moveHight=0;
			pBuf=new char[sz];
			ReadFile(hFile,pBuf,sz,&bytesRead,NULL);
			SetFilePointer(hFile,0,&moveHight,FILE_BEGIN);
			m_encryptMethod.Reset();
			m_encryptMethod.EncryptData(pBuf,bytesRead);
			WriteFile(hFile,pBuf,bytesRead,&sz,NULL);
		}

	}

#endif // ACTIVE_ENCRYPT

EXT:
	SAFE_CLOSE_HANDLE(hFile);
	SAFE_DELETE_ARRAY(pBuf);
	return ret;
}



void CFileHelper::LockFile(bool bLock)
{
#ifdef ACTIVE_ENCRYPT
	if(bLock)
 		m_pMutex->Lock();
#endif
}

void CFileHelper::UnlockFile(bool bLock)
{
#ifdef ACTIVE_ENCRYPT
	if(bLock)
		m_pMutex->Unlock();
#endif
}