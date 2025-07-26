#pragma once
#include "../Global/public.h"
class CProcessMutex
{
public:
	CProcessMutex(void);
	~CProcessMutex(void);

	bool CreateProcessMutex(BOOL bInitOwner,const TCHAR *szName);
	bool OpenProcessMutex(const TCHAR *szName);
	
	void Init();
	void CloseMutex(){SAFE_CLOSE_HANDLE(m_mutex);}

	void Lock(){WaitForSingleObject(m_mutex,INFINITE);}
	void Unlock(){ReleaseMutex(m_mutex);}
private:
	HANDLE m_mutex;
};
