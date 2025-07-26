// DlgShowLog.cpp : implementation file
//

#include "../../StdAfx.h"
#include "DlgShowLog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgShowLog dialog


CDlgShowLog::CDlgShowLog(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgShowLog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgShowLog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pDlgMain=NULL;
	m_bCreated=FALSE;
}


void CDlgShowLog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgShowLog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgShowLog, CDialog)
	//{{AFX_MSG_MAP(CDlgShowLog)
	ON_WM_CLOSE()
	ON_WM_NCHITTEST()
	ON_WM_NCMOUSEMOVE()
	ON_WM_NCLBUTTONDOWN()
	ON_BN_CLICKED(IDC_BTN_CLEAR_LOG, OnBtnClearLog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgShowLog message handlers

void CDlgShowLog::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	m_bCreated=FALSE;
	CDialog::OnCancel();
	CDialog::DestroyWindow();
	CDialog::OnClose();
}

BOOL CDlgShowLog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitCtrls();
	m_pEdtShowLog->SetSel(-1,-1);
	m_pEdtShowLog->ReplaceSel(_T(""));
	m_bCreated=TRUE;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgShowLog::InitCtrls()
{
	m_pEdtShowLog=(CEdit*)GetDlgItem(IDC_EDT_SHOW_LOG);
}


void CDlgShowLog::ClearText()
{
	m_pEdtShowLog->SetWindowText(_T(""));
}




BOOL CDlgShowLog::ReadLogToEdit(const TCHAR *szAccountName)
{
	BOOL ret=FALSE;

	return ret;
}

BOOL CDlgShowLog::WriteLogFile(const TCHAR *szAccountName,const TCHAR *buf)
{
	return FALSE;
}


void CDlgShowLog::OnBtnClearLog() 
{
	// TODO: Add your control notification handler code here
	
}


void CDlgShowLog::ClearLog(const TCHAR *szAccountName)
{
}
