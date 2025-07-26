// ./Dlgs/Settings/DlgBeastBossSettings.cpp : ʵ���ļ�
//

#include "../../stdafx.h"
// #include "GameBot.h"
#include "DlgBeastBossSettings.h"


// static const int max_boss_num=16;


// CDlgBeastBossSetting �Ի���

IMPLEMENT_DYNAMIC(CDlgBeastBossSetting, CDialog)

CDlgBeastBossSetting::CDlgBeastBossSetting(CWnd* pParent /*=NULL*/)
: CDialog(CDlgBeastBossSetting::IDD, pParent)
{

}

CDlgBeastBossSetting::~CDlgBeastBossSetting()
{
}

void CDlgBeastBossSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgBeastBossSetting, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_SELECT, &CDlgBeastBossSetting::OnBnClickedBtnSelect)
	ON_BN_CLICKED(IDC_BTN_UNSELECT, &CDlgBeastBossSetting::OnBnClickedBtnUnselect)
END_MESSAGE_MAP()


// CDlgDailyTaskSettings ��Ϣ�������

BOOL CDlgBeastBossSetting::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_brush.CreateSolidBrush(RGB(255,255,255));//while brush
	InitCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

HBRUSH CDlgBeastBossSetting::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	hbr=(HBRUSH)m_brush;
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CDlgBeastBossSetting::InitCtrls()
{
	m_pChkBeastBossSeleted=(CButton*)GetDlgItem(IDC_CHK_BEAST_BOSS);
	m_pLstAllBoss=(CListBox*)GetDlgItem(IDC_LIST_BEAST_BOSS_ALL_LIST);
	m_pLstSelectedBoss=(CListBox*)GetDlgItem(IDC_LIST_BEAST_BOSS_SELECT);;
	
	m_pEdtBossMaxTimeout=(CEdit*)GetDlgItem(IDC_EDT_BEAST_BOSS_MAX_TIMEOUT);
	m_pEdtBossMaxTimeout->SetLimitText(3);

	InitListBox();
}


void CDlgBeastBossSetting::ReadIniToCtrls()
{
	CString str;
	m_pChkBeastBossSeleted->SetCheck(m_pBeastBossConfig->IsBeastBossSelectedFromCfg());

	str.Format(_T("%d"),m_pBeastBossConfig->GetBossMaxTimeoutFromCfg());
	m_pEdtBossMaxTimeout->SetWindowText(str);

}


void CDlgBeastBossSetting::SaveCtrlsToIni()
{
	CString str;
	vector<int> selList;
	m_pBeastBossConfig->SetIsBeastBossSelectedToCfg(m_pChkBeastBossSeleted->GetCheck());;

	m_pBeastBossConfig->SetBeastBossListSelectedToCfg(selList);

	m_pBeastBossConfig->SetBossMaxTimeoutToCfg(GetDlgItemInt(IDC_EDT_BEAST_BOSS_MAX_TIMEOUT));

}






void CDlgBeastBossSetting::InitListBox()
{
	
}

void CDlgBeastBossSetting::OnBnClickedBtnSelect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int selCount=m_pLstAllBoss->GetSelCount();


}

void CDlgBeastBossSetting::OnBnClickedBtnUnselect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int selCount=m_pLstSelectedBoss->GetSelCount();

}



int CDlgBeastBossSetting::GetInsertIndexInList(int orgIndex,CListBox *pList)
{
	int findIndex=-1;
	return findIndex;
}