// ./Dlgs/Other/DlgShowReadMe.cpp : 实现文件
//

#include "../../StdAfx.h"
#include "DlgShowReadMe.h"

// CDlgShowReadMe 对话框

IMPLEMENT_DYNAMIC(CDlgShowReadMe, CDialog)

CDlgShowReadMe::CDlgShowReadMe(STRING &title,CWnd* pParent /*=NULL*/)
	: CDialog(CDlgShowReadMe::IDD, pParent)
{
	m_titleName=title;
}

CDlgShowReadMe::~CDlgShowReadMe()
{
}

void CDlgShowReadMe::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgShowReadMe, CDialog)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CDlgShowReadMe 消息处理程序

BOOL CDlgShowReadMe::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitCtrls();
	SetWindowText(m_titleName.c_str());
	ReadFileToEdit(_T("GameVersion.dat"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDlgShowReadMe::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialog::OnCancel();
	CDialog::OnClose();
}



void CDlgShowReadMe::InitCtrls()
{
	m_pEdtShowLog=(CEdit*)GetDlgItem(IDC_EDT_READ_ME);
}

BOOL CDlgShowReadMe::ReadFileToEdit(const TCHAR *szFileName)
{
	BOOL ret=FALSE;
	return ret;
}