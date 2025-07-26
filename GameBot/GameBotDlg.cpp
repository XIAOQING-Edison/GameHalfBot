// GongShaBotDlg.cpp : ʵ���ļ�
//

#include "StdAfx.h"
#include "GameBot.h"
#include "GameBotDlg.h"
#include <Tlhelp32.h>
#include "./Global/public.h"

#include "./Config/CommentConfig.h"	//for read ini fil e
#include "./Dlgs/Settings/DlgUserSettings.h"
#include "./Dlgs/Other/DlgShowReadMe.h"	//for read me

#include "./FileTools/FileHelper.h"

///////////////////////////////////����Ϊ������Ҫ������ͷ�������ͷ�ļ���Ҫ���Ժ����///////////////////////////////////////
#include "./Dlgs/Settings/DlgSettings.h"
#include "./Dlgs/Settings/DlgOtherSetting.h"
#include "./Dlgs/Settings/DlgBossSettings.h"

#include "./Dlgs/Other/DlgProcessList.h"	//�����б�

#include "./Dlgs/Other/DlgHotKeySetting.h"	//�ȼ�

#include "./Config/GameConfig.h"
#include "./Config/PlatformConfig.h"
#include "./Config/UserConfig.h"
#include "./Config/GlobalConfig.h"
#include "./Config/SkillConfig.h"

#include "MessageMapList.h"
#include "./Util/MessageSenderHelper.h"

#include "Misc/Misc.h"
#include "ProtocolMap.h"
#include "Misc/HookHelper.h"


//test
// #include "./LogFile/UserLogFile.h"


//tool object
#include "./Inject/InjectorRemoteThead.h"

//test,���漸��Ϊ�˲��Զ��ӵ�ͷ�ļ�
#include "FunctionHelper/SocketHelper.h"
#include "FunctionHelper/GameLogicHelper.h"
#include "Player.h"

// #define _TEST_	//���Կ������

#include <locale.h>	//Ϊ��TRACE����

char* g_old_locale=NULL;	//local

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

const int g_platform_info_count=1;
const int g_inject_method_count=3;
const int g_platform_width[]={185,100,80,100
};

//ƽ̨����������ID��
TCHAR *g_szListColumnInfoPlatForm[]={_T("ģ��������"),_T("ģ����״̬"),_T(""),_T(""),
};



const int g_player_info_count=6;
const int g_player_info_width[]={180,80,80,100,100,150,150

};

const char g_gameVersionSupport[]={0,5,10,11,20};	//��ʱ�汾

//Ĭ����yong_heng_lian_meng_
int g_gameVersionCount=1;
#if (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_)
// int g_gameVersionCount=1;
const int g_gameVersionValueArray[]={11,11,11,11,5,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
TCHAR *g_szGameVersion[]={_T("��ʹ����(����֮��")};
#elif (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_)
// int g_gameVersionCount=1;
const int g_gameVersionValueArray[]={10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
TCHAR *g_szGameVersion[]={_T("�漣2")};
#elif (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_)
const int g_gameVersionValueArray[]={0,0,0,0,0,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
TCHAR *g_szGameVersion[]={_T("�漣1")};
#elif (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
const int g_gameVersionValueArray[]={5,5,5,5,5,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
TCHAR *g_szGameVersion[]={_T("�漣1PC")};
#elif (_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_)
const int g_gameVersionValueArray[]={20,20,20,20,20,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
TCHAR *g_szGameVersion[]={_T("����漣")};
#endif


//������ԣ���������,typeName�Ǵ�ini���typeֵ�õ�������
TCHAR *g_szListColumnInfoRoleAttr[]={
	_T("��ɫ��"),_T("ְҵ"),_T("�ȼ�"),_T("ս��"),_T("���ڵ�ͼ"),_T("����(x,y)")
};
//_T("��ɫ״̬"),


#ifdef _M_IX86
// const TCHAR *g_szTitle=_T("Mu����\t\t      ����:v΢15915901852");
const TCHAR *g_szTitle=_T("Mu����\t\t     ����:�ۿ�493150845");//test
// const TCHAR *g_szTitle=_T("Mu����\t\t");//test
#else
const TCHAR *g_szTitle=_T("�漣����  �������� 0.%d��\t\t     ����Ⱥ:832921609");
// const TCHAR *g_szTitle=_T("�漣����  �������� 0.%d��\t\t");//     ����Ⱥ:832921609");
#endif

//����ʹ��postmessage��Ϊ���ͣ���ʹ��ǰ̨ģʽ

char *TestReadFile(const TCHAR *szPath,int &fileLength)
{
	STRING strFile=szPath;//_T("d:\\aa.bin");
	DWORD dstLength;
	DWORD bytesRead;
	HANDLE hFileRead=CreateFile(strFile.c_str(),GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_ARCHIVE,NULL);
	if(hFileRead==INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL,_T("Error when open file\n"),_T("Error"),MB_ICONERROR);
		return NULL;
	}
	DWORD sz,szHigh;
	sz=GetFileSize(hFileRead,&szHigh);
	fileLength=sz;
	BYTE *pReadBuf=new BYTE[sz];
	ReadFile(hFileRead,pReadBuf,sz,&bytesRead,NULL);

	char *data=(char*)pReadBuf;
	SAFE_CLOSE_HANDLE(hFileRead);
	return data;

}
//////////////////////////////////////////////////////////////////////////

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CGongShaBotDlg �Ի���




CGameBotDlg::CGameBotDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGameBotDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_pSharedMemory=new CShareMemory(512);	//creator
	m_bInit=false;
	m_pInjector=NULL;
}

void CGameBotDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_LINK1, m_hyperLink1);
}

BEGIN_MESSAGE_MAP(CGameBotDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_SELF_HANDLE_MSG,OnHandleSelfMessage)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_LOGIN, &CGameBotDlg::OnBnClickedBtnLogin)
	ON_BN_CLICKED(IDC_BTN_TALK_TEST, &CGameBotDlg::OnBnClickedBtnTalkTest)
	ON_BN_CLICKED(IDC_BTN_TEST, &CGameBotDlg::OnBnClickedBtnLoginGameServ)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_INFO, &CGameBotDlg::OnLvnItemchangedListInfo)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_INFO, &CGameBotDlg::OnNMRClickListInfo)

	ON_COMMAND_RANGE(IDM_SERETARY_SETTINGS,IDM_CLEAR_LOG,OnListPopupMenu)
	ON_MESSAGE(WM_CLICK_TRAY,OnClickTray)
	ON_BN_CLICKED(IDC_BTN_PLAY_ALL, &CGameBotDlg::OnBnClickedBtnPlayAll)
	ON_WM_COPYDATA()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BTN_REPAIR_CFG_FILE, &CGameBotDlg::OnBnClickedBtnRepairCfgFile)
	ON_NOTIFY(NM_CLICK, IDC_LIST_INFO, &CGameBotDlg::OnNMClickListInfo)
	ON_BN_CLICKED(IDC_BTN_CONNECT, &CGameBotDlg::OnBnClickedBtnConnect)
	ON_BN_CLICKED(IDC_BTN_TEST_MISC, &CGameBotDlg::OnBnClickedBtnTestMisc)
	ON_BN_CLICKED(IDC_BTN_CLICK_ME, &CGameBotDlg::OnBnClickedBtnClickMe)
	ON_CBN_SELCHANGE(IDC_CB_GAME_VERSION, &CGameBotDlg::OnCbnSelchangeCbGameVersion)
	ON_WM_HOTKEY()
	ON_CBN_SELCHANGE(IDC_CB_INJECT_TYPE, &CGameBotDlg::OnCbnSelchangeCbInjectType)
	ON_BN_CLICKED(IDC_BTN_ACCERLATE_SETTING, &CGameBotDlg::OnBnClickedBtnAccerlateSetting)
