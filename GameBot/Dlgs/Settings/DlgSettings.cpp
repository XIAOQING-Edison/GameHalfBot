// ./Dlgs/Settings/DlgSettings.cpp : 实现文件
//

#include "../../StdAfx.h"
// #include "GameBot.h"
#include "DlgSettings.h"
#include "../../Msg.h"
#include "../../Struct/AccountInfo.h"
#include "../../Config/UserConfig.h"
#include "../../Player.h"

// #include "DlgUserSettings.h"
// #include "DlgBotSetttings.h"
// #include "DlgGiftHallSettings.h"
// #include "DlgBossSettings.h"
// #include "DlgDailyTaskSettings.h"
// #include "DlgAsuramSettings.h"
// #include "DlgOtherTaskSettings.h"
// #include "DlgSystemSettings.h"

const int g_tabCount=5;//总共是8

//const int g_tabCount=8;//总共是8
const TCHAR* g_szTabSecretaryTitle[]={_T("功能1"),_T("功能2"),_T("功能3"),_T("功能4"),_T("功能5")

};
// CDlgSettings 对话框

IMPLEMENT_DYNAMIC(CDlgSecretarySettings, CDialog)

CDlgSecretarySettings::CDlgSecretarySettings(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSecretarySettings::IDD, pParent)
{
	SetAddUser(true);	//默认为true
	SetMainHwnd(NULL);
	SetIndex(-1);
}

CDlgSecretarySettings::~CDlgSecretarySettings()
{
	//DeleteChildDlgs();
}

void CDlgSecretarySettings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgSecretarySettings, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_SETTINGS, &CDlgSecretarySettings::OnTcnSelchangeTabSettings)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDOK, &CDlgSecretarySettings::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgSettings 消息处理程序



void CDlgSecretarySettings::InitCtrls()
{
	int i=0;
	m_pTab=(CTabCtrl*)GetDlgItem(IDC_TAB_SETTINGS);
	for(i=0;i<g_tabCount;++i)
	{
		m_pTab->InsertItem(i,g_szTabSecretaryTitle[i]);
	}

}


void CDlgSecretarySettings::AddDlgsToTab()
{
	int i=0;

	i=0;
// 	m_pDlgUserSetttings.Create(IDD_DLG_USER_SETTINGS,m_pTab);
// 	m_pDlgBotSetttings.Create(IDD_DLG_BOT_SETTINGS,m_pTab);
// 	m_pDlgGiftHallSettings.Create(IDD_DLG_GIFT_HALL_SETTINGS,m_pTab);
// 	m_pDlgBossSettings.Create(IDD_DLG_BOSS_SETTTINGS,m_pTab);
// 	m_pDlgDailyTaskSettgins.Create(IDD_DLG_DAILY_TASK_SETTINGS,m_pTab);
// 	m_pDlgAsuramSettings.Create(IDD_DLG_ASURAM_SETTINGS,m_pTab);
// 	m_pDlgOtherTaskSettings.Create(IDD_DLG_OTHER_TASK_SETTINGS,m_pTab);
//  	m_pDlgSystemSettings.Create(IDD_DLG_SYSTEM_SETTINGS,m_pTab);
// 
// 
// 	i=0;
// 	m_pDlg[i++]=(CDialog*)m_pDlgUserSetttings;
// 	m_pDlg[i++]=(CDialog*)m_pDlgUserSetttings;
// 	m_pDlg[i++]=(CDialog*)m_pDlgBotSetttings;
// 	m_pDlg[i++]=(CDialog*)m_pDlgGiftHallSettings;
// 	m_pDlg[i++]=(CDialog*)m_pDlgBossSettings;
// 	m_pDlg[i++]=(CDialog*)m_pDlgDailyTaskSettgins;
// 	m_pDlg[i++]=(CDialog*)m_pDlgAsuramSettings;
// 	m_pDlg[i++]=(CDialog*)m_pDlgOtherTaskSettings;
// 	m_pDlg[i++]=(CDialog*)m_pDlgSystemSettings;
// 
// 	i=0;
// 	m_pTab->SetCurSel(i);
// 	int j=i;
// 	for(i=0;i<g_tabCount;++i)
// 	{
// 		if(i==j)
// 		{
// 			m_pDlg[i]->ShowWindow(SW_SHOW);
// 		}
// 		else
// 		{
// 			m_pDlg[i]->ShowWindow(SW_HIDE);
// 		}
// 	}

}


void CDlgSecretarySettings::InitChildDlgs()
{
	int i=0;


	m_pDlg[i++]=(CDialog*)&m_dlgSecretary1Settings;
	m_pDlg[i++]=(CDialog*)&m_dlgSecretary2Settings;
	m_pDlg[i++]=(CDialog*)&m_dlgSecretary3Settings;
	m_pDlg[i++]=(CDialog*)&m_dlgSecretary4Settings;
	m_pDlg[i++]=(CDialog*)&m_dlgSecretary5Settings;



}


