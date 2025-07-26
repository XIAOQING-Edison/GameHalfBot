#pragma once

#include "../../Config/WorldBossConfig.h"
#include "../../resource.h"
// CDlgDailyTaskSettings 对话框

class CDlgWorldBossSetting : public CDialog
{
	DECLARE_DYNAMIC(CDlgWorldBossSetting)

public:
	CDlgWorldBossSetting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgWorldBossSetting();

// 对话框数据
	enum { IDD = IDD_DLG_WORLD_BOSS };

	void SetConfigObject(CWorldBossConfig *p){m_pWorldBossConfig=p;}

	void SetConfigObjectAndReadToCtrls(CWorldBossConfig *p){SetConfigObject(p);ReadIniToCtrls();}
	void SetConfigObjectAndSaveCtrlsToIni(CWorldBossConfig *p){SetConfigObject(p);SaveCtrlsToIni();}

	void InitCtrls();

	void ReadIniToCtrls();
	void SaveCtrlsToIni();

	void CheckAll(bool bSelect);

	int GetInsertIndexInList(int orgIndex,CListBox *pList);

	void InitListBox();

	virtual void OnOK(){}
	virtual void OnCancel(){}

	void SetPlayerIndex(int index){m_playerIndex=index;}
private:
	int m_playerIndex;
private:
	CButton *m_pChkWorldBossSeleted;
	CListBox *m_pLstAllBoss;
	CListBox *m_pLstSelectedBoss;
	CEdit *m_pEdtBossMaxTimeout;
	CComboBox *m_pCbBossKillMode;
private:
	CWorldBossConfig *m_pWorldBossConfig;
	CBrush m_brush;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedChkDailyTaskSelAll();
	afx_msg void OnBnClickedBtnSelect();
	afx_msg void OnBnClickedBtnUnselect();
};
