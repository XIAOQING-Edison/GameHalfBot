// GongShaBotDlg.cpp : 实现文件
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

///////////////////////////////////下面为真正需要包含的头，上面的头文件需要在以后更改///////////////////////////////////////
#include "./Dlgs/Settings/DlgSettings.h"
#include "./Dlgs/Settings/DlgOtherSetting.h"
#include "./Dlgs/Settings/DlgBossSettings.h"

#include "./Dlgs/Other/DlgProcessList.h"	//进程列表

#include "./Dlgs/Other/DlgHotKeySetting.h"	//热键

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

//test,下面几个为了测试而加的头文件
#include "FunctionHelper/SocketHelper.h"
#include "FunctionHelper/GameLogicHelper.h"
#include "Player.h"

// #define _TEST_	//测试开启标记

#include <locale.h>	//为了TRACE中文

char* g_old_locale=NULL;	//local

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

const int g_platform_info_count=1;
const int g_inject_method_count=3;
const int g_platform_width[]={185,100,80,100
};

//平台名，服务器ID等
TCHAR *g_szListColumnInfoPlatForm[]={_T("模拟器窗口"),_T("模拟器状态"),_T(""),_T(""),
};



const int g_player_info_count=6;
const int g_player_info_width[]={180,80,80,100,100,150,150

};

const char g_gameVersionSupport[]={0,5,10,11,20};	//现时版本

