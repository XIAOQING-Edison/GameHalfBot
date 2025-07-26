// ./Dlgs/Settings/DlgSettingSecretary4.cpp : 实现文件
//

#include "../../stdafx.h"
#include "../../GameBot.h"
#include "DlgSettingSecretary4.h"


// CDlgSettingSecretary4 对话框

IMPLEMENT_DYNAMIC(CDlgSettingSecretary4, CDialog)

CDlgSettingSecretary4::CDlgSettingSecretary4(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSettingSecretary4::IDD, pParent)
{

}

CDlgSettingSecretary4::~CDlgSettingSecretary4()
{
}

void CDlgSettingSecretary4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgSettingSecretary4, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CDlgSettingSecretary4 消息处理程序


BOOL CDlgSettingSecretary4::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_brush.CreateSolidBrush(RGB(255,255,255));//while brush
	InitCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


HBRUSH CDlgSettingSecretary4::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	hbr=(HBRUSH)m_brush;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}





void CDlgSettingSecretary4::InitCtrls()
{
	m_pChkBlackMarsh=(CButton*)GetDlgItem(IDC_CHK_BLACK_MARSH);
	m_pCbBlackMarshAttr=(CComboBox*)GetDlgItem(IDC_CB_BLACK_MARSH_ATTR);
	m_pCbBlackMarshMonsterLevel=(CComboBox*)GetDlgItem(IDC_CB_BLACK_MARSH_MONSTER_LEVEL);
	m_pEdtBlackMarshChallengeCount=(CEdit*)GetDlgItem(IDC_EDT_BLACK_MARSH_CHALLENGE_COUNT);
	m_pEdtBlackMarshHour=(CEdit*)GetDlgItem(IDC_EDT_BLACK_MARSH_HOUR);
	m_pEdtBlackMarshMinute=(CEdit*)GetDlgItem(IDC_EDT_BLACK_MARSH_MINUTE);
	m_pChkBlackMarshAutoBuyTicketWhenNotEnough=(CButton*)GetDlgItem(IDC_CHK_BLACK_MARSH_AUTO_BUY_TICKET_WHEN_NOT_ENOUGH);


	m_pChkPetIsland=(CButton*)GetDlgItem(IDC_CHK_PET_ISLAND);
	m_pEdtPetIslandChallegeCount=(CEdit*)GetDlgItem(IDC_EDT_PET_ISLAND_COUNT);
	m_pCbPetIslandCatchMode=(CComboBox*)GetDlgItem(IDC_CB_PET_ISLAND_MODE);
	m_pChkPetIslandAutoBuyTicketWhenNotEnough=(CButton*)GetDlgItem(IDC_CHK_PET_ISLAND_BUY_TICKET_WHEN_NOT_ENOUGH);

	m_pChkFairLand=(CButton*)GetDlgItem(IDC_CHK_FAIRY_LAND);
	m_pEdtFairLandChallegeCount=(CEdit*)GetDlgItem(IDC_EDT_FAIRY_LAND_COUNT);
	m_pChkFairLandAutoBuyTicketWhenNotEnough=(CButton*)GetDlgItem(IDC_CHK_FAIR_LAND_BUY_TICKET_WHEN_NOT_ENOUGH);

	m_pChkAsuramBountyTask=(CButton*)GetDlgItem(IDC_CHK_ASURAM_BOUNTY_TASK);
	m_pChkAsuramItemDonate=(CButton*)GetDlgItem(IDC_CHK_ASURAM_ITEM_DONATE);


	m_pChkAsuramShopNereus=(CButton*)GetDlgItem(IDC_CHK_ASURAM_SHOP_NEREUS);
	m_pChkAsuramShopGemStoneTicket=(CButton*)GetDlgItem(IDC_CHK_ASURAM_SHOP_GEMSTONES_TICKET);
	m_pChkAsuramShopFairLandTicket=(CButton*)GetDlgItem(IDC_CHK_ASURAM_SHOP_FAIRYLAND_TICKET);
	m_pChkAsuramShopLostMap=(CButton*)GetDlgItem(IDC_CHK_ASURAM_SHOP_LOST_MAP);


	int limit=2;
}