END_MESSAGE_MAP()


// CGongShaBotDlg ��Ϣ�������

BOOL CGameBotDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	
#ifdef ACTIVE_ENCRYPT
	m_workerThread.Create();
	TryToRepairConfigInInit();	//test,���Խ׶Σ������ʼ
#endif // ACTIVE_ENCRYPT

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
#ifdef _DEBUG
	g_old_locale = _strdup( setlocale(LC_CTYPE,NULL) );
	setlocale( LC_CTYPE, "chs" );

#endif // _DEBUG

#ifdef _TEST_
	CButton *pBtn=(CButton*)GetDlgItem(IDC_BTN_REPAIR_CFG_FILE);
	pBtn->ShowWindow(SW_SHOW);
#endif // _TEST_

	SetInit(true);

	m_server.Init();	//�����ʼ������Ϊ���Կ������

#ifdef _M_IX86
	//ChangeToBasicTheme();
#else
	//64λ����Ҫת������
#endif // _M_IX86

	this->ShowWindow(SW_HIDE);
	m_dlgLoading.Create(IDD_DLG_LOADING);
	m_dlgLoading.ShowWindow(SW_SHOW);
	CRect rcMain,rcLoading;
	this->GetClientRect(&rcMain);

	m_dlgLoading.GetClientRect(&rcLoading);
	int loadingWidth=rcLoading.Width();
	int loadHeight=rcLoading.Height();
	m_dlgLoading.MoveWindow(rcMain.Width()/2-rcLoading.Width()/2,rcMain.Height()/2-rcLoading.Height()/2,loadingWidth,loadHeight);


	InitCtrls();

	//GenConsoleWindow();
	int version=31;	//�����汾	
	TCHAR buf[MAX_PATH];

#ifdef _M_IX86
	m_pCbGameVersion->ShowWindow(SW_HIDE);
	m_hyperLink1.ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BTN_CLICK_ME)->ShowWindow(SW_HIDE);
	_tcscpy(buf,g_szTitle);
#else
	_stprintf(buf,g_szTitle,version);
#endif // _M_IX86
	this->SetWindowText((LPTSTR)buf);


	InitHelperObjects();

	InitToolObjects();
	InitPlayers();

	if(!m_pSharedMemory->CreateShareMemory(g_szSharedMemoryName))
	{
		MessageBox(_T("�����ڴ�ʧ�ܣ�����"));
		return FALSE;
	}
	HWND hMain=this->GetSafeHwnd();
	m_pSharedMemory->WriteSharedMemoryByOffset((char*)&hMain,0,sizeof(HWND));	//0��д������ʹ���Է�����Ϣ
	m_pSharedMemory->WriteSharedMemoryByOffset((char*)&g_maxCount,1*sizeof(int),sizeof(int));	//1��д������

	this->ShowWindow(SW_SHOW);
	m_dlgLoading.DestroyWindow();

	printf("main hwnd :%d\n",this->GetSafeHwnd());




	RegisterGlobalHotKey();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CGameBotDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
