#pragma once

#include "../../resource.h"
#include "../../Config/ConfigSecretary5.h"
// CDlgSecretary5 对话框

class CDlgSettingSecretary5 : public CDialog
{
	DECLARE_DYNAMIC(CDlgSettingSecretary5)

public:
	CDlgSettingSecretary5(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgSettingSecretary5();

// 对话框数据
	enum { IDD = IDD_DLG_SETTING_SECRETARY5 };

	void SetConfigObject(CConfigSecretary5 *p){m_pSecrectary5Config=p;}


	void SetConfigObjectAndReadToCtrls(CConfigSecretary5 *p){SetConfigObject(p);ReadIniToCtrls();}
	void SetConfigObjectAndSaveCtrlsToIni(CConfigSecretary5 *p){SetConfigObject(p);SaveCtrlsToIni();}



	void InitCtrls();

	void ReadIniToCtrls();
	void SaveCtrlsToIni();

	void CheckAll(bool bSelect);

	void InitBtns();

	CBrush m_brush;


	virtual void OnOK(){}
	virtual void OnCancel(){}

private:
	CButton *m_pChk[11];
	CButton *m_pChkAll;
private:

	CButton *m_pChkExchangeEquipSandToGlory;
	CEdit *m_pEdtExchangeEquipSandToGloryCount;

	CButton *m_pChkSpaceCorridor;
	CEdit *m_pEdtSpaceCorridorBuyExtraCount;

	CButton *m_pChkDemonStrongHold;
	CButton *m_pChkDemonStrongHoldGetTreasureBox;

	CButton *m_pChkAsuramLeagueBoss;
	CEdit *m_pEdtAsuramLeagueBossBuyExtraTimes;
	CButton *m_pChkAutoShareAsuramLeagueMonster;
	CButton *m_pChkAsuramLeagueAutoExchangeTreasure;

	CButton *m_pChkAutoMerceneryDispath;
	CButton *m_pChkContinueMerceneryDispathWhenNoUnits;
	CComboBox *m_pCbMerceneryDispathStarLevel;
	CButton *m_pChkAutoMeceneryTask;
	CButton *m_pChkAutoBuyHandCemecery;	//手礼

private:
	CConfigSecretary5 *m_pSecrectary5Config;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

};
