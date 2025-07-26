// ./Dlgs/Settings/DlgBossSettings.cpp : 实现文件
//

#include "../../StdAfx.h"
// #include "GameBot.h"
#include "DlgBossSettings.h"


static int g_tabCount=5;
#if _GAME_VERSION_ == _YONG_HENG_LIAN_MENG_
	static const TCHAR *g_szTabString[]={_T("野外BOSS"),_T("秘境boss"),_T("转生BOSS"),_T("试炼之地"),_T("苦难炼狱"),_T("卡利玛"),_T("个人卡利玛")};
#elif _GAME_VERSION_ == _TIAN_SHI_SHEN_YU_
	static const TCHAR *g_szTabString[]={_T("野外BOSS"),_T("秘境boss"),_T("黄金怪"),_T("试炼之地"),_T("苦难炼狱"),_T("卡利玛"),_T("个人卡利玛")};
#elif (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
	static const TCHAR *g_szTabString[]={_T("野外BOSS"),_T("秘境boss"),_T("黄金怪"),_T("示例"),_T("示例"),_T("示例"),_T("示例")};
#else
	static const TCHAR *g_szTabString[]={_T("野外BOSS"),_T("秘境boss"),_T("转生BOSS"),_T("试炼之地"),_T("苦难炼狱"),_T("卡利玛"),_T("个人卡利玛")};
#endif
// CDlgBossSettings 对话框

IMPLEMENT_DYNAMIC(CDlgBossSettings, CDialog)

CDlgBossSettings::CDlgBossSettings(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgBossSettings::IDD, pParent)
{
	SetPlayerIndex(-1);
}

CDlgBossSettings::~CDlgBossSettings()
{
}

void CDlgBossSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgBossSettings, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_SAVE, &CDlgBossSettings::OnBnClickedBtnSave)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_BOSS_SETINGS, &CDlgBossSettings::OnTcnSelchangeTabBossSetings)
END_MESSAGE_MAP()


// CDlgBossSettings 消息处理程序

BOOL CDlgBossSettings::OnInitDialog()
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
		m_pDlg[i]->Create(IDD_DLG_NEUTRAL_BOSS+i,m_pTab);
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

HBRUSH CDlgBossSettings::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
		
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CDlgBossSettings::InitCtrls()
{
	int i=0;
	m_pTab=(CTabCtrl*)GetDlgItem(IDC_TAB_BOSS_SETINGS);
	for(i=0;i<g_tabCount;++i)
	{
		m_pTab->InsertItem(i,g_szTabString[i]);
	}

}


void CDlgBossSettings::AddDlgsToTab()
{
	int i=0;


	i=0;
	m_pTab->SetCurSel(i);
	int j=i;
	for(i=0;i<g_tabCount;++i)
	{
		if(i==j)
		{
			m_pDlg[i]->ShowWindow(SW_SHOW);
		}
		else
		{
			m_pDlg[i]->ShowWindow(SW_HIDE);
		}
 	}

}


void CDlgBossSettings::InitChildDlgs()
{
	int i=0;


	m_pDlg[i++]=(CDialog*)&m_dlgNeutralBossSettings;
	m_pDlg[i++]=(CDialog*)&m_dlgWorldBossSettings;
	m_pDlg[i++]=(CDialog*)&m_dlgCrossBossSettings;
	m_pDlg[i++]=(CDialog*)&m_dlgLocalCorpsBossSettings;
	m_pDlg[i++]=(CDialog*)&m_dlgCrossCorpsBossSettings;
	m_pDlg[i++]=(CDialog*)&m_dlgBeastBossSettings;
	m_pDlg[i++]=(CDialog*)&m_dlgBossAssistSettings;

	m_dlgNeutralBossSettings.SetPlayerIndex(m_playerIndex);
	m_dlgWorldBossSettings.SetPlayerIndex(m_playerIndex);
	m_dlgCrossCorpsBossSettings.SetPlayerIndex(m_playerIndex);
	m_dlgLocalCorpsBossSettings.SetPlayerIndex(m_playerIndex);
	m_dlgCrossCorpsBossSettings.SetPlayerIndex(m_playerIndex);
	m_dlgCrossBossSettings.SetPlayerIndex(m_playerIndex);
	m_dlgBeastBossSettings.SetPlayerIndex(m_playerIndex);
	m_dlgBeastBossSettings.SetPlayerIndex(m_playerIndex);

}


void CDlgBossSettings::DestroyAllChildDlgs()
{
	for(int i=0;i<g_tabCount;++i)
	{
		m_pDlg[i]->DestroyWindow();
	}
}


void CDlgBossSettings::ReadIniToCtrls()
{
	CString str;
	CGameConfig gameCfg(m_accountName,false);

	m_dlgNeutralBossSettings.SetConfigObjectAndReadToCtrls(gameCfg.GetNeutralBossConfig());	//野外
	m_dlgWorldBossSettings.SetConfigObjectAndReadToCtrls(gameCfg.GetWorldBossConfig());	//秘境
	m_dlgCrossBossSettings.SetConfigObjectAndReadToCtrls(gameCfg.GetCrossBossConfig());	//转生/黄金怪
	m_dlgLocalCorpsBossSettings.SetConfigObjectAndReadToCtrls(gameCfg.GetLocalCorpsBossConfig());//试炼之地
	m_dlgCrossCorpsBossSettings.SetConfigObjectAndReadToCtrls(gameCfg.GetCrossCorpsBossConfig());//苦难炼狱
// 	m_dlgBeastBossSettings.SetConfigObjectAndReadToCtrls(gameCfg.GetBeastBossConfig());
// 	m_dlgBossAssistSettings.SetConfigObjectAndReadToCtrls(gameCfg.GetBossAssistConfig());

}


void CDlgBossSettings::SaveCtrlsToIni()
{
	CString str;
	
	CGameConfig gameCfg(m_accountName,false);
	m_dlgNeutralBossSettings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetNeutralBossConfig());//野外
	m_dlgWorldBossSettings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetWorldBossConfig());//秘境
	m_dlgCrossBossSettings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetCrossBossConfig());//转生
	m_dlgLocalCorpsBossSettings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetLocalCorpsBossConfig());//试炼之地
	m_dlgCrossCorpsBossSettings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetCrossCorpsBossConfig());//苦难炼狱
// 	m_dlgBeastBossSettings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetBeastBossConfig());
// 	m_dlgBossAssistSettings.SetConfigObjectAndSaveCtrlsToIni(gameCfg.GetBossAssistConfig());
}



void CDlgBossSettings::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	DestroyAllChildDlgs();
	CDialog::OnCancel();
	CDialog::OnClose();
}

void CDlgBossSettings::OnBnClickedBtnSave()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveCtrlsToIni();
	AfxMessageBox(_T("保存成功!"));
	EndDialog(0);
}

void CDlgBossSettings::OnTcnSelchangeTabBossSetings(NMHDR *pNMHDR, LRESULT *pResult)
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
