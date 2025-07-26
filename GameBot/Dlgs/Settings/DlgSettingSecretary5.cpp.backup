// ./Dlgs/Settings/DlgSettingSecretary5.cpp : 实现文件
//

#include "../../stdafx.h"
#include "../../GameBot.h"
#include "DlgSettingSecretary5.h"


// CDlgSettingSecretary5 对话框

IMPLEMENT_DYNAMIC(CDlgSettingSecretary5, CDialog)

CDlgSettingSecretary5::CDlgSettingSecretary5(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSettingSecretary5::IDD, pParent)
{

}

CDlgSettingSecretary5::~CDlgSettingSecretary5()
{
}

void CDlgSettingSecretary5::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgSettingSecretary5, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CDlgSettingSecretary5 消息处理程序
BOOL CDlgSettingSecretary5::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_brush.CreateSolidBrush(RGB(255,255,255));//while brush
	InitCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


HBRUSH CDlgSettingSecretary5::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	hbr=(HBRUSH)m_brush;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}




void CDlgSettingSecretary5::InitCtrls()
{
	m_pChkExchangeEquipSandToGlory=(CButton*)GetDlgItem(IDC_CHK_AUTO_EXCHANGE_GLORY);
	m_pEdtExchangeEquipSandToGloryCount=(CEdit*)GetDlgItem(IDC_EDT_EQUIP_SAND_TO_GLORY_COUNT);

	m_pChkSpaceCorridor=(CButton*)GetDlgItem(IDC_CHK_SPACE_CORRIDOR);
	m_pEdtSpaceCorridorBuyExtraCount=(CEdit*)GetDlgItem(IDC_EDT_SPACE_CORRIDOR_EXTRA_COUNT);

	m_pChkDemonStrongHold=(CButton*)GetDlgItem(IDC_CHK_DEMON_STRONGHOLD);
	m_pChkDemonStrongHoldGetTreasureBox=(CButton*)GetDlgItem(IDC_CHK_DEMON_STRONGHOLD_GET_TREASURE_BOX);

	m_pChkAsuramLeagueBoss=(CButton*)GetDlgItem(IDC_CHK_ASURAM_LEAGUE_BOSS);
	m_pEdtAsuramLeagueBossBuyExtraTimes=(CEdit*)GetDlgItem(IDC_EDT_ASURAM_LEAGUE_BOSS_EXTRA_COUNT);
	m_pChkAutoShareAsuramLeagueMonster=(CButton*)GetDlgItem(IDC_CHK_AUTO_SHARE_ASURAM_LEAGUE_MONSTER_CHALLENGE);
	m_pChkAsuramLeagueAutoExchangeTreasure=(CButton*)GetDlgItem(IDC_CHK_ASURAM_LEAGUE_AUTO_EXCHANGE_TREASURE);

	m_pChkAutoMerceneryDispath=(CButton*)GetDlgItem(IDC_CHK_AUTO_MERCENERY_DISPATH);
	m_pChkContinueMerceneryDispathWhenNoUnits=(CButton*)GetDlgItem(IDC_CHK_CONTINUE_DISPATH_WHEN_NO_UNITS);
	m_pCbMerceneryDispathStarLevel=(CComboBox*)GetDlgItem(IDC_CB_MERCENERY_DISPATH_STAR_LEVEL);
	m_pChkAutoMeceneryTask=(CButton*)GetDlgItem(IDC_CHK_AUTO_MERCENERY_TASK);
	m_pChkAutoBuyHandCemecery=(CButton*)GetDlgItem(IDC_CHK_AUTO_BUY_HAND_CEMECERY);	//手礼
}



