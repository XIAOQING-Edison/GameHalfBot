#pragma once

#include "../../Config/SystemConfig.h"
#include "../../resource.h"
// CDlgSystemSettings 对话框

class CDlgSystemSettings : public CDialog
{
	DECLARE_DYNAMIC(CDlgSystemSettings)

public:
	CDlgSystemSettings(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgSystemSettings();

// 对话框数据
	enum { IDD = IDD_DLG_SYSTEM_SETTINGS };

	void SetConfigObject(CSystemConfig *p){m_pSystemConfig=p;}

	void SetConfigObjectAndReadToCtrls(CSystemConfig *p){SetConfigObject(p);ReadIniToCtrls();}
	void SetConfigObjectAndSaveCtrlsToIni(CSystemConfig *p){SetConfigObject(p);SaveCtrlsToIni();}

	void InitCtrls();

	void ReadIniToCtrls();
	void SaveCtrlsToIni();


	virtual void OnOK(){}
	virtual void OnCancel(){}
private:
	CEdit *m_pEdtMinutesToReloginWhenLogoutByOther;
	CEdit *m_pEdtMinutesToReloginWhenLogoutWhenDisconnect;

	CEdit *m_pEdtRestarHours;
	CComboBox *m_pCbReviveType;
private:
	CSystemConfig *m_pSystemConfig;
	CBrush m_brush;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
