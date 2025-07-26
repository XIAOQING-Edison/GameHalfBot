#include "ProcessMutex.h"

CProcessMutex::CProcessMutex(void)
{
	Init();
}

CProcessMutex::~CProcessMutex(void)
{
	Unlock();
	CloseMutex();
}

void CProcessMutex::Init()
{
	m_mutex=NULL;
}

bool CProcessMutex::CreateProcessMutex(BOOL bInitOwner,const TCHAR *szName)
{
	bool ret=false;
	if(!m_mutex)
	{
		m_mutex=CreateMutex(NULL,bInitOwner,szName);
	}
	DWORD res=GetLastError();
	if(res !=0 && res != ERROR_ALREADY_EXISTS)
	{
		TRACE_OUTPUT(_T("创建mutex错误，代号:%x\n"),GetLastError());
	}
	TRACE_OUTPUT(_T("获取mutex句柄:%08x\n"),m_mutex);
	ret=(m_mutex!=NULL);
	return ret;
}



bool CProcessMutex::OpenProcessMutex(const TCHAR *szName)
{
	bool ret=false;
	SAFE_CLOSE_HANDLE(m_mutex);
	m_mutex=OpenMutex(MUTEX_ALL_ACCESS,TRUE,szName);
	ret=(m_mutex != NULL);
	return ret;
}