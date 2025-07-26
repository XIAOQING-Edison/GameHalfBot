#ifndef _MISSION_INFO_HELPER_H_
#define _MISSION_INFO_HELPER_H_
#include "../Global/public.h"


//
enum TaskGoalType {
	TaskGoalTypeLearnSkill=99,	//����ʹ�ü���ʯ������ѧ������
	TaskGoalTypeKillMonster = 101,
	TaskGoalTypeAffiliationKill = 103,
	TaskGoalTypeTeamAffiliationKill = 113,
	TaskGoalTypeDialogue = 201,
	TaskGoalTypeUpgrade = 301,
	TaskGoalTypeTransferToDstMap=401,	//���͵�ͼ
	TaskGoalTypeKillMonsterGetItem=601,	//��ֻ�ȡ���ϣ���תְ����
	TaskGoalTypeWearEquipment=721,	//��ĳЩ��װ��һ����֧��
	TaskGoalTypeEnhance=803,	//ǿ��
	TaskGoalTypeRecycleEquipment=1001,		//����װ��
	TaskGoalTypeUpgradeDefence = 3101,		//������Ŀ�����������װ����������

};

enum TaskTargetMonsterType {
	TaskTargetMonsterTypeNone = 0,
	TaskTargetMonsterTypeMonsterId ,
	TaskTargetMonsterTypeMonsterTpye ,
	TaskTargetMonsterTypeRandom ,
	TaskTargetMonsterTypeMapLock ,
	TaskTargetMonsterTypeAutoFight ,
	TaskTargetMonsterTypeRandomAutoFight
};

enum TaskStateType{
	Acceptable =0,
	Accept,
	Completed,
	Submitted,
	Fail,
	GiveUp
};


enum RoleTaskType{
	MainTask =1,
	BranchTask =2,
	UnionTask =3,
	StarTask =4,
	StageTask =5,
	MiracleTask =6,
	MarsTask =8,
	HelpTask =9,
	SkillTask =10,
	TranscriptTask =11,
	TransferTask =12,
	RewardsTask =13
};


//�����ң�����������Ǻ�navi������ص�
enum TaskNavigationType {
	DirectlyOpen = 0,
	FindNpc,
	FindPos,
	ClickEvent,
	ConditionOpen,
	OpenPromptBox,
	JumpPos,
	FindRandomPos
};
struct _MISSION_INFO_
{
	int configId;
	int type;
	int subType;
	int state;	//���գ���ɣ�����xxx
	STRING name;	//��������
	STRING param;
	STRING condition;
	STRING completeCondition;
	int toNpc;
	int fromNpc;
	int transferId;

	_MISSION_INFO_()
	{
		configId=type=0;
		subType=state=0;
		toNpc=fromNpc=0;
		transferId=0;
	}
};


#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_)
static const int g_defGoldType=113;
static const int g_defUpdateType=2;
static const TCHAR* g_szDefGoalTips=_T("��ɱ������Ȯ��");
#elif (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) || (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_) ||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_)
static const int g_defGoldType=603;
static const int g_defUpdateType=2;
static const TCHAR* g_szDefGoalTips=_T("�����ۼƳ�ֵ50Ԫ");

#endif

struct _MISSION_GOAL_INFO_
{
	int goldId;
	int type;
	int updateType;
	STRING strTarget;	//Ŀ�꣬��ʱ���ַ�����
	STRING strGoalParam;	//�����ú��ٷֽ�
	STRING strTips;	//��ʾ�����ȴ�ӡ������
	int goalCount;//Ŀ�����
	int transferId;
	bool show;	//
	vector<POINT> position;	//�����Ǹ�point���飬��ʱ��ת������
	int boxId;
	int toNpc;	//����
	int fromNpc;//����
	_MISSION_GOAL_INFO_()
	{
		type=g_defGoldType;
		updateType=g_defUpdateType;
		strTips=g_szDefGoalTips;
		goalCount=1;
		transferId=0;
		show=false;
		boxId=0;
		toNpc=fromNpc=0;
	}
};


#endif // _MISSION_INFO_HELPER_H_