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

//�����ü���ʱ�������
// #define ACTIVE_ENCRYPT

#include "GameVersion.h"	//��Ϸ�汾�趨
//��Ϸ�汾�����ܺ꿪��
// #define _GAME_VERSION_	_TIAN_SHI_ZHI_ZHAN_MOBILE_	//mu1
#define _GAME_VERSION_	_TIAN_SHI_ZHI_ZHAN_PC_	//mu1 pc��
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

#define  MILLISEOND_DELAY_PER_TIME	50	//��ʱ���������
#define  MILLISECOND_PER_SECOND	1000	//ÿ��ĺ�����
#define  SECONDS_PER_MINUTE	60
#define  MINUTES_PER_HOUR	60
#define  HOURS_PER_DAY	24


/************************************************************************/
/* ��Ϸͨ��Ϣ�صĶ���                                                   */
/************************************************************************/

#define NORMAL_MAX_WAIT_TIME	300	//�趨Ϊ500ms�ȴ�ʱ��
#define KILL_BOSS_MAX_WAIT_TIME	60*30*1000	//�趨Ϊ30����,����BOSS�ʱ��30����
#define KILL_MONSTER_MAX_WAIT_TIME 60*1000	//��ͨ��ֵȴ�Ϊ1����
#define OTHER_MAX_WAIT_TIME	500	//�����ȴ�ʱ�䣬����


#define MAX_BUF_LENGTH	0x10000	//16kb���ݽ��ջ���
#define MAX_STACK_BUF_LENGTH	0x1000	//4kbջ

/************************************************************************/
/*                    global vars                                       */
/************************************************************************/
//////////////////////////////////////////////////////////////////////////
extern const TCHAR *g_szDefSectionName;
extern const TCHAR *g_szMainGameCfgName;

extern const TCHAR *g_szSharedMemoryName;
extern const int g_maxCount;	//�࿪��

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
extern int g_gameVersion;	//����������Ϸ�汾

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

STRING GetCurrentAppPath();	//ȡ�õ�ǰEXE����Ŀ¼
STRING GetCurrentDllModuleFolderPath();	//ȡ�õ�ǰdll����Ŀ¼
STRING GetCurrentDllModuleParentPath();	//ȡ�õ�ǰDLL�ĸ�·��
STRING GetModuleFullPath(HMODULE hMod);	//ȡ�õ�ǰģ���ȫ·��

STRING GetModuleFolderPath(HMODULE hMod);//ȡ�õ�ǰģ���Ŀ¼·��

HMODULE GetCurrentModuleHandle();	//ȡ�õ�ǰģ���ַ




//////////////////////////////////////////////////////////////////////////




/////////////////////////////////socket libs init or cleanup/////////////////////////////////////////
bool InitSocketLib();	//��ʼ��sockect��
bool CleanupSocketLib();	//����socket��


/////////////////////////////////socket lib end//////////////////////////////////////////////////


////////////////////////////////����//////////////////////////////////////////

/////////////////////////////////����end/////////////////////////////////////


////////////////////////////����URL//////////////////////////////////////////


bool HostNameToAddress(STRING &hostName,STRING& strAddress);


//////////////////////////////////////////////////////////////////////////
//����

void TRACE_OUTPUT(LPCTSTR szFormat, ... );	//�Զ����trace

