#include "InjectorRemoteThead.h"



CInjectorRemoteThead::CInjectorRemoteThead():CInjector(e_inject_remote_thread)
{

}

CInjectorRemoteThead::~CInjectorRemoteThead(void)
{
}


//bool CInjectorRemoteThead::Inject(LPCTSTR szProcessName)
bool CInjectorRemoteThead::Inject(DWORD pid)
{
	bool ret=false;
	//DWORD pid;
	if(m_dllFullPath.empty())
	{
		OutputDebugStringA("dll path is empty\n");
		return ret;
	}
	//pid=CInjector::FindTargetProcessPid(szProcessName);
	m_pidSelect=pid;
	if(pid==-1)
	{
		OutputDebugStringA("find target falied %x\n");//,GetLastError());
		return ret;
	}
	ret=DoInjectByMethodType(pid,m_dllFullPath.c_str(),false);
	m_bInjectSucc=ret;
	return ret;
}

bool CInjectorRemoteThead::Uninject()	//释放,这个未完成，有问题,待修改
{
	bool ret=false;
	if(m_bInjectSucc)
	{
		DWORD pid=m_pidSelect;
		if(pid==-1)
		{
			OutputDebugStringA("find target falied %x\n");//,GetLastError());
			return ret;
		}
		ret=DoInjectByMethodType(pid,m_dllFullPath.c_str(),true);
	}
	return ret;

}