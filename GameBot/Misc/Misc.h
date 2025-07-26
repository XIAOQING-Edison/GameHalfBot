#pragma once

// #include "../Util/MapSpriteList.h"
// #include "../Util/SkillList.h"	//skill list
// 
// 
// #include "../Protocol/InfoSprite.h"
// #include "../Protocol/InfoSkill.h"	//parse skill;
// 
// 
// #include "../Protocol/InfoItem.h"
// #include "../ItemGrid/Item.h"
#include "../Msg.h"

class CMisc
{
public:
	CMisc(void);
	~CMisc(void);

	static bool InitInstance();

	static void DeleteInstance();
	static CMisc *GetInstance();

	void SetHwndMain(HWND hwnd){m_hwndMain=hwnd;}
	HWND GetHwndMain(){return m_hwndMain;}

	bool SendMsgToMainHwnd(UINT msg,WPARAM wParam,LPARAM lParam);

	bool SendWriteLogMsgToMainHwnd(LPARAM lParam);

	bool SendAddAccountInfoToMainHwnd(LPARAM lParam);

	bool SendUpdateAccountInfoToMainHwnd(LPARAM lParam);

	bool SendUpdatePlayerStatusToMainHwnd(LPARAM lParam);

	bool SendConnectInfoToMainHwnd(LPARAM lParam);

	bool SendReportCurrentOperationToMainHwnd(LPARAM lParam);

	bool SendReportMaterialDataToMainHwnd(LPARAM lParam);


	bool SendPopupMsgBox(int msgType,const TCHAR* szMsg);	//发送弹框并使某按钮激活


	bool SendDataToOtherWindow(HWND hClient,COPYDATASTRUCT *pCopyStruct);

	bool ChangeThemeOnWin7();	//转成basic

private:
	HWND m_hwndMain;	//主窗口用来处理信息之类
	static CMisc *s_pMisc;
};
