#include "InfoPlayerInfoStatus.h"

//encode decode都需要实现
CInfoPlayerInfoStatus::CInfoPlayerInfoStatus(void)
{
	SetProtocolId(e_cmd_info_player_info_status);
}

CInfoPlayerInfoStatus::~CInfoPlayerInfoStatus(void)
{
}


void CInfoPlayerInfoStatus::Reset()
{
	connectionInfo=e_disconnect_no_error;	//离线还是在线
	roleName=_T("");
	job=0;
	level=0;
	asuramName=_T("");
	mapName=_T("");
	taskName=_T("");
	skillList.clear();
	x=y=0;
	roleId=0;
}



bool CInfoPlayerInfoStatus::Encode(CStreamReadWrite *pStreamBuf)
{
	CBaseMessage::Encode(pStreamBuf);
	ResetWritePostion();

	pStreamBuf->WriteShort(GetProtocolId());	//协议ID
	pStreamBuf->WriteFixedInt64(roleId);
	pStreamBuf->WriteFixedInt32(-1/*connectionInfo*/);
	pStreamBuf->WriteBigString(roleName.c_str());
	pStreamBuf->WriteFixedInt32(job);
	pStreamBuf->WriteFixedInt32(level);
	pStreamBuf->WriteBigString(asuramName.c_str());
	pStreamBuf->WriteBigString(mapName.c_str());
	pStreamBuf->WriteBigString(taskName.c_str());
	pStreamBuf->WriteFixedInt32(skillList.size());
	vector<int>::iterator it=skillList.begin();
	while(it != skillList.end())
	{
		pStreamBuf->WriteFixedInt32(*it);
		++it;
	}
	pStreamBuf->WriteFixedInt32(x);
	pStreamBuf->WriteFixedInt32(y);
	return true;
}


int CInfoPlayerInfoStatus::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	Reset();

	roleId=pStreamBuf->ReadFixedInt64();
	connectionInfo=(E_DISCONNECT_ERROR_REASON)pStreamBuf->ReadFixedInt32();
	roleName=pStreamBuf->ReadBigString();
	job=pStreamBuf->ReadFixedInt32();
	level=pStreamBuf->ReadFixedInt32();
	asuramName=pStreamBuf->ReadBigString();
	mapName=pStreamBuf->ReadBigString();
	taskName=pStreamBuf->ReadBigString();

	int skillCount=pStreamBuf->ReadFixedInt32();
	for(int i=0;i<skillCount;++i)
	{
		skillList.push_back(pStreamBuf->ReadFixedInt32());
	}
	x=pStreamBuf->ReadFixedInt32();
	y=pStreamBuf->ReadFixedInt32();

EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;
}
