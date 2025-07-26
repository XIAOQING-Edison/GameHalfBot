#pragma once



#include "../../Config/GameConfig.h"
#include "../../resource.h"
// CDlgSettings �Ի���

enum E_SETTING_MODE	
{
	e_setting_mode_add_or_modify_user=0,	//ֻ�޸��û�
	e_setting_mode_other_task	//�޸�������������
};

extern const int g_tabCount;

#include "DlgBotSetttings.h"
#include "DlgDailyTaskSettings.h"
#include "DlgAsuramSettings.h"
#include "DlgSettingSecretary4.h"
#include "DlgSettingSecretary5.h"

class CPlayer;
class CDlgSecretarySettings : public CDialog
{
	DECLARE_DYNAMIC(CDlgSecretarySettings)

public:
	CDlgSecretarySettings(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgSecretarySettings();

// �Ի�������
	enum { IDD = IDD_DLG_SECRETARY_SETTINGS };


public:
	CTabCtrl *m_pTab;

	void InitCtrls();

	void AddDlgsToTab();

	void InitChildDlgs();

	void DestroyAllChildDlgs();

	void SetAddUser(bool b){m_bAdd=b;}
	bool IsAddUser(){return m_bAdd;}

	void SetAccountName(STRING &name){m_accountName=name;}
	STRING GetAccountName(){return m_accountName;}


	void ReadIniToCtrls();	//��ini���ȡֵ�����Ӵ���
	void SaveCtrlsToIni();	//�Ӵ��ڸ��Ա���ֵ��ini



	virtual void OnOK(){}
	virtual void OnCancel(){}

	void SendMsgToMainWin(WPARAM wParam,LPARAM lParam);
	
	void SetMainHwnd(HWND hwnd){m_hwndMain=hwnd;}
	HWND GetMainHwnd(){return m_hwndMain;}

	void SetIndex(int i){m_index=i;}
	int GetIndex(){return m_index;}
	void SetPlayerPointer(CPlayer *player);
private:
	CDialog *m_pDlg[5];	//��dlgָ�뷽�����,����Ϊ�����������ٸ���
	
	CDlgSettingSecretary1 m_dlgSecretary1Settings;
	CDlgSettingSecretary2 m_dlgSecretary2Settings;
	CDlgSettingSecretary3 m_dlgSecretary3Settings;
	CDlgSettingSecretary4 m_dlgSecretary4Settings;
	CDlgSettingSecretary5 m_dlgSecretary5Settings;
	

private:
	bool m_bAdd;	//�Ƿ�������û�
	STRING m_accountName;
	HWND m_hwndMain;	//������
	int m_index;	//�б��±�
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTabSettings(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
