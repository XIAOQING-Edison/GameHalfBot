#ifndef _MSG_H_
#define _MSG_H_

#include "./Global/public.h"
#define WM_SELF_HANDLE_MSG		WM_USER+401
#define WM_GAME_CONTROL_MSG		WM_USER+402


#define RES_ERROR_CODE_SUCC	0
#define RES_ERROR_CODE_NONE	-1
#define RES_ERROR_CODE_FAILED	-2

enum E_MSG_TYPE{
	e_msg_type_none=-1,	//无状态
	e_msg_type_login_web=0,
	e_msg_type_login_game_server,
	e_msg_type_report_player_status,//更新玩家角色信息,这里是游戏状态
	e_msg_type_connect_info,
	e_msg_type_error_occur,
	e_msg_type_update_sprite_info,	//test,测试怪物数据
	e_msg_type_change_map,	//地图改变了，就把地图数据加载，并且界面上显示
	e_msg_type_update_skill_info,	//test,测试技能数据
	e_msg_type_update_account_info,	//更新account信息到listctrl
	e_msg_type_add_account_info,	//增加account
	e_msg_type_del_account_info,	//删除account
	e_msg_type_write_log,		//写日志
	e_msg_type_report_current_operation,	//当前进行的操作状态,例如XX副本，打怪，采集，挖矿等等
	e_msg_type_do_game_operation,	//游戏中需要手动发送协议
	e_msg_type_report_material_data,	//报告一些材料数据
	e_msg_type_do_trade_task	//启动线程交易操作
};


enum E_POP_UP_MSG_TYPE
{
	e_pop_up_msg_update_server_list=0
};

struct _GAME_LOG_MSG_
{
	STRING accountName;
	TCHAR msgBuf[1024];
	int msgLength;
	E_MSG_TYPE msgType;
	_GAME_LOG_MSG_()
	{
		Init();
	}
	void Init()
	{
		msgLength=0;
		memset(msgBuf,0,sizeof(msgBuf));
		msgType=e_msg_type_none;
	}
	~_GAME_LOG_MSG_()
	{

	}

	void CopyBuf(_GAME_LOG_MSG_ *pLogMsg)
	{
		msgLength=pLogMsg->msgLength;
		accountName=pLogMsg->accountName;
		memcpy(msgBuf,pLogMsg->msgBuf,msgLength);
	}

	void CopyMsg(const TCHAR *pUser,const TCHAR *szMsg)
	{
		accountName=pUser;
		_tcscpy(this->msgBuf,szMsg);
	}
};


struct _OPERATION_MSG_
{
	int playerIndex;
	int bytesIntLength;	//消息的字节长芳
	int protocolId;	//要发送的协议id
	char szMsg[512];

	_OPERATION_MSG_()
	{
		playerIndex=-1;
		bytesIntLength=0;
		protocolId=0;
	}
};


struct _POINTER_INFO_
{
	BYTE *pData;
	int length;
	bool bNeedFree;	//是否需要主动释放
	_POINTER_INFO_()
	{
		pData=NULL;
		length=0;
		bNeedFree=true;	//默认为true
	}
};
#endif