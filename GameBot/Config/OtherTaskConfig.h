#pragma once
#include "config.h"

class COtherTaskConfig :
	public CConfig
{
public:
	COtherTaskConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	~COtherTaskConfig(void);

	//world server
	BOOL IsCrossServerCollectSelectedFromCfg();
	void SetCrossServerCollectToCfg(BOOL b);


	BOOL IsRedHoodSelectedFromCfg();
	void SetSelectRedHoodToCfg(BOOL b);


	BOOL IsJoinWorldServerFightFromCfg();
	void SetJoinWorldServerFightToCfg(BOOL b);


	BOOL IsAutoLegionSignInFromCfg();
	void SetAutoLegionSignInToCfg(BOOL b);


	//other task;
	BOOL IsSpaceCorridorSelectedFromCfg();
	void SetSelectSpaceCorridorToCfg(BOOL b);

	BOOL IsSpecialRoomSelectedFromCfg();
	void SetSelectSpecialRoomToCfg(BOOL b);


	BOOL IsFastFightSelectedFromCfg();
	void SetSelectFastFightToCfg(BOOL b);

	BOOL IsCampWarSelectedFromCfg();
	void SetSelectCampWarToCfg(BOOL b);

	BOOL IsCertificateSelectedFromCfg();
	void SetSelectCertificateToCfg(BOOL b);


	BOOL IsPinkDiamondSelectedFromcCfg();
	void SetSelectPinkDiamondToCfg(BOOL b);

	BOOL IsHorcruxSelectedFromCfg();
	void SetSelectHorcruxToCfg(BOOL b);

	
	BOOL IsOriginalSinSelectedFromCfg();
	void SetSelectOriginalSinToCfg(BOOL b);

	BOOL IsFairyLandSelectedFromCfg();
	void SetSelectFairyLandToCfg(BOOL b);


	int GetFairyLandCountFromCfg();
	void SetFairyLandCountToCfg(int count);


	BOOL IsOrcGodBlessSelectedFromCfg();
	void SetSelectOrcGodBlessToCfg(BOOL b);

};
