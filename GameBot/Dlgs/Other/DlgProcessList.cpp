// ./Dlgs/Other/DlgProcessList.cpp : 实现文件
//

#include "../../stdafx.h"
#include "../../GameBot.h"
#include "DlgProcessList.h"
#include <TLHELP32.H>

//模拟器进程名字,依次是雷电，海马，后续再加入
const TCHAR *g_szEmuProcName[]={_T("LdvBoxHeadless.exe"),_T("LdBoxHeadless.exe")_T("MemuHeadless.exe"),_T("Ld9BoxHeadless.exe"),_T("NemuHeadless.exe"),
					_T("NoxVMHandle.exe"),_T("MuMuVMMHeadless.exe"),_T("LEmuHeadless.exe"),_T("Mu.exe")
};


// CDlgProcessList 对话框

IMPLEMENT_DYNAMIC(CDlgProcessList, CDialog)

CDlgProcessList::CDlgProcessList(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgProcessList::IDD, pParent)
{
	m_pidSelect=-1;
	m_bShowEmuOnly=true;	//默认只显示模拟器进程
}

CDlgProcessList::~CDlgProcessList()
{
}

void CDlgProcessList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgProcessList, CDialog)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_REFRESH, &CDlgProcessList::OnBnClickedBtnRefresh)
	ON_BN_CLICKED(IDC_BTN_SEL, &CDlgProcessList::OnBnClickedBtnSel)
END_MESSAGE_MAP()


// CDlgProcessList 消息处理程序

void CDlgProcessList::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialog::OnCancel();
	CDialog::OnClose();
}

BOOL CDlgProcessList::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitCtrls();
	InitListHeader();
	InitFilterMap();
	GetAllProcessList();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDlgProcessList::GetAllProcessList()
{
	if(m_processList.size()>0)
		m_processList.clear();
	if(m_pList->GetItemCount()>0)
		m_pList->DeleteAllItems();



	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	HANDLE hModule;
	PROCESSENTRY32 pe32;
	MODULEENTRY32 me32;
	pe32.dwSize = sizeof( PROCESSENTRY32 );
	me32.dwSize=sizeof(MODULEENTRY32);
	Process32First(hSnapshot, &pe32);  
	do
	{  
		hModule=CreateToolhelp32Snapshot(TH32CS_SNAPMODULE,pe32.th32ProcessID);
		if(Module32First(hModule,&me32))
		{
			PROCESS_INFO pinfo;
			pinfo.pid=me32.th32ProcessID;
			pinfo.szExeName=pe32.szExeFile;

			pinfo.szPath=me32.szExePath;
			if(IsProcNeedToBeShown(pinfo))
			{
				m_processList.push_back(pinfo);
			}
		}

	} 
	while (Process32Next(hSnapshot, &pe32));  
	CloseHandle( hSnapshot );  
	vector<PROCESS_INFO>::iterator it=m_processList.begin();
	int i=0,j;
	CString strPid;
	while(it !=m_processList.end())
	{
		j=0;
		m_pList->InsertItem(i,_T(""));	
		m_pList->SetItemText(i,j++,it->szExeName);
		strPid.Format(_T("%d"),it->pid);
		m_pList->SetItemText(i,j++,strPid);	
		//m_pList->SetItemText(i,j++,it->szDescription);
		m_pList->SetItemText(i,j++,it->szPath);
		m_pList->SetItemData(i,it->pid);
		++i;
		++it;
	}

}


void CDlgProcessList::InitCtrls()
{
	m_pList=(CListCtrl*)GetDlgItem(IDC_LST_PROCESS_LIST);
	LONG lStyle;
	lStyle = GetWindowLong(m_pList->GetSafeHwnd(), GWL_STYLE);
	lStyle |= LVS_REPORT; 
	SetWindowLong(m_pList->GetSafeHwnd(), GWL_STYLE, lStyle);
	DWORD dwStyle = m_pList->GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT; 
	dwStyle |= LVS_EX_GRIDLINES; 
	m_pList->SetExtendedStyle(dwStyle);  
}

void CDlgProcessList::InitListHeader()
{
	int i=0;
	m_pList->InsertColumn(i++,_T("EXE名称"),LVCFMT_CENTER,100);
	m_pList->InsertColumn(i++,_T("进程ID"),LVCFMT_CENTER,50);
	//m_pList->InsertColumn(i++,_T("描述"),LVCFMT_CENTER,150);
	m_pList->InsertColumn(i++,_T("进程路径"),LVCFMT_LEFT,350);

}


PROCESS_INFO CDlgProcessList::GetSelectProceeInfo()
{
	PROCESS_INFO pinfo;
	pinfo.pid=-1;	//invalid
	if(m_pidSelect!=-1)
	{
		vector<PROCESS_INFO>::iterator it=m_processList.begin();
		while(it !=m_processList.end())
		{
			if(it->pid==m_pidSelect)
			{
				pinfo=*it;
			}
			++it;
		}

	}
	return pinfo;
}

void CDlgProcessList::InitFilterMap()
{
	int count=sizeof(g_szEmuProcName)/sizeof(g_szEmuProcName[0]);
	CString strTmp;
	for(int i=0;i<count;++i)
	{
		strTmp=g_szEmuProcName[i];
		strTmp.MakeUpper();
		m_filterStringMap[strTmp]=strTmp;
	}
}

bool CDlgProcessList::IsProcNeedToBeShown(PROCESS_INFO &info)
{
	bool ret=true;
	CString foundExeUpper=info.szExeName.MakeUpper();
	map<CString,CString>::iterator it=m_filterStringMap.find(info.szExeName);
	if(m_bShowEmuOnly)
	{
		if(it == m_filterStringMap.end())
		{
			ret=false;
		}
	}

	return ret;
}


void CDlgProcessList::OnBnClickedBtnRefresh()
{
	// TODO: 在此添加控件通知处理程序代码
	GetAllProcessList();

}

void CDlgProcessList::OnBnClickedBtnSel()
{
	// TODO: 在此添加控件通知处理程序代码
	int index=-1;
	if(m_pList->GetItemCount()>0)
	{
		index = m_pList->GetNextItem(-1, LVNI_ALL|LVNI_SELECTED);
		m_pidSelect=m_pList->GetItemData(index);
	}
	CDialog::OnOK();
}

