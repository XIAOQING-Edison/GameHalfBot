#pragma once

#include "SocketHelper.h"	//���������õ�
#include "../Struct/GameOperation.h"


//�߼�������������������ȥ������������ȴ����л���
class CPlayer;
class CGameConfig;
class CGameLogicHelper
{
	friend class CTestHelper;	//����
	friend class CBossLogicHelper;	//BOSS
	friend class CTaskLogicHelper;	//����
public:
	CGameLogicHelper(void);
	~CGameLogicHelper(void);

	bool IsFirstRunning(){return  m_bFirstRunning;}
	void SetIsFirstRunning(bool b){m_bFirstRunning=b;}
	void ResetIsFirstRunning(){SetIsFirstRunning(true);}


	void SetPlayer(CPlayer *p);
	CPlayer *GetPlayer(){return m_pThisPlayer;}

	CGameOperation *GetGameOperation(){return &m_gameOperation;}

	void SetResCode(int code){m_gameOperation.SetResCode(code);}
	int GetResCode(){return m_gameOperation.GetResCode();}
	void ResetResCode(){return m_gameOperation.ResetResCode();}

	void Init();

	//�ⲿ��player�õĽӿ�
	void DoGameOperaion(int protocolId,int paramLength,char *cmdData,CSocketHelper *pSocketHelper);	//�������protocolId������ĳЩЭ��

	//game operation�ӿ�

	void ResetMoveSucc(){m_gameOperation.ResetMoveSucc();}
	void SetMoveSucc(bool b){m_gameOperation.SetMoveSucc(b);}
	bool IsMoveSucc(){return m_gameOperation.IsMoveSucc();} //����Ŀ������������Ϣ�Ƿ�ɹ�



	//����
	bool InterruptTaskByEmergencyLevel();	//�ж���ʱ���Ķ���
	void ResetTaskEmergencyLevel(){m_gameOperation.ResetEmergencyLevel();}

	//����
	void DoSetPkModeTask(CGameConfig *pCfg,CSocketHelper *pSocketHelper);	//pkģʽת��

public:	//�����ӿ�
	void DoTimerTask(CSocketHelper *pSocketHelper);	//����ʱ����	//������Ҫ������ʱ����	
public:	//boss����

public:	//������Ĳ���,�����Ǹ�������
	
private:	//˽�нӿڣ���������

	void Test(CSocketHelper *pSocketHelper);


private:
	CPlayer *m_pThisPlayer;
	HANDLE m_hEvtTaskFinished;	//��������ǵȴ�������ɣ��н��������������ȥ,��״̬ʱ���жϻ����
	bool m_bFirstRunning;

	int m_sendErrorCount;	//�����Ҫͳ�Ʒ���С����Ĵ����������һ�������ͱ�ʾ�Ͽ���
	CGameOperation m_gameOperation;	//��Ϸ�����࣬����ִ��һϵ�з�������

private:
};
