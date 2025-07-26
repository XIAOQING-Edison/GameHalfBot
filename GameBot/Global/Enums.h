#ifndef _ENUM_H_
#define _ENUM_H_

enum E_ITEM_GRID_TYPE{
	e_item_grid_type_none=-1,
	e_item_grid_type_equipment=0,	//װ����Ŀ
	e_item_grid_type_bag,		//����
	e_item_grid_type_warehose,	//�ֿ�
	e_item_grid_type_angel_equipment,	//����ʹװ��
	e_item_gird_type_gem_storage	//��ʯ�ֿ�
};



//��λ����,��������Ϸ�е�����
//����1000-2000֮���Ҳ����ͨ��
//���ٻ���Ҳ������ͨ��
//2000-3000Ҳ����boss
/*
wildBoss = 2001,
goldBoss = 2002,
build = 3000,
KaLiMa =2206
*/
enum E_UNIT_TYPE{
	e_unit_type2_normal = 1000,//��ͨ����
	e_unit_type2_boss = 2001,	//boss
	e_unit_type2_build = 3000,	//����
	e_unit_type2_wolf= 4001,	//�ǻ긱�������ͨ��
};


//��λ����1��������unit_type1
enum E_UNIT_TYPE2
{
	e_unit_type1_person=1,//���
	e_unit_type1_pet=2,	//�ٻ���
	e_unit_type1_mars=3,	//Ӣ��
	e_unit_type1_monster=4,	//���BOSS�Ļ���Ҫ���ж����type1,�ٽ��type2��ͬʱ�Ƚ��Ƿ���BOSS��Ӣ
	e_unit_type1_npc=5,	//npc
	e_unit_type1_guard=6,//����
	e_unit_type1_drop=7,	//�������Ʒ
	e_unit_type1_trap=8,	//����
	e_unit_type1_deco=9,	//����װ��
	e_unit_type1_follower=11	//���?	
};



enum E_MISSION_STATE 
{
	e_mission_state_none=0,	//������״̬,
	//e_mission_state_finish,
	e_mission_state_can_accept,	//�ɽ���
	e_mission_state_uncomplete,	//δ��ɣ����ѽ���
	e_mission_state_complete,	//����ɣ���δ�ύ

};


//TASK�������ڳ����������е�����,������Ϸ�������ϵ�����
//δ���,
//�ȴ��ύ�����ύ������
//��ɣ����ɾ��task
enum E_TASK_STATE
{
	//e_task_state_none=0,
	e_task_state_unfinished=0,
	e_task_state_wait_for_commit,
	e_task_state_finished
};



enum E_REVIVE_TYPE
{	
	e_revive_from_death_place=0,	//�����ص㸴���ʱ����
	e_revive_from_main_town	//�سǸ���
};



//��½ƽ̨,�кܶ���ʱ�ȼ������
enum E_LOGIN_PLATFORM{
	e_login_platform_none=-1,
	e_login_platform_xy=0
};


//��Ϸ��Ľ���״̬
enum E_EMERGENCY_LEVEL{
	e_emergency_level_none=0,	//�ǽ���״̬
	e_emergency_level_emergency	//����״̬��Ҫ�ӵ�ǰ�������жϳ����ȴ�������������
};

//��Ϸ��Ĳ������ؽ���������ƶ���Ŀ�ĵش�֣��ȵȣ��᷵��һ����������ݽ��������Ӧ����
enum E_OPERATION_RESULT{
	e_operation_result_none=0,
	e_operation_result_finished,	//��������
	e_operation_result_error,	//�������������������
	e_operation_result_interrupt,	//������������,������ִ�и���������������
	e_operation_result_quit	//��Ϸ�˳�
};


//��Ϸ����������״̬������������״̬���ж�״̬�������
enum E_TASK_RUNNING_STATUS
{
	e_task_running_status_end=0,		//��������
	e_task_running_status_interrupt,	//�ж�״̬���и���������Ҫ���
	e_task_running_status_finished,		//�����,����Ҫ�������������
	e_task_running_status_error		//���ִ���
};



