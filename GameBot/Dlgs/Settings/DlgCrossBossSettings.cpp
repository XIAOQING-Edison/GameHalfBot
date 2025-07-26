// ./Dlgs/Settings/DlgCrossBossSettings.cpp : ʵ���ļ�
//

#include "../../stdafx.h"
// #include "GameBot.h"
#include "DlgCrossBossSettings.h"


// static const int max_boss_num=16;


// CDlgCrossBossSetting �Ի���

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


// CDlgDailyTaskSettings ��Ϣ�������

BOOL CDlgCrossBossSetting::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_brush.CreateSolidBrush(RGB(255,255,255));//while brush
	InitCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

HBRUSH CDlgCrossBossSetting::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	hbr=(HBRUSH)m_brush;
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
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
	m_pChkCrossBossSeleted->SetWindowText(_T("ת��boss"));
#else
	m_pChkCrossBossSeleted->SetWindowText(_T("�ƽ��"));
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int selCount=m_pLstAllBoss->GetSelCount();
	CArray<int,int> aryListBoxSel;

	aryListBoxSel.SetSize(selCount);

	m_pLstAllBoss->GetSelItems(selCount,aryListBoxSel.GetData()); 
	

}

void CDlgCrossBossSetting::OnBnClickedBtnUnselect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int selCount=m_pLstSelectedBoss->GetSelCount();
	
}



int CDlgCrossBossSetting::GetInsertIndexInList(int orgIndex,CListBox *pList)
{
	int findIndex=-1;
	int count=pList->GetCount();
	
	return findIndex;
}