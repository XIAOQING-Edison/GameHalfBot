#pragma once

#include "../Global/public.h"
#include "../Util/Encrypt.h"
#include "../Util/ProcessMutex.h"

class CFileHelper
{
public:
	CFileHelper(void);
	~CFileHelper(void);


	static CFileHelper *GetInstance();
	static void DeleteInstance();

	bool EncryptFile(const TCHAR *szFileName,bool bEncrypt);
	bool DecryptFile(const TCHAR *szFileName,bool bDecrypt);

	CEncrypt *GetEncryptMethod(){return &m_encryptMethod;}

	void LockFile(bool bLock);
	void UnlockFile(bool bLock);

	void CheckAndRepairConfigFiles();
private:
	CEncrypt m_encryptMethod;
	CProcessMutex *m_pMutex;
	int m_key;
	static CFileHelper *s_pFileHelperInstance;
};