// #ifdef  _M_IX86
// #else
// 		CAboutDlg dlgAbout;
// 		dlgAbout.DoModal();
// #endif
	}
	else
	{
		if(nID==SC_MINIMIZE)
		{
			OnMinimize();
		}
		else
			CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGameBotDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGameBotDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CGameBotDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
#ifdef _DEBUG
	setlocale( LC_CTYPE, g_old_locale);
	free(g_old_locale);
#endif // _DEBUG
	

	SAFE_DELETE_POINTER(m_pSharedMemory);

	//m_pInjector->Uninject();	//�ͷ�dll
	m_server.SendQuitMessageToClients();//�������ÿͻ��˱��quit״̬���Ȳ�ֱ���ͷ�dll

	ClearPlayers();

	m_server.ClearClients();	//�ͷ��ʺ���ض���

	ClearHelperObjects();
	DeleteToolObjects();
	
	CDialog::OnCancel();
	CDialog::OnClose();
}

void CGameBotDlg::OnBnClickedBtnLogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	

}

void CGameBotDlg::InitCtrls()
{
	CFont font;
	font.CreatePointFont(90, _T("����"));
	CButton *pBtnAddOrModify=(CButton*)GetDlgItem(IDC_BTN_TEST);
	pBtnAddOrModify->SetFont(&font);
	m_hyperLink1.SetURL(_T("https://www.baidu.com"));

	m_pCbGameVersion=(CComboBox*)GetDlgItem(IDC_CB_GAME_VERSION);
	m_pCbInjectType=(CComboBox*)GetDlgItem(IDC_CB_INJECT_TYPE);

	InitCombo();
	InitListCtrl();


}


void CGameBotDlg::InitListCtrl()
{
	m_pListCtrlInfo=(CListCtrl*)GetDlgItem(IDC_LIST_INFO);
	m_pListCtrlInfo->ModifyStyle(0, LVS_SINGLESEL, 0);
	m_pListCtrlInfo->SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_CHECKBOXES);	//��ѡ����
	int i;
	int j=0;
	for(i=0;i<g_platform_info_count;++i)
	{
		m_pListCtrlInfo->InsertColumn(j++,g_szListColumnInfoPlatForm[i],LVCFMT_CENTER,g_platform_width[i]);
	}


	for(i=0;i<g_player_info_count;++i)
	{
		m_pListCtrlInfo->InsertColumn(j++,g_szListColumnInfoRoleAttr[i],LVCFMT_CENTER,g_player_info_width[i]);
	}

// 	CRect rc;
// 	GetClientRect(&rc);
// #ifdef _DEBUG
// 	rc.bottom-=100;
// #else
// 	rc.bottom-=45;
// #endif // _DEBUG
// 	m_pListCtrlInfo->MoveWindow(rc);
}


void CGameBotDlg::InitCombo()	//��ʼ��infoType
{
// 	m_pCbInfoType=(CComboBox*)GetDlgItem(IDC_CB_INFO_TYPE);
// 	for(int i=0;i<g_type_info_count;++i)
// 	{
// 		m_pCbInfoType->AddString(g_szCbInfoTypeText[i]);
// 	}


// 	m_pCbInfoType->SetCurSel(0);
#if _GAME_VERSION_ == _TIAN_SHI_SHEN_YU_
	int sel=0;
#else
	int sel=0;
#endif
	for(int i=0;i<g_gameVersionCount;++i)
	{
		m_pCbGameVersion->InsertString(i,g_szGameVersion[i]);
	}
	m_pCbGameVersion->SetCurSel(sel);	//test,��Ĭ���漣2
	m_pCbInjectType->SetCurSel(1);	//Ĭ�Ϸ�ʽ2

}


void CGameBotDlg::InitPlayers()	//��ʼ���ʺŵĽ�ɫ,���Ե�½
{
	//CPlayerMap::GetInstance();
	ClearPlayers();

	ReadGameConfigFileToList();

}


void CGameBotDlg::ClearPlayers()	//ɾ����ǰ���ʺ���Ϣ
{
	//CPlayerMap::DelInstance();
	vector<CPlayer*>::iterator it=m_playerList.begin();
	it=m_playerList.begin();
	while(it != m_playerList.end())
	{
		CPlayer *p=*it;
		p->SetQuit(true);
		++it;
	}


	it=m_playerList.begin();
	while(it !=m_playerList.end())
	{
		CPlayer *p=*it;
		SAFE_DELETE_POINTER(p);
		++it;
	}
	m_playerList.clear();
}

CPlayer *CGameBotDlg::GetPlayerById(int index)	//ȡ�ö�Ӧ�±���ʺŽ�ɫָ��
{
	CPlayer *p=NULL;
	vector<CPlayer*>::iterator it=m_playerList.begin();
	while(it !=m_playerList.end())
	{
		CPlayer *pTmp=*it;
		if(pTmp->GetPlayerIndex()==index && index>=0)
		{
			p=pTmp;
			break;
		}
		++it;
	}
	return p;
}






