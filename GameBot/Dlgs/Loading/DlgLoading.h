#pragma once


// CDlgLoading �Ի���
#include "../../resource.h"

class CDlgLoading : public CDialog
{
	DECLARE_DYNAMIC(CDlgLoading)

public:
	CDlgLoading(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgLoading();

// �Ի�������
	enum { IDD = IDD_DLG_LOADING };

	void PlayAnimation();	//��ʾ����
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
