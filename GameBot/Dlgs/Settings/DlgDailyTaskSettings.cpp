// ./Dlgs/Settings/DlgDailyTaskSettings.cpp : 实现文件
//

#include "../../StdAfx.h"
// #include "GameBot.h"
#include "DlgDailyTaskSettings.h"
#include "../../Misc/Misc.h"
#include "../../Player.h"
#include "../../Config/GameConfig.h"
const TCHAR *g_szMapType[]={_T("非会员"),_T("会员")};

// CDlgDailyTaskSettings 对话框
static int g_checkCount=0;
IMPLEMENT_DYNAMIC(CDlgSettingSecretary1, CDialog)

CDlgSettingSecretary1::CDlgSettingSecretary1(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSettingSecretary1::IDD, pParent)
{

}

CDlgSettingSecretary1::~CDlgSettingSecretary1()
{
}

void CDlgSettingSecretary1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgSettingSecretary1, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CHK_DAILY_TASK_SEL_ALL, &CDlgSettingSecretary1::OnBnClickedChkDailyTaskSelAll)
	ON_CBN_SELCHANGE(IDC_CB_ARENA_MULTI_COUNT, &CDlgSettingSecretary1::OnCbnSelchangeCbArenaMultiCount)
	ON_BN_CLICKED(IDC_BTN_READ_CUR_ROLE_COOR, &CDlgSettingSecretary1::OnBnClickedBtnReadCurRoleCoor)
END_MESSAGE_MAP()


// CDlgDailyTaskSettings 消息处理程序

BOOL CDlgSettingSecretary1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_brush.CreateSolidBrush(RGB(255,255,255));//while brush
	InitCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

HBRUSH CDlgSettingSecretary1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	hbr=(HBRUSH)m_brush;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CDlgSettingSecretary1::InitCtrls()
{
	m_pChkAutoHungUp=(CButton*)GetDlgItem(IDC_CHK_ARENA);	
	m_pEdtAutoHungUpPointX=(CEdit*)GetDlgItem(IDC_EDT_VIP_BOSS_EXTRA_TIME);
	m_pEdtAutoHungUPPointY=(CEdit*)GetDlgItem(IDC_EDT_ARENA_EXTRA_TIME);
	m_pCbMapType=(CComboBox*)GetDlgItem(IDC_CB_ARENA_MULTI_COUNT);
	m_pCbMaps=(CComboBox*)GetDlgItem(IDC_CB_BLOOD_TOWN_MULTI_CHALLENGE_COUNT);	//地图id

	m_pChkIsUsingSelfSkillsWhenSeeOtherPlayer=(CButton*)GetDlgItem(IDC_CHK_BLOODTOWN_BUY_WHEN_TICKET_GONE);
	m_pChkIsAutoCounterStrikeOtherPlayer=(CButton*)GetDlgItem(IDC_CHK_AUTO_COUNTER_STRIKE);

	m_pChkIsAutoCounterStrikeOtherPlayerUsingConfigSkills=(CButton*)GetDlgItem(IDC_CHK_USE_SKILL_CONFIG_WHEN_COUNTER_STRIKE);
	m_pCbPkMode=(CComboBox*)GetDlgItem(IDC_CB_PK_MODE);
	m_pStaticPkMode=(CStatic*)GetDlgItem(IDC_STATIC_PK_MODE);

	m_pChkAll=(CButton*)GetDlgItem(IDC_CHK_DAILY_TASK_SEL_ALL);



	int limit=3;
	m_pEdtAutoHungUPPointY->SetLimitText(limit);
	m_pEdtAutoHungUpPointX->SetLimitText(limit);


#ifdef _CAI_SHANG_VERSION_	//菜商版
	int cmd=SW_SHOW;
#else
	int cmd=SW_HIDE;
#endif
	m_pChkIsUsingSelfSkillsWhenSeeOtherPlayer->ShowWindow(cmd);
	m_pChkIsAutoCounterStrikeOtherPlayer->ShowWindow(cmd);
	m_pChkIsAutoCounterStrikeOtherPlayerUsingConfigSkills->ShowWindow(cmd);
	m_pCbPkMode->ShowWindow(cmd);
	m_pStaticPkMode->ShowWindow(cmd);
	InitBtns();
}


