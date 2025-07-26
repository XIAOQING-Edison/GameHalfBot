#if !defined(AFX_DLGSHOWLOG_H__B8AC2A33_8CDD_4474_B4B5_0A84B4EEB93D__INCLUDED_)
#define AFX_DLGSHOWLOG_H__B8AC2A33_8CDD_4474_B4B5_0A84B4EEB93D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../../Global/public.h"
#include "../../resource.h"
// DlgShowLog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgShowLog dialog

class CDlgShowLog : public CDialog
{
// Construction
public:
	CDlgShowLog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgShowLog)
	enum { IDD = IDD_DLG_SHOW_LOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
public:
	HWND GetEdtHwnd(){return m_pEdtShowLog->GetSafeHwnd();}
	void InitCtrls();
	void ClearText();
	BOOL ReadLogToEdit(const TCHAR *szAccountName);
	BOOL WriteLogFile(const TCHAR *szAccountName,const TCHAR *buf);
	void ClearLog(const TCHAR *szAccountName);
	void SetMainDlg(CDialog *pDlg){m_pDlgMain=pDlg;}
	CDialog *GetMainDlg(){return m_pDlgMain;}

	BOOL IsDlgCreated(){return m_bCreated;}
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgShowLog)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
private:
	BOOL m_bCreated;
	STRING m_accountName;
	CEdit *m_pEdtShowLog;
	CDialog *m_pDlgMain;	//dock to main window
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgShowLog)
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnClearLog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSHOWLOG_H__B8AC2A33_8CDD_4474_B4B5_0A84B4EEB93D__INCLUDED_)
