#pragma once

#include "../../Config/NeutralBossConfig.h"
#include "../../resource.h"
// CDlgDailyTaskSettings 对话框

class CDlgNeutralBossSetting : public CDialog
{
	DECLARE_DYNAMIC(CDlgNeutralBossSetting)

public:
	CDlgNeutralBossSetting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgNeutralBossSetting();

// 对话框数据
	enum { IDD = IDD_DLG_NEUTRAL_BOSS };

	void SetConfigObject(CNeutralBossConfig *p){m_pNeutralBossConfig=p;}

	void SetConfigObjectAndReadToCtrls(CNeutralBossConfig *p){SetConfigObject(p);ReadIniToCtrls();}
	void SetConfigObjectAndSaveCtrlsToIni(CNeutralBossConfig *p){SetConfigObject(p);SaveCtrlsToIni();}

	void InitCtrls();

	void ReadIniToCtrls();
	void SaveCtrlsToIni();
	
	CComboBox *m_pCbSelectMaps[10];	//选择的地图combo
	void InitCombo();

	void InitListBox();
	void InitListCtrl();
	void InitBossPointByConfigId(int configId);

	int GetInsertIndexInList(int orgIndex,CListBox *pList);

	virtual void OnOK(){}
	virtual void OnCancel(){}

	void SetPlayerIndex(int index){m_playerIndex=index;}
private:
	int m_playerIndex;
private:
	CButton *m_pChkNeutralBossSeleted;
	CListBox *m_pLstAllBoss;
	CListBox *m_pLstSelectedBoss;
	CEdit *m_pEdtBossMaxTimeout;
	CComboBox *m_pCbBossKillMode;
	CListCtrl *m_pLstCtrlBossPoint;
private:
	CNeutralBossConfig *m_pNeutralBossConfig;
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
	afx_msg void OnLbnDblclkListNeutralBossSelect();
	afx_msg void OnNMDblclkLstBossPoint(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLbnSelchangeListNeutralBossSelect();
	afx_msg void OnCbnSelchangeCbBossMap1();
};
