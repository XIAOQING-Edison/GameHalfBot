#include "Role.h"
#include "../Protocol/Role/InfoRoleSimpleInfo.h"
CRole::CRole(void)
{
}

CRole::~CRole(void)
{
}


bool CRole::ParseInfoRoleToRoleStruct(void *pInfoRole)	//解析协议中的角色信息
{
	bool ret=true;
	CInfoRoleSimpleInfo *pInfo=(CInfoRoleSimpleInfo*)pInfoRole;
	m_roleId=pInfo->GetRoleId();	//暂时只解析roleId字段

	return ret;
}