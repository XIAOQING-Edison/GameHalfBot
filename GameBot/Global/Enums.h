#ifndef _ENUM_H_
#define _ENUM_H_

enum E_ITEM_GRID_TYPE{
	e_item_grid_type_none=-1,
	e_item_grid_type_equipment=0,	//装锟斤拷锟斤拷目
	e_item_grid_type_bag,		//锟斤拷锟斤拷
	e_item_grid_type_warehose,	//锟街匡拷
	e_item_grid_type_angel_equipment,	//锟斤拷锟斤拷使装锟斤拷
	e_item_gird_type_gem_storage	//锟斤拷石锟街匡拷
};



//锟斤拷位锟斤拷锟斤拷,锟斤拷锟斤拷锟斤拷锟斤拷戏锟叫碉拷锟斤拷锟斤拷
//锟斤拷锟斤拷1000-2000之锟斤拷锟揭诧拷锟斤拷锟酵锟斤拷
//锟斤拷锟劫伙拷锟斤拷也锟斤拷锟斤拷锟斤拷通锟斤拷
//2000-3000也锟斤拷锟斤拷boss
/*
wildBoss = 2001,
goldBoss = 2002,
build = 3000,
KaLiMa =2206
*/
enum E_UNIT_TYPE{
	e_unit_type2_normal = 1000,//锟斤拷通锟斤拷锟斤拷
	e_unit_type2_boss = 2001,	//boss
	e_unit_type2_build = 3000,	//锟斤拷锟斤拷
	e_unit_type2_wolf= 4001,	//锟角魂副锟斤拷锟斤拷锟斤拷锟酵锟斤拷
};


//锟斤拷位锟斤拷锟斤拷1锟斤拷锟斤拷锟斤拷锟斤拷unit_type1
enum E_UNIT_TYPE2
{
	e_unit_type1_person=1,//锟斤拷锟
	e_unit_type1_pet=2,	//锟劫伙拷锟斤拷
	e_unit_type1_mars=3,	//英锟斤拷
	e_unit_type1_monster=4,	//锟斤拷锟斤，BOSS锟侥伙拷锟斤拷要锟斤拷锟叫讹拷锟斤拷锟絫ype1,锟劫斤拷锟絫ype2锟斤拷同时锟饺斤拷锟角凤拷锟斤拷BOSS锟斤拷英
	e_unit_type1_npc=5,	//npc
	e_unit_type1_guard=6,//锟斤拷锟斤拷
	e_unit_type1_drop=7,	//锟斤拷锟斤拷锟斤拷锟狡
	e_unit_type1_trap=8,	//锟斤拷锟斤拷
	e_unit_type1_deco=9,	//锟斤拷锟斤拷装锟斤拷
	e_unit_type1_follower=11	//锟斤拷锟?	
};



enum E_MISSION_STATE 
{
	e_mission_state_none=0,	//锟斤拷锟斤拷锟斤拷状态,
	//e_mission_state_finish,
	e_mission_state_can_accept,	//锟缴斤拷锟斤拷
	e_mission_state_uncomplete,	//未锟斤拷桑锟斤拷锟斤拷呀锟斤拷锟
	e_mission_state_complete,	//锟斤拷锟斤拷桑锟斤拷锟轿达拷峤

};


//TASK锟斤拷锟斤拷锟斤拷锟节筹拷锟斤拷锟斤拷锟斤拷锟斤拷锟叫碉拷锟斤拷锟斤拷,锟斤拷锟斤拷锟斤拷戏锟斤拷锟斤拷锟斤拷锟较碉拷锟斤拷锟斤拷
//未锟斤拷锟,
//锟饺达拷锟结交锟斤拷锟斤拷锟结交锟斤拷锟斤拷锟斤拷
//锟斤拷桑锟斤拷锟斤拷删锟斤拷task
enum E_TASK_STATE
{
	//e_task_state_none=0,
	e_task_state_unfinished=0,
	e_task_state_wait_for_commit,
	e_task_state_finished
};



enum E_REVIVE_TYPE
{	
	e_revive_from_death_place=0,	//锟斤拷锟斤拷锟截点复锟筋，锟斤拷时锟斤拷锟斤拷
	e_revive_from_main_town	//锟截城革拷锟斤拷
};



