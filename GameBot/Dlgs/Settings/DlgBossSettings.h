#pragma once

#include "../../Config/BossConfig.h"
#include "DlgNeutralBossSetting.h"
#include "DlgWorldBossSetting.h"
#include "DlgCrossBossSettings.h"
#include "DlgLocalCorpsBossSettings.h"
#include "DlgCrossCorpsBossSettings.h"
#include "DlgBeastBossSettings.h"
#include "DlgOtherTaskSettings.h"	//作为协助界面
#include "../../resource.h"
// CDlgBossSettings 对话框

class CDlgBossSettings : public CDialog
{
	DECLARE_DYNAMIC(CDlgBossSettings)

public:
	CDlgBossSettings(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgBossSettings();

// 对话框数据
	enum { IDD = IDD_DLG_BOSS_SETTTINGS };

	void SetConfigObject(CBossConfig *p){m_pBossConfig=p;}

	void SetConfigObjectAndReadToCtrls(CBossConfig *p){SetConfigObject(p);ReadIniToCtrls();}
	void SetConfigObjectAndSaveCtrlsToIni(CBossConfig *p){SetConfigObject(p);SaveCtrlsToIni();}

	void InitCtrls();

	void ReadIniToCtrls();	//从ini里读取值到各子窗口
	void SaveCtrlsToIni();	//子窗口各自保存值到ini

	virtual void OnOK(){}
	virtual void OnCancel(){}
	void SetAccountName(STRING &acc){m_accountName=acc;}
	void SetPlayerIndex(int idx){m_playerIndex=idx;}
private:
	void InitTab();
	void InitChildDlgs();

	void DestroyAllChildDlgs();
	void AddDlgsToTab();
private:
	CDialog *m_pDlg[7];	//放dlg指针方便操作,先设为常量，后面再更改
	CTabCtrl *m_pTabCtrl;
	CDlgNeutralBossSetting m_dlgNeutralBossSettings;
	CDlgWorldBossSetting m_dlgWorldBossSettings;
	CDlgCrossBossSetting m_dlgCrossBossSettings;
	CDlgLocalCorpsBossSetting m_dlgLocalCorpsBossSettings;
	CDlgCrossCorpsBossSetting m_dlgCrossCorpsBossSettings;
	CDlgBeastBossSetting m_dlgBeastBossSettings;
	CDlgBossAssistSettings m_dlgBossAssistSettings;
// 	CDlgBossSettings m_dlgBossSettings;

	STRING m_accountName;
	int m_playerIndex;

	CTabCtrl *m_pTab;


private:
	

private:
	CBossConfig *m_pBossConfig;
	CBrush m_brush;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedChkBossSettingsSelAll();
	afx_msg void OnClose();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnTcnSelchangeTabBossSetings(NMHDR *pNMHDR, LRESULT *pResult);
};
