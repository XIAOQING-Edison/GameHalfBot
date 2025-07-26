#pragma once

#include "../../Global/public.h"
#include "../../resource.h"

struct PROCESS_INFO
{
	DWORD pid;
	CString szExeName;
	CString szDescription;
	CString szPath;
};

// CDlgProcessList 对话框

class CDlgProcessList : public CDialog
{
	DECLARE_DYNAMIC(CDlgProcessList)

public:
	CDlgProcessList(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgProcessList();

// 对话框数据
	enum { IDD = IDD_DLG_PROCESS_LIST };
public:
	void GetAllProcessList();
	void InitCtrls();
	void InitListHeader();
	PROCESS_INFO	GetSelectProceeInfo();
	virtual void OnOK(){}
	virtual void OnCancel(){}
	int GetSelectPid(){return m_pidSelect;}
	void SetShowEmuOnly(bool b){m_bShowEmuOnly=b;}
	vector<PROCESS_INFO>& GetAllProcessInfos(){return m_processList;}
private:
	bool IsProcNeedToBeShown(PROCESS_INFO &info);
	void InitFilterMap();
private:
	vector<PROCESS_INFO>	m_processList;
	CListCtrl *m_pList;
	int m_pidSelect;
	bool m_bShowEmuOnly;
	map<CString,CString> m_filterStringMap;	//用来过滤
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnRefresh();
	afx_msg void OnBnClickedBtnSel();
};