///////////////////////////����change map///////////////////////////////////////
void CGameBotDlg::ShowChangeMap(int id)
{
// 	CEdit *pEdt=(CEdit*)GetDlgItem(IDC_EDT_MAP_NAME);
// 	CCommentConfig cfg(_T("GameConfig\\MapCfg.ini"),_T("id$name$minLevelLimit$maxLevelLimit$"));
// 	CString str;
// 	str.Format(_T("%d"),id);
// 	vector<STRING> valueArr=cfg.ReadIniAndGetStringVec(str);
// 
// 
// 	if(valueArr.size()>2)
// 	{
// 		str.Format(_T("%s"),valueArr.at(1).c_str());	//name
// 	}
// 	else
// 	{
// 		str=_T("δ֪��ͼ:id=")+str;
// 	}
// 	pEdt->SetWindowText(str);

}



LRESULT CGameBotDlg::OnHandleSelfMessage(WPARAM wParam,LPARAM lParam)
{
	E_MSG_TYPE msgType=(E_MSG_TYPE)wParam;
	CClient *pClient=(CClient*)lParam;
	//TCHAR buf[MAX_PATH];
	CAccountInfo *pInfo=(CAccountInfo*)lParam;
	switch(msgType)
	{
	case e_msg_type_report_player_status:	//���½�ɫ״̬����ʱֻ��ʾ��ӽ�ɫ����Ϣ
		UpdateRoleInfoToList(pClient->GetIndex(),pClient);
		//UpdatePlayerConnectInfo(pClient->GetIndex(),pClient);	//��������״̬������
		UpdateCurrentOperation(pClient->GetIndex(),pClient);
		break;
	case e_msg_type_add_account_info:
		AddAccountInfoToList(pInfo);	
		break;
	case e_msg_type_update_account_info:
		UpdateAccountInfoToList((CAccountInfo*)lParam);
		break;
	case e_msg_type_write_log:
		WriteLogMsg((_GAME_LOG_MSG_*)lParam);
		break;
	case e_msg_type_report_current_operation:	//��ǰ���еĲ���
		UpdateCurrentOperation(pClient->GetIndex(),pClient);
		break;
	case e_msg_type_do_game_operation:
		SendOperation((_OPERATION_MSG_*)lParam);
		break;
	default:
		break;

	}

	return 0;
}




void CGameBotDlg::OnBnClickedBtnTalkTest()
{
	
}



void CGameBotDlg::OnBnClickedBtnLoginGameServ()
{

#if 0
	char data[48] = {
		0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x03, 0xF2, 0x00, 0x00, 0x08, 0x80, 0xF0, 0xB9, 0x99, 0xAF, 
		0xCB, 0x80, 0xE0, 0x1D, 0x12, 0x13, 0x32, 0x31, 0x34, 0x33, 0x37, 0x31, 0x36, 0x30, 0x31, 0x32, 
		0x32, 0x37, 0x38, 0x35, 0x37, 0x37, 0x31, 0x35, 0x32, 0x18, 0xC4, 0xA8, 0xFD, 0xD8, 0xED, 0x30
	};
	CSocketHelper *pSocket=m_playerList.at(0)->GetSocketHelper();
	pSocket->DecodeNormalPlayload(data,sizeof(data));	//��������
#endif
#if 0
	INT64 targetId=0;
	int targetX=180;
	int tareetY=125;
	int skillId=12120107;
	CSocketHelper *pSocket=m_playerList.at(0)->GetSocketHelper();
	pSocket->SendUseSkillMessage(skillId,targetId,targetX,tareetY);	//������ȷ
#endif
#if 0
	int index=m_pListCtrlInfo->GetSelectionMark();
	bool bSelected=(m_pListCtrlInfo->GetItemState(index,LVIS_SELECTED)==LVIS_SELECTED);
	CDlgUserSettings userDlg;

	if(index != -1 && bSelected)
	{
		STRING accountName=m_pListCtrlInfo->GetItemText(index,0);	//ȡ��0����Ϊ����
		userDlg.SetIndex(index);
		userDlg.SetUserName(accountName);
		userDlg.SetAddUser(false);
	}
	else
	{
		userDlg.SetAddUser(true);
	}
	userDlg.DoModal();

#endif
	
}



void CGameBotDlg::OnLvnItemchangedListInfo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMListView = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	if(pNMListView->uChanged == LVIF_STATE)
	{
		if(pNMListView->uNewState)
		{
			int nIndex = pNMListView->iItem;
		}

	}


	//����������ʱ������Σ��ݲ�ʹ��
// 	LPNMITEMACTIVATE   pNMLV   =   (LPNMITEMACTIVATE)pNMHDR;
// 	CString str;
// 	if((pNMLV->uOldState & INDEXTOSTATEIMAGEMASK(1)) /* old state : unchecked */  && (pNMLV->uNewState & INDEXTOSTATEIMAGEMASK(2)) /* new state : checked */)  
// 	{  
// 		str.Format(_T("Item���У� %d subItem���У� %d is checked\n"), pNMLV->iItem,pNMLV->iSubItem);
// 	}  
// 	else if((pNMLV->uOldState & INDEXTOSTATEIMAGEMASK(2)) /* old state : checked */  && (pNMLV->uNewState & INDEXTOSTATEIMAGEMASK(1)) /* new state : unchecked */)
// 	{  
// 		str.Format(_T("Item %d is unchecked\n"), pNMLV->iItem);  
// 	}  
// 	else  
// 	{  
// 		str.Format(_T("Item %d does't change the check-status\n"), pNMLV->iItem);  
// 	}
// 	AfxMessageBox(str);
	*pResult = 0;
}