void CDlgSettingSecretary5::ReadIniToCtrls()
{
	CString str;
	m_pChkExchangeEquipSandToGlory->SetCheck(m_pSecrectary5Config->IsAutoExchangeEquipSandToGloryFromCfg());

	str.Format(_T("%d"),m_pSecrectary5Config->GetExchangeEquipSandCountFromCfg());
	m_pEdtExchangeEquipSandToGloryCount->SetWindowText(str);

	m_pChkSpaceCorridor->SetCheck(m_pSecrectary5Config->IsSpaceCorridorSelectedFromCfg());
	
	str.Format(_T("%d"),m_pSecrectary5Config->GetSpaceCorridorBuyExtraTimesFromCfg());
	m_pEdtSpaceCorridorBuyExtraCount->SetWindowText(str);

	m_pChkDemonStrongHold->SetCheck(m_pSecrectary5Config->IsDemonStrongHoldSelectedFromCfg());
	m_pChkDemonStrongHoldGetTreasureBox->SetCheck(m_pSecrectary5Config->IsAsuramLeagueBossAutoExchangeTreasureFromCfg());

	m_pChkAsuramLeagueBoss->SetCheck(m_pSecrectary5Config->IsAsuramLeagueBossSelectedFromCfg());
	
	str.Format(_T("%d"),m_pSecrectary5Config->GetAsuramLeagueBossBuyExtraTimesFromCfg());
	m_pEdtAsuramLeagueBossBuyExtraTimes->SetWindowText(str);

	m_pChkAutoShareAsuramLeagueMonster->SetCheck(m_pSecrectary5Config->IsAsuramLeagueBossAutoShareMonsterChallengeFromCfg());
	m_pChkAsuramLeagueAutoExchangeTreasure->SetCheck(m_pSecrectary5Config->IsAsuramLeagueBossAutoExchangeTreasureFromCfg());

	m_pChkAutoMerceneryDispath->SetCheck(m_pSecrectary5Config->IsAutoMeceneryDispathSelectedFromCfg());
	m_pChkContinueMerceneryDispathWhenNoUnits->SetCheck(m_pSecrectary5Config->IsMeceneryDispathContinueWhenNoUnitsFromCfg());


	m_pCbMerceneryDispathStarLevel->SetCurSel(m_pSecrectary5Config->GetMeceneryDispathStarLevelFromCfg());
	m_pChkAutoMeceneryTask->SetCheck(m_pSecrectary5Config->IsMeceneryDispathAutoDoTaskFromCfg());
	m_pChkAutoBuyHandCemecery->SetCheck(m_pSecrectary5Config->IsMeceneryDispathAutoBuyHandCemeceryFromCfg());	//手礼

}


void CDlgSettingSecretary5::SaveCtrlsToIni()
{
	CString str;
	m_pSecrectary5Config->SetIsAutoExchangeEquipSandToGloryToCfg(m_pChkExchangeEquipSandToGlory->GetCheck());
	
	m_pEdtExchangeEquipSandToGloryCount->GetWindowText(str);
	m_pSecrectary5Config->SetExchangeEquipSandCountToCfg(_ttoi(str));

	m_pSecrectary5Config->SetIsSpaceCorridorSelectedToCfg(m_pChkSpaceCorridor->GetCheck());
	
	m_pEdtSpaceCorridorBuyExtraCount->GetWindowText(str);
	m_pSecrectary5Config->SetSpaceCorridorBuyExtraTimesToCfg(_ttoi(str));

	m_pSecrectary5Config->SetIsDemonStrongHoldSelectedToCfg(m_pChkDemonStrongHold->GetCheck());
	m_pSecrectary5Config->SetIsDemonStrongHoldOneKeyGetTreasureToCfg(m_pChkDemonStrongHoldGetTreasureBox->GetCheck());

	m_pSecrectary5Config->SetIsAsuramLeagueBossSelectedToCfg(m_pChkAsuramLeagueBoss->GetCheck());
	
	m_pEdtAsuramLeagueBossBuyExtraTimes->GetWindowText(str);
	m_pSecrectary5Config->SetAsuramLeagueBossBuyExtraTimesToCfg(_ttoi(str));
	
	m_pSecrectary5Config->SetIsAsuramLeagueBossAutoShareMonsterChallengeToCfg(m_pChkAutoShareAsuramLeagueMonster->GetCheck());
	m_pSecrectary5Config->SetIsAsuramLeagueBossAutoExchangeTreasureToCfg(m_pChkAsuramLeagueAutoExchangeTreasure->GetCheck());

	m_pSecrectary5Config->SetIsAutoMeceneryDispathSelectedToCfg(m_pChkAutoMerceneryDispath->GetCheck());
	m_pSecrectary5Config->SetIsMeceneryDispathContinueWhenNoUnitsToCfg(m_pChkContinueMerceneryDispathWhenNoUnits->GetCheck());
	
	m_pSecrectary5Config->SetMeceneryDispathStarLevelToCfg(m_pCbMerceneryDispathStarLevel->GetCurSel());
	m_pSecrectary5Config->SetIsMeceneryDispathAutoDoTaskToCfg(m_pChkAutoMeceneryTask->GetCheck());
	m_pSecrectary5Config->SetIsMeceneryDispathAutoBuyHandCemeceryToCfg(m_pChkAutoBuyHandCemecery->GetCheck());	//手礼
}



void CDlgSettingSecretary5::CheckAll(bool bSelect)
{
	
}



void CDlgSettingSecretary5::InitBtns()
{

}

