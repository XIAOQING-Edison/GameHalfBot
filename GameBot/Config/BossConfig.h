#pragma once
#include "GameConfig.h"

//这里把bossConfig作为基类，因为处理方法雷同，就不再复制代码了
class CBossConfig :
	public CConfig
{
public:
	CBossConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	~CBossConfig(void);

	BOOL IsBossSelectedFromCfg();
	void SetIsBossSelectedToCfg(BOOL b);

	void SetBossListSelectedToCfg(vector<int> &arr);
	vector<int> GetBossSelectedListFromCfg();

	void SetBossMaxTimeoutToCfg(int minutes);
	int GetBossMaxTimeoutFromCfg();

	void SetBossKillModeToCfg(int mode);	//手动或自动模式
	int GetBossKillModeFromCfg();	//手动或自动模式


	void Init();
protected:
	TCHAR *m_szIsBossSelected;	//是否BOSS选择，会在初始化赋值
	TCHAR *m_szBossList;	//BOSS列表字段,会在初始化赋值
	TCHAR *m_szBossMaxTimeout;	//BOSS列表最大的超时间
	TCHAR *m_szBossKillMode;	//打BOSS模式，手动或自动

};
