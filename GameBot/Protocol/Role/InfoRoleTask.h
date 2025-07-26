#pragma once
#include "../protocol.h"
#include "../Task/InfoTasks.h"
#include "../Task/InfoAuxiliaryTask.h"
//这个类用来包装infoTasks
//为方便解析和游戏中的数据一样处理了
class CInfoRoleTask :
	public CProtocol
{
public:
	CInfoRoleTask(void);
	virtual ~CInfoRoleTask(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);
private:
	CInfoTasks tasks;// = 1;
	CInfoAuxiliaryTask tasks2;//=2;
};
