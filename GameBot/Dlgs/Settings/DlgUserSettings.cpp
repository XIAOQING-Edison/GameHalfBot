// ./Dlgs/Settings/DlgUserSettings.cpp : 实现文件
//

#include "../../StdAfx.h"
// #include "GameBot.h"
#include "DlgUserSettings.h"

#include "../../Config/PlatformConfig.h"
#include "../../Config/CommentConfig.h"
#include "../../Misc/Misc.h"
#include "../../Struct/AccountInfo.h"

// CDlgUserSettings 对话框

IMPLEMENT_DYNAMIC(CDlgUserSettings, CDialog)

CDlgUserSettings::CDlgUserSettings(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgUserSettings::IDD, pParent)
{
	SetAddUser(true);	//默认增加用户
}

CDlgUserSettings::~CDlgUserSettings()
{
	delete m_pGameCfg;
}

void CDlgUserSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgUserSettings, CDialog)
	ON_WM_CLOSE()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_CONFIRM, &CDlgUserSettings::OnBnClickedBtnConfirm)
END_MESSAGE_MAP()


// CDlgUserSettings 消息处理程序

BOOL CDlgUserSettings::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_brush.CreateSolidBrush(RGB(255,255,255));//while brush

	m_pGameCfg=new CGameConfig(m_strUserName,false);
// 	m_gameCfg.SetUserName(m_strUserName);
// 	m_gameCfg.SetAllObjectSectionNames();
	SetConfigObject(m_pGameCfg->GetUserConfig());

	InitCtrls();
	InitCombo();
	ReadIniToCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

HBRUSH CDlgUserSettings::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	hbr=(HBRUSH)m_brush;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CDlgUserSettings::InitCtrls()
{
	m_pEdtUserName=(CEdit*)GetDlgItem(IDC_EDT_USER_NAME);
	m_pEdtPassword=(CEdit*)GetDlgItem(IDC_EDT_PASSWORD);
	m_pEdtServerId=(CEdit*)GetDlgItem(IDC_EDT_SERVER_ID);
	m_pCbPlatform=(CComboBox*)GetDlgItem(IDC_CB_PLATFORM);
	m_pEdtCookie=(CEdit*)GetDlgItem(IDC_EDT_COOKIE);
	m_pChkIsUseCookie=(CButton*)GetDlgItem(IDC_CHK_USE_COOKIE);

}

void CDlgUserSettings::InitCombo()
{
	CPlatformConfig platCfg;
	CCommentConfig cfg(platCfg.GetCfgFileName(),_T(";"),true);
	vector<pair<STRING,STRING> > allKeyValue=cfg.GetAllKeyValueBySetionNameNoSorted(g_szDefSectionName);
	vector<pair<STRING,STRING> >::iterator it=allKeyValue.begin();
	int i=0;
	while(it !=allKeyValue.end())
	{
		m_pCbPlatform->InsertString(i++,it->second.c_str());
		++it;
	}
}


void CDlgUserSettings::ReadIniToCtrls()
{
// 	if(!m_bAdd)
// 	{
// 		m_pEdtUserName->EnableWindow(FALSE);
// 	}
	m_strUserNameOrg=m_pUserConfig->GetUserNameFromCfg();
	m_pEdtUserName->SetWindowText(m_strUserNameOrg.c_str());
	m_pEdtPassword->SetWindowText(m_pUserConfig->GetPasswordFromCfg().c_str());
	SetDlgItemInt(IDC_EDT_SERVER_ID,m_pUserConfig->GetServerIdFromCfg());
	m_pCbPlatform->SetCurSel(m_pUserConfig->GetPlatformIdFromCfg());

	m_pEdtCookie->SetWindowText(m_pUserConfig->GetCookieFromCfg().c_str());
	m_pChkIsUseCookie->SetCheck(m_pUserConfig->IsUseCookieFromCfg());
}



void CDlgUserSettings::SaveCtrlsToIni()
{
	CString str;
	STRING res;
	CGameConfig gameCfg(m_strUserName,false);
	
	m_pEdtUserName->GetWindowText(str);
	res=str;
	m_pUserConfig->SetUserNameToCfg(res);

	m_pEdtPassword->GetWindowText(str);
	res=str;
	m_pUserConfig->SetPasswordToCfg(res);

	int serverId=GetDlgItemInt(IDC_EDT_SERVER_ID);
	m_pUserConfig->SetServerIdToCfg(serverId);

	m_pUserConfig->SetPlatformIdToCfg(m_pCbPlatform->GetCurSel());


	m_pEdtCookie->GetWindowText(str);
	res=str;
	m_pUserConfig->SetCookieToCfg(res);

	m_pUserConfig->SetIsUseCookieToCfg(m_pChkIsUseCookie->GetCheck());
	
}
void CDlgUserSettings::OnBnClickedBtnConfirm()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!CheckValid())
	{
		return;
	}

	SaveCtrlsToIni();
	
	CAccountInfo accountInfo;
	accountInfo.SetIndex(this->GetIndex());
	accountInfo.SetPlatformIndex(m_pUserConfig->GetPlatformIdFromCfg());
	accountInfo.SetServerId(m_pUserConfig->GetServerIdFromCfg());
	accountInfo.SetAccountName(m_pUserConfig->GetUserNameFromCfg());
	if(IsAddUser())
	{
		CMisc::GetInstance()->SendAddAccountInfoToMainHwnd((LPARAM)&accountInfo);
	}
	else
	{
		CMisc::GetInstance()->SendUpdateAccountInfoToMainHwnd((LPARAM)&accountInfo);
	}
	AfxMessageBox(_T("保存成功!"));
	EndDialog(0);
}


void CDlgUserSettings::OnClose()
{
	CDialog::OnCancel();
}


bool  CDlgUserSettings::CheckValid()	//检测输入是否合法
{
	bool ret=true;
	CString str;
	m_pEdtUserName->GetWindowText(str);
	if(str.GetLength()==0)
	{
		AfxMessageBox(_T("请输入用户名!"));
		ret=false;
		goto EXT;
	}
	m_pEdtPassword->GetWindowText(str);
	if(str.GetLength()==0)
	{
		AfxMessageBox(_T("请输入密码!"));
		ret=false;
		goto EXT;
	}

	m_pEdtServerId->GetWindowText(str);
	if(str.GetLength()==0)
	{
		AfxMessageBox(_T("请输入服务器Id!"));
		ret=false;
		goto EXT;
	}
EXT:
	return ret;
}