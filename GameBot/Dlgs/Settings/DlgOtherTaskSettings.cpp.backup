// ./Dlgs/Settings/DlgOtherTaskSettings.cpp : 实现文件
//

#include "../../StdAfx.h"
// #include "GameBot.h"
#include "DlgOtherTaskSettings.h"


// CDlgOtherTaskSettings 对话框

IMPLEMENT_DYNAMIC(CDlgBossAssistSettings, CDialog)

CDlgBossAssistSettings::CDlgBossAssistSettings(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgBossAssistSettings::IDD, pParent)
{

}

CDlgBossAssistSettings::~CDlgBossAssistSettings()
{
}

void CDlgBossAssistSettings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgBossAssistSettings, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CHK_OTHER_TASK_SEL_ALL, &CDlgBossAssistSettings::OnBnClickedChkOtherTaskSelAll)
END_MESSAGE_MAP()


// CDlgOtherTaskSettings 消息处理程序

BOOL CDlgBossAssistSettings::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_brush.CreateSolidBrush(RGB(255,255,255));//while brush
	InitCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

HBRUSH CDlgBossAssistSettings::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	hbr=(HBRUSH)m_brush;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CDlgBossAssistSettings::InitCtrls()
{
	m_pChkBeastBossAutoAssistOther=(CButton*)GetDlgItem(IDC_CHK_BEAST_BOSS_AUTO_ASSIST_OTHER);
	m_pEdtBeastBossAssistMaxTimeout=(CEdit*)GetDlgItem(IDC_EDT_BEAST_BOSS_ASSIST_MAX_TIMEOUT);
	m_pChkBeastBossAutoSendAssist=(CButton*)GetDlgItem(IDC_CHK_BEAST_BOSS_AUTO_SEND_ASSIST);
	m_pChkBeastBossAssistAutoSendAssist=(CButton*)GetDlgItem(IDC_CHK_BEAST_BOSS_ASSIST_AUTO_SEND_ASSIST);
	m_pChkBeastBossOnlyAssistSelfMaxCount=(CButton*)GetDlgItem(IDC_CHK_BEAST_BOSS_ONLY_ASSIST_SELF_MAX_COUNT);


	m_pChkCorpsBossAutoAssistOther=(CButton*)GetDlgItem(IDC_CHK_CORPS_BOSS_AUTO_ASSIST_OTHER);
	m_pEdtCorpsBossAssistMaxTimout=(CEdit*)GetDlgItem(IDC_EDT_CORPS_BOSS_ASSIST_MAX_TIMEOUT);
	m_pChkCorpsBossAusoSendAssist=(CButton*)GetDlgItem(IDC_CHK_CROPS_BOSS_AUTO_SEND_ASSIST);
	m_pChkCorpsBossAssistAutoSendAssist=(CButton*)GetDlgItem(IDC_CHK_CORPS_BOSS_ASSIST_AUTO_SEND_ASSIST);
	m_pChkCorpsBossOnlyAssistSelfMaxCount=(CButton*)GetDlgItem(IDC_CHK_CORPS_BOSS_ONLY_ASSIST_SELF_MAX_COUNT);
// 
// 	m_pChkSpaceCorridor=(CButton*)GetDlgItem(IDC_CHK_SPACE_CORRIDOR);	//时光回廊
// 	m_pChkSpecialSpace=(CButton*)GetDlgItem(IDC_CHK_SPECIAL_ROOM);
// 	m_pChkFastFight=(CButton*)GetDlgItem(IDC_CHK_FAST_FIGHT);
// 	m_pChkCampWar=(CButton*)GetDlgItem(IDC_CHK_CAMP_WAR);	//冰渊战场
// 	m_pChkCertificate=(CButton*)GetDlgItem(IDC_CHK_CERTIFICATE);	//天使战令
// 	m_pChkPinkDiamond=(CButton*)GetDlgItem(IDC_CHK_PINK_DIAMOND);	//粉钻
// 	m_pChkHorcrux=(CButton*)GetDlgItem(IDC_CHK_HORCRUX);	//魂器
// 	m_pChkOriginalSin=(CButton*)GetDlgItem(IDC_CHK_ORIGINAL_SIN);	//原罪xxxx
// 	m_pChkFairyLand=(CButton*)GetDlgItem(IDC_CHK_FAIRY_LAND);	//幻境
// 	m_pEdtFairyLandCount=(CEdit*)GetDlgItem(IDC_EDT_FAIRY_LAND_COUNT);
// 	m_pChkOrcGodBless=(CButton*)GetDlgItem(IDC_CHK_ORC_GOD_BLESS);	//兽神祈愿
// 
// 
// 	int limit=2;
// 	m_pEdtFairyLandCount->SetLimitText(limit);
// 

	m_pChkAll=(CButton*)GetDlgItem(IDC_CHK_OTHER_TASK_SEL_ALL);

	InitBtns();
}