//�������ͣ�
enum E_MONSTER_TYPE
{	
	e_monster_type_none=0,	//�ǹ�������
	e_monster_type_normal=1,//��ͨ��
	e_monster_type_elite,	//��Ӣ
	e_monster_type_boss,	//boss
};


//���ߴ�������
enum E_DISCONNECT_ERROR_REASON{
	e_disconnect_no_error=-1,	//��ʾû�д���
	e_disconnect_by_server=0,
	e_disconnect_by_another_login,	//�ʺ��ڱ𴦵�½
	e_disconnect_by_local_error		//�����Ĵ���
};


//cmd��������:--------------
enum E_CMD_OP
{
	e_cmd_heartbeat_req=0x1,	//�ͻ��������˷��͵�����
	e_cmd_heartbeat_res=0x2,	//�������ͻ��˻ص�����
	e_cmd_login_req=0x3,	//�ͻ��������˷��͵�½����,�����Я��һЩ������֤�ͻ����Ƿ�
	e_cmd_login_res=0x4,	//��������ͻ��˷��͵�½��Ӧ,���ݻ�Ӧ��code���ж��Ƿ���Ե�½
	e_cmd_client_status=0x5,	//�ͻ��������˱���״̬,���߻�����(������Ϸ����״̬����)
	e_cmd_client_player_info_status=0x6,	//�ͻ��������˱������״̬(ƽ̨��������ID�����֣���ͼ����ս������)
	e_cmd_client_player_task_status=0x7,	//�ͻ��������˱�������״̬(ˢ�֣�������)

	e_cmd_info_player_info_status=0x8,	//info�಻��Ҫֱ�ӽ������������������������Ϊ�����������
	e_cmd_write_text=0x9,	//д�ļ�����
	e_cmd_client_report_detail=0xa,	//�ϱ�һЩ������Ϣ,��ʱ

	//�м��ָ�������...
	e_cmd_client_quit_req=0x10,	//�ͻ��������˷����˳�����
	e_cmd_client_quit_res=0x11,	//�������ͻ��˷����˳���Ӧ
	e_cmd_client_minimize=0x12,	//��С��
	e_cmd_client_restore=0x13,	//��ԭ
	e_cmd_control_client_req=0x14,	//�Կͻ��˽��п���
	e_cmd_client_do_game_operation_req=0x15,	//����Ϸ��Ľ�ɫ���в���

	//�м��ָ�������
	e_cmd_force_quit_res=0x20	//����˷��͸��ͻ���ǿ���˳�
};


enum E_PLAYER_STATE{
	e_player_state_null=0,	//ʲô״̬������
	e_player_state_logined=1,	//�ѵ�½
	e_player_state_role_chosen,	//��ѡ��ɫ
	e_player_state_in_game_already,	//�ѽ�����Ϸ
	e_player_state_login_need_invite_code,	//��Ҫ������������ܽ���Ϸ

	e_player_state_disconnected,	//����
	e_player_state_quit		//�˳�
};

enum E_ATTCK_TYPE
{
	e_attack_normal_monster=0,	//��ͨ��
	e_attack_boss,//boss
	e_attack_other_player//���
};


enum E_INSTANCE_ZONE_STATE{
	//ִ�г�ʼ������  INIT(1),
	//�ȴ���ҽ��� WAITING(2),
	//���������� RUNNING(3),
	//�ر� CLOSING(4),
	//��ֹ  END(5);
	e_instance_state_none=0,//ƽʱ��ʾû���븱��
	e_instance_state_init=1,
	e_instance_state_waiting,
	e_instance_state_running,
	e_instance_state_closing,
	e_instance_state_end
};


//��Ϸ��ĺ�������
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

//���͵�������ʱ��д��������
enum E_WRITE_DATA_TYPE
{
	e_write_data_type_log=0	//��ʱֻдlog
};

#endif