//默认是yong_heng_lian_meng_
int g_gameVersionCount=1;
#if (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_)
// int g_gameVersionCount=1;
const int g_gameVersionValueArray[]={11,11,11,11,5,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
TCHAR *g_szGameVersion[]={_T("天使神谕(永恒之巅")};
#elif (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_)
// int g_gameVersionCount=1;
const int g_gameVersionValueArray[]={10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
TCHAR *g_szGameVersion[]={_T("奇迹2")};
#elif (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_)
const int g_gameVersionValueArray[]={0,0,0,0,0,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
TCHAR *g_szGameVersion[]={_T("奇迹1")};
#elif (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
const int g_gameVersionValueArray[]={5,5,5,5,5,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
TCHAR *g_szGameVersion[]={_T("奇迹1PC")};
#elif (_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_)
const int g_gameVersionValueArray[]={20,20,20,20,20,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
TCHAR *g_szGameVersion[]={_T("神兵奇迹")};
#endif


//玩家属性，包括自身,typeName是从ini查得type值得到的名称
TCHAR *g_szListColumnInfoRoleAttr[]={
	_T("角色名"),_T("职业"),_T("等级"),_T("战盟"),_T("所在地图"),_T("坐标(x,y)")
};
//_T("角色状态"),


#ifdef _M_IX86
// const TCHAR *g_szTitle=_T("Mu助手\t\t      购买:v微15915901852");
const TCHAR *g_szTitle=_T("Mu助手\t\t     购买:扣扣493150845");//test
// const TCHAR *g_szTitle=_T("Mu助手\t\t");//test
#else
const TCHAR *g_szTitle=_T("奇迹手游  极客助手 0.%d版\t\t     交流群:832921609");
// const TCHAR *g_szTitle=_T("奇迹手游  极客助手 0.%d版\t\t");//     交流群:832921609");
#endif

//这里使用postmessage作为发送，不使用前台模式

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

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CGongShaBotDlg 对话框




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


// CGongShaBotDlg 消息处理程序

BOOL CGameBotDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	
#ifdef ACTIVE_ENCRYPT
	m_workerThread.Create();
	TryToRepairConfigInInit();	//test,测试阶段，放在最开始
#endif // ACTIVE_ENCRYPT

	// TODO: 在此添加额外的初始化代码
#ifdef _DEBUG
	g_old_locale = _strdup( setlocale(LC_CTYPE,NULL) );
	setlocale( LC_CTYPE, "chs" );

#endif // _DEBUG

#ifdef _TEST_
	CButton *pBtn=(CButton*)GetDlgItem(IDC_BTN_REPAIR_CFG_FILE);
	pBtn->ShowWindow(SW_SHOW);
#endif // _TEST_

	SetInit(true);

	m_server.Init();	//这里初始化是因为可以看到输出

#ifdef _M_IX86
	//ChangeToBasicTheme();
#else
	//64位不需要转换主题
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
	int version=31;	//整数版本	
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
		MessageBox(_T("创建内存失败！！！"));
		return FALSE;
	}
	HWND hMain=this->GetSafeHwnd();
	m_pSharedMemory->WriteSharedMemoryByOffset((char*)&hMain,0,sizeof(HWND));	//0号写入句柄，使可以发送消息
	m_pSharedMemory->WriteSharedMemoryByOffset((char*)&g_maxCount,1*sizeof(int),sizeof(int));	//1号写入数量

	this->ShowWindow(SW_SHOW);
	m_dlgLoading.DestroyWindow();

	printf("main hwnd :%d\n",this->GetSafeHwnd());




	RegisterGlobalHotKey();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGameBotDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CGameBotDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CGameBotDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
#ifdef _DEBUG
	setlocale( LC_CTYPE, g_old_locale);
	free(g_old_locale);
#endif // _DEBUG
	

	SAFE_DELETE_POINTER(m_pSharedMemory);

	//m_pInjector->Uninject();	//释放dll
	m_server.SendQuitMessageToClients();//这里先让客户端变成quit状态，先不直接释放dll

	ClearPlayers();

	m_server.ClearClients();	//释放帐号相关对象

	ClearHelperObjects();
	DeleteToolObjects();
	
	CDialog::OnCancel();
	CDialog::OnClose();
}

void CGameBotDlg::OnBnClickedBtnLogin()
{
	// TODO: 在此添加控件通知处理程序代码
	

}

void CGameBotDlg::InitCtrls()
{
	CFont font;
	font.CreatePointFont(90, _T("黑体"));
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
	m_pListCtrlInfo->SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_CHECKBOXES);	//复选框风格
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


void CGameBotDlg::InitCombo()	//初始化infoType
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
	m_pCbGameVersion->SetCurSel(sel);	//test,先默认奇迹2
	m_pCbInjectType->SetCurSel(1);	//默认方式2

}


void CGameBotDlg::InitPlayers()	//初始化帐号的角色,用以登陆
{
	//CPlayerMap::GetInstance();
	ClearPlayers();

	ReadGameConfigFileToList();

}


void CGameBotDlg::ClearPlayers()	//删除以前的帐号信息
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

CPlayer *CGameBotDlg::GetPlayerById(int index)	//取得对应下标的帐号角色指针
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






///////////////////////////更新change map///////////////////////////////////////
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
// 		str=_T("未知地图:id=")+str;
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
	case e_msg_type_report_player_status:	//更新角色状态，暂时只显示领队角色的信息
		UpdateRoleInfoToList(pClient->GetIndex(),pClient);
		//UpdatePlayerConnectInfo(pClient->GetIndex(),pClient);	//更新在线状态在这里
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
	case e_msg_type_report_current_operation:	//当前进行的操作
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
	pSocket->DecodeNormalPlayload(data,sizeof(data));	//解码正常
#endif
#if 0
	INT64 targetId=0;
	int targetX=180;
	int tareetY=125;
	int skillId=12120107;
	CSocketHelper *pSocket=m_playerList.at(0)->GetSocketHelper();
	pSocket->SendUseSkillMessage(skillId,targetId,targetX,tareetY);	//编码正确
#endif
#if 0
	int index=m_pListCtrlInfo->GetSelectionMark();
	bool bSelected=(m_pListCtrlInfo->GetItemState(index,LVIS_SELECTED)==LVIS_SELECTED);
	CDlgUserSettings userDlg;

	if(index != -1 && bSelected)
	{
		STRING accountName=m_pListCtrlInfo->GetItemText(index,0);	//取第0行作为名字
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
	// TODO: 在此添加控件通知处理程序代码

	if(pNMListView->uChanged == LVIF_STATE)
	{
		if(pNMListView->uNewState)
		{
			int nIndex = pNMListView->iItem;
		}

	}


	//这个方法点击时触发多次，暂不使用
// 	LPNMITEMACTIVATE   pNMLV   =   (LPNMITEMACTIVATE)pNMHDR;
// 	CString str;
// 	if((pNMLV->uOldState & INDEXTOSTATEIMAGEMASK(1)) /* old state : unchecked */  && (pNMLV->uNewState & INDEXTOSTATEIMAGEMASK(2)) /* new state : checked */)  
// 	{  
// 		str.Format(_T("Item（行） %d subItem（列） %d is checked\n"), pNMLV->iItem,pNMLV->iSubItem);
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
	// TODO: 在此添加控件通知处理程序代码

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
	//test,有未完成的功能，菜单先去掉
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

	accountName=m_playerList.at(index)->GetAccountName();	//取第0行作为名字
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


void CGameBotDlg::ReadGameConfigFileToList()	//读取INI里的字段到LISTCTRL
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
		m_pListCtrlInfo->SetItemText(i,j++,_T(""));	//这里显示角色名字,登进游戏才有
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



void CGameBotDlg::UpdateRoleInfoToList(int index,CClient *pClient)	//更新角色信息,职业等级之类
{
	int count=m_pListCtrlInfo->GetItemCount();
	CString str;
	int i=1;	//1开始是角色名
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
		//取得从服务器取得的skillList;
		//role name
		m_pListCtrlInfo->SetItemText(index,i++,pStatus->roleName.c_str());	//

		//job
		_stprintf(buf,_T("%d"),pStatus->job);
		m_pListCtrlInfo->SetItemText(index,i++,buf);

		//level
		_stprintf(buf,_T("%d"),pStatus->level);
		m_pListCtrlInfo->SetItemText(index,i++,buf);	//这里需要转成大师多少级或其它


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
		TRACE(_T("更新角色索引下标:%d不正确!\n"),index);
	}
}


void CGameBotDlg::UpdatePlayerConnectInfo(int index,CClient *pClient)	//更新角色在线信息
{

}


void CGameBotDlg::InitHelperObjects()	//实始化地图对象，传送点对象，单位对象，物品对象等列表
{
	CFileHelper::GetInstance();
	CMisc::GetInstance()->SetHwndMain(this->GetSafeHwnd());
	
	CMessageMapList::GetInstance()->InitMessageList();
	CMessageSenderHelper::GetInstance()->SetServer(&m_server);

}


void CGameBotDlg::ClearHelperObjects()	//释放资源
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


void CGameBotDlg::ResizeWindow(int cx,int cy)	//把宽高调整一下
{
	//先不自动调整

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


void CGameBotDlg::OnMinimize()	//最小化到托盘
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
	// TODO: 在此添加控件通知处理程序代码
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


void CGameBotDlg::UpdateCurrentOperation(int index,CClient *pClient)	//暂定为tchar*
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//HWND hwnd=pCopyDataStruct->dwData;	//作为下标
	int len=pCopyDataStruct->cbData;
	char *data=(char*)pCopyDataStruct->lpData;
	HWND hClient=(HWND)pCopyDataStruct->dwData;	//dwData装客户的hwnd
	m_hWndTest=hClient;
	TCHAR szWindow[MAX_PATH];
	::GetWindowText(hClient,szWindow,MAX_PATH-1);
	TRACE_OUTPUT(_T("对方窗口句柄:0x%x，窗口标题:%s\n"),hClient,szWindow);
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
	// TODO: 在此处添加消息处理程序代码
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


void CGameBotDlg::TryToRepairConfigInInit()	//初始化时尝试修复文件,主要是崩溃后文件没重新加密
{
	

}


void CGameBotDlg::OnNMClickListInfo(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
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



void CGameBotDlg::InitToolObjects()	//工具类
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



void CGameBotDlg::OnBnClickedBtnConnect()	//开始
{
	// TODO: 在此添加控件通知处理程序代码
	int count=m_pListCtrlInfo->GetItemCount();
	for(int i=0;i<count;++i)
	{
		BOOL bClickToCheck=m_pListCtrlInfo->GetCheck(i);	//这里是反过来的，点一次是无到有，先第二次是有到无，但这里获取的check是点击前的状态
		if(bClickToCheck)
			CMessageSenderHelper::GetInstance()->SendControlClientReq(i,false);

	}

}


void CGameBotDlg::OnBnClickedBtnTestMisc()	//暂停
{

}

void CGameBotDlg::OnBnClickedBtnClickMe()
{
	STRING title=_T("各游戏版本说明");
	CDlgShowReadMe dlg(title);
	dlg.DoModal();
}

void CGameBotDlg::OnCbnSelchangeCbGameVersion()
{
	// TODO: 在此添加控件通知处理程序代码
	int curSel=m_pCbGameVersion->GetCurSel();
	g_gameVersion=g_gameVersionValueArray[curSel];
}


void CGameBotDlg::RegisterGlobalHotKey()
{
	RegisterGlobalHotKeyInternal(true);
	RegisterGlobalHotKeyInternal(false);
}


void CGameBotDlg::RegisterGlobalHotKeyInternal(bool bStart)	//注册全局热键
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
	// TODO: 在此添加控件通知处理程序代码
	//可在这里写记录注入类型
}

void CGameBotDlg::OnBnClickedBtnAccerlateSetting()
{
	// TODO: 在此添加控件通知处理程序代码
	
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
