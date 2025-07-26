#pragma once
#include "../protocol.h"
#include "../Role/InfoRoleToOtherInfo.h"
class CInfoResGetRoleList :
	public CProtocol
{
public:
	CInfoResGetRoleList(void);
	virtual ~CInfoResGetRoleList(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);
	vector<CInfoRoleToOtherInfo>& GetRoleList(){return roleList;}
private:
	INT64 userId;// = 1;
	vector<CInfoRoleToOtherInfo> roleList;// = 2; //角色列表
	vector<CInfoRoleToOtherInfo> deleteRoleList;// = 3; //删除的角色列表

};
