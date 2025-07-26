// ./Dlgs/Settings/DlgOtherTaskSettings.cpp : ʵ���ļ�
//

#include "../../StdAfx.h"
// #include "GameBot.h"
#include "DlgOtherTaskSettings.h"


// CDlgOtherTaskSettings �Ի���

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


// CDlgOtherTaskSettings ��Ϣ�������

BOOL CDlgBossAssistSettings::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_brush.CreateSolidBrush(RGB(255,255,255));//while brush
	InitCtrls();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

HBRUSH CDlgBossAssistSettings::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	hbr=(HBRUSH)m_brush;
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
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
// 	m_pChkSpaceCorridor=(CButton*)GetDlgItem(IDC_CHK_SPACE_CORRIDOR);	//ʱ�����
// 	m_pChkSpecialSpace=(CButton*)GetDlgItem(IDC_CHK_SPECIAL_ROOM);
// 	m_pChkFastFight=(CButton*)GetDlgItem(IDC_CHK_FAST_FIGHT);
// 	m_pChkCampWar=(CButton*)GetDlgItem(IDC_CHK_CAMP_WAR);	//��Ԩս��
// 	m_pChkCertificate=(CButton*)GetDlgItem(IDC_CHK_CERTIFICATE);	//��ʹս��
// 	m_pChkPinkDiamond=(CButton*)GetDlgItem(IDC_CHK_PINK_DIAMOND);	//����
// 	m_pChkHorcrux=(CButton*)GetDlgItem(IDC_CHK_HORCRUX);	//����
// 	m_pChkOriginalSin=(CButton*)GetDlgItem(IDC_CHK_ORIGINAL_SIN);	//ԭ��xxxx
// 	m_pChkFairyLand=(CButton*)GetDlgItem(IDC_CHK_FAIRY_LAND);	//�þ�
// 	m_pEdtFairyLandCount=(CEdit*)GetDlgItem(IDC_EDT_FAIRY_LAND_COUNT);
// 	m_pChkOrcGodBless=(CButton*)GetDlgItem(IDC_CHK_ORC_GOD_BLESS);	//������Ը
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
	m_pEdtBeastBossAssistMaxTimeout->SetWindowText(str);	//Э���ʱ��
	m_pChkBeastBossAutoAssistOther->SetCheck(m_pBossAssistConfig->IsBeastBossAutoAssistOtherFromCfg());	//Э������
	m_pChkBeastBossAutoSendAssist->SetCheck(m_pBossAssistConfig->IsBeastBossAutoSendAssistFromCfg());	//��ɱʱ����Э��
	m_pChkBeastBossAssistAutoSendAssist->SetCheck(m_pBossAssistConfig->IsBeastBossAssistAutoSendAssistFromCfg());//Э��ʱ����Э��
	m_pChkBeastBossOnlyAssistSelfMaxCount->SetCheck(m_pBossAssistConfig->IsBeastBossOnlyAssistSelfMaxCountFromCfg());	//ֻЭ������������

	str.Format(_T("%d"),m_pBossAssistConfig->GetCorpsBossAssistMaxTimeoutFromCfg());
	m_pEdtCorpsBossAssistMaxTimout->SetWindowText(str);//Э���ʱ��
	m_pChkCorpsBossAutoAssistOther->SetCheck(m_pBossAssistConfig->IsCorpsBossAutoAssistOtherFromCfg());//Э������
	m_pChkCorpsBossAusoSendAssist->SetCheck(m_pBossAssistConfig->IsCorpsBossAutoSendAssistFromCfg());//��ɱʱ����Э��
	m_pChkCorpsBossAssistAutoSendAssist->SetCheck(m_pBossAssistConfig->IsCorpsBossAssistAutoSendAssistFromCfg());//Э��ʱ����Э��
	m_pChkCorpsBossOnlyAssistSelfMaxCount->SetCheck(m_pBossAssistConfig->IsCorpsBossOnlyAssistSelfMaxCountFromCfg());//ֻЭ������������
	
	// 
