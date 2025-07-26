#pragma once

#include "../../Config/GiftHallConfig.h"
#include "../../resource.h"
// CDlgGiftHallSettings 对话框

class CDlgGiftHallSettings : public CDialog
{
	DECLARE_DYNAMIC(CDlgGiftHallSettings)

public:
	CDlgGiftHallSettings(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgGiftHallSettings();

// 对话框数据
	enum { IDD = IDD_DLG_GIFT_HALL_SETTINGS };

	void SetConfigObject(CGiftHallConfig *p){m_pGiftHallConfig=p;}

	void SetConfigObjectAndReadToCtrls(CGiftHallConfig *p){SetConfigObject(p);ReadIniToCtrls();}
	void SetConfigObjectAndSaveCtrlsToIni(CGiftHallConfig *p){SetConfigObject(p);SaveCtrlsToIni();}

	void InitCtrls();

	void ReadIniToCtrls();
	void SaveCtrlsToIni();

	void CheckAll(bool bSelect);

	void InitBtns();


	virtual void OnOK(){}
	virtual void OnCancel(){}
private:
	CButton *m_pChk[5];
	CButton *m_pChkAll;

private:
	CGiftHallConfig *m_pGiftHallConfig;
	CBrush m_brush;

	CButton *m_pChkAutoSignIn;
	CButton *m_pChkAutoTreasureHole;
	CButton *m_pChkAutoGetOnlineReward;
	CButton *m_pChkAutoGetOfflineExp;

	CButton *m_pChkAutoSendGetVipMemberInfo;	//是否定时发送获取会员消息
	CButton *m_pChkAutoGetActivityReward;	//活跃度领奖

	CButton *m_pChkAutoUpdateMagicNuclear;	//魔核充能

	CButton *m_pChkAutoReadMail;
	CButton *m_pChkAutoDeleteMailWhenRead;	//删除已读邮件



	CButton *m_pChkAutoComposeTicket;
	CButton *m_pChkAutoRecycleEquipment;

	CComboBox *m_pCbRecycleEquipmentStar;
	CComboBox *m_pCbRecycleEquipmentStepLv;

	CComboBox *m_pCbGetOfflineExpType;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedChkGiftHallSelAll();
};
