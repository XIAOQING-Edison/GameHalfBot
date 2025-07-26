#include "Mission.h"

CMission::CMission(void)
{
	Reset();
}

CMission::~CMission(void)
{
}


void CMission::Reset()
{
	m_pMissionInfo=NULL;
	m_missionId=m_missionGoalId=0;
	m_missionParams.clear();
}