void CDlgSettingSecretary1::ReadIniToCtrls()
{
	CString str;
	
	m_pChkAutoHungUp->SetCheck(m_pSecretary1Config->IsAutoHungUpFromCfg());

	str.Format(_T("%d"),m_pSecretary1Config->GetAutoHungUpPointXFromCfg());
	m_pEdtAutoHungUpPointX->SetWindowText(str);

	str.Format(_T("%d"),m_pSecretary1Config->GetAutoHungUpPointYFromCfg());
	m_pEdtAutoHungUPPointY->SetWindowText(str);
	m_pChkIsUsingSelfSkillsWhenSeeOtherPlayer->SetCheck(m_pSecretary1Config->IsUseSelfSkillsWhenSeeOtherPlayerFromCfg());
	m_pChkIsAutoCounterStrikeOtherPlayer->SetCheck(m_pSecretary1Config->IsAutoCounterStrikeFromCfg());
	m_pChkIsAutoCounterStrikeOtherPlayerUsingConfigSkills->SetCheck(m_pSecretary1Config->IsAutoCounterStrikeUsingConfigSkillsFromCfg());
	m_pCbPkMode->SetCurSel(m_pSecretary1Config->GetPkModeFromCfg());
	InitCombo();

}


void CDlgSettingSecretary1::SaveCtrlsToIni()
{
	CString str;
	
	m_pSecretary1Config->SetIsAutoHungUpToCfg(m_pChkAutoHungUp->GetCheck());
	
	m_pEdtAutoHungUpPointX->GetWindowText(str);
	m_pSecretary1Config->SetAutoHungUpPointXToCfg(_ttoi(str));
	
	m_pEdtAutoHungUPPointY->GetWindowText(str);
	m_pSecretary1Config->SetAutoHungUpPointYToCfg(_ttoi(str));

	m_pSecretary1Config->SetHungUpMapTypeToCfg(m_pCbMapType->GetCurSel());
	m_pSecretary1Config->SetAutoHungUpMapIdToCfg(m_pCbMaps->GetCurSel());

	m_pSecretary1Config->SetIsUseSelfSkillsWhenSeeOtherPlayerToCfg(m_pChkIsUsingSelfSkillsWhenSeeOtherPlayer->GetCheck());
	m_pSecretary1Config->SetIsAutoCounterStrikeToCfg(m_pChkIsAutoCounterStrikeOtherPlayer->GetCheck());
	m_pSecretary1Config->SetIsAutoCounterStrikeUsingConfigSkillsToCfg(m_pChkIsAutoCounterStrikeOtherPlayerUsingConfigSkills->GetCheck());
	m_pSecretary1Config->SetPkModeToCfg(m_pCbPkMode->GetCurSel());
}


void CDlgSettingSecretary1::InitBtns()
{
	int i=0;

	m_pChk[i++]=m_pChkAutoHungUp;
	m_pChk[i++]=m_pChkIsUsingSelfSkillsWhenSeeOtherPlayer;


}



void CDlgSettingSecretary1::CheckAll(bool bSelect)
{
	for(int i=0;i<g_checkCount;++i)
	{
		m_pChk[i]->SetCheck(bSelect);
	}
}


void CDlgSettingSecretary1::OnBnClickedChkDailyTaskSelAll()
{
	// TODO: 在此添加控件通知处理程序代码
	CheckAll(m_pChkAll->GetCheck());
}


void CDlgSettingSecretary1::InitCombo()	//主要是初始化地图类型和地图列表
{
	int i=0;
	for(i=0;i<2;++i)
	{
		m_pCbMapType->InsertString(i,g_szMapType[i]);
	}


	int mapSelType=m_pSecretary1Config->GetHungUpMapTypeFromCfg();	
	InitMapList(mapSelType,m_pCbMaps);
	m_pCbMapType->SetCurSel(mapSelType);
	int mapIndex=m_pSecretary1Config->GetAutoHungUpMapIndexCfg();
	m_pCbMaps->SetCurSel(mapIndex);


}



void CDlgSettingSecretary1::InitMapList(int mapSelType,CComboBox *pCombo)
{
	
}
void CDlgSettingSecretary1::OnCbnSelchangeCbArenaMultiCount()
{
	int curSel=m_pCbMapType->GetCurSel();
	InitMapList(curSel,m_pCbMaps);
}



void CDlgSettingSecretary1::OnBnClickedBtnReadCurRoleCoor()
{
	// TODO: 在此添加控件通知处理程序代码
	CGameConfig cfg(m_pPlayer->GetAccountName(),true,false);
	m_pSecretary1Config=cfg.GetConfigSecretary1();
	CString str;
	str.Format(_T("%d"),m_pPlayer->GetX());
	m_pEdtAutoHungUpPointX->SetWindowText(str);

	str.Format(_T("%d"),m_pPlayer->GetY());
	m_pEdtAutoHungUPPointY->SetWindowText(str);

	m_pSecretary1Config->SetAutoHungUpPointXToCfg(m_pPlayer->GetX());
	m_pSecretary1Config->SetAutoHungUpPointYToCfg(m_pPlayer->GetY());

}
