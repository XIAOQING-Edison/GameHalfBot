// ./Dlgs/Settings/DlgDailyTaskSettings.cpp : 实现文件
//

#include "../../StdAfx.h"
// #include "GameBot.h"
#include "DlgNeutralBossSetting.h"
#include "../../Misc/Misc.h"
// static const int max_boss_num=16;


// CDlgNeutralBossSetting 对话框
static const int g_bossTransferInfoCount=1;
static const TCHAR *g_szBossTransferInfo[]={_T("boss信息")
};

IMPLEMENT_DYNAMIC(CDlgNeutralBossSetting, CDialog)

CDlgNeutralBossSetting::CDlgNeutralBossSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgNeutralBossSetting::IDD, pParent)
{

}

CDlgNeutralBossSetting::~CDlgNeutralBossSetting()
{
}

void CDlgNeutralBossSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgNeutralBossSetting, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_SELECT, &CDlgNeutralBossSetting::OnBnClickedBtnSelect)
	ON_BN_CLICKED(IDC_BTN_UNSELECT, &CDlgNeutralBossSetting::OnBnClickedBtnUnselect)
	ON_LBN_DBLCLK(IDC_LIST_NEUTRAL_BOSS_SELECT, &CDlgNeutralBossSetting::OnLbnDblclkListNeutralBossSelect)
	ON_NOTIFY(NM_DBLCLK, IDC_LST_BOSS_POINT, &CDlgNeutralBossSetting::OnNMDblclkLstBossPoint)
	ON_LBN_SELCHANGE(IDC_LIST_NEUTRAL_BOSS_SELECT, &CDlgNeutralBossSetting::OnLbnSelchangeListNeutralBossSelect)
	ON_CBN_SELCHANGE(IDC_CB_BOSS_MAP1, &CDlgNeutralBossSetting::OnCbnSelchangeCbBossMap1)
END_MESSAGE_MAP()


// CDlgDailyTaskSettings 消息处理程序

BOOL CDlgNeutralBossSetting::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_brush.CreateSolidBrush(RGB(255,255,255));//while brush
	InitCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

HBRUSH CDlgNeutralBossSetting::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	hbr=(HBRUSH)m_brush;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CDlgNeutralBossSetting::InitCtrls()
{
	m_pChkNeutralBossSeleted=(CButton*)GetDlgItem(IDC_CHK_NEUTRAL_BOSS);
	m_pLstAllBoss=(CListBox*)GetDlgItem(IDC_LIST_NETRAL_BOSS_ALL_LIST);
	m_pLstSelectedBoss=(CListBox*)GetDlgItem(IDC_LIST_NEUTRAL_BOSS_SELECT);;

	m_pEdtBossMaxTimeout=(CEdit*)GetDlgItem(IDC_EDT_NEUTRAL_BOSS_MAX_TIMEOUT);
	m_pEdtBossMaxTimeout->SetLimitText(3);

	m_pCbBossKillMode=(CComboBox*)GetDlgItem(IDC_CB_NETURAL_BOSS_MODE);
	m_pLstCtrlBossPoint=(CListCtrl*)GetDlgItem(IDC_LST_BOSS_POINT);

// 	int count=1;
// 	for(int i=0;i<count;++i)
// 	{
// 		m_pCbSelectMaps[i]=(CComboBox*)GetDlgItem(IDC_CB_BOSS_MAP1+i);
// 	}
// 

	InitListBox();//BOSS列表先屏蔽
	InitListCtrl();//已知传送点先屏蔽
}


void CDlgNeutralBossSetting::ReadIniToCtrls()
{
	CString str;
	m_pChkNeutralBossSeleted->SetCheck(m_pNeutralBossConfig->IsNeutralBossSelectedFromCfg());
	
	str.Format(_T("%d"),m_pNeutralBossConfig->GetBossMaxTimeoutFromCfg());
	m_pEdtBossMaxTimeout->SetWindowText(str);

	m_pCbBossKillMode->SetCurSel(m_pNeutralBossConfig->GetBossKillModeFromCfg());
}


void CDlgNeutralBossSetting::SaveCtrlsToIni()
{
	CString str;
	vector<int> selList;
	m_pNeutralBossConfig->SetIsNeutralBossSelectedToCfg(m_pChkNeutralBossSeleted->GetCheck());;

	
	m_pNeutralBossConfig->SetNeutralBossListSelectedToCfg(selList);
	m_pNeutralBossConfig->SetBossMaxTimeoutToCfg(GetDlgItemInt(IDC_EDT_NEUTRAL_BOSS_MAX_TIMEOUT));
	m_pNeutralBossConfig->SetBossKillModeToCfg(m_pCbBossKillMode->GetCurSel());
}



void CDlgNeutralBossSetting::InitCombo()	//主要是初始化地图类型和地图列表
{
	int i=0;
	int count=1;

}



//这里也要分多版本
void CDlgNeutralBossSetting::InitListBox()
{
	
}


void CDlgNeutralBossSetting::InitListCtrl()
{
	for(int i=0;i<g_bossTransferInfoCount;++i)
	{
		m_pLstCtrlBossPoint->InsertColumn(i,g_szBossTransferInfo[i],LVCFMT_CENTER,200);
	}


}


void CDlgNeutralBossSetting::OnBnClickedBtnSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	int selCount=m_pLstAllBoss->GetSelCount();



}

void CDlgNeutralBossSetting::OnBnClickedBtnUnselect()
{
	// TODO: 在此添加控件通知处理程序代码
	int selCount=m_pLstSelectedBoss->GetSelCount();

}



int CDlgNeutralBossSetting::GetInsertIndexInList(int orgIndex,CListBox *pList)
{
	int findIndex=-1;
	
	return findIndex;
}
void CDlgNeutralBossSetting::OnLbnDblclkListNeutralBossSelect()
{
	// TODO: 在此添加控件通知处理程序代码
}

//双击
void CDlgNeutralBossSetting::OnNMDblclkLstBossPoint(NMHDR *pNMHDR, LRESULT *pResult)
{
	*pResult = 0;
}

void CDlgNeutralBossSetting::OnLbnSelchangeListNeutralBossSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = m_pLstSelectedBoss->GetCurSel();

}


void CDlgNeutralBossSetting::InitBossPointByConfigId(int configId)
{

}
void CDlgNeutralBossSetting::OnCbnSelchangeCbBossMap1()
{
	// TODO: 在此添加控件通知处理程序代码
	//取得现时的地图下标，计算
	int curSel=m_pCbSelectMaps[0]->GetCurSel();

}

