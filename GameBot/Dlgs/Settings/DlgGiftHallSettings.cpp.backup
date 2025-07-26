// ./Dlgs/Settings/DlgGiftHallSettings.cpp : 实现文件
//

#include "../../StdAfx.h"
// #include "GameBot.h"
#include "DlgGiftHallSettings.h"


// CDlgGiftHallSettings 对话框

IMPLEMENT_DYNAMIC(CDlgGiftHallSettings, CDialog)

CDlgGiftHallSettings::CDlgGiftHallSettings(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgGiftHallSettings::IDD, pParent)
{

}

CDlgGiftHallSettings::~CDlgGiftHallSettings()
{
}

void CDlgGiftHallSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgGiftHallSettings, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CHK_GIFT_HALL_SEL_ALL, &CDlgGiftHallSettings::OnBnClickedChkGiftHallSelAll)
END_MESSAGE_MAP()


// CDlgGiftHallSettings 消息处理程序

BOOL CDlgGiftHallSettings::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_brush.CreateSolidBrush(RGB(255,255,255));//while brush
	InitCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

HBRUSH CDlgGiftHallSettings::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	hbr=(HBRUSH)m_brush;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

void CDlgGiftHallSettings::InitCtrls()
{
	m_pChkAutoSignIn=(CButton*)GetDlgItem(IDC_CHK_SIGN_IN);
	m_pChkAutoTreasureHole=(CButton*)GetDlgItem(IDC_CHK_TREASURE_HOLE);
	m_pChkAutoGetOnlineReward=(CButton*)GetDlgItem(IDC_CHK_ONLINE_REWARD);
	m_pChkAutoGetOfflineExp=(CButton*)GetDlgItem(IDC_CHK_OFFLINE_EXP);
	m_pChkAutoComposeTicket=(CButton*)GetDlgItem(IDC_CHK_AUTO_COMPOSE_TICKET);
	m_pChkAutoRecycleEquipment=(CButton*)GetDlgItem(IDC_CHK_AUTO_RECYCYLE);

	m_pChkAutoSendGetVipMemberInfo=(CButton*)GetDlgItem(IDC_CHK_ACCUMULATE_SIGN_REWARD);//定时发送会员
	m_pChkAutoGetActivityReward=(CButton*)GetDlgItem(IDC_CHK_ACTIVITY_REWARD);;	//活跃度领奖

	m_pChkAutoUpdateMagicNuclear=(CButton*)GetDlgItem(IDC_CHK_AUTO_UPDATE_MAGIC_NUCLEAR);;	//魔核充能

	m_pChkAutoReadMail=(CButton*)GetDlgItem(IDC_CHK_AUTO_READ_MAIL);;
	m_pChkAutoDeleteMailWhenRead=(CButton*)GetDlgItem(IDC_CHK_AUTO_DELETE_READ_MAIL);;	//删除已读邮件

	m_pCbRecycleEquipmentStar=(CComboBox*)GetDlgItem(IDC_CB_STAR);
	m_pCbRecycleEquipmentStepLv=(CComboBox*)GetDlgItem(IDC_CB_STEP_LV);

	m_pChkAll=(CButton*)GetDlgItem(IDC_CHK_GIFT_HALL_SEL_ALL);

	m_pCbGetOfflineExpType=(CComboBox*)GetDlgItem(IDC_CB_GET_OFFLINE_EXP_TYPE);

	InitBtns();
}