//锟斤拷陆平台,锟叫很讹拷锟斤拷时锟饺硷拷锟斤拷锟斤拷锟
enum E_LOGIN_PLATFORM{
	e_login_platform_none=-1,
	e_login_platform_xy=0
};


//锟斤拷戏锟斤拷慕锟斤拷锟阶刺
enum E_EMERGENCY_LEVEL{
	e_emergency_level_none=0,	//锟角斤拷锟斤拷状态
	e_emergency_level_emergency	//锟斤拷锟斤拷状态锟斤拷要锟接碉拷前锟斤拷锟斤拷锟斤拷锟叫断筹拷锟斤拷锟饺达拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷
};

//锟斤拷戏锟斤拷牟锟斤拷锟斤拷锟斤拷亟锟斤拷锟斤拷锟斤拷锟斤拷锟狡讹拷锟斤拷目锟侥地达拷郑锟斤拷鹊龋锟斤拷岱碉拷锟揭伙拷锟斤拷锟斤拷锟斤拷锟斤拷锟捷斤拷锟斤拷锟斤拷锟斤拷锟接︼拷锟斤拷锟
enum E_OPERATION_RESULT{
	e_operation_result_none=0,
	e_operation_result_finished,	//锟斤拷锟斤拷锟斤拷锟斤拷
	e_operation_result_error,	//锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟
	e_operation_result_interrupt,	//锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷,锟斤拷锟斤拷锟斤拷执锟叫革拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷
	e_operation_result_quit	//锟斤拷戏锟剿筹拷
};


//锟斤拷戏锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷状态锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷状态锟斤拷锟叫讹拷状态锟斤拷锟斤拷锟斤拷锟
enum E_TASK_RUNNING_STATUS
{
	e_task_running_status_end=0,		//锟斤拷锟斤拷锟斤拷锟斤拷
	e_task_running_status_interrupt,	//锟叫讹拷状态锟斤拷锟叫革拷锟斤拷锟斤拷锟斤拷锟斤拷要锟斤拷锟
	e_task_running_status_finished,		//锟斤拷锟斤拷锟,锟斤拷锟斤拷要锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟
	e_task_running_status_error		//锟斤拷锟街达拷锟斤拷
};



//锟斤拷锟斤拷锟斤拷锟酵ｏ拷
enum E_MONSTER_TYPE
{	
	e_monster_type_none=0,	//锟角癸拷锟斤拷锟斤拷锟斤拷
	e_monster_type_normal=1,//锟斤拷通锟斤拷
	e_monster_type_elite,	//锟斤拷英
	e_monster_type_boss,	//boss
};


//锟斤拷锟竭达拷锟斤拷锟斤拷锟斤拷
enum E_DISCONNECT_ERROR_REASON{
	e_disconnect_no_error=-1,	//锟斤拷示没锟叫达拷锟斤拷
	e_disconnect_by_server=0,
	e_disconnect_by_another_login,	//锟绞猴拷锟节别处碉拷陆
	e_disconnect_by_local_error		//锟斤拷锟斤拷锟侥达拷锟斤拷
};


//cmd锟斤拷锟斤拷锟斤拷锟斤拷:--------------
enum E_CMD_OP
{
	e_cmd_heartbeat_req=0x1,	//锟酵伙拷锟斤拷锟斤拷锟斤拷锟剿凤拷锟酵碉拷锟斤拷锟斤拷
	e_cmd_heartbeat_res=0x2,	//锟斤拷锟斤拷锟斤拷锟酵伙拷锟剿回碉拷锟斤拷锟斤拷
	e_cmd_login_req=0x3,	//锟酵伙拷锟斤拷锟斤拷锟斤拷锟剿凤拷锟酵碉拷陆锟斤拷锟斤拷,锟斤拷锟斤拷锟叫锟斤拷一些锟斤拷锟斤拷锟斤拷证锟酵伙拷锟斤拷锟角凤拷
	e_cmd_login_res=0x4,	//锟斤拷锟斤拷锟斤拷锟斤拷突锟斤拷朔锟斤拷偷锟铰斤拷锟接,锟斤拷锟捷伙拷应锟斤拷code锟斤拷锟叫讹拷锟角凤拷锟斤拷缘锟铰
	e_cmd_client_status=0x5,	//锟酵伙拷锟斤拷锟斤拷锟斤拷锟剿憋拷锟斤拷状态,锟斤拷锟竭伙拷锟斤拷锟斤拷(锟斤拷锟斤拷锟斤拷戏锟斤拷锟斤拷状态锟斤拷锟斤拷)
	e_cmd_client_player_info_status=0x6,	//锟酵伙拷锟斤拷锟斤拷锟斤拷锟剿憋拷锟斤拷锟斤拷锟阶刺(平台锟斤拷锟斤拷锟斤拷锟斤拷ID锟斤拷锟斤拷锟街ｏ拷锟斤拷图锟斤拷锟斤拷战锟斤拷锟斤拷锟斤拷)
	e_cmd_client_player_task_status=0x7,	//锟酵伙拷锟斤拷锟斤拷锟斤拷锟剿憋拷锟斤拷锟斤拷锟斤拷状态(刷锟街ｏ拷锟斤拷锟斤拷锟斤拷)

