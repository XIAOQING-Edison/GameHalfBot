#ifndef _ENUM_H_
#define _ENUM_H_

// 物品格子类型枚举
enum E_ITEM_GRID_TYPE{
	e_item_grid_type_none=-1,			// 无类型
	e_item_grid_type_equipment=0,		// 装备格子
	e_item_grid_type_bag,				// 背包格子
	e_item_grid_type_warehose,			// 仓库格子
	e_item_grid_type_angel_equipment,	// 天使装备格子
	e_item_gird_type_gem_storage		// 宝石仓库格子
};

// 单位类型2，用于区分游戏中的不同单位类型
// 普通怪物在1000-2000之间
// 精英怪物也是普通怪物
// 2000-3000也是boss
/*
wildBoss = 2001,
goldBoss = 2002,
build = 3000,
KaLiMa =2206
*/
enum E_UNIT_TYPE{
	e_unit_type2_normal = 1000,		// 普通怪物
	e_unit_type2_boss = 2001,		// boss怪物
	e_unit_type2_build = 3000,		// 建筑
	e_unit_type2_wolf= 4001,			// 狼魂副本怪物
};

// 单位类型1，用于区分unit_type1
enum E_UNIT_TYPE2
{
	e_unit_type1_person=1,			// 人物
	e_unit_type1_pet=2,				// 宠物
	e_unit_type1_mars=3,			// 英雄
	e_unit_type1_monster=4,			// 怪物，BOSS怪物需要设置type1，精英怪物type1和type2同时设置
	e_unit_type1_npc=5,				// npc
	e_unit_type1_guard=6,			// 守卫
	e_unit_type1_drop=7,			// 掉落物品
	e_unit_type1_trap=8,			// 陷阱
	e_unit_type1_deco=9,			// 装饰物
	e_unit_type1_follower=11		// 跟随者
};

// 任务状态枚举
enum E_MISSION_STATE 
{
	e_mission_state_none=0,			// 无任务状态
	//e_mission_state_finish,
	e_mission_state_can_accept,		// 可以接受
	e_mission_state_uncomplete,		// 未完成，正在做
	e_mission_state_complete,		// 已完成，可以提交
};

// TASK任务状态，用于区分任务的不同阶段，游戏中的任务状态
// 未完成,
// 等待提交，可以提交
// 已完成，删除task
enum E_TASK_STATE
{
	//e_task_state_none=0,
	e_task_state_unfinished=0,		// 未完成
	e_task_state_wait_for_commit,	// 等待提交
	e_task_state_finished			// 已完成
};

// 复活类型枚举
enum E_REVIVE_TYPE
{	
	e_revive_from_death_place=0,	// 原地复活，免费复活
	e_revive_from_main_town		// 主城复活
};

// 登录平台，暂时只加了这个
enum E_LOGIN_PLATFORM{
	e_login_platform_none=-1,		// 无平台
	e_login_platform_xy=0			// 逍遥平台
};

// 游戏紧急状态
enum E_EMERGENCY_LEVEL{
	e_emergency_level_none=0,		// 正常状态
	e_emergency_level_emergency		// 紧急状态，需要中断当前正在做的事情
};

// 游戏操作结果，用于表示游戏操作的结果状态
enum E_OPERATION_RESULT{
	e_operation_result_none=0,		// 无结果
	e_operation_result_finished,		// 操作完成
	e_operation_result_error,		// 操作错误，操作失败
	e_operation_result_interrupt,	// 操作中断，操作被中断，停止执行
	e_operation_result_quit			// 游戏退出
};

// 游戏任务运行状态，用于表示任务的不同运行状态
enum E_TASK_RUNNING_STATUS
{
	e_task_running_status_end=0,		// 任务结束
	e_task_running_status_interrupt,	// 中断状态，中断任务
	e_task_running_status_finished,		// 任务完成，任务要删除
	e_task_running_status_error		// 任务错误
};

