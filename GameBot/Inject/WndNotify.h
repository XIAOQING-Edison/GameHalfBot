#pragma once
#include "../CustomDef.h"
#include<stdio.h>
WPEX_STATUS g_wpex_Status=WPEX_STOP;
class CWndNotify
{
private:
	WPEX_STATUS m_wpex_Status;
	DWORD m_showFlag;	//显示标记
public:
    CWndNotify()
    {
		m_showFlag=SHOW_FLAG;
		g_wpex_Status=WPEX_STOP;
    }
    
    virtual ~CWndNotify()
    {
    }

	static void Start()
	{
		g_wpex_Status=WPEX_START;
	}

	static void Stop()
	{
		g_wpex_Status=WPEX_STOP;
	}

	static WPEX_STATUS GetStatus()
	{
		return g_wpex_Status;
	}

	DWORD GetShowFlag(){return m_showFlag;}
	void SetShowFlag(DWORD flag){m_showFlag=flag;}
	
};