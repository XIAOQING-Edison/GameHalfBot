#pragma once

#include "../../Config/BotConfig.h"
#include "../../resource.h"
// CDlgBotSetttings 对话框

class CDlgSettingSecretary2 : public CDialog
{
	DECLARE_DYNAMIC(CDlgSettingSecretary2)

public:
	CDlgSettingSecretary2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgSettingSecretary2();

// 对话框数据
	enum { IDD = IDD_DLG_SETTING_SECRETARY2};

	void SetConfigObject(CConfigSecretary2 *p){m_pSecretary2Config=p;}

	void SetConfigObjectAndReadToCtrls(CConfigSecretary2 *p){SetConfigObject(p);ReadIniToCtrls();}
	void SetConfigObjectAndSaveCtrlsToIni(CConfigSecretary2 *p){SetConfigObject(p);SaveCtrlsToIni();}

	void ReadIniToCtrls();
	void SaveCtrlsToIni();

	void InitCtrls();



	void CheckAll(bool bSelect);

	void InitBtns();


	virtual void OnOK(){}
	virtual void OnCancel(){}
private:
	CButton *m_pChk[15];
	CButton *m_pChkAll;
private:
	CButton *m_pChkDemonPlaza;
	CButton *m_pChkDemonPlazaBuyTicketWhenNotEnough;
	CButton *m_pChkDemonPlazaAutoComposeTicket;	//自动合成门票

	CEdit *m_pEdtDemonPlazaHungUpPointX;
	CEdit *m_pEdtDemonPlazaHungUpPointY;


	void InitListBox();
	int GetInsertIndexInList(int orgIndex,CListBox *pList);

	CListBox *m_pListSkillAll;
	CListBox *m_pListSkillSelected;
	vector<int> m_demonPlazaTimeSelectedList;	//已选择时间段的下标
private:
	CConfigSecretary2 *m_pSecretary2Config;
	CBrush m_brush;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedChkBotSettingsSelAll();
	afx_msg void OnBnClickedBtnDel();
	afx_msg void OnBnClickedBtnAdd();
};
