// ./Dlgs/Settings/DlgAsuramSettings.cpp : 实现文件
//

#include "../../StdAfx.h"
// #include "GameBot.h"
#include "DlgAsuramSettings.h"
#include "../../Misc/Misc.h"

static int g_checkCount=1;
// CDlgAsuramSettings 对话框

IMPLEMENT_DYNAMIC(CDlgSettingSecretary3, CDialog)

CDlgSettingSecretary3::CDlgSettingSecretary3(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSettingSecretary3::IDD, pParent)
{

}

CDlgSettingSecretary3::~CDlgSettingSecretary3()
{
}

void CDlgSettingSecretary3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgSettingSecretary3, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CHK_ASURAM_SETTINGS_SEL_ALL, &CDlgSettingSecretary3::OnBnClickedChkAsuramSettingsSelAll)
	ON_BN_CLICKED(IDC_BTN_DEL, &CDlgSettingSecretary3::OnBnClickedBtnDel)
	ON_BN_CLICKED(IDC_BTN_ADD, &CDlgSettingSecretary3::OnBnClickedBtnAdd)
END_MESSAGE_MAP()


// CDlgAsuramSettings 消息处理程序

BOOL CDlgSettingSecretary3::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_brush.CreateSolidBrush(RGB(255,255,255));//while brush
	InitCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


HBRUSH CDlgSettingSecretary3::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
// 	if(nCtlColor==CTLCOLOR_DLG || nCtlColor==CTLCOLOR_BTN)
// 	{
		hbr=(HBRUSH)m_brush;
// 	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CDlgSettingSecretary3::InitCtrls()
{
	m_pChkBloodTown=(CButton*)GetDlgItem(IDC_CHK_BLOOD_TOWN);
	m_pChkBloodTownAutoComposeTicket=(CButton*)GetDlgItem(IDC_CHK_BLOOD_TOWN_AUTO_COMPOSE_TICKET);

	m_pEdtBloodCastleAutoHungUpPointX=(CEdit*)GetDlgItem(IDC_EDT_BLOOD_CASTLE_TARGET_X);
	m_pEdtBloodCastleAutoHungUPPointY=(CEdit*)GetDlgItem(IDC_EDT_BLOOD_CASTLE_TARGET_Y);	 

	m_pListSkillAll=(CListBox*)GetDlgItem(IDC_LST_BLOOD_CASTLE_TIME_ALL);
	m_pListSkillSelected=(CListBox*)GetDlgItem(IDC_LST_BLOOD_CASTLE_TIME_SELECT);

	m_pChkAll=(CButton*)GetDlgItem(IDC_CHK_ASURAM_SETTINGS_SEL_ALL);

	InitBtns();
	InitListBox();
}



void CDlgSettingSecretary3::ReadIniToCtrls()
{
	CString str;

	int tx=m_pSecretary1Config->GetBloodCastleHungUpPointXFromCfg();	
	int ty=m_pSecretary1Config->GetBloodCastleHungUpPointYFromCfg();

	const int defX=14;
	const int defY=43;
	if(tx==0)
		tx=defX;
	if(ty==0)
		ty=defY;

	str.Format(_T("%d"),tx);
	m_pEdtBloodCastleAutoHungUpPointX->SetWindowText(str);

	str.Format(_T("%d"),ty);
	m_pEdtBloodCastleAutoHungUPPointY->SetWindowText(str);


	m_pChkBloodTown->SetCheck(m_pSecretary1Config->IsBloodCastleSelectedFromCfg());
	//m_pChkBloodTownAutoComposeTicket->SetCheck(m_pSecretary1Config->IsBloodTownAutoComposeTicketFromCfg());	

	vector<int> selSkillList=m_pSecretary1Config->GetBloodCastleTimeSelectArrayFromCfg();	

	vector<int>::iterator it=selSkillList.begin();
	int i=0;
	

}


void CDlgSettingSecretary3::SaveCtrlsToIni()
{
	CString str;
	int count=m_pListSkillSelected->GetCount();
	vector<int> selList;
	m_pSecretary1Config->SetBloodCastleTimeSelectArrayToCfg(selList);

	m_pEdtBloodCastleAutoHungUpPointX->GetWindowText(str);
	m_pSecretary1Config->SetBloodCastleHungUpPointXToCfg(_ttoi(str));

	m_pEdtBloodCastleAutoHungUPPointY->GetWindowText(str);
	m_pSecretary1Config->SetBloodCastleHungUpPointYToCfg(_ttoi(str));

	m_pSecretary1Config->SetIsBloodTownSelectedToCfg(m_pChkBloodTown->GetCheck());
	m_pSecretary1Config->SetIsBloodTownBloodTownAutoComposeTicketToCfg(m_pChkBloodTownAutoComposeTicket->GetCheck());
}



void CDlgSettingSecretary3::InitBtns()
{
	int i=0;
	m_pChk[i++]=m_pChkBloodTown;

}



void CDlgSettingSecretary3::CheckAll(bool bSelect)
{
	for(int i=0;i<g_checkCount;++i)
	{
		m_pChk[i]->SetCheck(bSelect);
	}
}


void CDlgSettingSecretary3::InitListBox()
{

}


int CDlgSettingSecretary3::GetInsertIndexInList(int orgIndex,CListBox *pList)
{
	int findIndex=-1;
	int count=pList->GetCount();
	return findIndex;

}


void CDlgSettingSecretary3::OnBnClickedChkAsuramSettingsSelAll()
{
	// TODO: 在此添加控件通知处理程序代码
	CheckAll(m_pChkAll->GetCheck());
}

void CDlgSettingSecretary3::OnBnClickedBtnDel()
{
	// TODO: 在此添加控件通知处理程序代码
	int selCount=m_pListSkillSelected->GetSelCount();

}

void CDlgSettingSecretary3::OnBnClickedBtnAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	int selCount=m_pListSkillAll->GetSelCount();
}

