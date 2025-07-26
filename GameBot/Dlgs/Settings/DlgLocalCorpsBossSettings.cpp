// ./Dlgs/Settings/DlgCrossBossSettings.cpp : ʵ���ļ�
//

#include "../../stdafx.h"
// #include "GameBot.h"
#include "DlgLocalCorpsBossSettings.h"


// static const int max_boss_num=16;


// CDlgCrossBossSetting �Ի���

IMPLEMENT_DYNAMIC(CDlgLocalCorpsBossSetting, CDialog)

CDlgLocalCorpsBossSetting::CDlgLocalCorpsBossSetting(CWnd* pParent /*=NULL*/)
: CDialog(CDlgLocalCorpsBossSetting::IDD, pParent)
{

}

CDlgLocalCorpsBossSetting::~CDlgLocalCorpsBossSetting()
{
}

void CDlgLocalCorpsBossSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgLocalCorpsBossSetting, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_SELECT, &CDlgLocalCorpsBossSetting::OnBnClickedBtnSelect)
	ON_BN_CLICKED(IDC_BTN_UNSELECT, &CDlgLocalCorpsBossSetting::OnBnClickedBtnUnselect)
END_MESSAGE_MAP()


// CDlgDailyTaskSettings ��Ϣ�������

BOOL CDlgLocalCorpsBossSetting::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_brush.CreateSolidBrush(RGB(255,255,255));//while brush
	InitCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

HBRUSH CDlgLocalCorpsBossSetting::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	hbr=(HBRUSH)m_brush;
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CDlgLocalCorpsBossSetting::InitCtrls()
{
	m_pChkCrossBossSeleted=(CButton*)GetDlgItem(IDC_CHK_LOCAL_CORPS_BOSS);
	m_pLstAllBoss=(CListBox*)GetDlgItem(IDC_LIST_LOCAL_CORPS_BOSS_ALL_LIST);
	m_pLstSelectedBoss=(CListBox*)GetDlgItem(IDC_LIST_LOCAL_CORPS_BOSS_SELECT);;

	m_pEdtBossMaxTimeout=(CEdit*)GetDlgItem(IDC_EDT_LOCAL_CORPS_BOSS_MAX_TIMEOUT);
	m_pEdtBossMaxTimeout->SetLimitText(3);

	m_pCbBossKillMode=(CComboBox*)GetDlgItem(IDC_CB_LOCAL_CORPS_BOSS_MODE);
	InitListBox();
}


void CDlgLocalCorpsBossSetting::ReadIniToCtrls()
{
	CString str;
	m_pChkCrossBossSeleted->SetCheck(m_pLocalCorpsBossConfig->IsLocalCorpsBossSelectedFromCfg());
	
	str.Format(_T("%d"),m_pLocalCorpsBossConfig->GetBossMaxTimeoutFromCfg());
	m_pEdtBossMaxTimeout->SetWindowText(str);

	m_pCbBossKillMode->SetCurSel(m_pLocalCorpsBossConfig->GetBossKillModeFromCfg());

}


void CDlgLocalCorpsBossSetting::SaveCtrlsToIni()
{
	CString str;
	vector<int> selList;
	m_pLocalCorpsBossConfig->SetIsLocalCorpsBossSelectedToCfg(m_pChkCrossBossSeleted->GetCheck());;

	
	m_pLocalCorpsBossConfig->SetLocalCorpsBossListSelectedToCfg(selList);
	m_pLocalCorpsBossConfig->SetBossMaxTimeoutToCfg(GetDlgItemInt(IDC_EDT_LOCAL_CORPS_BOSS_MAX_TIMEOUT));
	m_pLocalCorpsBossConfig->SetBossKillModeToCfg(m_pCbBossKillMode->GetCurSel());

}






void CDlgLocalCorpsBossSetting::InitListBox()
{
	
}

void CDlgLocalCorpsBossSetting::OnBnClickedBtnSelect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int selCount=m_pLstAllBoss->GetSelCount();
	

}

void CDlgLocalCorpsBossSetting::OnBnClickedBtnUnselect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int selCount=m_pLstSelectedBoss->GetSelCount();
	
}



int CDlgLocalCorpsBossSetting::GetInsertIndexInList(int orgIndex,CListBox *pList)
{
	int findIndex=-1;
	int count=pList->GetCount();
	
	return findIndex;
}