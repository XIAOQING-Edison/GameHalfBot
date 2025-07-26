// GameBotDlg.h : ͷ�ļ�
//

#pragma once

#define WM_CLICK_TRAY (WM_USER+403)

#include "Msg.h"
#include "player.h"
#include "./Struct/AccountInfo.h"	//update account
#include "./Dlgs/Log/DlgShowLog.h"
#include "./Dlgs/Loading/DlgLoading.h"

#include "./Util/ShareMemory.h"

#include "Server.h"

typedef HRESULT(WINAPI* PFNDIIGetClass0bject) (REFCLSID rclsid, REFIID riid, LPVOID* ppv);

#include <iostream>
#include <Windows.h>
#include "hyperlink.h"

#define ID_HOT_KEY1	4001
#define ID_HOT_KEY2	4002
//��ͨ�ַ�ת��Ϊ bstr
#define ST(x)  CComBSTR(x)

class CInjector;	//ע����
// CGongShaBotDlg �Ի���
class CGameBotDlg : public CDialog
{
// ����
public:
	CGameBotDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GAMEBOT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	void InitCtrls();

	void InitListCtrl();	//��ʼ��listctrl

	void InitCombo();	//��ʼ��infoType

	void ShowChangeMap(int id);

	void SetTestBtnVisible(bool b);

	virtual void OnOK(){};
	virtual void OnCancel(){};

	void ResizeWindow(int cx,int cy);	//�ѿ��ߵ���һ��

	void SetInit(bool b){m_bInit=b;}
	bool IsInit(){return m_bInit;}
	
	void InitPlayers();	//��ʼ���ʺŵĽ�ɫ,���Ե�½
	void ClearPlayers();	//ɾ����ǰ���ʺ���Ϣ

	CPlayer *GetPlayerById(int index);	//ȡ�������Ϣ

	void ChangeToBasicTheme();

	void ChangeDisplaySolution(int width,int height);

	void RegisterGlobalHotKey();	//ע��ȫ���ȼ�
public:
	void RegisterGlobalHotKeyInternal(bool bStart);	//ע��ȫ���ȼ�
	

	//test
	void ReadGameConfigFileToList();	//��ȡINI����ֶε�LISTCTRL

	void TryToRepairConfigInInit();	//��ʼ��ʱ�����޸��ļ�,��Ҫ�Ǳ������ļ�û���¼���

	void TestWrite();

	void TestAttachProcess();
private:
	CRichEditCtrl *m_pRichEdt;
	CEdit *m_pEdtUserName;
	CEdit *m_pEdtUserPass;
	CComboBox *m_pCbGameVersion;

	//for test
	CEdit *m_pEdtTalkMessage;
	CListCtrl *m_pListCtrlInfo;
	CComboBox *m_pCbInjectType;

	vector<CPlayer*> m_playerList;
	map<DWORD,DWORD> m_attachProcessMap;

	void UpdateAccountInfoToList(CAccountInfo *pInfo);	//
	void AddAccountInfoToList(CAccountInfo *pInfo);
	void DeleteAccountInfoFromList(int index);

	void UpdateRoleInfoToList(int index,CClient *pClient);	//���½�ɫ��Ϣ,ְҵ�ȼ�֮��
	void UpdatePlayerConnectInfo(int index,CClient *pClient);	//���½�ɫ������Ϣ

	void OnMinimize();	//��С��������
	void DeleteTray();	//ɾ������

	void WriteLogMsg(_GAME_LOG_MSG_ *pMsg);

	void UpdateCurrentOperation(int index,CClient *pClient);	//
	
	void SendOperation(_OPERATION_MSG_ *pOperate);	//����wm_copy

	void InitHelperObjects();	//ʵʼ����ͼ���󣬴��͵���󣬵�λ������Ʒ������б�
	void ClearHelperObjects();	//�ͷ���Դ
private:
	
	CDlgShowLog m_dlgShowLog;
	CDlgLoading m_dlgLoading;
	NOTIFYICONDATA m_notifyData;	//��������

	CShareMemory *m_pSharedMemory;

	CServer m_server;

	STRING m_dllPath;
	bool m_bInit;
	HWND m_hWndTest;	//���Է�����Ϣ

	void InitToolObjects();	//������
	void DeleteToolObjects();	//
private:	//ĳЩ������
	CInjector *m_pInjector;	//��ǰѡ���ע����
	vector<CInjector*> m_injectorArray;	//ע����
// ʵ��
protected:
	HICON m_hIcon;
	CHyperLink m_hyperLink1;	//����

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	LRESULT OnHandleSelfMessage(WPARAM wParam,LPARAM lParam);
	afx_msg void OnClose();
	afx_msg void OnBnClickedBtnLogin();
	afx_msg void OnBnClickedBtnTalkTest();
	afx_msg void OnBnClickedBtnLoginGameServ();
	afx_msg void OnCbnSelchangeCbInfoType();
	afx_msg void OnLvnItemchangedListInfo(NMHDR *pNMHDR, LRESULT *pResult);


	afx_msg void OnListPopupMenu(UINT nId);
	afx_msg void OnNMRClickListInfo(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg LRESULT OnClickTray(WPARAM wParam,LPARAM IParam);
	afx_msg void OnBnClickedBtnPlayAll();
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedBtnRepairCfgFile();
	afx_msg void OnNMClickListInfo(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnConnect();
	afx_msg void OnBnClickedBtnTestMisc();
	afx_msg void OnBnClickedBtnClickMe();
	afx_msg void OnCbnSelchangeCbGameVersion();
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);//��ݼ���Ӧ
	afx_msg void OnCbnSelchangeCbInjectType();
	afx_msg void OnBnClickedBtnAccerlateSetting();
};
