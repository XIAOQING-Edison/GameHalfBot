#pragma once

#include "../../Config/GiftHallConfig.h"
#include "../../resource.h"
// CDlgGiftHallSettings �Ի���

class CDlgGiftHallSettings : public CDialog
{
	DECLARE_DYNAMIC(CDlgGiftHallSettings)

public:
	CDlgGiftHallSettings(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgGiftHallSettings();

// �Ի�������
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

	CButton *m_pChkAutoSendGetVipMemberInfo;	//�Ƿ�ʱ���ͻ�ȡ��Ա��Ϣ
	CButton *m_pChkAutoGetActivityReward;	//��Ծ���콱

	CButton *m_pChkAutoUpdateMagicNuclear;	//ħ�˳���

	CButton *m_pChkAutoReadMail;
	CButton *m_pChkAutoDeleteMailWhenRead;	//ɾ���Ѷ��ʼ�



	CButton *m_pChkAutoComposeTicket;
	CButton *m_pChkAutoRecycleEquipment;

	CComboBox *m_pCbRecycleEquipmentStar;
	CComboBox *m_pCbRecycleEquipmentStepLv;

	CComboBox *m_pCbGetOfflineExpType;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedChkGiftHallSelAll();
};
