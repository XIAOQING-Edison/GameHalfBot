#include "InfoRoleSimpleInfo.h"

CInfoRoleSimpleInfo::CInfoRoleSimpleInfo(void)
{
}

CInfoRoleSimpleInfo::~CInfoRoleSimpleInfo(void)
{
}


void CInfoRoleSimpleInfo::Reset()
{
	roleId=unionId=0;
	name=unionName=appear=_T("");
	level=career=sex=0;
	online=false;
	unionPosition=fight=0;
	equipScore=unionLevel=0;
	notoriety=redLevel=createTime=0;
	hasShield=false;
	serverId=unionCamp=mapId=hostId=0;
#if _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_
	
#elif _GAME_VERSION_ == _TIAN_SHI_SHEN_YU_
#endif
}


int CInfoRoleSimpleInfo::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();


	TRACE_OUTPUT(_T("解析CInfoRoleSimpleInfo\n"));
	Reset();

	int restBytes=m_packageLengthInRes;	//读取固定长度的字节就解析完
	int objLength=0;
	bool bFinish=false;

	while(!bFinish)
	{
		DWORD fieldFlag=pStreamBuf->ReadRawVarInt32();
		switch(fieldFlag>>3)
		{
		case 1:
			roleId=pStreamBuf->ReadRawVarInt64();
			break;
		case 2:
// 			name=pStreamBuf->ReadVarIntString();
			objLength=pStreamBuf->ReadRawVarInt32();
			pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);

			break;
		case 3:
			level=pStreamBuf->ReadRawVarInt32();
			break;
		case 4:
			career=pStreamBuf->ReadRawVarInt32();
			break;
		case 5:
			sex=pStreamBuf->ReadRawVarInt32();
			break;
		case 6:
			online=pStreamBuf->ReadBoolean();
			break;
		case 7:
			unionId=pStreamBuf->ReadRawVarInt64();
			break;
		case 8:
// 			unionName=pStreamBuf->ReadVarIntString();
			objLength=pStreamBuf->ReadRawVarInt32();
			pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);

			break;
		case 9://无？？？
			break;
		case 10:
			unionPosition=pStreamBuf->ReadRawVarInt32();
			break;
		case 11:
			{
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) || (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||( _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_)\
	||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				fight=pStreamBuf->ReadRawVarInt32();
#elif _GAME_VERSION_ ==_YONG_HENG_ZHI_DIAN_
				fight=pStreamBuf->ReadRawVarInt64();
#endif
			}
			break;
		case 12:
			appear=pStreamBuf->ReadVarIntString();
// 			objLength=pStreamBuf->ReadRawVarInt32();
// 			pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);
			break;
		case 13:
			equipScore=pStreamBuf->ReadRawVarInt32();
			break;
		case 14:
			unionLevel=pStreamBuf->ReadRawVarInt32();
			break;
		case 15:
			{
#if (_GAME_VERSION_	== _TIAN_SHI_ZHI_ZHAN_MOBILE_) ||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				badgeLevel=pStreamBuf->ReadRawVarInt32();
#elif (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) ||(_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_)
#elif (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_)
				badgeLevel=pStreamBuf->ReadRawVarInt32();
#endif				
			}
			break;
		case 16:
			notoriety=pStreamBuf->ReadRawVarInt32();
			break;
		case 17:
			redLevel=pStreamBuf->ReadRawVarInt32();
			break;
		case 18:
			createTime=pStreamBuf->ReadRawVarInt64();
			break;
		case 19:
			hasShield=pStreamBuf->ReadBoolean();
			break;
		case 20:
			serverId=pStreamBuf->ReadRawVarInt32();
			break;
		case 21:
			unionCamp=pStreamBuf->ReadRawVarInt32();
			break;
		case 22:
			mapId=pStreamBuf->ReadRawVarInt32();
			break;
		case 23:
			hostId=pStreamBuf->ReadRawVarInt32();
			break;
		case 24:
			{
#if _GAME_VERSION_ == _YONG_HENG_LIAN_MENG_
#elif _GAME_VERSION_ == _TIAN_SHI_SHEN_YU_
#elif (_GAME_VERSION_ ==_YONG_HENG_ZHI_DIAN_) || (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_)|| (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				charm=pStreamBuf->ReadRawVarInt32();
#endif
			}
			break;
		case 25:
			{
#if _GAME_VERSION_ == _YONG_HENG_LIAN_MENG_
#elif _GAME_VERSION_ == _TIAN_SHI_SHEN_YU_
#elif (_GAME_VERSION_ ==_YONG_HENG_ZHI_DIAN_) || (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_)|| (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				unionBadgeIntensify=pStreamBuf->ReadRawVarInt32();
#endif
			}
			break;
		case 26:
			{
#if (_GAME_VERSION_ ==_YONG_HENG_ZHI_DIAN_) || ( _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_)|| (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				stageId=pStreamBuf->ReadRawVarInt32();
#endif
			}

			break;
		case 27:
			{
#if (_GAME_VERSION_	== _TIAN_SHI_ZHI_ZHAN_MOBILE_) || (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				killCount=pStreamBuf->ReadRawVarInt32();
#elif _GAME_VERSION_ ==_YONG_HENG_ZHI_DIAN_
#endif
			}
			break;
		case 28:
			{
#if (_GAME_VERSION_	== _TIAN_SHI_ZHI_ZHAN_MOBILE_) || (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				showRankAppear=pStreamBuf->ReadBoolean();
#endif			
			}
			break;
		case 29:
			{
#if (_GAME_VERSION_	== _TIAN_SHI_ZHI_ZHAN_MOBILE_) || (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				dawankaLevel=pStreamBuf->ReadRawVarInt32();
#endif
			}
			break;
		case 30:
			{
#if (_GAME_VERSION_	== _TIAN_SHI_ZHI_ZHAN_MOBILE_) || (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				skillInstanceFloor=pStreamBuf->ReadRawVarInt32();
#endif
			}
			break;
		case 31:
			{
#if _GAME_VERSION_	== _TIAN_SHI_ZHI_ZHAN_MOBILE_
#endif
			}
			break;
		case 32:
			{
#if _GAME_VERSION_	== _TIAN_SHI_ZHI_ZHAN_MOBILE_
#endif
			}
			break;
		case 33:
			{
#if _GAME_VERSION_	== _TIAN_SHI_ZHI_ZHAN_MOBILE_
#endif
			}
			break;
		case 34:
			{
#if _GAME_VERSION_	== _TIAN_SHI_ZHI_ZHAN_MOBILE_
#endif
			}
			break;
		case 35:
			{
#if _GAME_VERSION_	== _TIAN_SHI_ZHI_ZHAN_MOBILE_
#endif
			}
			break;
		case 36:
			{
#if _GAME_VERSION_	== _TIAN_SHI_ZHI_ZHAN_MOBILE_
#endif
			}
			break;
		default:
			TRACE_OUTPUT(_T("--------------------------解析出错了?????-----------------------------\n"));
// 			if(fieldFlag%8 !=0)	//暂时没找到解析的，先跳过
// 			{
// 				int objLength=pStreamBuf->ReadRawVarInt32();
// 				pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);
// 			}
			break;
		}
		bFinish=(pStreamBuf->GetHandlePos()-orgPos)>=restBytes;
	}
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	//TRACE_OUTPUT(_T("CInfoRoleSimpleInfo 解析长度:%d\n"),handleLength);
	return handleLength;
}