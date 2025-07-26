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
	
	BOOL IsAutoActivityGetRewardFromCfg();	//�Զ���Ծ�Ƚ�����ȡ
	void SetIsAutoAcitivityGetRewardToCfg(BOOL b);

	BOOL IsAutoReadMailFromCfg();	//�Զ���ȡ�ʼ�
	void SetIsAutoReadMailToCfg(BOOL b);

	BOOL IsAutoDeleteReadMailFromCfg();	//�Զ�ɾ���Ѷ��ʼ�
	void SetIsAutoDeleteReadMailToCfg(BOOL b);

	BOOL IsAutoUpdateMagicNuclearFromCfg();	//�Զ�ħ�˳���
	void SetIsAutoUpdateMagicNuclearToCfg(BOOL b);

	BOOL IsAutoTidyBagFromCfg();	//�Զ�������
	void SetIsAutoTidyBagToCfg(BOOL b);


};
