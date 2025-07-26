#pragma once
#include "Config.h"

class CBossAssistConfig :
	public CConfig
{
public:
	CBossAssistConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	~CBossAssistConfig(void);

	BOOL IsBeastBossOnlyAssistSelfMaxCountFromCfg();	//是否达到最大次数就不协助，默认是都协助
	void SetIsBeastBossOnlyAssistSelfMaxCountToCfg(BOOL b);

	BOOL IsBeastBossAutoSendAssistFromCfg();	//击杀时发送协助
	void SetIsBeastBossAutoSendAssistToCfg(BOOL b);

	int GetBeastBossAssistMaxTimeoutFromCfg();	//兽神最大协助超时
	void SetBeastBossAssistMaxTimeoutToCfg(int timeout);

	BOOL IsBeastBossAssistAutoSendAssistFromCfg();	//兽神协助自动发送求协助
	void SetIsBeastBossAssistAutoSendAssistToCfg(BOOL b);

	BOOL IsBeastBossAutoAssistOtherFromCfg();	//是否自动协助他人
	void SetIsBeastBossAutoAssistOtherToCfg(BOOL b);	//


	//军团
	BOOL IsCorpsBossAutoSendAssistFromCfg();
	void SetIsCorpsBossAutoSendAssistToCfg(BOOL b);

	BOOL IsCorpsBossOnlyAssistSelfMaxCountFromCfg();	//是否达到最大次数就不协助，默认是都协助
	void SetIsCorpsBossOnlyAssistSelfMaxCountToCfg(BOOL b);

	int GetCorpsBossAssistMaxTimeoutFromCfg();	//军团最大协助超时
	void SetCorpsBossAssistMaxTimeoutToCfg(int timeout);


	BOOL IsCorpsBossAssistAutoSendAssistFromCfg();	//军团协助自动发送求协助
	void SetIsCorpsBossAssistAutoSendAssistToCfg(BOOL b);


	BOOL IsCorpsBossAutoAssistOtherFromCfg();	//是否自动协助他人
	void SetIsCorpsBossAutoAssistOtherToCfg(BOOL b);	//

	void Init();
};
