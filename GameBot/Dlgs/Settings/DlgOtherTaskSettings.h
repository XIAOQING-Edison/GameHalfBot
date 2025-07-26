#pragma once


#include "../../Config/BossAssistConfig.h"
#include "../../resource.h"
// CDlgOtherTaskSettings 对话框

class CDlgBossAssistSettings : public CDialog
{
	DECLARE_DYNAMIC(CDlgBossAssistSettings)

public:
	CDlgBossAssistSettings(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgBossAssistSettings();

// 对话框数据
	enum { IDD = IDD_DLG_ASSIST_SETTINGS };

	void SetConfigObject(CBossAssistConfig *p){m_pBossAssistConfig=p;}

	void SetConfigObjectAndReadToCtrls(CBossAssistConfig *p){SetConfigObject(p);ReadIniToCtrls();}
	void SetConfigObjectAndSaveCtrlsToIni(CBossAssistConfig *p){SetConfigObject(p);SaveCtrlsToIni();}

	void InitCtrls();

	void ReadIniToCtrls();
	void SaveCtrlsToIni();

	void CheckAll(bool bSelect);

	void InitBtns();


	virtual void OnOK(){}
	virtual void OnCancel(){}

	void SetPlayerIndex(int index){m_playerIndex=index;}
private:
	int m_playerIndex;

private:
	CButton *m_pChk[14];
	CButton *m_pChkAll;
private:
	CEdit *m_pEdtBeastBossAssistMaxTimeout;	//协助最长时间
	CButton *m_pChkBeastBossAutoAssistOther;	//协助他人
	CButton *m_pChkBeastBossAutoSendAssist;	//击杀时发送协助
	CButton *m_pChkBeastBossAssistAutoSendAssist;//协助时发送协助
	CButton *m_pChkBeastBossOnlyAssistSelfMaxCount;	//只协助本身最大次数

	CEdit *m_pEdtCorpsBossAssistMaxTimout;//协助最长时间
	CButton *m_pChkCorpsBossAutoAssistOther;//协助他人
	CButton *m_pChkCorpsBossAusoSendAssist;//击杀时发送协助
	CButton *m_pChkCorpsBossAssistAutoSendAssist;//协助时发送协助
	CButton *m_pChkCorpsBossOnlyAssistSelfMaxCount;//只协助本身最大次数
// 
// 	CButton *m_pChkSpaceCorridor;	//时光回廊
// 	CButton *m_pChkSpecialSpace;
// 	CButton *m_pChkFastFight;
// 	CButton *m_pChkCampWar;	//冰渊战场
// 	CButton *m_pChkCertificate;	//天使战令
// 	CButton *m_pChkPinkDiamond;	//粉钻
// 	CButton *m_pChkHorcrux;	//魂器
// 	CButton *m_pChkOriginalSin;	//原罪xxxx
// 	CButton *m_pChkFairyLand;	//幻境
// 	CEdit	*m_pEdtFairyLandCount;
// 	CButton *m_pChkOrcGodBless;	//兽神祈愿
private:
	CBossAssistConfig *m_pBossAssistConfig;
	CBrush m_brush;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedChkOtherTaskSelAll();
};
