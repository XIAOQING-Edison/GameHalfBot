#pragma once


#include "../../resource.h"

#include "../../Config/GameConfig.h"

#include "DlgSystemSettings.h"
#include "DlgGiftHallSettings.h"
#include "DlgSkillSetting.h"

// CDlgOtherSetting �Ի���
class CPlayer;
class CDlgOtherSetting : public CDialog
{
	DECLARE_DYNAMIC(CDlgOtherSetting)

public:
	CDlgOtherSetting(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgOtherSetting();

// �Ի�������
	enum { IDD = IDD_DLG_OTHER_SETTING };

	virtual void OnOK(){}
	virtual void OnCancel(){}

public:
	void SetAccountName(STRING &acc){m_accountName=acc;}
	void InitCtrls();
	void InitTab();
	void InitChildDlgs();

	void DestroyAllChildDlgs();


	void ReadIniToCtrls();	//��ini���ȡֵ�����Ӵ���
	void SaveCtrlsToIni();	//�Ӵ��ڸ��Ա���ֵ��ini

	void SetIndex(int i){m_index=i;}
	int GetIndex(){return m_index;}

	void SetPlayerSkillList(vector<int> &skills){m_dlgSkillSetting.SetPlayerSkillList(skills);}

private:
	CDialog *m_pDlg[5];	//��dlgָ�뷽�����,����Ϊ�����������ٸ���


	CDlgSystemSettings m_dlgSystemSettings;
	CDlgGiftHallSettings m_dlgGiftHallSettings;
	CDlgSkillSetting m_dlgSkillSetting;	//�����趨
	STRING m_accountName;
	int m_index;

	CPlayer *m_pPlayer;

	CTabCtrl *m_pTab;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnTcnSelchangeTabOtherSetting(NMHDR *pNMHDR, LRESULT *pResult);
};