	e_cmd_info_player_info_status=0x8,	//info锟洁不锟斤拷要直锟接斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟轿锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟
	e_cmd_write_text=0x9,	//写锟侥硷拷锟斤拷锟斤拷
	e_cmd_client_report_detail=0xa,	//锟较憋拷一些锟斤拷锟斤拷锟斤拷息,锟斤拷时

	//锟叫硷拷锟街革拷锟斤拷锟斤拷锟斤拷...
	e_cmd_client_quit_req=0x10,	//锟酵伙拷锟斤拷锟斤拷锟斤拷锟剿凤拷锟斤拷锟剿筹拷锟斤拷锟斤拷
	e_cmd_client_quit_res=0x11,	//锟斤拷锟斤拷锟斤拷锟酵伙拷锟剿凤拷锟斤拷锟剿筹拷锟斤拷应
	e_cmd_client_minimize=0x12,	//锟斤拷小锟斤拷
	e_cmd_client_restore=0x13,	//锟斤拷原
	e_cmd_control_client_req=0x14,	//锟皆客伙拷锟剿斤拷锟叫匡拷锟斤拷
	e_cmd_client_do_game_operation_req=0x15,	//锟斤拷锟斤拷戏锟斤拷慕锟缴锟斤拷锟叫诧拷锟斤拷

	//锟叫硷拷锟街革拷锟斤拷锟斤拷锟斤拷
	e_cmd_force_quit_res=0x20	//锟斤拷锟斤拷朔锟斤拷透锟斤拷突锟斤拷锟角匡拷锟斤拷顺锟
};


enum E_PLAYER_STATE{
	e_player_state_null=0,	//什么状态锟斤拷锟斤拷锟斤拷
	e_player_state_logined=1,	//锟窖碉拷陆
	e_player_state_role_chosen,	//锟斤拷选锟斤拷色
	e_player_state_in_game_already,	//锟窖斤拷锟斤拷锟斤拷戏
	e_player_state_login_need_invite_code,	//锟斤拷要锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷芙锟斤拷锟较

	e_player_state_disconnected,	//锟斤拷锟斤拷
	e_player_state_quit		//锟剿筹拷
};

enum E_ATTCK_TYPE
{
	e_attack_normal_monster=0,	//锟斤拷通锟斤拷
	e_attack_boss,//boss
	e_attack_other_player//锟斤拷锟
};


enum E_INSTANCE_ZONE_STATE{
	//执锟叫筹拷始锟斤拷锟斤拷锟斤拷  INIT(1),
	//锟饺达拷锟斤拷医锟斤拷锟 WAITING(2),
	//锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷 RUNNING(3),
	//锟截憋拷 CLOSING(4),
	//锟斤拷止  END(5);
	e_instance_state_none=0,//平时锟斤拷示没锟斤拷锟诫副锟斤拷
	e_instance_state_init=1,
	e_instance_state_waiting,
	e_instance_state_running,
	e_instance_state_closing,
	e_instance_state_end
};


//锟斤拷戏锟斤拷暮锟斤拷锟斤拷锟斤拷锟
enum ChatChannelEnum {
	WORLD = 2050001,
	CROSS_REALM,
	GUILD,
	TEAM,
	LOCAL,
	PRIVATE,
	SYSTEM,
	RECRUIT,
	UNION = 2050011
};

//锟斤拷锟酵碉拷锟斤拷锟斤拷锟斤拷时锟斤拷写锟斤拷锟斤拷锟斤拷锟斤拷
enum E_WRITE_DATA_TYPE
{
	e_write_data_type_log=0	//锟斤拷时只写log
};

#endif