#include "Role.h"
#include "../Protocol/Role/InfoRoleSimpleInfo.h"
CRole::CRole(void)
{
}

CRole::~CRole(void)
{
}


bool CRole::ParseInfoRoleToRoleStruct(void *pInfoRole)	//����Э���еĽ�ɫ��Ϣ
{
	bool ret=true;
	CInfoRoleSimpleInfo *pInfo=(CInfoRoleSimpleInfo*)pInfoRole;
	m_roleId=pInfo->GetRoleId();	//��ʱֻ����roleId�ֶ�

	return ret;
}