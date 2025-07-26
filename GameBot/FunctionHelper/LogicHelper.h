#pragma once
#include "../Global/public.h"
class CPlayer;
class CGameLogicHelper;
class CGameOperation;
//��Ϊ�����߼���Ļ���
class CLogicHelper
{
public:
	CLogicHelper(void);
	virtual ~CLogicHelper(void);

	void SetGameLogicHelper(CGameLogicHelper *pLogicHelper);

protected:
	virtual void Init();	//����̳�
protected:
	CPlayer *m_pThisPlayer;
	CGameOperation *m_pGameOperation;	//��Ϸ�����࣬����ִ��һϵ�з�������
	CGameLogicHelper *m_pGameLogicHelper;	//Ϊ�˵���ĳЩ����

};
