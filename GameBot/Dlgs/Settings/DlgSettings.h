#pragma once



#include "../../Config/GameConfig.h"
#include "../../resource.h"
// CDlgSettings 对话框

enum E_SETTING_MODE	
{
	e_setting_mode_add_or_modify_user=0,	//只修改用户
	e_setting_mode_other_task	//修改其它任务配置
};

extern const int g_tabCount;

#include "DlgBotSetttings.h"
#include "DlgDailyTaskSettings.h"
#include "DlgAsuramSettings.h"
#include "DlgSettingSecretary4.h"
#include "DlgSettingSecretary5.h"

class CPlayer;
class CDlgSecretarySettings : public CDialog
{
	DECLARE_DYNAMIC(CDlgSecretarySettings)

public:
	CDlgSecretarySettings(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgSecretarySettings();

// 对话框数据
	enum { IDD = IDD_DLG_SECRETARY_SETTINGS };


public:
	CTabCtrl *m_pTab;

	void InitCtrls();

	void AddDlgsToTab();

	void InitChildDlgs();

	void DestroyAllChildDlgs();

	void SetAddUser(bool b){m_bAdd=b;}
	bool IsAddUser(){return m_bAdd;}

	void SetAccountName(STRING &name){m_accountName=name;}
	STRING GetAccountName(){return m_accountName;}


	void ReadIniToCtrls();	//从ini里读取值到各子窗口
	void SaveCtrlsToIni();	//子窗口各自保存值到ini



	virtual void OnOK(){}
	virtual void OnCancel(){}

	void SendMsgToMainWin(WPARAM wParam,LPARAM lParam);
	
	void SetMainHwnd(HWND hwnd){m_hwndMain=hwnd;}
	HWND GetMainHwnd(){return m_hwndMain;}

	void SetIndex(int i){m_index=i;}
	int GetIndex(){return m_index;}
	void SetPlayerPointer(CPlayer *player);
private:
	CDialog *m_pDlg[5];	//放dlg指针方便操作,先设为常量，后面再更改
	
	CDlgSettingSecretary1 m_dlgSecretary1Settings;
	CDlgSettingSecretary2 m_dlgSecretary2Settings;
	CDlgSettingSecretary3 m_dlgSecretary3Settings;
	CDlgSettingSecretary4 m_dlgSecretary4Settings;
	CDlgSettingSecretary5 m_dlgSecretary5Settings;
	

private:
	bool m_bAdd;	//是否是添加用户
	STRING m_accountName;
	HWND m_hwndMain;	//主窗口
	int m_index;	//列表下标
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTabSettings(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
