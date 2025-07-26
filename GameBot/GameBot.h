// GameBot.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGongShaBotApp:
// �йش����ʵ�֣������ GongShaBot.cpp
//

class CGameBotApp : public CWinApp
{
public:
	CGameBotApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGameBotApp theApp;