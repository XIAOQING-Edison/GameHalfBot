#include "InfoRoleTask.h"

CInfoRoleTask::CInfoRoleTask(void)
{
}

CInfoRoleTask::~CInfoRoleTask(void)
{
}


int CInfoRoleTask::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();



	TRACE_OUTPUT(_T("解析CInfoRoleTask\n"));

	bool bFinish=false;
	int restBytes=m_packageLengthInRes;
	int objLength=0;
	while(!bFinish)
	{
		DWORD fieldFlag=pStreamBuf->ReadRawVarInt32();
		switch(fieldFlag>>3)
		{
		case 1:
			{
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
				{
					tasks.SetPackageLengthInRes(objLength);
					tasks.Decode(pStreamBuf);
				}
			}
			break;
		case 2:
			{
				objLength=pStreamBuf->ReadRawVarInt32();
				tasks2.SetPackageLengthInRes(objLength);
				if(objLength>0)
				{
					tasks2.Decode(pStreamBuf);
				}
			}
		default:
			break;
		}
	
		bFinish=(pStreamBuf->GetHandlePos()-orgPos)>=restBytes;
	}
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	//TRACE_OUTPUT(_T("CInfoRoleTask 解析长度:%d\n"),handleLength);
	return handleLength;
}
