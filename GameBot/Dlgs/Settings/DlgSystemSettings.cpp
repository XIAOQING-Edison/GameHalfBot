// ./Dlgs/Settings/DlgSystemSettings.cpp : ʵ���ļ�
//

#include "../../StdAfx.h"
// #include "GameBot.h"
#include "DlgSystemSettings.h"


// CDlgSystemSettings �Ի���

IMPLEMENT_DYNAMIC(CDlgSystemSettings, CDialog)

CDlgSystemSettings::CDlgSystemSettings(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSystemSettings::IDD, pParent)
{

}

CDlgSystemSettings::~CDlgSystemSettings()
{
}

void CDlgSystemSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgSystemSettings, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CDlgSystemSettings ��Ϣ�������

BOOL CDlgSystemSettings::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_brush.CreateSolidBrush(RGB(255,255,255));//while brush
	InitCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

HBRUSH CDlgSystemSettings::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	hbr=(HBRUSH)m_brush;
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CDlgSystemSettings::InitCtrls()
{
	int limit=2;
	m_pEdtMinutesToReloginWhenLogoutByOther=(CEdit*)GetDlgItem(IDC_EDT_RELOGIN_BY_OTHER);
	m_pEdtMinutesToReloginWhenLogoutWhenDisconnect=(CEdit*)GetDlgItem(IDC_EDT_RELOGIN_BY_DISCONNET);

	m_pEdtMinutesToReloginWhenLogoutByOther->SetLimitText(limit);
	m_pEdtMinutesToReloginWhenLogoutWhenDisconnect->SetLimitText(limit);
 

	m_pCbReviveType=(CComboBox*)GetDlgItem(IDC_CB_REVIVE_TYPE);

	m_pEdtRestarHours=(CEdit*)GetDlgItem(IDC_EDT_RESTART_HOURS);
	m_pEdtRestarHours->SetLimitText(limit);
}


void CDlgSystemSettings::ReadIniToCtrls()
{
	CString str;

	str.Format(_T("%d"),m_pSystemConfig->GetMinutesToReloginWhenLogoutByOtherFromCfg());
	m_pEdtMinutesToReloginWhenLogoutByOther->SetWindowText(str);

	str.Format(_T("%d"),m_pSystemConfig->GetMinutesToReloginWhenLogoutByDisconnectFromCfg());
	m_pEdtMinutesToReloginWhenLogoutWhenDisconnect->SetWindowText(str);


	m_pCbReviveType->SetCurSel(m_pSystemConfig->GetReviveTypeFromCfg());

	str.Format(_T("%d"),m_pSystemConfig->GetLoadMapMaxWaitSecondsFromCfg());
	m_pEdtRestarHours->SetWindowText(str);



}


void CDlgSystemSettings::SaveCtrlsToIni()
{
	CString str;
	m_pEdtMinutesToReloginWhenLogoutByOther->GetWindowText(str);
	m_pSystemConfig->SetMinutesToReloginWhenLogoutByOtherToCfg(_ttoi(str));

	m_pEdtMinutesToReloginWhenLogoutWhenDisconnect->GetWindowText(str);
	m_pSystemConfig->SetMinutesToReloginWhenLogoutByDisconnectToCfg(_ttoi(str));


	m_pSystemConfig->SetLoadMapMaxWaitSecondsToCfg(m_pCbReviveType->GetCurSel());

	m_pEdtRestarHours->GetWindowText(str);
	m_pSystemConfig->SetLoadMapMaxWaitSecondsToCfg(_ttoi(str));

	m_pSystemConfig->SetReviveTypeToCfg(m_pCbReviveType->GetCurSel());

}