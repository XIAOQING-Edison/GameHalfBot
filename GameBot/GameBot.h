// GameBot.h : PROJECT_NAME 应锟矫筹拷锟斤拷锟斤拷锟酵凤拷募锟
//

#pragma once

#ifndef __AFXWIN_H__
	#error "锟节帮拷锟斤拷锟斤拷锟侥硷拷之前锟斤拷锟斤拷锟斤拷stdafx.h锟斤拷锟斤拷锟斤拷锟斤拷 PCH 锟侥硷拷"
#endif

#include "resource.h"		// 锟斤拷锟斤拷锟斤拷


// CGongShaBotApp:
// 锟叫关达拷锟斤拷锟绞碉拷郑锟斤拷锟斤拷锟斤拷 GongShaBot.cpp
//

class CGameBotApp : public CWinApp
{
public:
	CGameBotApp();

// 锟斤拷写
	public:
	virtual BOOL InitInstance();

// 实锟斤拷

	DECLARE_MESSAGE_MAP()
};

extern CGameBotApp theApp;