void CGameBotDlg::OnNMRClickListInfo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	NMLISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	DWORD dwPos = GetMessagePos();
	CPoint point( LOWORD(dwPos), HIWORD(dwPos) );

	CMenu menu;
	CMenu* popup;
	VERIFY( menu.LoadMenu(IDR_MENU_LIST_POPUP));
// 	if(pNMListView->iItem != -1)
// 	{	
// 		popup = menu.GetSubMenu(1);
// 		ASSERT( popup != NULL );
// 		//popup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this );
// 
// 	}
// 	else
	{
		popup = menu.GetSubMenu(0);
		ASSERT( popup != NULL );
		printf("no item in the listctrl\n");
	}
	//test,��δ��ɵĹ��ܣ��˵���ȥ��
 	popup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this );

	*pResult = 0;
}


void CGameBotDlg::OnListPopupMenu(UINT nId)
{
	printf("nid is %d\n",nId);
	int index=m_pListCtrlInfo->GetSelectionMark();
	bool bSelected=(m_pListCtrlInfo->GetItemState(index,LVIS_SELECTED)==LVIS_SELECTED);
	STRING accountName;
	//m_pListCtrlInfo->GetItemData(index);
	CDlgSecretarySettings dlgSettings;
	CDlgOtherSetting dlgOtherSettings;
	CDlgBossSettings dlgBossSettings;
	dlgSettings.SetMainHwnd(this->GetSafeHwnd());
	CPlayer *pPlayer=NULL;
	CClient *pClient=NULL;

	accountName=m_playerList.at(index)->GetAccountName();	//ȡ��0����Ϊ����
	dlgOtherSettings.SetAccountName(accountName);
	dlgSettings.SetAccountName(accountName);
	dlgBossSettings.SetAccountName(accountName);
	dlgBossSettings.SetPlayerIndex(index);
	switch(nId)
	{
	case IDM_SERETARY_SETTINGS:
		if(index !=-1&& bSelected)
		{
			pPlayer=m_playerList.at(index);
			dlgSettings.SetPlayerPointer(pPlayer);
			dlgSettings.SetAddUser(false);
			dlgSettings.DoModal();
		}
		break;
	case IDM_OTHER_SETTING:
		if(index !=-1&& bSelected)
		{
			pPlayer=m_playerList.at(index);
			pClient=m_server.GetClientById(index);
			dlgOtherSettings.SetPlayerSkillList(pClient->GetPlayerStatus()->GetSkillList());
			dlgOtherSettings.SetIndex(pPlayer->GetCareer());
			dlgOtherSettings.DoModal();
		}
		break;
	case IDM_BOSS_SETTING:
		if(index !=-1&& bSelected)
		{
			dlgBossSettings.DoModal();
		}
		break;
	case IDM_SHOW_LOG:
		if(index !=-1&& bSelected)
		{
			pPlayer=m_playerList.at(index);
			if(!m_dlgShowLog.IsDlgCreated())
			{
				m_dlgShowLog.Create(IDD_DLG_SHOW_LOG,this);
				m_dlgShowLog.ShowWindow(SW_SHOW);
			}
			m_dlgShowLog.ReadLogToEdit(pPlayer->GetAccountName().c_str());
		}
	case IDM_CLEAR_LOG:
		if(index !=-1&& bSelected)
		{
			m_dlgShowLog.ClearLog(pPlayer->GetAccountName().c_str());
		}
		break;
	default:
		break;

	}
}


void CGameBotDlg::ReadGameConfigFileToList()	//��ȡINI����ֶε�LISTCTRL
{
	CGameConfig gameCfg(STRING(_T("")),false);
	CUserConfig *pUserConfig=NULL;
	vector<STRING> allSections;
	allSections.push_back(_T("0"));
	vector<STRING>::iterator it=allSections.begin();
	int i=0;
	int maxCount=g_maxCount;
	while(it != allSections.end() && i<maxCount)
	{
		int j=0;

		CPlayer *p=new CPlayer;
		//CPlayerMap::GetInstance()->AddPlayerToMap(*it,p);
		p->SetPlayerIndex(i);
		p->SetAccountName(*it);	//accountName
		m_playerList.push_back(p);
		m_server.AddPlayerToClientList(p);
		//test
// 		CClient *pClient=m_server.GetClientById(0);
// 		pClient->SetIndex(0);
// 		pClient->SetMainWindow(this->GetSafeHwnd());
// 		pClient->SetSelfWindow(this->GetSafeHwnd());
// 		p->SetClient(pClient);
		m_pListCtrlInfo->InsertItem(i,it->c_str());
		//m_pListCtrlInfo->SetItemText(i,j++,it->c_str());	//account name
		m_pListCtrlInfo->SetItemText(i,j++,_T(""));	//������ʾ��ɫ����,�ǽ���Ϸ����
		TCHAR buf[MAX_PATH];
		CPlatformConfig cfg(false);
		gameCfg.SetUserName(*it);	//section name;
		gameCfg.SetAllObjectSectionNames();
		pUserConfig=gameCfg.GetUserConfig();
		//ASSERT(pInfo->GetIndex()==-1);
		_stprintf(buf,_T("%d"),gameCfg.GetUserConfig()->GetServerIdFromCfg());

		cfg.SetPlatformId(gameCfg.GetUserConfig()->GetPlatformIdFromCfg());

		int index=i;
		//m_pListCtrlInfo->SetItemText(index,i++,);	//account name;
		m_pListCtrlInfo->SetItemText(index,j++,cfg.GetPlatformNameFromCfg().c_str());	//platform name;
		m_pListCtrlInfo->SetItemText(index,j++,buf);	//serverId
		m_pListCtrlInfo->SetCheck(i,pUserConfig->IsChosenToStartFromCfg());
		++i;
		++it;
	}
	
}


