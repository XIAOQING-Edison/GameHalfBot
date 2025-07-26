#pragma once


// CDlgLoading 对话框
#include "../../resource.h"

class CDlgLoading : public CDialog
{
	DECLARE_DYNAMIC(CDlgLoading)

public:
	CDlgLoading(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgLoading();

// 对话框数据
	enum { IDD = IDD_DLG_LOADING };

	void PlayAnimation();	//显示动画
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
