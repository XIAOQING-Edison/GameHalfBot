#pragma once
#include "config.h"

class CConfigSecretary1 :
	public CConfig
{
public:
	CConfigSecretary1(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	~CConfigSecretary1(void);


	BOOL IsAutoHungUpFromCfg();	//是否自动挂机
	BOOL SetIsAutoHungUpToCfg(BOOL b);

	int GetAutoHungUpPointXFromCfg();//多倍挑战倍数
	BOOL SetAutoHungUpPointXToCfg(int count);//多倍挑战倍数

	int GetAutoHungUpPointYFromCfg();//购买次数
	BOOL SetAutoHungUpPointYToCfg(int count);//购买次数

	int GetAutoHungUpMapIndexCfg();	//自动领奖
	BOOL SetAutoHungUpMapIdToCfg(int mapId);	//自动领奖

	int GetHungUpMapTypeFromCfg();	//地图类型
	BOOL SetHungUpMapTypeToCfg(int type);	//地图类型

	vector<int> GetBloodCastleTimeSelectArrayFromCfg();
	BOOL SetBloodCastleTimeSelectArrayToCfg(vector<int> &timeSels);

	BOOL IsBloodCastleSelectedFromCfg();
	BOOL SetIsBloodTownSelectedToCfg(BOOL b);

	int GetBloodCastleHungUpPointXFromCfg();
	BOOL SetBloodCastleHungUpPointXToCfg(int x);

	int GetBloodCastleHungUpPointYFromCfg();
	BOOL SetBloodCastleHungUpPointYToCfg(int y);

	BOOL IsUseSelfSkillsWhenSeeOtherPlayerFromCfg();
	BOOL SetIsUseSelfSkillsWhenSeeOtherPlayerToCfg(BOOL b);

	BOOL IsBloodTownAutoComposeTicketFromCfg();
	BOOL SetIsBloodTownBloodTownAutoComposeTicketToCfg(BOOL b);

	BOOL IsAutoCounterStrikeFromCfg();
	BOOL SetIsAutoCounterStrikeToCfg(BOOL b);

	BOOL IsAutoCounterStrikeUsingConfigSkillsFromCfg();	//是否使用配置里的技能
	BOOL SetIsAutoCounterStrikeUsingConfigSkillsToCfg(BOOL b);

	int GetPkModeFromCfg();
	BOOL SetPkModeToCfg(int m);

};
