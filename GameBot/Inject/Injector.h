#pragma once
#include "../Global/public.h"
enum E_INJECT_TYPE
{
	e_inject_remote_thread=0,
	e_inject_zw_create_threadex,	//
	e_inject_apc,
	e_inject_rtl_create_user_thread,
	e_inject_shell_code,
	e_inject_input_method,
	e_inject_msg_hook
};

class CInjector
{
public:
	CInjector(E_INJECT_TYPE type);
	virtual ~CInjector(void);

	E_INJECT_TYPE GetInjectType(){return m_injectType;}
	void SetDllFullPath(const TCHAR *szFullPath){m_dllFullPath=szFullPath;}//ȫ·��,·����Ҫ���������

	//virtual bool Inject(LPCTSTR szProcessName)=0;
	virtual bool Inject(DWORD pid)=0;
	virtual bool Uninject()=0;	//�ͷ�

	DWORD FindTargetProcessPid(LPCTSTR lpszProcess);
	SIZE_T GetTargetProcessDllBase(DWORD pid,LPCTSTR szDllName);
protected:
	void SetInjectType(E_INJECT_TYPE type){m_injectType=type;}
	bool EnableDebugPrivilege();	//��Ȩ
	bool DoInjectByMethodType(DWORD dwPID, LPCTSTR lpszDllName,bool bFreeDll);	//ntcreatthread or createremotethread
private:
	bool InjectByCreateRemoteThread(HANDLE hProcess, LPTHREAD_START_ROUTINE  lpThreadProc, LPVOID lpDllName,bool bFreeDll);	//��ͨԶ���߳�
	bool InjectByZwCreateThreadEx(HANDLE hProcess, LPTHREAD_START_ROUTINE  lpThreadProc, LPVOID lpDllName,bool bFreeDll);	//ntCreateThreadEx
	bool InjectByAPC(DWORD processId,PAPCFUNC pFunc,LPVOID lpDllName,bool bFreeDll);	//APCע��
	bool InjectByRtlCreateUserThread(HANDLE hProcess, LPTHREAD_START_ROUTINE  lpThreadProc, LPVOID lpDllName,bool bFreeDll);	//RtlCreateUserThread
protected:
	E_INJECT_TYPE m_injectType;
	DWORD m_pidSelect;	//ѡ���pid
	bool m_bInjectSucc;	//�Ƿ�ע��ɹ�
	STRING m_dllFullPath;
};
