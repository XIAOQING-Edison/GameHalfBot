#pragma once
#include "../Global/public.h"
//角色某些属性归类
class CRole
{
public:
	CRole(void);
	~CRole(void);
	bool ParseInfoRoleToRoleStruct(void *pInfoRole);	//解析协议中的角色信息

	UINT64 GetRoleId(){return m_roleId;}
//get set接口:
public:


private:
	void Reset();
private:
	UINT64 m_roleId;	//服务器中的唯一id
	
};
