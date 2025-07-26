#pragma once

#include "../../Config/LocalCorpsBossConfig.h"
#include "../../resource.h"

// CDlgCrossBossSettings 对话框

class CDlgLocalCorpsBossSetting : public CDialog
{
	DECLARE_DYNAMIC(CDlgLocalCorpsBossSetting)

public:
	CDlgLocalCorpsBossSetting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgLocalCorpsBossSetting();

// 对话框数据
	enum { IDD = IDD_DLG_LOCAL_CORPS_BOSS };

	void SetConfigObject(CLocalCorpsBossConfig *p){m_pLocalCorpsBossConfig=p;}

	void SetConfigObjectAndReadToCtrls(CLocalCorpsBossConfig *p){SetConfigObject(p);ReadIniToCtrls();}
	void SetConfigObjectAndSaveCtrlsToIni(CLocalCorpsBossConfig *p){SetConfigObject(p);SaveCtrlsToIni();}

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
	CButton *m_pChkCrossBossSeleted;
	CListBox *m_pLstAllBoss;
	CListBox *m_pLstSelectedBoss;
	CEdit *m_pEdtBossMaxTimeout;
	CComboBox *m_pCbBossKillMode;
private:
	CLocalCorpsBossConfig *m_pLocalCorpsBossConfig;
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