void CGameBotDlg::UpdateAccountInfoToList(CAccountInfo *pInfo)	//
{
	TCHAR buf[MAX_PATH];
	CPlatformConfig cfg;
	int i=0;
	//ASSERT(pInfo->GetIndex()==-1);
	_stprintf(buf,_T("%d"),pInfo->GetServerId());

	cfg.SetPlatformId(pInfo->GetPlatformIndex());

	int index=pInfo->GetIndex();
	m_pListCtrlInfo->SetItemText(index,i++,pInfo->GetAccountName().c_str());	//account name;
	m_pListCtrlInfo->SetItemText(index,i++,cfg.GetPlatformNameFromCfg().c_str());	//platform name;
	m_pListCtrlInfo->SetItemText(index,i++,buf);	//serverId
	
}


void CGameBotDlg::AddAccountInfoToList(CAccountInfo *pInfo)
{
	TCHAR buf[MAX_PATH];
	CPlatformConfig cfg;
	CGameConfig gameCfg(STRING(_T("")),false);;
	int i=0;
	//ASSERT(pInfo->GetIndex()!=-1);
	int count=m_pListCtrlInfo->GetItemCount();
	pInfo->SetIndex(count);	//new index
	cfg.SetPlatformId(pInfo->GetPlatformIndex());

	int index=m_pListCtrlInfo->InsertItem(count,0);

	m_pListCtrlInfo->SetItemText(index,i++,pInfo->GetAccountName().c_str());	//account name;

	m_pListCtrlInfo->SetItemText(index,i++,cfg.GetPlatformNameFromCfg().c_str());	//platform name;
	_stprintf(buf,_T("%d"),pInfo->GetServerId());
	m_pListCtrlInfo->SetItemText(index,i++,buf);	//serverId

	CPlayer *pPlayer=new CPlayer;
		//pPlayer->ReadyForPlaying();
	pPlayer->SetAccountName(pInfo->GetAccountName());
	pPlayer->SetPlayerIndex(index);
	m_playerList.push_back(pPlayer);
	
	m_pListCtrlInfo->SetItemData(index,(DWORD)pPlayer);
}


void CGameBotDlg::DeleteAccountInfoFromList(int index)
{
}



void CGameBotDlg::UpdateRoleInfoToList(int index,CClient *pClient)	//���½�ɫ��Ϣ,ְҵ�ȼ�֮��
{
	int count=m_pListCtrlInfo->GetItemCount();
	CString str;
	int i=1;	//1��ʼ�ǽ�ɫ��
	TCHAR buf[MAX_PATH];
	STRING strTmp;
	int mapId=0;
	printf("update role info to list index:%d\n",index);
	CInfoPlayerInfoStatus *pStatus=pClient->GetPlayerStatus();
	CPlayer *pPlayer=NULL;
	if(index>=0 && index<count)
	{
		pPlayer=m_playerList.at(index);
		pPlayer->SetX(pStatus->GetX());
		pPlayer->SetY(pStatus->GetY());
		//ȡ�ôӷ�����ȡ�õ�skillList;
		//role name
		m_pListCtrlInfo->SetItemText(index,i++,pStatus->roleName.c_str());	//

		//job
		_stprintf(buf,_T("%d"),pStatus->job);
		m_pListCtrlInfo->SetItemText(index,i++,buf);

		//level
		_stprintf(buf,_T("%d"),pStatus->level);
		m_pListCtrlInfo->SetItemText(index,i++,buf);	//������Ҫת�ɴ�ʦ���ټ�������


		//asuram
		m_pListCtrlInfo->SetItemText(index,i++,pStatus->asuramName.c_str());	//


		//map name
		strTmp=pStatus->mapName;
		m_pListCtrlInfo->SetItemText(index,i++,strTmp.c_str());

		//(x,y)
		_stprintf(buf,_T("(%d,%d)"),pStatus->GetX(),pStatus->GetY());
		m_pListCtrlInfo->SetItemText(index,i++,buf);
	}
	else
	{
		TRACE(_T("���½�ɫ�����±�:%d����ȷ!\n"),index);
	}
}


void CGameBotDlg::UpdatePlayerConnectInfo(int index,CClient *pClient)	//���½�ɫ������Ϣ
{

}


void CGameBotDlg::InitHelperObjects()	//ʵʼ����ͼ���󣬴��͵���󣬵�λ������Ʒ������б�
{
	CFileHelper::GetInstance();
	CMisc::GetInstance()->SetHwndMain(this->GetSafeHwnd());
	
	CMessageMapList::GetInstance()->InitMessageList();
	CMessageSenderHelper::GetInstance()->SetServer(&m_server);

}


void CGameBotDlg::ClearHelperObjects()	//�ͷ���Դ
{
	CMisc::DeleteInstance();
	CFileHelper::DeleteInstance();
}


void CGameBotDlg::SetTestBtnVisible(bool b)
{
	int cmd=SW_SHOW;
	if(!b)
	{
		cmd=SW_HIDE;
	}
	GetDlgItem(IDC_BTN_CONNECT)->ShowWindow(cmd);
	GetDlgItem(IDC_BTN_TEST)->ShowWindow(cmd);
	GetDlgItem(IDC_BTN_TEST_MISC)->ShowWindow(cmd);
}


