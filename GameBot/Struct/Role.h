#pragma once
#include "../Global/public.h"
//��ɫĳЩ���Թ���
class CRole
{
public:
	CRole(void);
	~CRole(void);
	bool ParseInfoRoleToRoleStruct(void *pInfoRole);	//����Э���еĽ�ɫ��Ϣ

	UINT64 GetRoleId(){return m_roleId;}
//get set�ӿ�:
public:


private:
	void Reset();
private:
	UINT64 m_roleId;	//�������е�Ψһid
	
};
