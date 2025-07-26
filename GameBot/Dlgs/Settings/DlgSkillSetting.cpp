// ./Dlgs/Settings/DlgSkillSetting.cpp : 实现文件
//

#include "../../stdafx.h"
#include "DlgSkillSetting.h"
#include "../../Config/SkillConfig.h"


// CDlgSkillSetting 对话框

IMPLEMENT_DYNAMIC(CDlgSkillSetting, CDialog)

CDlgSkillSetting::CDlgSkillSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSkillSetting::IDD, pParent)
{
	SetCareer(-1);
}

CDlgSkillSetting::~CDlgSkillSetting()
{
}

void CDlgSkillSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgSkillSetting, CDialog)
	ON_BN_CLICKED(IDC_BTN_DEL, &CDlgSkillSetting::OnBnClickedBtnDel)
	ON_BN_CLICKED(IDC_BTN_ADD, &CDlgSkillSetting::OnBnClickedBtnAdd)
	ON_CBN_SELCHANGE(IDC_CB_SKILL_JOB, &CDlgSkillSetting::OnCbnSelchangeCbSkillJob)
	ON_BN_CLICKED(IDC_BTN_SEL_EXIST, &CDlgSkillSetting::OnBnClickedBtnSelExist)
END_MESSAGE_MAP()


// CDlgSkillSetting 消息处理程序
void CDlgSkillSetting::InitCtrls()
{
	m_pCbListJobSel=(CComboBox*)GetDlgItem(IDC_CB_SKILL_JOB);
	m_pListSkillAll=(CListBox*)GetDlgItem(IDC_LST_SKILL_SRC);
	m_pListSkillSelected=(CListBox*)GetDlgItem(IDC_LST_SKILL_DST);

	m_pEdtSendInterval=(CEdit*)GetDlgItem(IDC_EDT_SEND_INTERVAL);
	m_pEdtTargetX=(CEdit*)GetDlgItem(IDC_EDT_TARGET_X);
	m_pEdtTargetY=(CEdit*)GetDlgItem(IDC_EDT_TARGET_Y);
	m_pEdtSendInterval->SetLimitText(2);
	m_pEdtTargetX->SetLimitText(3);
	m_pEdtTargetY->SetLimitText(3);
}




void CDlgSkillSetting::ReadIniToCtrls()
{
	CString str;
	CSkillConfig *pSkillConfig=m_pSkillConfig;
	
	str.Format(_T("%d"),pSkillConfig->GetSkillTargetXFromCfg());
	m_pEdtTargetX->SetWindowText(str);

	str.Format(_T("%d"),pSkillConfig->GetSkillTargetYFromCfg());
	m_pEdtTargetY->SetWindowText(str);

	str.Format(_T("%d"),pSkillConfig->GetSkillSendIntervalFromCfg());
	m_pEdtSendInterval->SetWindowText(str);

}


void CDlgSkillSetting::SaveCtrlsToIni()
{
	CString str;
	CSkillConfig *pSkillConfig=m_pSkillConfig;
	
	
	int count=GetDlgItemInt(IDC_EDT_SEND_INTERVAL);
	pSkillConfig->SetSkillSendIntervalToCfg(count);


	count=GetDlgItemInt(IDC_EDT_TARGET_X);
	pSkillConfig->SetSkillTargetXToCfg(count);

	count=GetDlgItemInt(IDC_EDT_TARGET_Y);
	pSkillConfig->SetSkillTargetYToCfg(count);


}



void CDlgSkillSetting::InitListBox()
{
	ClearListBoxShow(m_pListSkillAll);
	
}


void CDlgSkillSetting::InitComboBox()
{

}

void CDlgSkillSetting::OnBnClickedBtnDel()
{
	// TODO: 在此添加控件通知处理程序代码
	int selCount=m_pListSkillAll->GetSelCount();
	
	
}

void CDlgSkillSetting::OnBnClickedBtnAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	int selCount=m_pListSkillSelected->GetSelCount();
	
}

void CDlgSkillSetting::OnCbnSelchangeCbSkillJob()
{
	// TODO: 在此添加控件通知处理程序代码
	InitListBox();
}


//这时用skillId作为比较值
int CDlgSkillSetting::GetInsertIndexInList(int orgIndex,CListBox *pList)
{
	int findIndex=-1;
	int count=pList->GetCount();

	return findIndex;
}

BOOL CDlgSkillSetting::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	InitCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlgSkillSetting::ClearListBoxShow(CListBox *pListBox)
{
	 int count = pListBox->GetCount(); 
	 for (int i = count; i >= 0; i--) 
		 pListBox->DeleteString (i);
}


void CDlgSkillSetting::OnBnClickedBtnSelExist()
{

}