void CDlgSettingSecretary4::ReadIniToCtrls()
{
	CString str;

	m_pChkBlackMarsh->SetCheck(m_pSecretary4Config->IsBlackMarshSelectedFromCfg());
	m_pCbBlackMarshAttr->SetCurSel(m_pSecretary4Config->GetBlackMarshAttrFromCfg());
	
	m_pCbBlackMarshMonsterLevel->SetCurSel(m_pSecretary4Config->GetBlackMarshMonsterLevelFromCfg());


	str.Format(_T("%d"),m_pSecretary4Config->GetBlackMarshChallengeTimesFromCfg());
	m_pEdtBlackMarshChallengeCount->SetWindowText(str);

	str.Format(_T("%d"),m_pSecretary4Config->GetBlackMarshHourFromCfg());
	m_pEdtBlackMarshHour->SetWindowText(str);
	
	str.Format(_T("%d"),m_pSecretary4Config->GetBlackMarshMinuteFromCfg());
	m_pEdtBlackMarshMinute->SetWindowText(str);

	m_pChkBlackMarshAutoBuyTicketWhenNotEnough->SetCheck(m_pSecretary4Config->IsBlackMarshBuyTicketWhenNotEnoughFromCfg());


	m_pChkPetIsland->SetCheck(m_pSecretary4Config->IsPetIslandSelectedFromCfg());
	
	str.Format(_T("%d"),m_pSecretary4Config->GetPetIslandChallengeCountFromCfg());
	m_pEdtPetIslandChallegeCount->SetWindowText(str);

	m_pCbPetIslandCatchMode->SetCurSel(m_pSecretary4Config->GetPetIslandCatchModeFromCfg());
	m_pChkPetIslandAutoBuyTicketWhenNotEnough->SetCheck(m_pSecretary4Config->IsPetIslandBuyTicketWhenNotEnough());

	m_pChkFairLand->SetCheck(m_pSecretary4Config->IsFairLandSelectedFromCfg());
	
	str.Format(_T("%d"),m_pSecretary4Config->GetFairLandChallengeCountFromCfg());
	m_pEdtFairLandChallegeCount->SetWindowText(str);

	m_pChkFairLandAutoBuyTicketWhenNotEnough->SetCheck(m_pSecretary4Config->IsFairLandBuyTicketWhenNotEnoughFromCfg());

	m_pChkAsuramBountyTask->SetCheck(m_pSecretary4Config->IsAsuramBountyTaskSelectedFromCfg());
	m_pChkAsuramItemDonate->SetCheck(m_pSecretary4Config->IsAsuramItemDonateFromCfg());


	m_pChkAsuramShopNereus->SetCheck(m_pSecretary4Config->IsAsuramShopNereusSelectedFromCfg());
	m_pChkAsuramShopGemStoneTicket->SetCheck(m_pSecretary4Config->IsAsuramShopGemStoneTicketSelectedFromCfg());
	m_pChkAsuramShopFairLandTicket->SetCheck(m_pSecretary4Config->IsAsuramShopFairlandTicketSelectedFromCfg());
	m_pChkAsuramShopLostMap->SetCheck(m_pSecretary4Config->IsAsuramShopLostMapSelectedFromCfg());

	
}


