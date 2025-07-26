// ./Dlgs/Other/DlgHotKeySetting.cpp : 实现文件
//

#include "../../stdafx.h"
#include "../../GameBot.h"
#include "DlgHotKeySetting.h"
#include "../../Config/GlobalConfig.h"

// CDlgHotKeySetting 对话框

IMPLEMENT_DYNAMIC(CDlgHotKeySetting, CDialog)

CDlgHotKeySetting::CDlgHotKeySetting(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgHotKeySetting::IDD, pParent)
{

}

CDlgHotKeySetting::~CDlgHotKeySetting()
{
}

void CDlgHotKeySetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgHotKeySetting, CDialog)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_SAVE_HOT_KEY, &CDlgHotKeySetting::OnBnClickedBtnSaveHotKey)
	ON_CBN_SELCHANGE(IDC_CB_HOT_KEY_TYPE, &CDlgHotKeySetting::OnCbnSelchangeCbHotKeyType)
END_MESSAGE_MAP()


// CDlgHotKeySetting 消息处理程序

BOOL CDlgHotKeySetting::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CDlgHotKeySetting::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitCtrls();
	ReadIniToCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDlgHotKeySetting::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialog::OnCancel();
	CDialog::OnClose();
}




void CDlgHotKeySetting::InitCtrls()
{
	m_pEdtHotKey=(CStatic*)GetDlgItem(IDC_EDT_HOT_KEY);
	m_pEdtTips=(CEdit*)GetDlgItem(IDC_EDT_TIPS);
	CFont font;
	font.CreatePointFont(90, _T("黑体"));
	m_pEdtTips->SetWindowText(_T("按下任意键显示在下面的即为所需快捷键,Shift,Ctrl按两次就会取消,其它键不变!)"));	

	m_pEdtHotKey->SetFont(&font);
	m_pEdtHotKey->SetFocus();

	m_pCbHotkeyType=(CComboBox*)GetDlgItem(IDC_CB_HOT_KEY_TYPE);
	m_pCbHotkeyType->SetCurSel(0);

}
void CDlgHotKeySetting::OnBnClickedBtnSaveHotKey()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveIniFromCtrls();
	MessageBox(_T("保存成功!"));
	CDialog::OnOK();
}


void CDlgHotKeySetting::ShowKeyCodeString()
{
	CString str;

}


void CDlgHotKeySetting::ReadIniToCtrls()
{
	CGlobalConfig cfg(false);

}


void CDlgHotKeySetting::SaveIniFromCtrls()
{
	CGlobalConfig cfg(false);


}
void CDlgHotKeySetting::OnCbnSelchangeCbHotKeyType()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowKeyCodeString();
}