// 
// 	m_pChkSpaceCorridor->SetCheck(m_pOtherTaskConfig->IsSpaceCorridorSelectedFromCfg());	//ʱ�����
// 	m_pChkSpecialSpace->SetCheck(m_pOtherTaskConfig->IsSpecialRoomSelectedFromCfg());
// 	m_pChkFastFight->SetCheck(m_pOtherTaskConfig->IsFastFightSelectedFromCfg());
// 	m_pChkCampWar->SetCheck(m_pOtherTaskConfig->IsCampWarSelectedFromCfg());	//��Ԩս��
// 	m_pChkCertificate->SetCheck(m_pOtherTaskConfig->IsCertificateSelectedFromCfg());	//��ʹս��
// 	m_pChkPinkDiamond->SetCheck(m_pOtherTaskConfig->IsPinkDiamondSelectedFromcCfg());	//����
// 	m_pChkHorcrux->SetCheck(m_pOtherTaskConfig->IsHorcruxSelectedFromCfg());	//����
// 	m_pChkOriginalSin->SetCheck(m_pOtherTaskConfig->IsOriginalSinSelectedFromCfg());	//ԭ��xxxx
// 	m_pChkFairyLand->SetCheck(m_pOtherTaskConfig->IsFairyLandSelectedFromCfg());	//�þ�
// 
// 	str.Format(_T("%d"),m_pOtherTaskConfig->GetFairyLandCountFromCfg());
// 	m_pEdtFairyLandCount->SetWindowText(str);
// 
// 	m_pChkOrcGodBless->SetCheck(m_pOtherTaskConfig->IsOrcGodBlessSelectedFromCfg());	//������Ը
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
// 	m_pOtherTaskConfig->SetSelectSpaceCorridorToCfg(m_pChkSpaceCorridor->GetCheck());	//ʱ�����
// 	m_pOtherTaskConfig->SetSelectSpecialRoomToCfg(m_pChkSpecialSpace->GetCheck());
// 	m_pOtherTaskConfig->SetSelectFastFightToCfg(m_pChkFastFight->GetCheck());
// 	m_pOtherTaskConfig->SetSelectCampWarToCfg(m_pChkCampWar->GetCheck());	//��Ԩս��
// 	m_pOtherTaskConfig->SetSelectCertificateToCfg(m_pChkCertificate->GetCheck());	//��ʹս��
// 	m_pOtherTaskConfig->SetSelectPinkDiamondToCfg(m_pChkPinkDiamond->GetCheck());	//����
// 	m_pOtherTaskConfig->SetSelectHorcruxToCfg(m_pChkHorcrux->GetCheck());	//����
// 	m_pOtherTaskConfig->SetSelectOriginalSinToCfg(m_pChkOriginalSin->GetCheck());	//ԭ��xxxx
// 	m_pOtherTaskConfig->SetSelectFairyLandToCfg(m_pChkFairyLand->GetCheck());	//�þ�
// 
// 	m_pEdtFairyLandCount->GetWindowText(str);
// 	m_pOtherTaskConfig->SetFairyLandCountToCfg(_ttoi(str));
// 
// 
// 	m_pOtherTaskConfig->SetSelectOrcGodBlessToCfg(m_pChkOrcGodBless->GetCheck());	//������Ը
}


void CDlgBossAssistSettings::InitBtns()
{
	int i=0;


	m_pChk[i++]=m_pChkBeastBossAssistAutoSendAssist;
	m_pChk[i++]=m_pChkBeastBossOnlyAssistSelfMaxCount;
	m_pChk[i++]=m_pChkCorpsBossAssistAutoSendAssist;
	m_pChk[i++]=m_pChkCorpsBossOnlyAssistSelfMaxCount;
// 
// 	m_pChk[i++]=m_pChkSpaceCorridor;	//ʱ�����
// 	m_pChk[i++]=m_pChkSpecialSpace;
// 	m_pChk[i++]=m_pChkFastFight;
// 	m_pChk[i++]=m_pChkCampWar;	//��Ԩս��
// 	m_pChk[i++]=m_pChkCertificate;	//��ʹս��
// 	m_pChk[i++]=m_pChkPinkDiamond;	//����
// 	m_pChk[i++]=m_pChkHorcrux;	//����
// 	m_pChk[i++]=m_pChkOriginalSin;	//ԭ��xxxx
// 	m_pChk[i++]=m_pChkFairyLand;	//�þ�
// 	m_pChk[i++]=m_pChkOrcGodBless;	//������Ը
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CheckAll(m_pChkAll->GetCheck());
}

