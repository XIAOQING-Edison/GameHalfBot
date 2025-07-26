#include "InfoPlayerBasicInfo.h"

CInfoPlayerBasicInfo::CInfoPlayerBasicInfo(void)
{
}

CInfoPlayerBasicInfo::~CInfoPlayerBasicInfo(void)
{
}

void CInfoPlayerBasicInfo::Reset()
{
	attribute.clear();// = 2;

}


int CInfoPlayerBasicInfo::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();
	Reset();
	TRACE_OUTPUT(_T("解析CInfoPlayerBasicInfo\n"));


	bool bFinish=false;
	int restBytes=m_packageLengthInRes;	//读取固定长度的字节就解析完
	int objLength=0;

	while(!bFinish)
	{
		DWORD fieldFlag=pStreamBuf->ReadRawVarInt32();
		switch(fieldFlag>>3)
		{
		case 1:
			{
				objLength=pStreamBuf->ReadRawVarInt32();
				basic.SetPackageLengthInRes(objLength);
				if(objLength>0)
					basic.Decode(pStreamBuf);
			}
			break;
		case 2:
			{
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
				{
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);
				}
			}
			break;
		case 3:
			{
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
				{
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);			
				}
			}
			break;
		case 4:
			{
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
				{
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);			
				}
			}
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
			{
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
				{
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);			
				}
			}
			break;
		case 8:
			{
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
				{
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);				
				}
			}
			break;
		case 9:
			{
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);			
			}
			break;
		case 10:
			{
				objLength=pStreamBuf->ReadRawVarInt32();
				if(objLength>0)
					pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+objLength);		
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
		case 13:
			{
			}
			break;	
		case 14:
			{
			}			
			break;	
		case 15:
			{
			}			
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
		default:
			break;
		}
		bFinish=(pStreamBuf->GetHandlePos()-orgPos)>=restBytes;
	}
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	//TRACE_OUTPUT(_T("CInfoPlayerBasicInfo 解析长度:%d\n"),handleLength);
	return handleLength;
}
