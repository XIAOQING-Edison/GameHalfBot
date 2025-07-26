#include "InfoResGetRoleList.h"

CInfoResGetRoleList::CInfoResGetRoleList(void)
{
}

CInfoResGetRoleList::~CInfoResGetRoleList(void)
{
}




int CInfoResGetRoleList::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();
	roleList.clear();
	deleteRoleList.clear();

	TRACE_OUTPUT(_T("解析CInfoResGetRoleList\n"));
	int restBytes=m_packageLengthInRes;//只有上层的res才需要减去头部长度protocol_header_length,里面的子对象不需要

	int objLength;	//某个类型的长度
	bool bFinish=false;
	DWORD fieldFlag;

	CInfoRoleToOtherInfo infoDecode;
	while(!bFinish)
	{
		fieldFlag=pStreamBuf->ReadRawVarInt32();
		//这里发现如果fieldFlag%8 ==2的话，是描述剩下那个类型的长度
		//如果%8==0则是参数的flag,表示第几个参数
		switch(fieldFlag>>3)
		{
		case 1:
			userId=pStreamBuf->ReadRawVarInt64();
			break;
		case 2:
			{
				//这里要设定长度
				objLength=pStreamBuf->ReadRawVarInt32();
				infoDecode.SetPackageLengthInRes(objLength);
				if(objLength>0)
				{
					infoDecode.Decode(pStreamBuf);	//在里面把长度处理了
					roleList.push_back(infoDecode);
				}
			}
	
			break;
		case 3:
			
			{
				//这里要设定长度
				objLength=pStreamBuf->ReadRawVarInt32();
				infoDecode.SetPackageLengthInRes(objLength);
				if(objLength>0)
					infoDecode.Decode(pStreamBuf);
			}
			
			break;
		default:
			break;

		}

		bFinish=(pStreamBuf->GetHandlePos()-orgPos)>=restBytes;

	}


// 	CInfoRoleToOtherInfo info;
// 	CInfoRoleToOtherInfo delInfo;
// 	bool bFinish=false;
// 
// 	int roleSimpleLength=pStreamBuf->ReadRawVarInt32();
// 	info.SetPackageLengthInRes(roleSimpleLength);
// 
// 	info.Decode(pStreamBuf);
// 	delInfo.Decode(pStreamBuf);
			

EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	//TRACE_OUTPUT(_T("CInfoResGetRoleList 解析长度:%d\n"),handleLength);
	return handleLength;
}