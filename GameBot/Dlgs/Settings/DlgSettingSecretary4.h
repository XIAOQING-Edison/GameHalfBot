#pragma once

#include "../../resource.h"
#include "../../Config/ConfigSecretary4.h"

// CDlgSettingSecret4 对话框

class CDlgSettingSecretary4 : public CDialog
{
	DECLARE_DYNAMIC(CDlgSettingSecretary4)

public:
	CDlgSettingSecretary4(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgSettingSecretary4();

// 对话框数据
	enum { IDD = IDD_DLG_SETTING_SECRETARY4 };




	void SetConfigObject(CConfigSecretary4 *p){m_pSecretary4Config=p;}


	void SetConfigObjectAndReadToCtrls(CConfigSecretary4 *p){SetConfigObject(p);ReadIniToCtrls();}
	void SetConfigObjectAndSaveCtrlsToIni(CConfigSecretary4 *p){SetConfigObject(p);SaveCtrlsToIni();}
	void InitCtrls();

	void ReadIniToCtrls();
	void SaveCtrlsToIni();

	void CheckAll(bool bSelect);

	void InitBtns();

	CBrush m_brush;


	virtual void OnOK(){}
	virtual void OnCancel(){}

private:
	CButton *m_pChk[12];
	CButton *m_pChkAll;
private:
	CButton *m_pChkBlackMarsh;
	CComboBox *m_pCbBlackMarshAttr;
	CComboBox *m_pCbBlackMarshMonsterLevel;
	CEdit *m_pEdtBlackMarshChallengeCount;
	CEdit *m_pEdtBlackMarshHour;
	CEdit *m_pEdtBlackMarshMinute;
	CButton *m_pChkBlackMarshAutoBuyTicketWhenNotEnough;


	CButton *m_pChkPetIsland;
	CEdit *m_pEdtPetIslandChallegeCount;
	CComboBox *m_pCbPetIslandCatchMode;
	CButton *m_pChkPetIslandAutoBuyTicketWhenNotEnough;

	CButton *m_pChkFairLand;
	CEdit *m_pEdtFairLandChallegeCount;
	CButton *m_pChkFairLandAutoBuyTicketWhenNotEnough;

	CButton *m_pChkAsuramBountyTask;
	CButton *m_pChkAsuramItemDonate;


	CButton *m_pChkAsuramShopNereus;
	CButton *m_pChkAsuramShopGemStoneTicket;
	CButton *m_pChkAsuramShopFairLandTicket;
	CButton *m_pChkAsuramShopLostMap;

private:
	CConfigSecretary4 *m_pSecretary4Config;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

};
