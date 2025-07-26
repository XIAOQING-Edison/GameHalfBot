// GameBotDlg.h : 头锟侥硷拷
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
//锟斤拷通锟街凤拷转锟斤拷为 bstr
#define ST(x)  CComBSTR(x)

class CInjector;	//注锟斤拷锟斤拷
// CGongShaBotDlg 锟皆伙拷锟斤拷
class CGameBotDlg : public CDialog
{
// 锟斤拷锟斤拷
public:
	CGameBotDlg(CWnd* pParent = NULL);	// 锟斤拷准锟斤拷锟届函锟斤拷

// 锟皆伙拷锟斤拷锟斤拷锟斤拷
	enum { IDD = IDD_GAMEBOT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支锟斤拷

	void InitCtrls();

	void InitListCtrl();	//锟斤拷始锟斤拷listctrl

	void InitCombo();	//锟斤拷始锟斤拷infoType

	void ShowChangeMap(int id);

	void SetTestBtnVisible(bool b);

	virtual void OnOK(){};
	virtual void OnCancel(){};

	void ResizeWindow(int cx,int cy);	//锟窖匡拷锟竭碉拷锟斤拷一锟斤拷

	void SetInit(bool b){m_bInit=b;}
	bool IsInit(){return m_bInit;}
	
	void InitPlayers();	//锟斤拷始锟斤拷锟绞号的斤拷色,锟斤拷锟皆碉拷陆
	void ClearPlayers();	//删锟斤拷锟斤拷前锟斤拷锟绞猴拷锟斤拷息

	CPlayer *GetPlayerById(int index);	//取锟斤拷锟斤拷锟斤拷锟较

	void ChangeToBasicTheme();

	void ChangeDisplaySolution(int width,int height);

	void RegisterGlobalHotKey();	//注锟斤拷全锟斤拷锟饺硷拷
public:
	void RegisterGlobalHotKeyInternal(bool bStart);	//注锟斤拷全锟斤拷锟饺硷拷
	

	//test
	void ReadGameConfigFileToList();	//锟斤拷取INI锟斤拷锟斤拷侄蔚锟絃ISTCTRL

	void TryToRepairConfigInInit();	//锟斤拷始锟斤拷时锟斤拷锟斤拷锟睫革拷锟侥硷拷,锟斤拷要锟角憋拷锟斤拷锟斤拷锟侥硷拷没锟斤拷锟铰硷拷锟斤拷

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

	void UpdateRoleInfoToList(int index,CClient *pClient);	//锟斤拷锟铰斤拷色锟斤拷息,职业锟饺硷拷之锟斤拷
	void UpdatePlayerConnectInfo(int index,CClient *pClient);	//锟斤拷锟铰斤拷色锟斤拷锟斤拷锟斤拷息

	void OnMinimize();	//锟斤拷小锟斤拷锟斤拷锟斤拷锟斤拷
	void DeleteTray();	//删锟斤拷锟斤拷锟斤拷

	void WriteLogMsg(_GAME_LOG_MSG_ *pMsg);

	void UpdateCurrentOperation(int index,CClient *pClient);	//
	
	void SendOperation(_OPERATION_MSG_ *pOperate);	//锟斤拷锟斤拷wm_copy

	void InitHelperObjects();	//实始锟斤拷锟斤拷图锟斤拷锟襟，达拷锟酵碉拷锟斤拷螅碉拷位锟斤拷锟斤拷锟斤拷品锟斤拷锟斤拷锟斤拷斜锟
	void ClearHelperObjects();	//锟酵凤拷锟斤拷源
private:
	
	CDlgShowLog m_dlgShowLog;
	CDlgLoading m_dlgLoading;
	NOTIFYICONDATA m_notifyData;	//锟斤拷锟斤拷锟斤拷锟斤拷

	CShareMemory *m_pSharedMemory;

	CServer m_server;

	STRING m_dllPath;
	bool m_bInit;
	HWND m_hWndTest;	//锟斤拷锟皆凤拷锟斤拷锟斤拷息

	void InitToolObjects();	//锟斤拷锟斤拷锟斤拷
	void DeleteToolObjects();	//
private:	//某些锟斤拷锟斤拷锟斤拷
	CInjector *m_pInjector;	//锟斤拷前选锟斤拷锟阶锟斤拷锟斤拷
	vector<CInjector*> m_injectorArray;	//注锟斤拷锟斤拷
// 实锟斤拷
protected:
	HICON m_hIcon;
	CHyperLink m_hyperLink1;	//锟斤拷锟斤拷

	// 锟斤拷锟缴碉拷锟斤拷息映锟戒函锟斤拷
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
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);//锟斤拷菁锟斤拷锟接
	afx_msg void OnCbnSelchangeCbInjectType();
	afx_msg void OnBnClickedBtnAccerlateSetting();
};
