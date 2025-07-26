#include "InfoRoleToOtherInfo.h"
CInfoRoleToOtherInfo::CInfoRoleToOtherInfo(void)
{
}

CInfoRoleToOtherInfo::~CInfoRoleToOtherInfo(void)
{
}

void CInfoRoleToOtherInfo::Reset()
{
	
}


int CInfoRoleToOtherInfo::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();
	int objLength=0;
	int restBytes=m_packageLengthInRes;	//读取固定长度的字节就解析完
	TRACE_OUTPUT(_T("解析CInfoRoleToOtherInfo\n"));

	Reset();


	bool bFinish=false;

	while(!bFinish)
	{
		DWORD fieldFlag=pStreamBuf->ReadRawVarInt32();
		switch(fieldFlag>>3)
		{
		case 1:
			if(fieldFlag %8 ==2)
			{
				objLength=pStreamBuf->ReadRawVarInt32();	//长度
				info.SetPackageLengthInRes(objLength);
				if(objLength>0)	//需要判断是否有长度才去解析，这里有0长度的情况
					info.Decode(pStreamBuf);
			}
			break;
		case 2:
			mapId=pStreamBuf->ReadRawVarInt32();
			break;
		case 3:
			line=pStreamBuf->ReadRawVarInt32();
			break;
		case 4:
			{
				objLength=pStreamBuf->ReadRawVarInt32();	//长度
					
				if(objLength>0)	//需要判断是否有长度才去解析，这里有0长度的情况
				{
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);	
				}
			}
			break;
		case 5:
			hostId=pStreamBuf->ReadRawVarInt32();
			break;
		case 6:
			{
				objLength=pStreamBuf->ReadRawVarInt32();
				pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);	
			}
			break;
		case 7:
			isDel=pStreamBuf->ReadBoolean();
			break;
		case 8:
			delTime=pStreamBuf->ReadRawVarInt64();
			break;
		case 9:
			{

			}
		
			break;
		case 10:
			{


			}
			break;
		case 11:
			{

			}
			break;
		case 12:
			{

			}
			break;
		default:
			TRACE_OUTPUT(_T("--------------------CInfoRoleToOtherInfo 解析出错了!!--------------------\n"));
// 			if(fieldFlag%8 !=0)	//暂时没找到解析的，先跳过
// 			{
// 				objLength=pStreamBuf->ReadRawVarInt32();
// 				pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);
// 			}
			break;
		}
		bFinish=(pStreamBuf->GetHandlePos()-orgPos)>=restBytes;
	}

EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	//TRACE_OUTPUT(_T("CInfoRoleToOtherInfo 解析长度:%d\n"),handleLength);
	return handleLength;
}