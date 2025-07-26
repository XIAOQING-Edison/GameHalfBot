#include "../Global/public.h"
#include "Protocol.h"
#include "../ProtocolMap.h"

#pragma comment(lib,"StreamReadWrite.lib")
// #pragma comment(lib,"StreamReadWriteStatic.lib")

CProtocol::CProtocol(void)
{
	SetCurrentPlayer(NULL);
	Init();
}

CProtocol::~CProtocol(void)
{
}



void CProtocol::Init()
{
	m_pProtocolEncodeStreamBuf=NULL;
	SetProtocolIdReq(0);
	SetProtocolIdResOrSyn(0);
}


// bool CProtocol::AllocateEncodeBuf(int len)	//需要分配编码内存缓冲,len=0的话用默认长度来创建
// {
// 	if(m_pProtocolEncodeStreamBuf)
// 	{
// 		if(m_pProtocolEncodeStreamBuf->GetBufLength()<len)
// 		{
// // 			m_pProtocolEncodeStreamBuf->AllocNewBufferAndSetLength(len);
// 			printf("encode buf:%d less than need %d\n",m_pProtocolEncodeStreamBuf->GetBufLength(),len);
// 			return false;
// 		}
// 	}
// 	else
// 	{
// 		if(len<=0)
// 		{
// 			len=g_defEncodeBufLength;
// 			m_pProtocolEncodeStreamBuf=new CStreamReadWrite(E_ENDIAN_TYPE_BIG_ENDIAN,g_defEncodeBufLength,FALSE);
// 
// 		}
// 	}
// 	return (m_pProtocolEncodeStreamBuf->GetBufHead()!=NULL);
// 	
// }


void CProtocol::Clone(CProtocol **p)	//用虚函数来返回子类对象,这里的指针需要手动释放
{
	**p=*this;
}


int CProtocol::DecodeFirst(CStreamReadWrite *pStreamBuf)	//先解码出长度,protocolId这类
{
	int orgHandlePos=pStreamBuf->GetHandlePos();	//最初的位置存起来，后面长度不够时就再
	int packageLen=0;
	int protocolId=0;
	int minLen=0;	//包结构是4字节长度+4字节0+2字节协议ID,包的总长度是包长度+4字节,如果整体长度包括包长在内的为0，否则要填写实现描述长度
	int packageFlag;//2字节0命名为packageFlag
	int len=pStreamBuf->GetRestBytesLength();
	static int preProtocolId=0;
	pStreamBuf->SetEndianType(E_ENDIAN_TYPE_BIG_ENDIAN);	//前面是大端模式
	if(len>=protocol_header_length)	//剩余长度必须大于或等于最小长度
	{
		packageLen=pStreamBuf->ReadFixedInt32();	//读取到的包描述长度
		//此处的包长是包含包长描述字段在内的，所以与后面比较时需要减去包长描述字段
		int alreadReadLength=pStreamBuf->GetHandlePos()-orgHandlePos;	//本次已读取的字段长度
		//TRACE_OUTPUT(_T("总包长:%d,已读:%d,剩下字节:%d\n"),packageLen,alreadReadLength,pStreamBuf->GetRestBytesLength());
		if((packageLen-alreadReadLength+minLen)<=pStreamBuf->GetRestBytesLength())
		{

			protocolId=pStreamBuf->ReadFixedInt32();		
			packageFlag=pStreamBuf->ReadShort();	//两字节flag(00 00)
			SetProtocolIdResOrSyn(protocolId);
			if(protocolId != ResHeart)	//过滤心跳
				TRACE_OUTPUT(_T("协议id:%d,包长:%d\n"),protocolId,packageLen);
			preProtocolId=protocolId;	//testQ	A/		SetProtocolIdResOrSyn(protocolId);
		}
		else
		{
			//包需要的长度大于接收长度，则需要继续接收
			if(packageLen>0x1ffff)	//不可能超过这个数，超过应该是错的
			{
				TRACE_OUTPUT(_T("协议长度:%u 太长!!!!!!\n"),(DWORD)packageLen);
				TRACE_OUTPUT(_T("前一个协议 id:%d\n"),preProtocolId);
			}
			if(protocol_header_length>pStreamBuf->GetRestBytesLength() || packageLen > 2*MAX_BUF_LENGTH)
			{
				TRACE_OUTPUT(_T("包包长度:%d太小或太长，解析出错..\n"),packageLen);
			}
			//TRACE_OUTPUT(_T("包不完整--包长度:%d,剩余长度:%d\n"),packageLen,pStreamBuf->GetRestBytesLength());
			pStreamBuf->SetHandlePos(orgHandlePos);
			packageLen=0;
		}
	}
	pStreamBuf->SetEndianType(E_ENDIAN_TYPE_LITTLE_ENDIAN);	//前面是大端模式
	return packageLen;
}


