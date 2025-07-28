#ifndef _ENUM_H_
#define _ENUM_H_

// 聊天频道枚举
enum E_CHAT_CHANNEL
{
	e_chat_msg_channel_private=0,	// 私聊频道
	e_chat_msg_channel_near,		// 附近频道
	e_chat_msg_channel_team,		// 队伍频道
	e_chat_msg_channel_banghui,		// 帮会频道
	e_chat_msg_channel_world		// 世界频道
};

// 登录平台枚举，支持多个游戏平台
enum E_LOGIN_PLATFORM{
	e_login_platform_none=-1,		// 无平台
	e_login_platform_37=0,			// 37游戏平台
	e_login_platform_8090,			// 8090游戏平台
	e_login_platform_360,			// 360游戏平台
	e_login_platform_2345,			// 2345游戏平台
	e_login_platform_liebao,		// 猎豹游戏平台
	e_login_platform_9211,			// 9211游戏平台
	e_login_platform_51,			// 51游戏平台
	e_login_platform_7youxi,		// 7游游戏平台
	e_login_platform_iqiyi,			// 爱奇艺游戏平台
	e_login_platform_douyu,			// 斗鱼游戏平台
	e_login_platform_heheyx,		// 和合游戏平台
	e_login_platform_keleyx,		// 可乐游戏平台
	e_login_platform_hemayx,		// 河马游戏平台
	e_login_platform_juwan,			// 聚玩游戏平台
	e_login_platform_ku25,			// 酷25游戏平台
	e_login_platform_ludashi,		// 鲁大师游戏平台
	e_login_platform_sogou,			// 搜狗游戏平台
	e_login_platform_swjoy,			// 顺网游戏平台
	e_login_platform_zixia,			// 紫霞游戏平台
	e_login_platform_37tang,		// 37堂游戏平台
	e_login_platform_yy,			// YY游戏平台
	e_login_platform_qq,			// QQ游戏平台
	e_login_platform_7k7k			// 7K7K游戏平台
};

// 断线错误类型枚举
enum E_DISCONNECT_ERROR_REASON{
	e_disconnect_no_error=-1,		// 表示没有错误
	e_disconnect_by_server=0,		// 服务器主动断开
	e_disconnect_by_another_login,	// 账号在别处登录
	e_disconnect_by_local_error		// 本地错误导致断开
};

// 命令类型描述枚举
enum
{
	e_cmd_heartbeat_req=0x1,			// 客户端向服务端发送的心跳请求
	e_cmd_heartbeat_res=0x2,			// 服务端向客户端回的心跳响应
	e_cmd_login_req=0x3,				// 客户端向服务端发送登录请求，可携带数据验证客户端
	e_cmd_login_res=0x4,				// 服务端向客户端发送登录响应，根据code判定是否可以登录
	e_cmd_client_status=0x5,			// 客户端向服务端报告状态，在线或离线
	e_cmd_client_player_info_status=0x6,	// 客户端向服务端报告玩家状态(平台，服务器ID，名字，地图名，战盟名字)
	e_cmd_client_player_task_status=0x7,	// 客户端向服务端报告任务状态(刷怪，副本等)

	e_cmd_info_player_info_status=0x8,		// info类不需要直接解析，在类里读出来，不能作为单独的类解析
	// 中间的指令待加入...
	e_cmd_client_quit_req=0x10,		// 客户端向服务端发送退出请求
	e_cmd_client_quit_res=0x11,		// 服务端向客户端发送退出响应
	e_cmd_client_minimize=0x12,		// 最小化
	e_cmd_client_restore=0x13,		// 还原

	// 中间的指令待加入
	e_cmd_force_quit_res=0x20		// 服务端发送给客户端强制退出
};

#endif