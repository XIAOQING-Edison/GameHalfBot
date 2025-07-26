// ./Dlgs/Settings/DlgCrossBossSettings.cpp : 实现文件
//

#include "../../stdafx.h"
// #include "GameBot.h"
#include "DlgCrossBossSettings.h"


// static const int max_boss_num=16;


// CDlgCrossBossSetting 对话框

IMPLEMENT_DYNAMIC(CDlgCrossBossSetting, CDialog)

CDlgCrossBossSetting::CDlgCrossBossSetting(CWnd* pParent /*=NULL*/)
: CDialog(CDlgCrossBossSetting::IDD, pParent)
{

}

CDlgCrossBossSetting::~CDlgCrossBossSetting()
{
}

void CDlgCrossBossSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgCrossBossSetting, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_SELECT, &CDlgCrossBossSetting::OnBnClickedBtnSelect)
	ON_BN_CLICKED(IDC_BTN_UNSELECT, &CDlgCrossBossSetting::OnBnClickedBtnUnselect)
END_MESSAGE_MAP()


// CDlgDailyTaskSettings 消息处理程序

BOOL CDlgCrossBossSetting::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_brush.CreateSolidBrush(RGB(255,255,255));//while brush
	InitCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

HBRUSH CDlgCrossBossSetting::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	hbr=(HBRUSH)m_brush;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CDlgCrossBossSetting::InitCtrls()
{
	m_pChkCrossBossSeleted=(CButton*)GetDlgItem(IDC_CHK_CROSS_BOSS);
	m_pLstAllBoss=(CListBox*)GetDlgItem(IDC_LIST_CROSS_BOSS_ALL_LIST);
	m_pLstSelectedBoss=(CListBox*)GetDlgItem(IDC_LIST_CROSS_BOSS_SELECT);;

	m_pEdtBossMaxTimeout=(CEdit*)GetDlgItem(IDC_EDT_CROSS_BOSS_MAX_TIMEOUT);
	m_pEdtBossMaxTimeout->SetLimitText(3);

	m_pCbBossKillMode=(CComboBox*)GetDlgItem(IDC_CB_CROSS_BOSS_MODE);
#if _GAME_VERSION_== _YONG_HENG_LIAN_MENG_
	m_pChkCrossBossSeleted->SetWindowText(_T("转生boss"));
#else
	m_pChkCrossBossSeleted->SetWindowText(_T("黄金怪"));
#endif
	InitListBox();
}


void CDlgCrossBossSetting::ReadIniToCtrls()
{
	CString str;
	m_pChkCrossBossSeleted->SetCheck(m_pCrossBossConfig->IsCrossBossSelectedFromCfg());
	vector<int> selBossList=m_pCrossBossConfig->GetCrossBossSelectedListFromCfg();
	
	str.Format(_T("%d"),m_pCrossBossConfig->GetBossMaxTimeoutFromCfg());
	m_pEdtBossMaxTimeout->SetWindowText(str);
	m_pCbBossKillMode->SetCurSel(m_pCrossBossConfig->GetBossKillModeFromCfg());

}


void CDlgCrossBossSetting::SaveCtrlsToIni()
{
	CString str;
	vector<int> selList;
	m_pCrossBossConfig->SetIsCrossBossSelectedToCfg(m_pChkCrossBossSeleted->GetCheck());;

	
	m_pCrossBossConfig->SetCrossBossListSelectedToCfg(selList);
	m_pCrossBossConfig->SetBossMaxTimeoutToCfg(GetDlgItemInt(IDC_EDT_CROSS_BOSS_MAX_TIMEOUT));
	m_pCrossBossConfig->SetBossKillModeToCfg(m_pCbBossKillMode->GetCurSel());

}




void CDlgCrossBossSetting::InitListBox()
{

}

void CDlgCrossBossSetting::OnBnClickedBtnSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	int selCount=m_pLstAllBoss->GetSelCount();
	CArray<int,int> aryListBoxSel;

	aryListBoxSel.SetSize(selCount);

	m_pLstAllBoss->GetSelItems(selCount,aryListBoxSel.GetData()); 
	

}

void CDlgCrossBossSetting::OnBnClickedBtnUnselect()
{
	// TODO: 在此添加控件通知处理程序代码
	int selCount=m_pLstSelectedBoss->GetSelCount();
	
}



int CDlgCrossBossSetting::GetInsertIndexInList(int orgIndex,CListBox *pList)
{
	int findIndex=-1;
	int count=pList->GetCount();
	
	return findIndex;
}