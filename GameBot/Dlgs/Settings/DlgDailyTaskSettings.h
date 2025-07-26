#pragma once

#include "../../Config/DailyTaskConfig.h"
#include "../../resource.h"
// CDlgDailyTaskSettings 对话框
class CPlayer;
class CDlgSettingSecretary1 : public CDialog
{
	DECLARE_DYNAMIC(CDlgSettingSecretary1)

public:
	CDlgSettingSecretary1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgSettingSecretary1();

// 对话框数据
	enum { IDD = IDD_DLG_SETTING_SECRETARY1 };

	void SetConfigObject(CConfigSecretary1 *p){m_pSecretary1Config=p;}

	void SetConfigObjectAndReadToCtrls(CConfigSecretary1 *p){SetConfigObject(p);ReadIniToCtrls();}
	void SetConfigObjectAndSaveCtrlsToIni(CConfigSecretary1 *p){SetConfigObject(p);SaveCtrlsToIni();}

	void InitCtrls();

	void InitCombo();	//主要是初始化地图类型和地图列表

	void ReadIniToCtrls();
	void SaveCtrlsToIni();

	void CheckAll(bool bSelect);

	void InitBtns();

	void InitMapList(int mapSelType,CComboBox *pCombo);
	void SetPlayer(CPlayer *player){m_pPlayer=player;}
	virtual void OnOK(){}
	virtual void OnCancel(){}
private:	//用于选择时间段
	CPlayer *m_pPlayer;
private:
	CButton *m_pChk[13];
	CButton *m_pChkAll;
private:
	CButton *m_pChkAutoHungUp;
	CComboBox *m_pCbMapType;

	CEdit *m_pEdtAutoHungUPPointY;	
	CEdit *m_pEdtAutoHungUpPointX;
	CButton *m_pChkIsUsingSelfSkillsWhenSeeOtherPlayer;
	CButton *m_pChkIsAutoCounterStrikeOtherPlayer;
	CButton *m_pChkIsAutoCounterStrikeOtherPlayerUsingConfigSkills;

	CComboBox *m_pCbMaps;	//地图id
	CComboBox *m_pCbPkMode;	//挂机的pk模式
	CStatic *m_pStaticPkMode;	//pkmode静态
private:
	CConfigSecretary1 *m_pSecretary1Config;
	CBrush m_brush;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedChkDailyTaskSelAll();
	afx_msg void OnCbnSelchangeCbArenaMultiCount();
	afx_msg void OnBnClickedBtnReadCurRoleCoor();
};
