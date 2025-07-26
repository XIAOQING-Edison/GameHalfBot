// ThreadLock.cpp: implementation of the CThreadLock class.
//
//////////////////////////////////////////////////////////////////////

#include "ThreadLock.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CThreadLock::CThreadLock()
{
	Init();
}

CThreadLock::~CThreadLock()
{
	Close();
}

void CThreadLock::Lock()
{
	EnterCriticalSection(&m_cs);
}

void CThreadLock::UnLock()
{
	LeaveCriticalSection(&m_cs);
}

void CThreadLock::Init()
{
	InitializeCriticalSection(&m_cs);
}

void CThreadLock::Close()
{
	DeleteCriticalSection(&m_cs);
}