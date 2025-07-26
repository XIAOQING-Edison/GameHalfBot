#include "InfoPlayerInfo.h"
CInfoPlayerInfo::CInfoPlayerInfo(void)
{
}

CInfoPlayerInfo::~CInfoPlayerInfo(void)
{
}

void CInfoPlayerInfo::Reset()
{




}


int CInfoPlayerInfo::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	Reset();

	TRACE_OUTPUT(_T("解析CInfoPlayerInfo\n"));

	bool bFinish=false;
	int restBytes=m_packageLengthInRes;	//读取固定长度的字节就解析完
	int objLength=0;

#if _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_
#elif _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_
#elif (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) || (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_)
#elif _GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_
#endif

	while(!bFinish)
	{
		DWORD fieldFlag=pStreamBuf->ReadRawVarInt32();
		switch(fieldFlag>>3)
		{
		case 1:
			{
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) || (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||(_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_)\
	||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				objLength=pStreamBuf->ReadRawVarInt32();
				basic.SetPackageLengthInRes(objLength);
				if(objLength>0)
					basic.Decode(pStreamBuf);
#endif
			}
			break;
		case 2:
			{
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) || (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||(_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_) \
	||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_)||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);
#endif
			}
			break;
		case 3:
			{
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) || (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||(_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_)\
	||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
				{
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);
				}
#endif
			}
			break;
		case 4:
			{
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) || (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||(_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_)\
	||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				if(objLength>0)
				{
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);
				}
#endif
			}
			break;
		case 5:
			{
				//equips;
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) ||(_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_) || (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_)\
	||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
				{
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);
				}
#endif

			}
			break;
		case 6:
			{
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) || (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||(_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_)\
	||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);
#endif
			}
			break;
		case 7:
			{
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) || (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||(_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_)\
	||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);
#endif
			}
			break;
		case 8:
			{
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) || (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||(_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_)\
	||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				//stoneLight;
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);
#endif
			}
			break;
		case 9:
			{
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) || (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||(_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_)\
	||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				//buff;
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
				{
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);
				}
#endif
			}
			break;
		case 10:
			{
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) || (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||(_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_)\
	||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)	
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);
#endif
			}
			break;
		case 11:
			{
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) || (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||(_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_)\
	||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);
#endif
			}
			break;
		case 12:
			{
#if _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_
#elif _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_
				unionVoiceOpen=pStreamBuf->ReadBoolean();
#elif _GAME_VERSION_ == _YONG_HENG_LIAN_MENG_	


#elif _GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_
				unionVoiceOpen=pStreamBuf->ReadBoolean();
#elif 
#endif
			}
			break;
		case 13:
			{
#if _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_
#elif _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);

			}
#endif
			break;
		case 14:
			{
#if _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_
#elif _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_
				objLength=pStreamBuf->ReadRawVarInt32();
				
				if(objLength>0)
				{
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);
				}
#endif
			}
			break;
		case 15:
			break;
		case 16:
			{

			}
			break;
		case 17:
			{
			}
			break;
		case 18:
			{

			}
			break;
		case 19:
			{

			}
			break;
		default:
			TRACE_OUTPUT(_T("解析InfoPlayerInfo出错了!!!!\n"));
			break;
		}
		bFinish=(pStreamBuf->GetHandlePos()-orgPos)>=restBytes;
	}
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	//TRACE_OUTPUT(_T("CInfoPlayerInfo 解析长度:%d\n"),handleLength);
	return handleLength;
}
