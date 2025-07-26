#include "InfoCommercialActivity.h"

CInfoCommercialActivity::CInfoCommercialActivity(void)
{
}

CInfoCommercialActivity::~CInfoCommercialActivity(void)
{
}




void CInfoCommercialActivity::Reset()
{
	
}

int CInfoCommercialActivity::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();

	TRACE_OUTPUT(_T("解析CInfoCommercialActivity\n"));

	Reset();
	bool bFinish=false;
	int restBytes=m_packageLengthInRes;	//读取固定长度的字节就解析完
	int objLength=0;
	divineCostumeInfo.SetPackageLengthInRes(restBytes);
	while(!bFinish)
	{
		DWORD fieldFlag=pStreamBuf->ReadRawVarInt32();
		switch(fieldFlag>>3)
		{
		case 1:
			{
				objLength=pStreamBuf->ReadRawVarInt32();
				divineCostumeInfo.SetPackageLengthInRes(objLength+protocol_header_length);	//res的会先减去头，这里先复原长度
				if(objLength>0)
				{
					divineCostumeInfo.Decode(pStreamBuf);
				}

			}
			break;
		default:
			break;
		}
		bFinish=(pStreamBuf->GetHandlePos()-orgPos)>=restBytes;
	}
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	//TRACE_OUTPUT(_T("CInfoCommercialActivity 解析长度:%d\n"),handleLength);
	return handleLength;
}
