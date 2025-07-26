#pragma once
#include "../Global/public.h"
#include "MissionInfoHelper.h"
class CMission
{
public:
	CMission(void);
	~CMission(void);
	void Reset();

	bool ParseInfoTaskToMission(void *p);

	int GetMissionId(){return m_missionId;}
	int GetMissionGoalId(){return m_missionGoalId;}
	_MISSION_INFO_ *GetMissionInfo(){return m_pMissionInfo;}
private:
	int m_missionId;
	int m_missionGoalId;
	_MISSION_INFO_ *m_pMissionInfo;	//�������������missionInfo����ϸ��Ϣ
	vector<STRING> m_missionParams;	//����
};