void CDlgGiftHallSettings::ReadIniToCtrls()
{
	m_pChkAutoSignIn->SetCheck(m_pGiftHallConfig->IsAutoSignInFromCfg());
#if _GAME_VERSION_ == _YONG_HENG_LIAN_MENG_
	m_pChkAutoSendGetVipMemberInfo->SetCheck(m_pGiftHallConfig->IsAutoSendGetVipMemberInfoFromCfg());
#else
	m_pChkAutoSendGetVipMemberInfo->ShowWindow(SW_HIDE);
	m_pChkAutoSendGetVipMemberInfo->SetCheck(false);
#endif
	m_pChkAutoTreasureHole->SetCheck(m_pGiftHallConfig->IsAutoTreasureHoleFromCfg());
	m_pChkAutoGetOnlineReward->SetCheck(m_pGiftHallConfig->IsAutoOnlineRewardFromCfg());
	m_pChkAutoGetOfflineExp->SetCheck(m_pGiftHallConfig->IsAutoOfflineExpFromCfg());

	m_pChkAutoComposeTicket->SetCheck(m_pGiftHallConfig->IsAutoComposeTicketFromCfg());

	m_pChkAutoReadMail->SetCheck(m_pGiftHallConfig->IsAutoReadMailFromCfg());
	m_pChkAutoDeleteMailWhenRead->SetCheck(m_pGiftHallConfig->IsAutoDeleteReadMailFromCfg());

	m_pChkAutoGetActivityReward->SetCheck(m_pGiftHallConfig->IsAutoActivityGetRewardFromCfg());

	m_pChkAutoUpdateMagicNuclear->SetCheck(m_pGiftHallConfig->IsAutoUpdateMagicNuclearFromCfg());

	m_pChkAutoRecycleEquipment->SetCheck(m_pGiftHallConfig->IsAutoRecycleEquipmentFromCfg());

	m_pCbRecycleEquipmentStar->SetCurSel(m_pGiftHallConfig->GetRecycleEquipmentStarFromCfg());
	m_pCbRecycleEquipmentStepLv->SetCurSel(m_pGiftHallConfig->GetRecycleEquipmentStepLvFromCfg());

	int type=m_pGiftHallConfig->GetOfflineExpTypeFromCfg();
	m_pCbGetOfflineExpType->SetCurSel(type);



}


void CDlgGiftHallSettings::SaveCtrlsToIni()
{
	m_pGiftHallConfig->SetAutoSignInToCfg(m_pChkAutoSignIn->GetCheck());
	m_pGiftHallConfig->SetAutoTreasureHoleToCfg(m_pChkAutoTreasureHole->GetCheck());
	m_pGiftHallConfig->SetAutoOnlineRewardToCfg(m_pChkAutoGetOnlineReward->GetCheck());
	m_pGiftHallConfig->SetAutoOfflineExpToCfg(m_pChkAutoGetOfflineExp->GetCheck());	

	m_pGiftHallConfig->SetIsAutoSendGetVipMemberInfoToCfg(m_pChkAutoSendGetVipMemberInfo->GetCheck());	//定时发送获取会员
	m_pGiftHallConfig->SetIsAutoAcitivityGetRewardToCfg(m_pChkAutoGetActivityReward->GetCheck());

	m_pGiftHallConfig->SetIsAutoReadMailToCfg(m_pChkAutoReadMail->GetCheck());
	m_pGiftHallConfig->SetIsAutoDeleteReadMailToCfg(m_pChkAutoDeleteMailWhenRead->GetCheck());

	m_pGiftHallConfig->SetIsAutoUpdateMagicNuclearToCfg(m_pChkAutoUpdateMagicNuclear->GetCheck());

	m_pGiftHallConfig->SetAutoComposeTickeToCfg(m_pChkAutoComposeTicket->GetCheck());

	m_pGiftHallConfig->SetRecycleEquipmentStarToCfg(m_pCbRecycleEquipmentStar->GetCurSel());
	m_pGiftHallConfig->SetRecycleEquipmentStepLvToCfg(m_pCbRecycleEquipmentStepLv->GetCurSel());

	m_pGiftHallConfig->SetAutoRecycleEquipmentToCfg(m_pChkAutoRecycleEquipment->GetCheck());

	int sel=m_pCbGetOfflineExpType->GetCurSel();
	m_pGiftHallConfig->SetOfflineExpTypeToCfg(sel);
}



void CDlgGiftHallSettings::InitBtns()
{
	int i=0;

	m_pChk[i++]=m_pChkAutoSignIn;
	m_pChk[i++]=m_pChkAutoTreasureHole;

	m_pChk[i++]=m_pChkAutoGetOnlineReward;	
	m_pChk[i++]=m_pChkAutoGetOfflineExp;
	m_pChk[i++]=m_pChkAutoComposeTicket;

	m_pChk[i++]=m_pChkAutoRecycleEquipment;
	
}



void CDlgGiftHallSettings::CheckAll(bool bSelect)
{
	for(int i=0;i<6;++i)
	{
		m_pChk[i]->SetCheck(bSelect);
	}
}

void CDlgGiftHallSettings::OnBnClickedChkGiftHallSelAll()
{
	// TODO: 在此添加控件通知处理程序代码
	CheckAll(m_pChkAll->GetCheck());
}
