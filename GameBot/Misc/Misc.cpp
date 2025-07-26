#include "Misc.h"
#include "../Global/public.h"
#include "../Protocol/ProtocolValue.h"
#include <math.h>

#include "../Config/CommentConfig.h"	//for read ini file
#include "../Player.h"

#pragma comment(lib,"winmm.lib")	//for timegettime

CMisc *CMisc::s_pMisc=NULL;


CMisc::CMisc(void)
{
	SetHwndMain(NULL);
}

CMisc::~CMisc(void)
{

}



bool CMisc::InitInstance()
{
	bool ret=true;
	ret=(CMisc::GetInstance()!=NULL);
	return ret;
}

void CMisc::DeleteInstance()
{
	SAFE_DELETE_POINTER(CMisc::s_pMisc);
}


CMisc *CMisc::GetInstance()
{
	if(!CMisc::s_pMisc)
	{
		CMisc::s_pMisc=new CMisc;
	}
	return CMisc::s_pMisc;
}


bool CMisc::SendMsgToMainHwnd(UINT msg,WPARAM wParam,LPARAM lParam)
{
	bool ret=true;

	{
		ret=::SendMessage(GetHwndMain(),msg,wParam,lParam);
	}
	return ret;
}


bool CMisc::SendWriteLogMsgToMainHwnd(LPARAM lParam)
{
	bool ret=SendMsgToMainHwnd(WM_SELF_HANDLE_MSG,e_msg_type_write_log,lParam);
	return ret;
}


bool CMisc::SendAddAccountInfoToMainHwnd(LPARAM lParam)
{
	bool ret=SendMsgToMainHwnd(WM_SELF_HANDLE_MSG,e_msg_type_add_account_info,lParam);
	return ret;

}



bool CMisc::SendUpdateAccountInfoToMainHwnd(LPARAM lParam)
{
	bool ret=SendMsgToMainHwnd(WM_SELF_HANDLE_MSG,e_msg_type_update_account_info,lParam);
	return ret;

}



bool CMisc::SendUpdatePlayerStatusToMainHwnd(LPARAM lParam)
{
	bool ret=SendMsgToMainHwnd(WM_SELF_HANDLE_MSG,e_msg_type_report_player_status,lParam);
	return ret;

}


bool CMisc::SendConnectInfoToMainHwnd(LPARAM lParam)
{
	bool ret=SendMsgToMainHwnd(WM_SELF_HANDLE_MSG,e_msg_type_connect_info,lParam);
	return ret;

}

bool CMisc::SendReportCurrentOperationToMainHwnd(LPARAM lParam)
{
	bool ret=SendMsgToMainHwnd(WM_SELF_HANDLE_MSG,e_msg_type_report_current_operation,lParam);
	return ret;
}

bool CMisc::SendReportMaterialDataToMainHwnd(LPARAM lParam)
{
	bool ret=SendMsgToMainHwnd(WM_SELF_HANDLE_MSG,e_msg_type_report_material_data,lParam);
	return ret;
}




bool CMisc::SendDataToOtherWindow(HWND hClient,COPYDATASTRUCT *pCopyStruct)
{
	bool ret=::SendMessage(hClient,WM_COPYDATA,(WPARAM)GetHwndMain(),(LPARAM)pCopyStruct);
	return ret;
}


bool CMisc::ChangeThemeOnWin7()
{
	bool ret=false;

#ifdef __AFX_H__
	SHELLEXECUTEINFO ShellInfo;

	memset(&ShellInfo, 0, sizeof(ShellInfo));
	ShellInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShellInfo.hwnd = this->GetHwndMain();
	ShellInfo.lpVerb = _T("open");
	ShellInfo.lpFile = _T("rundll32.exe");
	ShellInfo.lpParameters=_T("shell32.dll,Control_RunDLL desk.cpl desk,@Themes /Action:OpenTheme /file:\"C:\\Windows\\Resources\\Ease of Access Themes\\basic.theme\"");
	ShellInfo.nShow = SW_SHOW;
	ShellInfo.fMask = SEE_MASK_NOCLOSEPROCESS;

	BOOL bResult = ShellExecuteEx(&ShellInfo);

	WaitForSingleObject(ShellInfo.hProcess,INFINITE);
	ret=(GetLastError()==0);

#endif
	return ret;
}
