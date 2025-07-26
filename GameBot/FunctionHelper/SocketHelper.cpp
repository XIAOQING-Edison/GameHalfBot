#include "SocketHelper.h"
#include "../Player.h"
//#include "../Misc/HookHelper.h"


const int g_defEncodeBufLength=0x1000;

bool TestWriteFile(const TCHAR *szPath,char *data,int len)
{
	bool ret=false;
	STRING strFile=szPath;//_T("d:\\aa.bin");
	HANDLE hFile=CreateFile(strFile.c_str(),GENERIC_WRITE,FILE_SHARE_READ,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_ARCHIVE,NULL);
	if(hFile==INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL,_T("Error when write file\n"),_T("Error"),MB_ICONERROR);
		return false;
	}
	DWORD bytesWrote;
	ret=WriteFile(hFile,data,len,&bytesWrote,NULL);
	SAFE_CLOSE_HANDLE(hFile);
	return ret;
}



CSocketHelper::CSocketHelper(void)
{
	Init();
}

CSocketHelper::~CSocketHelper(void)
{
	CloseAllObjects();
}


void CSocketHelper::CloseAllObjects()
{
	TRACE_OUTPUT(_T("------------SocketHelper清理开始------------\n"));
	SAFE_CLOSE_SOCKET(m_playerSocket);

// 	WaitForSingleObject(m_hEvtPlay,200);
// 	WaitForSingleObject(m_hThreadPlay,100);
// 	SAFE_CLOSE_HANDLE(m_hEvtPlay);
	SAFE_CLOSE_HANDLE(m_hThreadPlay);

	//删除内存缓冲
	SAFE_DELETE_POINTER(m_pStreamBufEncode);
	SAFE_DELETE_POINTER(m_pStreamBufRecv);

	TRACE_OUTPUT(_T("------------SocketHelper清理结束------------\n"));
}

void CSocketHelper::Init()
{
#ifdef USE_WSS_SOCKET
	m_pWsClient=NULL;
#endif // USE_WSS_SOCKET
	
	m_port=0;
	m_playerSocket=INVALID_SOCKET;
	m_hThreadPlay=NULL;
	m_hThreadRecv=NULL;
	m_playerSocket=INVALID_SOCKET;

	//m_encryptMethod.InitEncrypt();	//在初始化时调用init sbox
	SetPlayer(NULL);
	m_pStreamBufRecv=new CStreamReadWrite(E_ENDIAN_TYPE_LITTLE_ENDIAN,0x100000);	//使用默认缓冲长度,传0就是用默认
	m_pStreamBufEncode=new CStreamReadWrite(E_ENDIAN_TYPE_LITTLE_ENDIAN,0);

	//test
	SetCaptureNow(false);	//默认不开启
}





bool CSocketHelper::IsPlayerQuit()
{
	{return (m_pThisPlayer&& m_pThisPlayer->IsQuit());}
}


/************************************************************************/
/* 发包前重新加入包头长度写到缓冲                                       */
/************************************************************************/
//发送前调用的函数:
char *CSocketHelper::CompactData(CProtocol *pProtocol,int &len)	//这里计算protocol原始长度，在发送这前计算总长度和加入sign_byte
{
	char *pData=NULL;
	//基础大小，代表包大小，4字节+1字节(sign_byte)，则总包长是5+包体长度
	//包的内容是包长4+flag(4字节0)+原来的包内容
	CStreamReadWrite byteWriter(E_ENDIAN_TYPE_BIG_ENDIAN,64);	//主要用于写前面10字节
	int headerLength=protocol_header_length;	//数据前有10字节描述
	
	int totalLength=headerLength+pProtocol->GetProtocolBufLength();	//这里需要重新写一个长度
	int packageFlag=0;
	len=totalLength;
	char *pNew=new char[totalLength];
	pData=pNew;

	//先写包头描述
	byteWriter.WriteFixedInt32(totalLength);
	byteWriter.WriteFixedInt32(pProtocol->GetProtocolIdReq());
	byteWriter.WriteShort(packageFlag);
	memcpy(pNew,byteWriter.GetBufHead(),byteWriter.GetCurWritePostion());
	pNew +=byteWriter.GetCurWritePostion();

	//再将包内容写入到剩余的地址里
	memcpy(pNew,pProtocol->GetProtocolBuf(),pProtocol->GetProtocolBufLength());

	//TRACE_OUTPUT(_T("最终发送数据:%s\n"),HexArrayToString(pData,totalLength).c_str());
	return pData;
}


bool CSocketHelper::SendData(char *pData,int totalLength)	//这里循环调用send直到发送完成
{
	bool ret=true;
	int sentDataLength=0;
	sentDataLength=send(m_playerSocket,pData,totalLength,0);
	ret=(sentDataLength>0);
	return ret;
}


/************************************************************************/
/*                   下面是调用发包实现功能的函数                       */
/************************************************************************/

bool CSocketHelper::SendSetPkMode(int mode)	//设定pk模式
{
	bool ret=true;
	CProtocol *p=NULL;
	int totalLength=0;
	p=CProtocolMap::GetInstance()->GetProtocolById(ReqSetPKMode);
	if(p && g_pThreadSendLock)
	{
		g_pThreadSendLock->Lock();
		CProtocolSetPkModeReq *pReq=(CProtocolSetPkModeReq*)p;
		pReq->MakePkModeMessage(mode);
		p->Encode(m_pStreamBufEncode);
		char *pData=CompactData(p,totalLength);
		g_pThreadSendLock->UnLock();
		if(!SendData(pData,totalLength))
		{
			TRACE_OUTPUT(_T("--------------------------------发送设置pk模式失败,错误号:%d---------------------------!!\n"),WSAGetLastError());
			ret=false;
		}
		SAFE_DELETE_ARRAY(pData);
	}
	return ret;
}








//////////////////////////////////////////////////////////////////////////
////////////////////////////////static functions//////////////////////////////////////////

// DWORD WINAPI CSocketHelper::ThreadReceive(LPVOID pParam)	//用于接收包以及解释
// {
// 	CSocketHelper *socketHelper=(CSocketHelper*)pParam;
// 	while(!socketHelper->IsPlayerQuit())
// 	{
// 		if(socketHelper->ReceiveServerMessage())
// 		{
// 			if(socketHelper->IsPlayerQuit())
// 			{
// 				goto EXT;
// 			}
// 		}
// 		else
// 		{
// 			printf("recv error,exit\n");
// 			goto EXT;
// 		}
// 	}
// EXT:
// 	return 0xdd;
// }
// 
// 