void CDlgSecretarySettings::DestroyAllChildDlgs()
{
	for(int i=0;i<g_tabCount;++i)
	{
		m_pDlg[i]->DestroyWindow();
	}
}


void CDlgSecretarySettings::OnTcnSelchangeTabSettings(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码

	int curSel=m_pTab->GetCurSel();
	int cmd=SW_SHOW;
	for(int i=0;i<g_tabCount;++i)
	{
		if(i==curSel)
		{
			cmd=SW_SHOW;
		}
		else
		{
			cmd=SW_HIDE;
		}
		m_pDlg[i]->ShowWindow(cmd);

	}

	*pResult = 0;
}

void CDlgSecretarySettings::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	DestroyAllChildDlgs();
	CDialog::OnCancel();
	CDialog::OnClose();
}

BOOL CDlgSecretarySettings::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitCtrls();
	

	CRect rc;
	m_pTab->GetClientRect(&rc);
	CRect rcItem;
	m_pTab->GetItemRect(0,&rcItem);
	int newHeight=rc.Height()-rcItem.Height();
	rc.top=rc.top+rcItem.Height();
	rc.bottom+=newHeight-10;
	InitChildDlgs();

	int i=0;

	for(i=0;i<g_tabCount;++i)
	{
		m_pDlg[i]->Create(IDD_DLG_SETTING_SECRETARY1+i,m_pTab);
		m_pDlg[i]->MoveWindow(rc);
		if(i==0)
		{
			m_pDlg[i]->ShowWindow(SW_SHOW);
		}
		else
		{
			m_pDlg[i]->ShowWindow(SW_HIDE);
		}
	}

	ReadIniToCtrls();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}




void CDlgSecretarySettings::ReadIniToCtrls()	//从ini里读取值到各子窗口
{
	CGameConfig gameCfg(m_accountName,false);
	if(!m_bAdd && GetAccountName().length()>0)	//调用各自的读取
	{
		m_dlgSecretary1Settings.SetConfigObjectAndReadToCtrls(gameCfg.GetConfigSecretary1());
		m_dlgSecretary2Settings.SetConfigObjectAndReadToCtrls(gameCfg.GetConfigSecretary2());
// 		m_dlgSecretary3Settings.SetConfigObjectAndReadToCtrls(gameCfg.GetConfigSecretary1());
// 		m_dlgSecretary4Settings.SetConfigObjectAndReadToCtrls(gameCfg.GetConfigSecretary4());
// 		m_dlgSecretary5Settings.SetConfigObjectAndReadToCtrls(gameCfg.GetConfigSecretary5());
	}
}


void CDlgSecretarySettings::SaveCtrlsToIni()	//子窗口各自保存值到ini
{
	CGameConfig gameCfg(m_accountName,false);
	//调用各自的写入
 	STRING sectionName=m_accountName;
	if(sectionName.length()>0)
	{	
		m_dlgSecretary1Settings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetConfigSecretary1());
		m_dlgSecretary2Settings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetConfigSecretary2());
// 		m_dlgSecretary3Settings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetConfigSecretary1());
// 		m_dlgSecretary4Settings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetConfigSecretary4());
// 		m_dlgSecretary5Settings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetConfigSecretary5());
	}
	
	


}

void CDlgSecretarySettings::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CGameConfig gameCfg(m_accountName,false);
	//调用各自的写入
	STRING sectionName=m_accountName;
	CAccountInfo accountInfo;
	if(sectionName.length()>0)
	{	
		gameCfg.SetSectionName(sectionName.c_str());
		gameCfg.SetAllObjectSectionNames();

		m_dlgSecretary1Settings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetConfigSecretary1());	
		m_dlgSecretary2Settings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetConfigSecretary2());
// 		m_dlgSecretary3Settings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetConfigSecretary1());
// 		m_dlgSecretary4Settings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetConfigSecretary4());
// 		m_dlgSecretary5Settings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetConfigSecretary5());	

		//set account info
		accountInfo.SetIndex(this->GetIndex());
		accountInfo.SetPlatformIndex(gameCfg.GetUserConfig()->GetPlatformIdFromCfg());
		accountInfo.SetServerId(gameCfg.GetUserConfig()->GetServerIdFromCfg());
		accountInfo.SetAccountName(gameCfg.GetUserConfig()->GetUserNameFromCfg());


		AfxMessageBox(_T("保存成功!"));
		if(IsAddUser())
		{
			SendMsgToMainWin(e_msg_type_add_account_info,(LPARAM)&accountInfo);
		}
		else
		{
			SendMsgToMainWin(e_msg_type_update_account_info,(LPARAM)&accountInfo);
		}
		EndDialog(0);
	}
}


void CDlgSecretarySettings::SendMsgToMainWin(WPARAM wParam,LPARAM lParam)
{
	::SendMessage(m_hwndMain,WM_SELF_HANDLE_MSG,wParam,lParam);
}


void CDlgSecretarySettings::SetPlayerPointer(CPlayer *player)
{
	m_dlgSecretary1Settings.SetPlayer(player);
}