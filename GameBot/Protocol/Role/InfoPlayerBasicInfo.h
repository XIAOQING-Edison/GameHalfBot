#pragma once
#include "../protocol.h"
#include "InfoRoleBasic.h"

//��һ������ݸ�ֵ
class CInfoPlayerBasicInfo :
	public CProtocol
{
public:
	CInfoPlayerBasicInfo(void);
	virtual ~CInfoPlayerBasicInfo(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);

	void Reset();

	INT64 GetRoleId(){return basic.GetRoleId();}
	STRING GetName(){return basic.GetName();};
	int GetLevel(){return basic.GetLevel();;}
	STRING GetUnionName(){return basic.GetUnionName();}	//ս������
	int GetTotalFight(){return basic.GetTotalFight();}	//ս��
	int GetServerId(){return basic.GetServerId();}
	int GetMapId(){return basic.GetMapId();}
	int GetCareer(){return basic.GetCareer();}

	map<int,INT64>& GetAttributes(){return attribute;}
	int GetAttributePoint(){return basic.GetAttributePoint();}

	int GetPkMode(){return basic.GetPkMode();}
private:

	CInfoRoleBasic basic;// = 1;
	map<int, INT64> attribute;// = 2;

};