void CGameBotDlg::ResizeWindow(int cx,int cy)	//�ѿ�ߵ���һ��
{
	//�Ȳ��Զ�����

// 	int minX=800;
// 	int minY=600;
// 	if(cx<minX || cy <minY)
// 	{
// 		return;
// 	}

	CRect rcBtnTest;
	CButton *pBtn=(CButton*)GetDlgItem(IDC_BTN_TEST);

	pBtn->GetWindowRect(&rcBtnTest);
	CRect rc;
	GetClientRect(&rc);
	rc.top+=rcBtnTest.Height()+16;
	rc.bottom-=7;
	rc.left+=7;
	rc.right-=7;
	m_pListCtrlInfo->MoveWindow(&rc);

}


void CGameBotDlg::OnMinimize()	//��С��������
{
	m_notifyData.cbSize=sizeof(m_notifyData);
	m_notifyData.hIcon=AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_notifyData.hWnd=m_hWnd;
	lstrcpy(m_notifyData.szTip,L"008");
	m_notifyData.uCallbackMessage=WM_CLICK_TRAY;
	m_notifyData.uFlags=NIF_ICON | NIF_MESSAGE | NIF_TIP;
	Shell_NotifyIcon(NIM_ADD,&m_notifyData);
	ShowWindow(SW_HIDE);
}


LRESULT CGameBotDlg::OnClickTray(WPARAM wParam,LPARAM IParam)
{
	if ((IParam == WM_LBUTTONDBLCLK) || (IParam == WM_RBUTTONDOWN))
	{ 
		ModifyStyleEx(0,WS_EX_TOPMOST);
		ShowWindow(SW_SHOW);
	}
	return 0;
}




void CGameBotDlg::OnBnClickedBtnPlayAll()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
// 	STRING path=GetCurrentAppPath()+_T("as.bin");
// 	TCHAR *appName=(TCHAR*)path.c_str();
// 	m_server.SetListCtrl(m_pListCtrlInfo);
// 	m_server.SetExeFullPath(path);
// 	m_server.WakeupToDoTask();
	TCHAR buf[MAX_PATH];
	CDlgProcessList dlg;
	if(dlg.DoModal()==IDOK)
	{
		PROCESS_INFO pinfo=dlg.GetSelectProceeInfo();
		_stprintf(buf,_T("%s%d\\%s"),GetCurrentAppPath().c_str(),g_gameVersion,g_szHookDllName);
		STRING dllPath=buf;//GetCurrentAppPath()+g_szHookDllName;
 		//InjectDllTest(pinfo.pid,dllPath.c_str());//ok
		int curSel=m_pCbInjectType->GetCurSel();
		CInjector *pInjector=m_injectorArray.at(curSel);
		pInjector->SetDllFullPath(buf);
		pInjector->Inject(pinfo.pid);
	}

}


void CGameBotDlg::WriteLogMsg(_GAME_LOG_MSG_ *pMsg)
{
	m_dlgShowLog.WriteLogFile(pMsg->accountName.c_str(),pMsg->msgBuf);	
}


void CGameBotDlg::UpdateCurrentOperation(int index,CClient *pClient)	//�ݶ�Ϊtchar*
{
	int subIndex=11;
	//int index=index;
	m_pListCtrlInfo->SetItemText(index,subIndex,pClient->GetTaskStatus().c_str());
}


void CGameBotDlg::SendOperation(_OPERATION_MSG_* pOperation)
{
	int index=pOperation->playerIndex;
	CPlayer *p=m_playerList.at(index);
	CClient *pClient=p->GetClient();
	int protocolId=pOperation->protocolId;
	CMessageSenderHelper::GetInstance()->SendDoGameOperationReq(index,protocolId,pOperation->bytesIntLength,pOperation->szMsg);
}


BOOL CGameBotDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//HWND hwnd=pCopyDataStruct->dwData;	//��Ϊ�±�
	int len=pCopyDataStruct->cbData;
	char *data=(char*)pCopyDataStruct->lpData;
	HWND hClient=(HWND)pCopyDataStruct->dwData;	//dwDataװ�ͻ���hwnd
	m_hWndTest=hClient;
	TCHAR szWindow[MAX_PATH];
	::GetWindowText(hClient,szWindow,MAX_PATH-1);
	TRACE_OUTPUT(_T("�Է����ھ��:0x%x�����ڱ���:%s\n"),hClient,szWindow);
// 	m_server.CopyMsgToStreamRead(hClient,data,len);
// 	m_server.WakeupToHandleMessage();
	m_server.DecodeMessage(hClient,data,len);
	return CDialog::OnCopyData(pWnd, pCopyDataStruct);
}

void CGameBotDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	if(IsInit())
	{
		ResizeWindow(cx,cy);
	}
	// TODO: �ڴ˴������Ϣ����������
}


void CGameBotDlg::OnBnClickedBtnRepairCfgFile()
{


}

void CGameBotDlg::ChangeToBasicTheme()
{
	
}


void CGameBotDlg::ChangeDisplaySolution(int width,int height)
{
	
}


void CGameBotDlg::TryToRepairConfigInInit()	//��ʼ��ʱ�����޸��ļ�,��Ҫ�Ǳ������ļ�û���¼���
{
	

}