void CDlgBossAssistSettings::ReadIniToCtrls()
{
	CString str;
	
	str.Format(_T("%d"),m_pBossAssistConfig->GetBeastBossAssistMaxTimeoutFromCfg());
	m_pEdtBeastBossAssistMaxTimeout->SetWindowText(str);	//协助最长时间
	m_pChkBeastBossAutoAssistOther->SetCheck(m_pBossAssistConfig->IsBeastBossAutoAssistOtherFromCfg());	//协助他人
	m_pChkBeastBossAutoSendAssist->SetCheck(m_pBossAssistConfig->IsBeastBossAutoSendAssistFromCfg());	//击杀时发送协助
	m_pChkBeastBossAssistAutoSendAssist->SetCheck(m_pBossAssistConfig->IsBeastBossAssistAutoSendAssistFromCfg());//协助时发送协助
	m_pChkBeastBossOnlyAssistSelfMaxCount->SetCheck(m_pBossAssistConfig->IsBeastBossOnlyAssistSelfMaxCountFromCfg());	//只协助本身最大次数

	str.Format(_T("%d"),m_pBossAssistConfig->GetCorpsBossAssistMaxTimeoutFromCfg());
	m_pEdtCorpsBossAssistMaxTimout->SetWindowText(str);//协助最长时间
	m_pChkCorpsBossAutoAssistOther->SetCheck(m_pBossAssistConfig->IsCorpsBossAutoAssistOtherFromCfg());//协助他人
	m_pChkCorpsBossAusoSendAssist->SetCheck(m_pBossAssistConfig->IsCorpsBossAutoSendAssistFromCfg());//击杀时发送协助
	m_pChkCorpsBossAssistAutoSendAssist->SetCheck(m_pBossAssistConfig->IsCorpsBossAssistAutoSendAssistFromCfg());//协助时发送协助
	m_pChkCorpsBossOnlyAssistSelfMaxCount->SetCheck(m_pBossAssistConfig->IsCorpsBossOnlyAssistSelfMaxCountFromCfg());//只协助本身最大次数
	
	// 
// 
// 	m_pChkSpaceCorridor->SetCheck(m_pOtherTaskConfig->IsSpaceCorridorSelectedFromCfg());	//时光回廊
// 	m_pChkSpecialSpace->SetCheck(m_pOtherTaskConfig->IsSpecialRoomSelectedFromCfg());
// 	m_pChkFastFight->SetCheck(m_pOtherTaskConfig->IsFastFightSelectedFromCfg());
// 	m_pChkCampWar->SetCheck(m_pOtherTaskConfig->IsCampWarSelectedFromCfg());	//冰渊战场
// 	m_pChkCertificate->SetCheck(m_pOtherTaskConfig->IsCertificateSelectedFromCfg());	//天使战令
// 	m_pChkPinkDiamond->SetCheck(m_pOtherTaskConfig->IsPinkDiamondSelectedFromcCfg());	//粉钻
// 	m_pChkHorcrux->SetCheck(m_pOtherTaskConfig->IsHorcruxSelectedFromCfg());	//魂器
// 	m_pChkOriginalSin->SetCheck(m_pOtherTaskConfig->IsOriginalSinSelectedFromCfg());	//原罪xxxx
// 	m_pChkFairyLand->SetCheck(m_pOtherTaskConfig->IsFairyLandSelectedFromCfg());	//幻境
// 
// 	str.Format(_T("%d"),m_pOtherTaskConfig->GetFairyLandCountFromCfg());
// 	m_pEdtFairyLandCount->SetWindowText(str);
// 
// 	m_pChkOrcGodBless->SetCheck(m_pOtherTaskConfig->IsOrcGodBlessSelectedFromCfg());	//兽神祈愿
}


