#pragma once

#include "../../Config/UserConfig.h"
#include "../../resource.h"

#include "../../Config/GameConfig.h"

// CDlgUserSettings 对话框

class CDlgUserSettings : public CDialog
{
	DECLARE_DYNAMIC(CDlgUserSettings)

public:
	CDlgUserSettings(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgUserSettings();

// 对话框数据
	enum { IDD = IDD_DLG_USER_SETTINGS };
	
	void InitCtrls();
	void InitCombo();

	void SetConfigObject(CUserConfig *p){m_pUserConfig=p;}

	STRING GetUserName(){return m_strUserName;}
	void SetUserName(STRING &name){m_strUserName=name;}

	void SetAddUser(bool b){m_bAdd=b;}
	bool IsAddUser(){return m_bAdd;}

	void SetIndex(int i){m_index=i;}
	int GetIndex(){return m_index;}

	void SetConfigObjectAndReadToCtrls(CUserConfig *p){SetConfigObject(p);ReadIniToCtrls();}
	void SetConfigObjectAndSaveCtrlsToIni(CUserConfig *p){SetConfigObject(p);SaveCtrlsToIni();}

	void ReadIniToCtrls();
	void SaveCtrlsToIni();

	bool CheckValid();	//检测输入是否合法

	virtual void OnOK(){}
	virtual void OnCancel(){}
private:
	CEdit *m_pEdtUserName;
	CEdit *m_pEdtPassword;
	CEdit *m_pEdtServerId;
	CEdit *m_pEdtCookie;
	CComboBox *m_pCbPlatform;
	CButton *m_pChkIsUseCookie;
private:
	CUserConfig *m_pUserConfig;
	CBrush m_brush;
	STRING m_strUserNameOrg;	//存原来的用户名
	STRING m_strUserName;
	int m_index;
	CGameConfig *m_pGameCfg;
	bool m_bAdd;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedBtnConfirm();
};