void CGameBotDlg::OnNMClickListInfo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
// 	CGameConfig gameCfg;
	CUserConfig *pUserConfig=NULL;
	DWORD dwPos = GetMessagePos();
	CPoint point( LOWORD(dwPos), HIWORD(dwPos) );

	m_pListCtrlInfo->ScreenToClient(&point);
	UINT nFlag = 0;
	int index=m_pListCtrlInfo->HitTest(point, &nFlag);
	if(-1 != index )
	{
		if(nFlag == LVHT_ONITEMSTATEICON)
		{
		}
	}

	*pResult = 0;
}



void CGameBotDlg::InitToolObjects()	//������
{
	if(!m_pInjector)
	{
// 		m_dllPath=g_szHookDllName;
// 		m_pInjector=new CInjectorRemoteThead();
	}
// 	m_dllPath=g_szHookDllName;

	CInjector *pInjector=new CInjectorRemoteThead();
	m_injectorArray.push_back(pInjector);

}


void CGameBotDlg::DeleteToolObjects()
{
	SAFE_DELETE_POINTER(m_pInjector);
	vector<CInjector*>::iterator it=m_injectorArray.begin();
	while(it != m_injectorArray.end())
	{
		CInjector *pInject=*it;
		SAFE_DELETE_POINTER(pInject);
		++it;
	}
}



void CGameBotDlg::OnBnClickedBtnConnect()	//��ʼ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int count=m_pListCtrlInfo->GetItemCount();
	for(int i=0;i<count;++i)
	{
		BOOL bClickToCheck=m_pListCtrlInfo->GetCheck(i);	//�����Ƿ������ģ���һ�����޵��У��ȵڶ������е��ޣ��������ȡ��check�ǵ��ǰ��״̬
		if(bClickToCheck)
			CMessageSenderHelper::GetInstance()->SendControlClientReq(i,false);

	}

}


void CGameBotDlg::OnBnClickedBtnTestMisc()	//��ͣ
{

}

void CGameBotDlg::OnBnClickedBtnClickMe()
{
	STRING title=_T("����Ϸ�汾˵��");
	CDlgShowReadMe dlg(title);
	dlg.DoModal();
}

void CGameBotDlg::OnCbnSelchangeCbGameVersion()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int curSel=m_pCbGameVersion->GetCurSel();
	g_gameVersion=g_gameVersionValueArray[curSel];
}


void CGameBotDlg::RegisterGlobalHotKey()
{
	RegisterGlobalHotKeyInternal(true);
	RegisterGlobalHotKeyInternal(false);
}


void CGameBotDlg::RegisterGlobalHotKeyInternal(bool bStart)	//ע��ȫ���ȼ�
{
	
	
}




void CGameBotDlg::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	if (nHotKeyId == ID_HOT_KEY1) //start
	{
		OnBnClickedBtnConnect();
		//MessageBox(_T("Ctrl + Alt + A pressed"), _T("message"), MB_OK);
	}
	if (nHotKeyId == ID_HOT_KEY2) 
	{//stop
		OnBnClickedBtnTestMisc();
		//MessageBox(_T("Ctrl + Alt + a pressed"), _T("message"), MB_OK);
	}

	CDialog::OnHotKey(nHotKeyId, nKey1, nKey2);
}
void CGameBotDlg::OnCbnSelchangeCbInjectType()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��������д��¼ע������
}

void CGameBotDlg::OnBnClickedBtnAccerlateSetting()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
}



void CGameBotDlg::TestWrite()
{
	vector<CPlayer*>::iterator it=m_playerList.begin();
	while(it != m_playerList.end())
	{
		CPlayer *player=*it;
		CGameConfig gameCfg(player->GetAccountName(),false);
		CSkillConfig *pFun=gameCfg.GetSkillConfig();
		CConfigSecretary1 *pFun1=gameCfg.GetConfigSecretary1();
		//pFun->SetSkillSendIntervalToCfg(10);
		pFun1->SetIsAutoCounterStrikeToCfg(false);
		pFun1->SetIsAutoCounterStrikeUsingConfigSkillsToCfg(false);
		pFun1->SetIsUseSelfSkillsWhenSeeOtherPlayerToCfg(true);
		++it;
	}
}


void CGameBotDlg::TestAttachProcess()
{
	TCHAR buf[MAX_PATH];
	CDlgProcessList dlg;
	vector<PROCESS_INFO> &processList=dlg.GetAllProcessInfos();
	vector<PROCESS_INFO>::iterator itProcess=processList.begin();
	vector<CPlayer*>::iterator it=m_playerList.begin();

	while(itProcess != processList.end() && it<m_playerList.end())
	{
		PROCESS_INFO& pinfo=*itProcess;
		if(m_attachProcessMap.find(pinfo.pid)==m_attachProcessMap.end())
		{
			m_attachProcessMap[pinfo.pid]=pinfo.pid;
			_stprintf(buf,_T("%s%d\\%s"),GetCurrentAppPath().c_str(),g_gameVersion,g_szHookDllName);
			STRING dllPath=buf;//GetCurrentAppPath()+g_szHookDllName;
			//InjectDllTest(pinfo.pid,dllPath.c_str());//ok
			int curSel=m_pCbInjectType->GetCurSel();
			CInjector *pInjector=m_injectorArray.at(curSel);
			pInjector->SetDllFullPath(buf);
			pInjector->Inject(pinfo.pid);
		}
		
		++it;
		++itProcess;
	}

}