void CDlgBossAssistSettings::SaveCtrlsToIni()
{
	CString str;
	int timeout=GetDlgItemInt(IDC_EDT_BEAST_BOSS_ASSIST_MAX_TIMEOUT);
	m_pBossAssistConfig->SetBeastBossAssistMaxTimeoutToCfg(timeout);
	m_pBossAssistConfig->SetIsBeastBossAutoAssistOtherToCfg(m_pChkBeastBossAutoAssistOther->GetCheck());
	m_pBossAssistConfig->SetIsBeastBossAutoSendAssistToCfg(m_pChkBeastBossAutoSendAssist->GetCheck());
	m_pBossAssistConfig->SetIsBeastBossAssistAutoSendAssistToCfg(m_pChkBeastBossAssistAutoSendAssist->GetCheck());
	m_pBossAssistConfig->SetIsBeastBossOnlyAssistSelfMaxCountToCfg(m_pChkBeastBossOnlyAssistSelfMaxCount->GetCheck());


	timeout=GetDlgItemInt(IDC_EDT_CORPS_BOSS_ASSIST_MAX_TIMEOUT);
	m_pBossAssistConfig->SetCorpsBossAssistMaxTimeoutToCfg(timeout);
	m_pBossAssistConfig->SetIsCorpsBossAutoAssistOtherToCfg(m_pChkCorpsBossAutoAssistOther->GetCheck());
	m_pBossAssistConfig->SetIsCorpsBossAssistAutoSendAssistToCfg(m_pChkCorpsBossAssistAutoSendAssist->GetCheck());
	m_pBossAssistConfig->SetIsCorpsBossAutoSendAssistToCfg(m_pChkCorpsBossAusoSendAssist->GetCheck());
	m_pBossAssistConfig->SetIsCorpsBossOnlyAssistSelfMaxCountToCfg(m_pChkCorpsBossOnlyAssistSelfMaxCount->GetCheck());


// 
// 	m_pOtherTaskConfig->SetSelectSpaceCorridorToCfg(m_pChkSpaceCorridor->GetCheck());	//时光回廊
// 	m_pOtherTaskConfig->SetSelectSpecialRoomToCfg(m_pChkSpecialSpace->GetCheck());
// 	m_pOtherTaskConfig->SetSelectFastFightToCfg(m_pChkFastFight->GetCheck());
// 	m_pOtherTaskConfig->SetSelectCampWarToCfg(m_pChkCampWar->GetCheck());	//冰渊战场
// 	m_pOtherTaskConfig->SetSelectCertificateToCfg(m_pChkCertificate->GetCheck());	//天使战令
// 	m_pOtherTaskConfig->SetSelectPinkDiamondToCfg(m_pChkPinkDiamond->GetCheck());	//粉钻
// 	m_pOtherTaskConfig->SetSelectHorcruxToCfg(m_pChkHorcrux->GetCheck());	//魂器
// 	m_pOtherTaskConfig->SetSelectOriginalSinToCfg(m_pChkOriginalSin->GetCheck());	//原罪xxxx
// 	m_pOtherTaskConfig->SetSelectFairyLandToCfg(m_pChkFairyLand->GetCheck());	//幻境
// 
// 	m_pEdtFairyLandCount->GetWindowText(str);
// 	m_pOtherTaskConfig->SetFairyLandCountToCfg(_ttoi(str));
// 
// 
// 	m_pOtherTaskConfig->SetSelectOrcGodBlessToCfg(m_pChkOrcGodBless->GetCheck());	//兽神祈愿
}


void CDlgBossAssistSettings::InitBtns()
{
	int i=0;


	m_pChk[i++]=m_pChkBeastBossAssistAutoSendAssist;
	m_pChk[i++]=m_pChkBeastBossOnlyAssistSelfMaxCount;
	m_pChk[i++]=m_pChkCorpsBossAssistAutoSendAssist;
	m_pChk[i++]=m_pChkCorpsBossOnlyAssistSelfMaxCount;
// 
// 	m_pChk[i++]=m_pChkSpaceCorridor;	//时光回廊
// 	m_pChk[i++]=m_pChkSpecialSpace;
// 	m_pChk[i++]=m_pChkFastFight;
// 	m_pChk[i++]=m_pChkCampWar;	//冰渊战场
// 	m_pChk[i++]=m_pChkCertificate;	//天使战令
// 	m_pChk[i++]=m_pChkPinkDiamond;	//粉钻
// 	m_pChk[i++]=m_pChkHorcrux;	//魂器
// 	m_pChk[i++]=m_pChkOriginalSin;	//原罪xxxx
// 	m_pChk[i++]=m_pChkFairyLand;	//幻境
// 	m_pChk[i++]=m_pChkOrcGodBless;	//兽神祈愿
}



void CDlgBossAssistSettings::CheckAll(bool bSelect)
{
	for(int i=0;i<13;++i)
	{
		m_pChk[i]->SetCheck(bSelect);
	}
}

void CDlgBossAssistSettings::OnBnClickedChkOtherTaskSelAll()
{
	// TODO: 在此添加控件通知处理程序代码
	CheckAll(m_pChkAll->GetCheck());
}

