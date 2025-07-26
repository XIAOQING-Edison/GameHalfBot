#pragma once
#include "injector.h"

class CInjectorRemoteThead :
	public CInjector
{
public:
	CInjectorRemoteThead();
	virtual ~CInjectorRemoteThead(void);

	//virtual bool Inject(LPCTSTR szProcessName);
	virtual bool Inject(DWORD pid);
	virtual bool Uninject();	//释放
private:

};