// 怪物类型枚举
enum E_MONSTER_TYPE
{	
	e_monster_type_none=0,			// 无怪物类型
	e_monster_type_normal=1,		// 普通怪物
	e_monster_type_elite,			// 精英怪物
	e_monster_type_boss,			// boss怪物
};

// 断线错误类型
enum E_DISCONNECT_ERROR_REASON{
	e_disconnect_no_error=-1,		// 表示没有错误
	e_disconnect_by_server=0,		// 服务器断开
	e_disconnect_by_another_login,	// 账号在别处登录
	e_disconnect_by_local_error		// 本地错误
};

// 命令类型描述
enum E_CMD_OP
{
	e_cmd_heartbeat_req=0x1,			// 客户端向服务端发送的心跳
	e_cmd_heartbeat_res=0x2,			// 服务端向客户端回的心跳
	e_cmd_login_req=0x3,				// 客户端向服务端发送登录请求，可携带一些数据验证客户端
	e_cmd_login_res=0x4,				// 服务端向客户端发送登录回应，根据回应的code来判定是否可以登录
	e_cmd_client_status=0x5,			// 客户端向服务端报告状态，在线或离线
	e_cmd_client_player_info_status=0x6,	// 客户端向服务端报告玩家状态(平台，服务器ID，名字，地图名，战盟名字)
	e_cmd_client_player_task_status=0x7,	// 客户端向服务端报告任务状态(刷怪，副本等)

	e_cmd_info_player_info_status=0x8,		// info类不需要直接解析，在类里读出来，不能作为单独的类解析
	e_cmd_write_text=0x9,				// 写日志
	e_cmd_client_report_detail=0xa,		// 报告一些详细信息，实时

	// 客户端相关命令
	e_cmd_client_quit_req=0x10,		// 客户端向服务端发送退出请求
	e_cmd_client_quit_res=0x11,		// 服务端向客户端发送退出回应
	e_cmd_client_minimize=0x12,		// 最小化
	e_cmd_client_restore=0x13,		// 还原
	e_cmd_control_client_req=0x14,		// 控制客户端请求
	e_cmd_client_do_game_operation_req=0x15,	// 客户端游戏操作请求

	// 服务端相关命令
	e_cmd_force_quit_res=0x20		// 服务端发送给客户端强制退出
};

// 玩家状态枚举
enum E_PLAYER_STATE{
	e_player_state_null=0,				// 无状态
	e_player_state_logined=1,			// 已登录
	e_player_state_role_chosen,			// 已选择角色
	e_player_state_in_game_already,		// 已进入游戏
	e_player_state_login_need_invite_code,	// 登录需要邀请码

	e_player_state_disconnected,		// 断开连接
	e_player_state_quit				// 退出
};

// 攻击类型枚举
enum E_ATTCK_TYPE
{
	e_attack_normal_monster=0,		// 普通怪物
	e_attack_boss,					// boss怪物
	e_attack_other_player			// 其他玩家
};

// 副本区域状态枚举
enum E_INSTANCE_ZONE_STATE{
	// 执行副本开始 INIT(1),
	// 等待进入 WAITING(2),
	// 副本运行 RUNNING(3),
	// 关闭 CLOSING(4),
	// 结束 END(5);
	e_instance_state_none=0,		// 平时表示没有副本
	e_instance_state_init=1,		// 初始化
	e_instance_state_waiting,		// 等待
	e_instance_state_running,		// 运行中
	e_instance_state_closing,		// 关闭中
	e_instance_state_end			// 结束
};

// 聊天频道枚举
enum ChatChannelEnum {
	WORLD = 2050001,				// 世界频道
	CROSS_REALM,					// 跨服频道
	GUILD,							// 公会频道
	TEAM,							// 队伍频道
	LOCAL,							// 本地频道
	PRIVATE,						// 私聊频道
	SYSTEM,							// 系统频道
	RECRUIT,						// 招募频道
	UNION = 2050011					// 联盟频道
};

// 写数据类型枚举
enum E_WRITE_DATA_TYPE
{
	e_write_data_type_log=0		// 暂时只写log
};

#endif