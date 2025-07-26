#pragma once

#include "../../resource.h"
#include "../../Config/GameConfig.h"
// CDlgSkillSetting 对话框
class CPlayer;
class CDlgSkillSetting : public CDialog
{
	DECLARE_DYNAMIC(CDlgSkillSetting)

public:
	CDlgSkillSetting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgSkillSetting();

	void SetConfigObject(CSkillConfig *p){m_pSkillConfig=p;}
	void SetConfigObjectAndReadToCtrls(CSkillConfig *p){SetConfigObject(p);ReadIniToCtrls();}
	void SetConfigObjectAndSaveCtrlsToIni(CSkillConfig *p){SetConfigObject(p);SaveCtrlsToIni();}

	void InitCtrls();

	void ReadIniToCtrls();
	void SaveCtrlsToIni();

	void InitListBox();
	void InitComboBox();
	void ClearListBoxShow(CListBox *pListBox);

	int GetInsertIndexInList(int orgIndex,CListBox *pList);

	void SetCareer(int career){m_career=career;}
	void SetAccountName(STRING &acc){m_accountName=acc;}

	void SetPlayerSkillList(vector<int>& skillList){m_playerSkillList=skillList;}

	void SetPlayerPointer(CPlayer *player){m_pPlyaer=player;}//为了方便取得数据
// 对话框数据
	enum { IDD = IDD_DLG_SKILL_SETTINGS };
private:
	CListBox *m_pListSkillAll;
	CListBox *m_pListSkillSelected;
	CEdit *m_pEdtSendInterval;
	CEdit *m_pEdtTargetX;
	CEdit *m_pEdtTargetY;
	CComboBox *m_pCbListJobSel;
	CSkillConfig *m_pSkillConfig;
	vector<int> m_playerSkillList;
private:
	int m_career;	//玩家生涯职业
	STRING m_accountName;	//帐户
	CPlayer *m_pPlyaer;	//玩家数据
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnDel();
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnCbnSelchangeCbSkillJob();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnSelExist();
};
