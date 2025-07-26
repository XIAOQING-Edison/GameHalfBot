#pragma once


#include "../../resource.h"

#include "../../Config/GameConfig.h"

#include "DlgSystemSettings.h"
#include "DlgGiftHallSettings.h"
#include "DlgSkillSetting.h"

// CDlgOtherSetting 对话框
class CPlayer;
class CDlgOtherSetting : public CDialog
{
	DECLARE_DYNAMIC(CDlgOtherSetting)

public:
	CDlgOtherSetting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgOtherSetting();

// 对话框数据
	enum { IDD = IDD_DLG_OTHER_SETTING };

	virtual void OnOK(){}
	virtual void OnCancel(){}

public:
	void SetAccountName(STRING &acc){m_accountName=acc;}
	void InitCtrls();
	void InitTab();
	void InitChildDlgs();

	void DestroyAllChildDlgs();


	void ReadIniToCtrls();	//从ini里读取值到各子窗口
	void SaveCtrlsToIni();	//子窗口各自保存值到ini

	void SetIndex(int i){m_index=i;}
	int GetIndex(){return m_index;}

	void SetPlayerSkillList(vector<int> &skills){m_dlgSkillSetting.SetPlayerSkillList(skills);}

private:
	CDialog *m_pDlg[5];	//放dlg指针方便操作,先设为常量，后面再更改


	CDlgSystemSettings m_dlgSystemSettings;
	CDlgGiftHallSettings m_dlgGiftHallSettings;
	CDlgSkillSetting m_dlgSkillSetting;	//技能设定
	STRING m_accountName;
	int m_index;

	CPlayer *m_pPlayer;

	CTabCtrl *m_pTab;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnTcnSelchangeTabOtherSetting(NMHDR *pNMHDR, LRESULT *pResult);
};
