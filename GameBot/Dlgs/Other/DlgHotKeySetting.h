#pragma once

#include "../../Global/public.h"
#include "../../resource.h"
#include "../../Msg.h"

// CDlgHotKeySetting 对话框

class CDlgHotKeySetting : public CDialog
{
	DECLARE_DYNAMIC(CDlgHotKeySetting)

public:
	CDlgHotKeySetting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgHotKeySetting();

// 对话框数据
	enum { IDD = IDD_DLG_ACCERLATE_SETTING };
	virtual void OnOK(){}
	virtual void OnCancel(){}
	void ShowKeyCodeString();
public:
	void InitCtrls();
	void ReadIniToCtrls();
	void SaveIniFromCtrls();
private:
	CStatic *m_pEdtHotKey;
	CEdit *m_pEdtTips;
	CComboBox *m_pCbHotkeyType;	//开始还是暂停
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnBnClickedBtnSaveHotKey();
	afx_msg void OnCbnSelchangeCbHotKeyType();
};
