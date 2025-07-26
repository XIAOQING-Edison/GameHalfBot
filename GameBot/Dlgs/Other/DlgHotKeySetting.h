#pragma once

#include "../../Global/public.h"
#include "../../resource.h"
#include "../../Msg.h"

// CDlgHotKeySetting �Ի���

class CDlgHotKeySetting : public CDialog
{
	DECLARE_DYNAMIC(CDlgHotKeySetting)

public:
	CDlgHotKeySetting(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgHotKeySetting();

// �Ի�������
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
	CComboBox *m_pCbHotkeyType;	//��ʼ������ͣ
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnBnClickedBtnSaveHotKey();
	afx_msg void OnCbnSelchangeCbHotKeyType();
};
