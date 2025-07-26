#ifndef _ENUM_H_
#define _ENUM_H_

//聊天频道
enum E_CHAT_CHANNEL
{
	e_chat_msg_channel_private=0,
	e_chat_msg_channel_near,	//附近
	e_chat_msg_channel_team,	//队伍
	e_chat_msg_channel_banghui,//帮会
	e_chat_msg_channel_world	//世界
};





//登陆平台,有很多暂时先加了这个
enum E_LOGIN_PLATFORM{
	e_login_platform_none=-1,
	e_login_platform_37=0,
	e_login_platform_8090,
	e_login_platform_360,
	e_login_platform_2345,
	e_login_platform_liebao,
	e_login_platform_9211,
	e_login_platform_51,
	e_login_platform_7youxi,
	e_login_platform_iqiyi,
	e_login_platform_douyu,
	e_login_platform_heheyx,
	e_login_platform_keleyx,
	e_login_platform_hemayx,
	e_login_platform_juwan,
	e_login_platform_ku25,
	e_login_platform_ludashi,
	e_login_platform_sogou,
	e_login_platform_swjoy,	//顺网
	e_login_platform_zixia,
	e_login_platform_37tang,
	e_login_platform_yy,
	e_login_platform_qq,
	e_login_platform_7k7k
};



//断线错误类型
enum E_DISCONNECT_ERROR_REASON{
	e_disconnect_no_error=-1,	//表示没有错误
	e_disconnect_by_server=0,
	e_disconnect_by_another_login,	//帐号在别处登陆
	e_disconnect_by_local_error		//本身的错误
};



//cmd类型描述:--------------
enum
{
	e_cmd_heartbeat_req=0x1,	//客户端向服务端发送的心跳
	e_cmd_heartbeat_res=0x2,	//服务端向客户端回的心跳
	e_cmd_login_req=0x3,	//客户端向服务端发送登陆请求,这里可携带一些数据验证客户端是否常
	e_cmd_login_res=0x4,	//服务湍向客户端发送登陆回应,根据回应的code来判定是否可以登陆
	e_cmd_client_status=0x5,	//客户端向服务端报告状态,在线还离线(根据游戏连接状态而定)
	e_cmd_client_player_info_status=0x6,	//客户端向服务端报告玩家状态(平台，服务器ID，名字，地图名，战盟名字)
	e_cmd_client_player_task_status=0x7,	//客户端向服务端报告任务状态(刷怪，副本等)

	e_cmd_info_player_info_status=0x8,	//info类不需要直接解析，在类里读出来，不能作为单独的类解析
	//中间的指令待加入...
	e_cmd_client_quit_req=0x10,	//客户端向服务端发送退出请求
	e_cmd_client_quit_res=0x11,	//服务端向客户端发送退出回应
	e_cmd_client_minimize=0x12,	//最小化
	e_cmd_client_restore=0x13,	//还原

	//中间的指令待加入
	e_cmd_force_quit_res=0x20	//服务端发送给客户端强制退出
};


#endif