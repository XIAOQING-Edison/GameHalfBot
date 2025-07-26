// ThreadLock.h: interface for the CThreadLock class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THREADLOCK_H__0887B42D_7659_4580_B8BA_3FC9BDF9CE05__INCLUDED_)
#define AFX_THREADLOCK_H__0887B42D_7659_4580_B8BA_3FC9BDF9CE05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "../Global/public.h"
class CThreadLock  
{
public:
	CThreadLock();
	virtual ~CThreadLock();
	void Lock();
	void UnLock();
	void Init();
	void Close();
private:
	CRITICAL_SECTION m_cs;
};

#endif // !defined(AFX_THREADLOCK_H__0887B42D_7659_4580_B8BA_3FC9BDF9CE05__INCLUDED_)
