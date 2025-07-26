#pragma once
#include <windows.h>
#include <MMSystem.h>	//for timeGetTime()
#include<WinInet.h>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

#include <tchar.h>

//alt
#include <atlenc.h>

#include "Enums.h"
#include "../Util/ThreadLock.h"

#include "../CrashHelper/BugTrap.h"
//  #include "./CrashHelper/BTMfcWindow.h"
//  #include "./CrashHelper/BTTrace.h"
//  #include "./CrashHelper/BTAtlWindow.h"

#pragma comment(lib,"wininet.lib")
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"Ws2_32.lib")

#ifndef _UNICODE
#define STRING string
#else
#define STRING wstring
#endif

#pragma warning(disable:4996)

//当启用加密时用这个宏
// #define ACTIVE_ENCRYPT

#include "GameVersion.h"	//游戏版本设定
//游戏版本编译总宏开关
// #define _GAME_VERSION_	_TIAN_SHI_ZHI_ZHAN_MOBILE_	//mu1
#define _GAME_VERSION_	_TIAN_SHI_ZHI_ZHAN_PC_	//mu1 pc版
// #define _GAME_VERSION_	_YONG_HENG_LIAN_MENG_	//mu2
// #define _GAME_VERSION_	_TIAN_SHI_SHEN_YU_
// #define _GAME_VERSION_	_YONG_HENG_ZHI_DIAN_	//mu3


extern const TCHAR *g_szMainUrl;


using namespace std;
#define SAFE_INTERNET_CLOSE(h)	if(h){ ::InternetCloseHandle(h);h=NULL;}
#define SAFE_DELETE_POINTER(p)	if(p){delete p;p=NULL;}
#define SAFE_DELETE_ARRAY(p) if(p){delete[] p;p=NULL;}
#define SAFE_CLOSE_HANDLE(h)	if(h){::CloseHandle(h);h=NULL;}
#define SAFE_CLOSE_SOCKET(h) if(h!=INVALID_SOCKET){closesocket(h);h=INVALID_SOCKET;}


#define DEF_HTTP_PORT	80
#define DEF_USER_AGENT	_T("User-Agent: Mozilla/4.0 (compatible;Indy Library)\r\n")
#define DEF_HOST_NAME	_T("")
#define DEF_ACCEPT		_T("Accept: text/html, */*\r\n")
#define DEF_ACCEPT_LANGUAGE	_T("zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3\r\n")
#define DEF_ACCEPT_ENCODING	_T("gzip, deflate\r\n")
#define DEF_ACCEPT_CONNECTION	_T("keep-alive\r\n")
#define DEF_CONTECT_TYPE	_T("Content-Type: application/x-www-form-urlencoded\r\n")
#define DEF_HTTP_VERSION	_T("HTTP/1.1")
#define HTTP_REFEREN		_T("Referer: ")
#define HTTP_HOST			_T("Host: ")
#define CRLF				_T("\r\n")
#define HTTP_COOKIE				_T("Cookie: ")


#define PRINT_ERROR_FUNC_LINE()	printf("%s call lines:%d falied,error 0x%x\n",__FUNCTION__,__LINE__,GetLastError())

#define  MAX_INT32	((DWORD)(~0)>>1)	//0x7fffffff
#define  MAX_UINT32	((DWORD)~0)	//0xffffffff

#define  MAX_INT64	((UINT64)(~0)>>1)	//0x7fffffffffffffff
#define  MAX_UINT64	((UINT64)~0)	//0xffffffffffffffff

#define  MILLISEOND_DELAY_PER_TIME	50	//延时间隔，毫秒
#define  MILLISECOND_PER_SECOND	1000	//每秒的毫秒数
#define  SECONDS_PER_MINUTE	60
#define  MINUTES_PER_HOUR	60
#define  HOURS_PER_DAY	24


/************************************************************************/
/* 游戏通信息关的定义                                                   */
/************************************************************************/

#define NORMAL_MAX_WAIT_TIME	300	//设定为500ms等待时间
#define KILL_BOSS_MAX_WAIT_TIME	60*30*1000	//设定为30分钟,个人BOSS最长时间30分钟
#define KILL_MONSTER_MAX_WAIT_TIME 60*1000	//普通打怪等待为1分钟
#define OTHER_MAX_WAIT_TIME	500	//其它等待时间，待定


#define MAX_BUF_LENGTH	0x10000	//16kb数据接收缓冲
#define MAX_STACK_BUF_LENGTH	0x1000	//4kb栈

/************************************************************************/
/*                    global vars                                       */
/************************************************************************/
//////////////////////////////////////////////////////////////////////////
extern const TCHAR *g_szDefSectionName;
extern const TCHAR *g_szMainGameCfgName;

extern const TCHAR *g_szSharedMemoryName;
extern const int g_maxCount;	//多开数

class CThreadLock;
extern CThreadLock *g_pThreadRecvLock;
extern CThreadLock *g_pThreadSendLock;

extern const TCHAR *g_szHttps;
extern const TCHAR *g_szHttp;

extern const TCHAR *g_szHookDllName;
extern const TCHAR *g_szProxyDllName;

//////////////////////////////////////////////////////////////////////////

/************************************************************************/
/*                  global path											*/
/************************************************************************/
extern const TCHAR *g_szConfigPath;
extern const TCHAR *g_szMapDataPath;
extern int g_gameVersion;	//用来区分游戏版本

extern STRING g_exePath;
extern STRING g_exeName;
//////////////////////////////////////////////////////////////////////////

string UTF8ToGBK(const std::string& strUTF8);
std::string GBKToUTF8(const std::string& strGBK);
wstring GBKToUnicode(const char *lpcszString);
string UnicodeToGBK(const wchar_t *lpwcszWString);
string UnicodeToUTF8(const wchar_t *lpwcszWString);
wstring UTF8ToUnicode(const char *lpcszString);



///////////////////////////////string functions///////////////////////////////////////////

STRING GetCurrentAppPath();	//取得当前EXE运行目录
STRING GetCurrentDllModuleFolderPath();	//取得当前dll运行目录
STRING GetCurrentDllModuleParentPath();	//取得当前DLL的父路径
STRING GetModuleFullPath(HMODULE hMod);	//取得当前模块的全路径

STRING GetModuleFolderPath(HMODULE hMod);//取得当前模块的目录路径

HMODULE GetCurrentModuleHandle();	//取得当前模块基址




//////////////////////////////////////////////////////////////////////////




/////////////////////////////////socket libs init or cleanup/////////////////////////////////////////
bool InitSocketLib();	//初始化sockect库
bool CleanupSocketLib();	//清理socket库


/////////////////////////////////socket lib end//////////////////////////////////////////////////


////////////////////////////////杂项//////////////////////////////////////////

/////////////////////////////////杂项end/////////////////////////////////////


////////////////////////////解析URL//////////////////////////////////////////


bool HostNameToAddress(STRING &hostName,STRING& strAddress);


//////////////////////////////////////////////////////////////////////////
//杂项

void TRACE_OUTPUT(LPCTSTR szFormat, ... );	//自定义的trace

