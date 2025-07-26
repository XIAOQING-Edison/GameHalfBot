#pragma once

#include "../../Config/BeastBossConfig.h"
#include "../../resource.h"

// CDlgBeastBossSettings 对话框

class CDlgBeastBossSetting : public CDialog
{
	DECLARE_DYNAMIC(CDlgBeastBossSetting)

public:
	CDlgBeastBossSetting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgBeastBossSetting();

// 对话框数据
	enum { IDD = IDD_DLG_CROSS_BOSS };

	void SetConfigObject(CBeastBossConfig *p){m_pBeastBossConfig=p;}

	void SetConfigObjectAndReadToCtrls(CBeastBossConfig *p){SetConfigObject(p);ReadIniToCtrls();}
	void SetConfigObjectAndSaveCtrlsToIni(CBeastBossConfig *p){SetConfigObject(p);SaveCtrlsToIni();}

	void InitCtrls();

	void ReadIniToCtrls();
	void SaveCtrlsToIni();

	void InitListBox();

	int GetInsertIndexInList(int orgIndex,CListBox *pList);

	virtual void OnOK(){}
	virtual void OnCancel(){}

	void SetPlayerIndex(int index){m_playerIndex=index;}
private:
	int m_playerIndex;
private:
	CButton *m_pChkBeastBossSeleted;
	CListBox *m_pLstAllBoss;
	CListBox *m_pLstSelectedBoss;
	CEdit *m_pEdtBossMaxTimeout;
private:
	CBeastBossConfig *m_pBeastBossConfig;
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
