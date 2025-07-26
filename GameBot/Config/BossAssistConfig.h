#pragma once
#include "Config.h"

class CBossAssistConfig :
	public CConfig
{
public:
	CBossAssistConfig(const TCHAR *szFileName,bool bUseEncryptDecrypt=true);
	~CBossAssistConfig(void);

	BOOL IsBeastBossOnlyAssistSelfMaxCountFromCfg();	//�Ƿ�ﵽ�������Ͳ�Э����Ĭ���Ƕ�Э��
	void SetIsBeastBossOnlyAssistSelfMaxCountToCfg(BOOL b);

	BOOL IsBeastBossAutoSendAssistFromCfg();	//��ɱʱ����Э��
	void SetIsBeastBossAutoSendAssistToCfg(BOOL b);

	int GetBeastBossAssistMaxTimeoutFromCfg();	//�������Э����ʱ
	void SetBeastBossAssistMaxTimeoutToCfg(int timeout);

	BOOL IsBeastBossAssistAutoSendAssistFromCfg();	//����Э���Զ�������Э��
	void SetIsBeastBossAssistAutoSendAssistToCfg(BOOL b);

	BOOL IsBeastBossAutoAssistOtherFromCfg();	//�Ƿ��Զ�Э������
	void SetIsBeastBossAutoAssistOtherToCfg(BOOL b);	//


	//����
	BOOL IsCorpsBossAutoSendAssistFromCfg();
	void SetIsCorpsBossAutoSendAssistToCfg(BOOL b);

	BOOL IsCorpsBossOnlyAssistSelfMaxCountFromCfg();	//�Ƿ�ﵽ�������Ͳ�Э����Ĭ���Ƕ�Э��
	void SetIsCorpsBossOnlyAssistSelfMaxCountToCfg(BOOL b);

	int GetCorpsBossAssistMaxTimeoutFromCfg();	//�������Э����ʱ
	void SetCorpsBossAssistMaxTimeoutToCfg(int timeout);


	BOOL IsCorpsBossAssistAutoSendAssistFromCfg();	//����Э���Զ�������Э��
	void SetIsCorpsBossAssistAutoSendAssistToCfg(BOOL b);


	BOOL IsCorpsBossAutoAssistOtherFromCfg();	//�Ƿ��Զ�Э������
	void SetIsCorpsBossAutoAssistOtherToCfg(BOOL b);	//

	void Init();
};
