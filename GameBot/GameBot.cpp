// GongShaBot.cpp : ����Ӧ�ó��������Ϊ��
//

#include "StdAfx.h"
#include "GameBot.h"
#include "GameBotDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGongShaBotApp

BEGIN_MESSAGE_MAP(CGameBotApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CGongShaBotApp ����

CGameBotApp::CGameBotApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CGongShaBotApp ����

CGameBotApp theApp;


// CGongShaBotApp ��ʼ��

BOOL CGameBotApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	//user rich edit 2.0
	AfxInitRichEdit();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CGameBotDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

// 	CGameBotDlg *dlg=new CGameBotDlg;
// 	dlg->Create(IDD_GAMEBOT_DIALOG);
// 	m_pMainWnd = dlg;
// 	int nResponse = dlg->ShowWindow(SW_SHOW);
// 	if (nResponse == IDOK)
// 	{
// 		// TODO: Place code here to handle when the dialog is
// 		//  dismissed with OK
// 	}
// 	else if (nResponse == IDCANCEL)
// 	{
// 		// TODO: Place code here to handle when the dialog is
// 		//  dismissed with Cancel
// 	}
// 
// 	// Since the dialog has been closed, return FALSE so that we exit the
// 	//  application, rather than start the application's message pump.
// 
// 	MSG msg={0};
// 	while(GetMessage(&msg,NULL,0,0))
// 	{
// 		TranslateMessage(&msg);
// 		DispatchMessage(&msg);
// 	}
// 
// 	delete dlg;


	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}