void CDlgSettingSecretary4::SaveCtrlsToIni()
{
	CString str;

	m_pSecretary4Config->SetIsBlackMarshSelectedToCfg(m_pChkBlackMarsh->GetCheck());
	m_pSecretary4Config->SetBlackMarshAttrToCfg(m_pCbBlackMarshAttr->GetCurSel());
	
	m_pSecretary4Config->SetBlackMarshMonsterLevelToCfg(m_pCbBlackMarshMonsterLevel->GetCurSel());

	m_pEdtBlackMarshChallengeCount->GetWindowText(str);
	m_pSecretary4Config->SetBlackMarshChallengeTimesToCfg(_ttoi(str));
	
	m_pEdtBlackMarshHour->GetWindowText(str);
	m_pSecretary4Config->SetBlackMarshHourToCfg(_ttoi(str));
	
	m_pEdtBlackMarshMinute->GetWindowText(str);
	m_pSecretary4Config->SetBlackMarshMinuteToCfg(_ttoi(str));

	m_pSecretary4Config->SetIsBlackMarshBuyTicketWhenNotEnoughToCfg(m_pChkBlackMarshAutoBuyTicketWhenNotEnough->GetCheck());


	m_pSecretary4Config->SetIsPetIslandSelectedToCfg(m_pChkPetIsland->GetCheck());
	
	m_pEdtPetIslandChallegeCount->GetWindowText(str);
	m_pSecretary4Config->SetPetIslandChallengeCountToCfg(_ttoi(str));

	m_pSecretary4Config->SetPetIslandCatchModeToCfg(m_pCbPetIslandCatchMode->GetCurSel());
	m_pSecretary4Config->SetIsPetIslandBuyTicketWhenNotEnough(m_pChkPetIslandAutoBuyTicketWhenNotEnough->GetCheck());

	m_pSecretary4Config->SetIsFairLandSelectedToCfg(m_pChkFairLand->GetCheck());
	
	m_pEdtFairLandChallegeCount->GetWindowText(str);
	m_pSecretary4Config->SetFairLandChallengeCountToCfg(_ttoi(str));

	m_pSecretary4Config->SetIsFairLandBuyTicketWhenNotEnoughToCfg(m_pChkFairLandAutoBuyTicketWhenNotEnough->GetCheck());

	m_pSecretary4Config->SetIsAsuramBountyTaskSelectedToCfg(m_pChkAsuramBountyTask->GetCheck());
	m_pSecretary4Config->SetIsAsuramItemDonateToCfg(m_pChkAsuramItemDonate->GetCheck());


	m_pSecretary4Config->SetIsAsuramShopNereusSelectedToCfg(m_pChkAsuramShopNereus->GetCheck());
	m_pSecretary4Config->SetisAsuramShopGemStoneTicketSelectedToCfg(m_pChkAsuramShopGemStoneTicket->GetCheck());
	m_pSecretary4Config->SetIsAsuramShopFairlandTicketSelectedToCfg(m_pChkAsuramShopFairLandTicket->GetCheck());
	m_pSecretary4Config->SetIsAsuramShhopLostMapSelectedToCfg(m_pChkAsuramShopLostMap->GetCheck());

}	


void CDlgSettingSecretary4::InitBtns()
{
	int i=0;

	m_pChk[i++]=m_pChkBlackMarsh;
	m_pChk[i++]=m_pChkBlackMarshAutoBuyTicketWhenNotEnough;


	m_pChk[i++]=m_pChkPetIsland;
	m_pChk[i++]=m_pChkPetIslandAutoBuyTicketWhenNotEnough;

	m_pChk[i++]=m_pChkFairLand;
	m_pChk[i++]=m_pChkFairLandAutoBuyTicketWhenNotEnough;

	m_pChk[i++]=m_pChkAsuramBountyTask;
	m_pChk[i++]=m_pChkAsuramItemDonate;


	m_pChk[i++]=m_pChkAsuramShopNereus;
	m_pChk[i++]=m_pChkAsuramShopGemStoneTicket;
	m_pChk[i++]=m_pChkAsuramShopFairLandTicket;
	m_pChk[i++]=m_pChkAsuramShopLostMap;

}



// void CDlgSettingSecretary4::CheckAll(bool bSelect)
// {
// 	for(int i=0;i<13;++i)
// 	{
// 		m_pChk[i]->SetCheck(bSelect);
// 	}
// }
// 
// 
// void CDlgSettingSecretary4::OnBnClickedChkDailyTaskSelAll()
// {
// 	// TODO: 在此添加控件通知处理程序代码
// 	CheckAll(m_pChkAll->GetCheck());
// }
