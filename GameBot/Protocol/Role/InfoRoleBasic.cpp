#include "InfoRoleBasic.h"
CInfoRoleBasic::CInfoRoleBasic(void)
{
}

CInfoRoleBasic::~CInfoRoleBasic(void)
{
}

void CInfoRoleBasic::Reset()
{
	createTime=0;// = 2; //创角时间 (s)
	attributePoint=0;// = 4; //可使用點數
	PKMode=0;// = 7;
	dailyOnlineTime=0;// = 8;//每日在线时长 (s)
	logoutTime=0;// = 10;//离线时间戳，秒

}

int CInfoRoleBasic::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();


	TRACE_OUTPUT(_T("解析CInfoRoleBasic\n"));
	Reset();

	bool bFinish=false;
	int objLength=0;
	int restBytes=m_packageLengthInRes;	//读取固定长度的字节就解析完

	while(!bFinish)
	{
		DWORD fieldFlag=pStreamBuf->ReadRawVarInt32();
		switch(fieldFlag>>3)
		{
		case 1:
			{
				objLength=pStreamBuf->ReadRawVarInt32();
				info.SetPackageLengthInRes(objLength);
				if(objLength>0)
				{
					//info.Decode(pStreamBuf);
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);
				}
			}
			break;
		case 2:
			createTime=pStreamBuf->ReadRawVarInt32();
			break;
		case 3:
			{
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_)	|| (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_)\
	||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
				exp=pStreamBuf->ReadRawVarInt64();
#elif (_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_)
				exp=pStreamBuf->ReadVarIntString();
#endif
			}
			break;
		case 4:
			attributePoint=pStreamBuf->ReadRawVarInt32();
			break;
		case 5:
			{
				objLength=pStreamBuf->ReadRawVarInt32();
				
				if(objLength>0)
				{
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);	
				}
			}
			break;
		case 6:
			{
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
				{
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);	
				}
			}
			break;
		case 7:
			PKMode=pStreamBuf->ReadRawVarInt32();
			break;
		case 8:
			dailyOnlineTime=pStreamBuf->ReadRawVarInt32();
			break;
		case 9:
			{
				pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);	
			}
			break;
		case 10:
			logoutTime=pStreamBuf->ReadRawVarInt32();
			break;
		case 11:
			{

			}
			break;
		case 12:
			{

			}
			break;
		case 13:
			break;
		default:
			{
				TRACE_OUTPUT(_T("----------------------Role basic 解析出错-------------------\n"));
// 				if(fieldFlag%8 !=0)	//暂时没找到解析的，先跳过
// 				{
// 					objLength=pStreamBuf->ReadRawVarInt32();
// 					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);
// 				}
				
			}
			break;
		}
		bFinish=(pStreamBuf->GetHandlePos()-orgPos)>=restBytes;
	}
	//TRACE_OUTPUT(_T("FoleBasic--创建时间:%d,登出时间:%d\n"),createTime,logoutTime);
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	//TRACE_OUTPUT(_T("CInfoRoleBasic 解析长度:%d\n"),handleLength);
	return handleLength;
}