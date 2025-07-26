// ./Dlgs/Settings/DlgCrossBossSettings.cpp : 实现文件
//

#include "../../stdafx.h"
// #include "GameBot.h"
#include "DlgCrossCorpsBossSettings.h"


// static const int max_boss_num=16;


// CDlgCrossCorpsBossSetting 对话框

IMPLEMENT_DYNAMIC(CDlgCrossCorpsBossSetting, CDialog)

CDlgCrossCorpsBossSetting::CDlgCrossCorpsBossSetting(CWnd* pParent /*=NULL*/)
: CDialog(CDlgCrossCorpsBossSetting::IDD, pParent)
{

}

CDlgCrossCorpsBossSetting::~CDlgCrossCorpsBossSetting()
{
}

void CDlgCrossCorpsBossSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgCrossCorpsBossSetting, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_SELECT, &CDlgCrossCorpsBossSetting::OnBnClickedBtnSelect)
	ON_BN_CLICKED(IDC_BTN_UNSELECT, &CDlgCrossCorpsBossSetting::OnBnClickedBtnUnselect)
END_MESSAGE_MAP()


// CDlgDailyTaskSettings 消息处理程序

BOOL CDlgCrossCorpsBossSetting::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_brush.CreateSolidBrush(RGB(255,255,255));//while brush
	InitCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

HBRUSH CDlgCrossCorpsBossSetting::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	hbr=(HBRUSH)m_brush;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CDlgCrossCorpsBossSetting::InitCtrls()
{
	m_pChkCrossBossSeleted=(CButton*)GetDlgItem(IDC_CHK_CROSS_CORPS_BOSS);
	m_pLstAllBoss=(CListBox*)GetDlgItem(IDC_LIST_CROSS_CORPS_BOSS_ALL_LIST);
	m_pLstSelectedBoss=(CListBox*)GetDlgItem(IDC_LIST_CROSS_CORPS_BOSS_SELECT);;

	m_pEdtBossMaxTimeout=(CEdit*)GetDlgItem(IDC_EDT_CROSS_CORPS_BOSS_MAX_TIMEOUT);
	m_pEdtBossMaxTimeout->SetLimitText(3);

	m_pCbBossKillMode=(CComboBox*)GetDlgItem(IDC_CB_CROSS_CORP_BOSS_MODE);

	InitListBox();
}


void CDlgCrossCorpsBossSetting::ReadIniToCtrls()
{
	CString str;
	m_pChkCrossBossSeleted->SetCheck(m_pCrossCorpsBossConfig->IsCrossCorpsBossSelectedFromCfg());
	
	str.Format(_T("%d"),m_pCrossCorpsBossConfig->GetBossMaxTimeoutFromCfg());
	m_pEdtBossMaxTimeout->SetWindowText(str);


}


void CDlgCrossCorpsBossSetting::SaveCtrlsToIni()
{
	CString str;
	vector<int> selList;
	m_pCrossCorpsBossConfig->SetIsCrossCorpsBossSelectedToCfg(m_pChkCrossBossSeleted->GetCheck());;

	
	m_pCrossCorpsBossConfig->SetCrossCorpsBossListSelectedToCfg(selList);
	m_pCrossCorpsBossConfig->SetBossMaxTimeoutToCfg(GetDlgItemInt(IDC_EDT_CROSS_CORPS_BOSS_MAX_TIMEOUT));

	m_pCrossCorpsBossConfig->SetBossKillModeToCfg(m_pCbBossKillMode->GetCurSel());
}






void CDlgCrossCorpsBossSetting::InitListBox()
{

}

void CDlgCrossCorpsBossSetting::OnBnClickedBtnSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	int selCount=m_pLstAllBoss->GetSelCount();
	

}

void CDlgCrossCorpsBossSetting::OnBnClickedBtnUnselect()
{
	// TODO: 在此添加控件通知处理程序代码
	int selCount=m_pLstSelectedBoss->GetSelCount();
	
}



int CDlgCrossCorpsBossSetting::GetInsertIndexInList(int orgIndex,CListBox *pList)
{
	int findIndex=-1;
	int count=pList->GetCount();
	
	return findIndex;
}