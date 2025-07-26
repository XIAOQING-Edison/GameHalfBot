#pragma once

#include "../../Config/DailyTaskConfig.h"
#include "../../resource.h"
// CDlgAsuramSettings 对话框

class CDlgSettingSecretary3 : public CDialog
{
	DECLARE_DYNAMIC(CDlgSettingSecretary3)

public:
	CDlgSettingSecretary3(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgSettingSecretary3();

// 对话框数据
	enum { IDD = IDD_DLG_SETTING_SECRETARY3 };

	void SetConfigObject(CConfigSecretary1 *p){m_pSecretary1Config=p;}

	void SetConfigObjectAndReadToCtrls(CConfigSecretary1 *p){SetConfigObject(p);ReadIniToCtrls();}
	void SetConfigObjectAndSaveCtrlsToIni(CConfigSecretary1 *p){SetConfigObject(p);SaveCtrlsToIni();}

	void InitCtrls();

	void ReadIniToCtrls();
	void SaveCtrlsToIni();

	void CheckAll(bool bSelect);

	void InitBtns();

	void InitListBox();
	int GetInsertIndexInList(int orgIndex,CListBox *pList);

	virtual void OnOK(){}
	virtual void OnCancel(){}
private:
	CButton *m_pChk[15];
	CButton *m_pChkAll;

	CListBox *m_pListSkillAll;
	CListBox *m_pListSkillSelected;
	vector<int> m_bloodCastleTimeSelectedList;	//已选择时间段的下标

private:
	CEdit *m_pEdtBloodCastleAutoHungUpPointX;
	CEdit *m_pEdtBloodCastleAutoHungUPPointY;	

	CButton *m_pChkBloodTown;

	CButton *m_pChkBloodTownAutoComposeTicket;	//


private:
	CConfigSecretary1 *m_pSecretary1Config;
	CBrush m_brush;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedChkAsuramSettingsSelAll();
	afx_msg void OnBnClickedBtnDel();
	afx_msg void OnBnClickedBtnAdd();
};
