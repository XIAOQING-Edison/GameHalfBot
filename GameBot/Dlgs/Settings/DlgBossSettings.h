#pragma once

#include "../../Config/BossConfig.h"
#include "DlgNeutralBossSetting.h"
#include "DlgWorldBossSetting.h"
#include "DlgCrossBossSettings.h"
#include "DlgLocalCorpsBossSettings.h"
#include "DlgCrossCorpsBossSettings.h"
#include "DlgBeastBossSettings.h"
#include "DlgOtherTaskSettings.h"	//��ΪЭ������
#include "../../resource.h"
// CDlgBossSettings �Ի���

class CDlgBossSettings : public CDialog
{
	DECLARE_DYNAMIC(CDlgBossSettings)

public:
	CDlgBossSettings(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgBossSettings();

// �Ի�������
	enum { IDD = IDD_DLG_BOSS_SETTTINGS };

	void SetConfigObject(CBossConfig *p){m_pBossConfig=p;}

	void SetConfigObjectAndReadToCtrls(CBossConfig *p){SetConfigObject(p);ReadIniToCtrls();}
	void SetConfigObjectAndSaveCtrlsToIni(CBossConfig *p){SetConfigObject(p);SaveCtrlsToIni();}

	void InitCtrls();

	void ReadIniToCtrls();	//��ini���ȡֵ�����Ӵ���
	void SaveCtrlsToIni();	//�Ӵ��ڸ��Ա���ֵ��ini

	virtual void OnOK(){}
	virtual void OnCancel(){}
	void SetAccountName(STRING &acc){m_accountName=acc;}
	void SetPlayerIndex(int idx){m_playerIndex=idx;}
private:
	void InitTab();
	void InitChildDlgs();

	void DestroyAllChildDlgs();
	void AddDlgsToTab();
private:
	CDialog *m_pDlg[7];	//��dlgָ�뷽�����,����Ϊ�����������ٸ���
	CTabCtrl *m_pTabCtrl;
	CDlgNeutralBossSetting m_dlgNeutralBossSettings;
	CDlgWorldBossSetting m_dlgWorldBossSettings;
	CDlgCrossBossSetting m_dlgCrossBossSettings;
	CDlgLocalCorpsBossSetting m_dlgLocalCorpsBossSettings;
	CDlgCrossCorpsBossSetting m_dlgCrossCorpsBossSettings;
	CDlgBeastBossSetting m_dlgBeastBossSettings;
	CDlgBossAssistSettings m_dlgBossAssistSettings;
// 	CDlgBossSettings m_dlgBossSettings;

	STRING m_accountName;
	int m_playerIndex;

	CTabCtrl *m_pTab;


private:
	

private:
	CBossConfig *m_pBossConfig;
	CBrush m_brush;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedChkBossSettingsSelAll();
	afx_msg void OnClose();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnTcnSelchangeTabBossSetings(NMHDR *pNMHDR, LRESULT *pResult);
};
