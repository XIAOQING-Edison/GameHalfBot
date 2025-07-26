#pragma once
#include "config.h"

class CConfigSecretary5 :
	public CConfig
{
public:
	CConfigSecretary5(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	~CConfigSecretary5(void);

	BOOL IsAutoExchangeEquipSandToGloryFromCfg();
	BOOL SetIsAutoExchangeEquipSandToGloryToCfg(BOOL b);


	int GetExchangeEquipSandCountFromCfg();
	BOOL SetExchangeEquipSandCountToCfg(int count);

	BOOL IsSpaceCorridorSelectedFromCfg();
	BOOL SetIsSpaceCorridorSelectedToCfg(BOOL b);

	int GetSpaceCorridorBuyExtraTimesFromCfg();
	BOOL SetSpaceCorridorBuyExtraTimesToCfg(int times);
	

	BOOL IsDemonStrongHoldSelectedFromCfg();
	BOOL SetIsDemonStrongHoldSelectedToCfg(BOOL b);

	BOOL IsDemonStrongHoldOneKeyGetTreasureFromCfg();
	BOOL SetIsDemonStrongHoldOneKeyGetTreasureToCfg(BOOL b);

	BOOL IsAsuramLeagueBossSelectedFromCfg();
	BOOL SetIsAsuramLeagueBossSelectedToCfg(BOOL b);

	int GetAsuramLeagueBossBuyExtraTimesFromCfg();
	BOOL SetAsuramLeagueBossBuyExtraTimesToCfg(int count);



	BOOL IsAsuramLeagueBossAutoShareMonsterChallengeFromCfg();
	BOOL SetIsAsuramLeagueBossAutoShareMonsterChallengeToCfg(BOOL b);

	BOOL IsAsuramLeagueBossAutoExchangeTreasureFromCfg();
	BOOL SetIsAsuramLeagueBossAutoExchangeTreasureToCfg(BOOL b);

	BOOL IsAutoMeceneryDispathSelectedFromCfg();
	BOOL SetIsAutoMeceneryDispathSelectedToCfg(BOOL b);

	int GetMeceneryDispathStarLevelFromCfg();
	BOOL SetMeceneryDispathStarLevelToCfg(int level);

	BOOL IsMeceneryDispathContinueWhenNoUnitsFromCfg();
	BOOL SetIsMeceneryDispathContinueWhenNoUnitsToCfg(BOOL b);

	BOOL IsMeceneryDispathAutoDoTaskFromCfg();
	BOOL SetIsMeceneryDispathAutoDoTaskToCfg(BOOL b);

	BOOL IsMeceneryDispathAutoBuyHandCemeceryFromCfg();
	BOOL SetIsMeceneryDispathAutoBuyHandCemeceryToCfg(BOOL b);




};
