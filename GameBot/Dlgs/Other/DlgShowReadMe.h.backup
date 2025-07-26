#pragma once

#include "../../Global/public.h"
#include "../../resource.h"

// CDlgShowReadMe 对话框

class CDlgShowReadMe : public CDialog
{
	DECLARE_DYNAMIC(CDlgShowReadMe)

public:
	CDlgShowReadMe(STRING &title,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgShowReadMe();

// 对话框数据
	enum { IDD = IDD_DLG_READ_ME };
public:
	void InitCtrls();
	BOOL ReadFileToEdit(const TCHAR *szFileName);
private:
	STRING m_titleName;
	CEdit *m_pEdtShowLog;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
};
