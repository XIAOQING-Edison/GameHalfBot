#ifndef _MISSION_INFO_HELPER_H_
#define _MISSION_INFO_HELPER_H_
#include "../Global/public.h"


//
enum TaskGoalType {
	TaskGoalTypeLearnSkill=99,	//购买并使用技能石，才能学到技能
	TaskGoalTypeKillMonster = 101,
	TaskGoalTypeAffiliationKill = 103,
	TaskGoalTypeTeamAffiliationKill = 113,
	TaskGoalTypeDialogue = 201,
	TaskGoalTypeUpgrade = 301,
	TaskGoalTypeTransferToDstMap=401,	//传送地图
	TaskGoalTypeKillMonsterGetItem=601,	//打怪获取材料，如转职材料
	TaskGoalTypeWearEquipment=721,	//穿某些套装，一般是支线
	TaskGoalTypeEnhance=803,	//强化
	TaskGoalTypeRecycleEquipment=1001,		//回收装备
	TaskGoalTypeUpgradeDefence = 3101,		//升级到目标防御，穿戴装备或升属性

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


//经查找，任务栏点击是和navi属性相关的
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
	int state;	//接收，完成，还是xxx
	STRING name;	//任务名称
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
static const TCHAR* g_szDefGoalTips=_T("击杀地狱猎犬怪");
#elif (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) || (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_) ||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_)
static const int g_defGoldType=603;
static const int g_defUpdateType=2;
static const TCHAR* g_szDefGoalTips=_T("今日累计充值50元");

#endif

struct _MISSION_GOAL_INFO_
{
	int goldId;
	int type;
	int updateType;
	STRING strTarget;	//目标，暂时用字符串存
	STRING strGoalParam;	//分析好后再分解
	STRING strTips;	//提示内容先打印作分析
	int goalCount;//目标进度
	int transferId;
	bool show;	//
	vector<POINT> position;	//估计是个point数组，到时候转成坐标
	int boxId;
	int toNpc;	//待定
	int fromNpc;//待定
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