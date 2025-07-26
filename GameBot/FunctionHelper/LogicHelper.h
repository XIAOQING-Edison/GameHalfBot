#pragma once
#include "../Global/public.h"
class CPlayer;
class CGameLogicHelper;
class CGameOperation;
//作为其它逻辑类的基类
class CLogicHelper
{
public:
	CLogicHelper(void);
	virtual ~CLogicHelper(void);

	void SetGameLogicHelper(CGameLogicHelper *pLogicHelper);

protected:
	virtual void Init();	//子类继承
protected:
	CPlayer *m_pThisPlayer;
	CGameOperation *m_pGameOperation;	//游戏操作类，用来执行一系列发包流程
	CGameLogicHelper *m_pGameLogicHelper;	//为了调用某些功能

};
