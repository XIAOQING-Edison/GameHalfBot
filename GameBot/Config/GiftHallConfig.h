#pragma once
#include "GameConfig.h"

class CGiftHallConfig :
	public CConfig
{
public:
	CGiftHallConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	~CGiftHallConfig(void);


	//gift hall
	BOOL IsAutoSignInFromCfg();
	void SetAutoSignInToCfg(BOOL b);

	BOOL IsAutoTreasureHoleFromCfg();
	void SetAutoTreasureHoleToCfg(BOOL b);

	BOOL IsAutoActivityTaskFromCfg();
	void SetAutoActivityTaskToCfg(BOOL b);


	BOOL IsAutoOnlineRewardFromCfg();
	void SetAutoOnlineRewardToCfg(BOOL b);

	BOOL IsAutoComposeTicketFromCfg();
	void SetAutoComposeTickeToCfg(BOOL b);

	BOOL IsAutoOfflineExpFromCfg();
	void SetAutoOfflineExpToCfg(BOOL b);

	int GetOfflineExpTypeFromCfg();
	void SetOfflineExpTypeToCfg(int type);
	
	BOOL IsAutoRecycleEquipmentFromCfg();
	void SetAutoRecycleEquipmentToCfg(BOOL b);


	int GetRecycleEquipmentStarFromCfg();
	void SetRecycleEquipmentStarToCfg(int star);

	int GetRecycleEquipmentStepLvFromCfg();
	void SetRecycleEquipmentStepLvToCfg(int stepLv);

	BOOL IsAutoSendGetVipMemberInfoFromCfg();
	void SetIsAutoSendGetVipMemberInfoToCfg(BOOL b);
	
	BOOL IsAutoActivityGetRewardFromCfg();	//自动活跃度奖励领取
	void SetIsAutoAcitivityGetRewardToCfg(BOOL b);

	BOOL IsAutoReadMailFromCfg();	//自动读取邮件
	void SetIsAutoReadMailToCfg(BOOL b);

	BOOL IsAutoDeleteReadMailFromCfg();	//自动删除已读邮件
	void SetIsAutoDeleteReadMailToCfg(BOOL b);

	BOOL IsAutoUpdateMagicNuclearFromCfg();	//自动魔核充能
	void SetIsAutoUpdateMagicNuclearToCfg(BOOL b);

	BOOL IsAutoTidyBagFromCfg();	//自动整理背包
	void SetIsAutoTidyBagToCfg(BOOL b);


};
