// ./Dlgs/Settings/DlgBotSetttings.cpp : 实现文件
//

#include "../../StdAfx.h"
// #include "GameBot.h"
#include "DlgBotSetttings.h"
#include "../../Misc/Misc.h"

// CDlgBotSetttings 对话框
static int g_checkCount=3;
IMPLEMENT_DYNAMIC(CDlgSettingSecretary2, CDialog)

CDlgSettingSecretary2::CDlgSettingSecretary2(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSettingSecretary2::IDD, pParent)
{

}

CDlgSettingSecretary2::~CDlgSettingSecretary2()
{
}

void CDlgSettingSecretary2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgSettingSecretary2, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CHK_BOT_SETTINGS_SEL_ALL, &CDlgSettingSecretary2::OnBnClickedChkBotSettingsSelAll)
	ON_BN_CLICKED(IDC_BTN_DP_DEL, &CDlgSettingSecretary2::OnBnClickedBtnDel)
	ON_BN_CLICKED(IDC_BTN_DP_ADD, &CDlgSettingSecretary2::OnBnClickedBtnAdd)
END_MESSAGE_MAP()


// CDlgBotSetttings 消息处理程序

BOOL CDlgSettingSecretary2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_brush.CreateSolidBrush(RGB(255,255,255));//while brush
	InitCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

HBRUSH CDlgSettingSecretary2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	hbr=(HBRUSH)m_brush;	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CDlgSettingSecretary2::ReadIniToCtrls()
{
	CString str;
	int i;

	m_pChkDemonPlaza->SetCheck(m_pSecretary2Config->IsAutoDemonPlazaSelectedFromCfg());
	m_pChkDemonPlazaBuyTicketWhenNotEnough->SetCheck(m_pSecretary2Config->IsDemonPlazaBuyTicketWhenNotEnoughFromCfg());

	m_pChkDemonPlazaAutoComposeTicket->SetCheck(m_pSecretary2Config->IsDemonPlazaAutoComposeTicketFromCfg());



	int tx=m_pSecretary2Config->GetDemonPlazaHungUpPointXFromCfg();	
	int ty=m_pSecretary2Config->GetDemonPlazaHungUpPointYFromCfg();

	const int defX=70;
	const int defY=89;
	if(tx==0)
		tx=defX;
	if(ty==0)
		ty=defY;

	str.Format(_T("%d"),tx);
	m_pEdtDemonPlazaHungUpPointX->SetWindowText(str);

	str.Format(_T("%d"),ty);
	m_pEdtDemonPlazaHungUpPointY->SetWindowText(str);

	vector<int> selList=m_pSecretary2Config->GetDemonPlazaTimeSelectArrayFromCfg();	

	vector<int>::iterator it=selList.begin();
	i=0;


}


void CDlgSettingSecretary2::SaveCtrlsToIni()
{
	CString str;
	int i=0;

	m_pSecretary2Config->SetIsAutoDemonPlazaSelectedToCfg(m_pChkDemonPlaza->GetCheck());
	m_pSecretary2Config->SetIsDemonPlazaBuyTicketWhenNotEnoughToCfg(m_pChkDemonPlazaBuyTicketWhenNotEnough->GetCheck());

	m_pSecretary2Config->SetIsDemonPlazaAutoComposeTicketToCfg(m_pChkDemonPlazaAutoComposeTicket->GetCheck());

	m_pEdtDemonPlazaHungUpPointX->GetWindowText(str);
	m_pSecretary2Config->SetDemonPlazaHungUpPointXToCfg(_ttoi(str));

	m_pEdtDemonPlazaHungUpPointY->GetWindowText(str);
	m_pSecretary2Config->SetDemonPlazaHungUpPointYToCfg(_ttoi(str));


	int count=m_pListSkillSelected->GetCount();

	vector<int> selList;
	m_pSecretary2Config->SetDemonPlazaTimeSelectArrayToCfg(selList);
	
}


void CDlgSettingSecretary2::InitCtrls()
{
	m_pChkDemonPlaza=(CButton*)GetDlgItem(IDC_CHK_DEMON_PLAZA);
	m_pChkDemonPlazaBuyTicketWhenNotEnough=(CButton*)GetDlgItem(IDC_CHK_DEMON_PLAZA_BUY_WHEN_TICKET_GONE);
	m_pChkDemonPlazaAutoComposeTicket=(CButton*)GetDlgItem(IDC_CHK_DEMON_PLAZA_AUTO_COMPOSE_TICKET);

	m_pEdtDemonPlazaHungUpPointX=(CEdit*)GetDlgItem(IDC_EDT_DEMON_PLAZA_EXTRA_TIME);;
	m_pEdtDemonPlazaHungUpPointY=(CEdit*)GetDlgItem(IDC_EDT_DEMON_PLAZA_QUICK_FIGHT_TIME);

	int limit=3;
	m_pEdtDemonPlazaHungUpPointX->SetLimitText(limit);
	m_pEdtDemonPlazaHungUpPointY->SetLimitText(limit);


	m_pListSkillAll=(CListBox*)GetDlgItem(IDC_LST_DEMON_PLAZA_TIME_ALL);
	m_pListSkillSelected=(CListBox*)GetDlgItem(IDC_LST_DEMON_PLAZA_TIME_SELECT);

	InitListBox();

}


void CDlgSettingSecretary2::InitBtns()
{
	int i=0;

	m_pChk[i++]=m_pChkDemonPlaza;
	m_pChk[i++]=m_pChkDemonPlazaBuyTicketWhenNotEnough;
	m_pChk[i++]=m_pChkDemonPlazaAutoComposeTicket;
	
}

void CDlgSettingSecretary2::InitListBox()
{

}



int CDlgSettingSecretary2::GetInsertIndexInList(int orgIndex,CListBox *pList)
{
	int findIndex=-1;
	int count=pList->GetCount();

	return findIndex;

}



void CDlgSettingSecretary2::CheckAll(bool bSelect)
{
	int i;
	for(i=0;i<g_checkCount;++i)
	{
		m_pChk[i]->SetCheck(bSelect);
	}

}

void CDlgSettingSecretary2::OnBnClickedChkBotSettingsSelAll()
{
	// TODO: 在此添加控件通知处理程序代码
	CheckAll(m_pChkAll->GetCheck());
}


void CDlgSettingSecretary2::OnBnClickedBtnDel()
{
	// TODO: 在此添加控件通知处理程序代码

}

void CDlgSettingSecretary2::OnBnClickedBtnAdd()
{
	// TODO: 在此添加控件通知处理程序代码
}
