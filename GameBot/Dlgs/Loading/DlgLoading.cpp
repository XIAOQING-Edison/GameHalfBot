// ./Dlgs/Loading/DlgLoading.cpp : 实现文件
//

#include "../../StdAfx.h"
#include "DlgLoading.h"


// CDlgLoading 对话框

IMPLEMENT_DYNAMIC(CDlgLoading, CDialog)

CDlgLoading::CDlgLoading(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLoading::IDD, pParent)
{

}

CDlgLoading::~CDlgLoading()
{
}

void CDlgLoading::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgLoading, CDialog)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDlgLoading 消息处理程序

void CDlgLoading::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	PlayAnimation();
	CDialog::OnTimer(nIDEvent);
}


void CDlgLoading::PlayAnimation()
{
	static int count=0;
	const int max_count=6;
	count%=max_count;
	CString str;
	CStatic *pStaticText=(CStatic*)GetDlgItem(IDC_STATIC_SHOW_TEXT);
	pStaticText->GetWindowText(str);
	str=str.Left(9);	//取左边9个字符
	for(int i=0;i<=count;++i)
	{
		str+=_T(".");
	}
	++count;
	pStaticText->SetWindowText(str);

}


BOOL CDlgLoading::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	SetTimer(1,500,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}