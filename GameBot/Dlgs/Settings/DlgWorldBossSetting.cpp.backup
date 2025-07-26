// ./Dlgs/Settings/DlgDailyTaskSettings.cpp : 实现文件
//

#include "../../StdAfx.h"
// #include "GameBot.h"
#include "DlgWorldBossSetting.h"


// CDlgDailyTaskSettings 对话框

IMPLEMENT_DYNAMIC(CDlgWorldBossSetting, CDialog)

CDlgWorldBossSetting::CDlgWorldBossSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgWorldBossSetting::IDD, pParent)
{

}

CDlgWorldBossSetting::~CDlgWorldBossSetting()
{
}

void CDlgWorldBossSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgWorldBossSetting, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_SELECT, &CDlgWorldBossSetting::OnBnClickedBtnSelect)
	ON_BN_CLICKED(IDC_BTN_UNSELECT, &CDlgWorldBossSetting::OnBnClickedBtnUnselect)
END_MESSAGE_MAP()


// CDlgDailyTaskSettings 消息处理程序

BOOL CDlgWorldBossSetting::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_brush.CreateSolidBrush(RGB(255,255,255));//while brush
	InitCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

HBRUSH CDlgWorldBossSetting::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	hbr=(HBRUSH)m_brush;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CDlgWorldBossSetting::InitCtrls()
{
	m_pChkWorldBossSeleted=(CButton*)GetDlgItem(IDC_CHK_WORLD_BOSS);
	m_pLstAllBoss=(CListBox*)GetDlgItem(IDC_LIST_WORLD_BOSS_ALL_LIST);
	m_pLstSelectedBoss=(CListBox*)GetDlgItem(IDC_LIST_WORLD_BOSS_SELECT);;

	m_pEdtBossMaxTimeout=(CEdit*)GetDlgItem(IDC_EDT_WORLD_BOSS_MAX_TIMEOUT);
	m_pEdtBossMaxTimeout->SetLimitText(3);

	m_pCbBossKillMode=(CComboBox*)GetDlgItem(IDC_CB_WORLD_BOSS_MODE);
	InitListBox();	
}


void CDlgWorldBossSetting::ReadIniToCtrls()
{
	CString str;
	m_pChkWorldBossSeleted->SetCheck(m_pWorldBossConfig->IsWorldBossSelectedFromCfg());
	vector<int> selBossList=m_pWorldBossConfig->GetWorldBossSelectedListFromCfg();
	vector<int>::iterator it=selBossList.begin();
	int i=0;
	str.Format(_T("%d"),m_pWorldBossConfig->GetBossMaxTimeoutFromCfg());
	m_pEdtBossMaxTimeout->SetWindowText(str);
	m_pCbBossKillMode->SetCurSel(m_pWorldBossConfig->GetBossKillModeFromCfg());
}


void CDlgWorldBossSetting::SaveCtrlsToIni()
{
	CString str;
	vector<int> selList;
	m_pWorldBossConfig->SetIsWorldBossSelectedToCfg(m_pChkWorldBossSeleted->GetCheck());;



	m_pWorldBossConfig->SetWorldBossListSelectedToCfg(selList);
	m_pWorldBossConfig->SetBossMaxTimeoutToCfg(GetDlgItemInt(IDC_EDT_WORLD_BOSS_MAX_TIMEOUT));
	m_pWorldBossConfig->SetBossKillModeToCfg(m_pCbBossKillMode->GetCurSel());
}



void CDlgWorldBossSetting::InitListBox()
{
	
}

void CDlgWorldBossSetting::OnBnClickedBtnSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	int selCount=m_pLstAllBoss->GetSelCount();
	

}

void CDlgWorldBossSetting::OnBnClickedBtnUnselect()
{
	// TODO: 在此添加控件通知处理程序代码
	int selCount=m_pLstSelectedBoss->GetSelCount();
	
}




int CDlgWorldBossSetting::GetInsertIndexInList(int orgIndex,CListBox *pList)
{
	int findIndex=-1;
	int count=pList->GetCount();
	
	return findIndex;
}