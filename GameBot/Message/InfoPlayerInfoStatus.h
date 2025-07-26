#pragma once
#include "basemessage.h"

class CInfoPlayerInfoStatus :
	public CBaseMessage
{
public:
	CInfoPlayerInfoStatus(void);
	virtual ~CInfoPlayerInfoStatus(void);


	virtual bool Encode(CStreamReadWrite *pStreamBuf);
	virtual int Decode(CStreamReadWrite *pStreamBuf);

	void Reset();

	int GetJob(){return job;}
	vector<int>& GetSkillList(){return skillList;}
	void SetSkillList(vector<int> &list){skillList=list;}
	int GetX(){return x;}
	int GetY(){return y;}
	void SetX(int x){this->x=x;}
	void SetY(int y){this->y=y;}

	void SetRoleId(UINT64 rid){roleId=rid;}
	UINT64 GetRoleId(){return roleId;}

	void SetDisconnectInfo(E_DISCONNECT_ERROR_REASON disInfo){connectionInfo=disInfo;}
	E_DISCONNECT_ERROR_REASON GetDisconnectInfo(){return connectionInfo;}
public:
	UINT64 roleId;
	E_DISCONNECT_ERROR_REASON  connectionInfo;	//离线还是在线
	STRING roleName;
	int job;
	int level;
	STRING asuramName;
	STRING mapName;
	STRING taskName;
	vector<int> skillList;
	int x;	//当前坐标
	int y;	//当前坐标
};
