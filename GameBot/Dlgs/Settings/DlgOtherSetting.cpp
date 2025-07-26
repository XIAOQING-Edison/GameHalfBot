// ./Dlgs/Settings/DlgOtherSetting.cpp : 实现文件
//

#include "../../stdafx.h"
#include "../../GameBot.h"
#include "DlgOtherSetting.h"

const int g_tab_count=3;

TCHAR *g_szTabOther[]={
	_T("技能设定"),_T("福利大厅"),_T("系统设定"),_T("")
};
// CDlgOtherSetting 对话框

IMPLEMENT_DYNAMIC(CDlgOtherSetting, CDialog)

CDlgOtherSetting::CDlgOtherSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgOtherSetting::IDD, pParent)
{
	SetIndex(-1);
}

CDlgOtherSetting::~CDlgOtherSetting()
{
}

void CDlgOtherSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgOtherSetting, CDialog)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CDlgOtherSetting::OnBnClickedBtnSave)
	ON_WM_CLOSE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_OTHER_SETTING, &CDlgOtherSetting::OnTcnSelchangeTabOtherSetting)
END_MESSAGE_MAP()


// CDlgOtherSetting 消息处理程序
BOOL CDlgOtherSetting::OnInitDialog()
{
	BOOL ret=TRUE;

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

	for(i=0;i<g_tab_count;++i)
	{
		m_pDlg[i]->Create(IDD_DLG_SKILL_SETTINGS+i,m_pTab);
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

	return ret;

}
void CDlgOtherSetting::OnBnClickedBtnSave()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveCtrlsToIni();
}

void CDlgOtherSetting::OnTcnSelchangeTabOtherSetting(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int curSel=m_pTab->GetCurSel();
	int cmd=SW_SHOW;
	for(int i=0;i<g_tab_count;++i)
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


void CDlgOtherSetting::OnClose()
{
	DestroyAllChildDlgs();
	CDialog::OnCancel();
	CDialog::OnClose();
}


void CDlgOtherSetting::InitCtrls()
{
	int i;
	m_pTab=(CTabCtrl*)GetDlgItem(IDC_TAB_OTHER_SETTING);
	for(i=0;i<g_tab_count;++i)
	{
		m_pTab->InsertItem(i,g_szTabOther[i]);
	}

}




void CDlgOtherSetting::InitChildDlgs()
{
	int i=0;
	m_dlgSkillSetting.SetCareer(m_index);	//index作为career字段
	m_pDlg[i++]=(CDialog*)&m_dlgSkillSetting;
	m_pDlg[i++]=(CDialog*)&m_dlgGiftHallSettings;
	m_pDlg[i++]=(CDialog*)&m_dlgSystemSettings;
// 	m_pDlg[i++]=(CDialog*)&m_dlgOtherTaskSettings;//待定
// 	m_pDlg[i++]=(CDialog*)&m_dlgBossSettings;	//待定

}


void CDlgOtherSetting::ReadIniToCtrls()
{
	CGameConfig gameCfg(m_accountName,false);

	m_dlgSkillSetting.SetConfigObjectAndReadToCtrls(gameCfg.GetSkillConfig());
	m_dlgGiftHallSettings.SetConfigObjectAndReadToCtrls(gameCfg.GetGiftHallConfig());
	m_dlgSystemSettings.SetConfigObjectAndReadToCtrls(gameCfg.GetSystemConfig());

// 	m_dlgOtherTaskSettings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetOtherTaskConfig());


}


void CDlgOtherSetting::SaveCtrlsToIni()
{
	CGameConfig gameCfg(m_accountName,false);

	m_dlgSkillSetting.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetSkillConfig());
	m_dlgGiftHallSettings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetGiftHallConfig());
	m_dlgSystemSettings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetSystemConfig());
// m_dlgOtherTaskSettings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetOtherTaskConfig());

	AfxMessageBox(_T("保存成功!"));
	EndDialog(0);
}

void CDlgOtherSetting::DestroyAllChildDlgs()
{
	for(int i=0;i<g_tab_count;++i)
	{
		m_pDlg[i]->DestroyWindow();
	}
}
