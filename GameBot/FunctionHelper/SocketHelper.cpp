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
	TRACE_OUTPUT(_T("------------SocketHelper����ʼ------------\n"));
	SAFE_CLOSE_SOCKET(m_playerSocket);

// 	WaitForSingleObject(m_hEvtPlay,200);
// 	WaitForSingleObject(m_hThreadPlay,100);
// 	SAFE_CLOSE_HANDLE(m_hEvtPlay);
	SAFE_CLOSE_HANDLE(m_hThreadPlay);

	//ɾ���ڴ滺��
	SAFE_DELETE_POINTER(m_pStreamBufEncode);
	SAFE_DELETE_POINTER(m_pStreamBufRecv);

	TRACE_OUTPUT(_T("------------SocketHelper�������------------\n"));
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

	//m_encryptMethod.InitEncrypt();	//�ڳ�ʼ��ʱ����init sbox
	SetPlayer(NULL);
	m_pStreamBufRecv=new CStreamReadWrite(E_ENDIAN_TYPE_LITTLE_ENDIAN,0x100000);	//ʹ��Ĭ�ϻ��峤��,��0������Ĭ��
	m_pStreamBufEncode=new CStreamReadWrite(E_ENDIAN_TYPE_LITTLE_ENDIAN,0);

	//test
	SetCaptureNow(false);	//Ĭ�ϲ�����
}





bool CSocketHelper::IsPlayerQuit()
{
	{return (m_pThisPlayer&& m_pThisPlayer->IsQuit());}
}


/************************************************************************/
/* ����ǰ���¼����ͷ����д������                                       */
/************************************************************************/
//����ǰ���õĺ���:
char *CSocketHelper::CompactData(CProtocol *pProtocol,int &len)	//�������protocolԭʼ���ȣ��ڷ�����ǰ�����ܳ��Ⱥͼ���sign_byte
{
	char *pData=NULL;
	//������С���������С��4�ֽ�+1�ֽ�(sign_byte)�����ܰ�����5+���峤��
	//���������ǰ���4+flag(4�ֽ�0)+ԭ���İ�����
	CStreamReadWrite byteWriter(E_ENDIAN_TYPE_BIG_ENDIAN,64);	//��Ҫ����дǰ��10�ֽ�
	int headerLength=protocol_header_length;	//����ǰ��10�ֽ�����
	
	int totalLength=headerLength+pProtocol->GetProtocolBufLength();	//������Ҫ����дһ������
	int packageFlag=0;
	len=totalLength;
	char *pNew=new char[totalLength];
	pData=pNew;

	//��д��ͷ����
	byteWriter.WriteFixedInt32(totalLength);
	byteWriter.WriteFixedInt32(pProtocol->GetProtocolIdReq());
	byteWriter.WriteShort(packageFlag);
	memcpy(pNew,byteWriter.GetBufHead(),byteWriter.GetCurWritePostion());
	pNew +=byteWriter.GetCurWritePostion();

	//�ٽ�������д�뵽ʣ��ĵ�ַ��
	memcpy(pNew,pProtocol->GetProtocolBuf(),pProtocol->GetProtocolBufLength());

	//TRACE_OUTPUT(_T("���շ�������:%s\n"),HexArrayToString(pData,totalLength).c_str());
	return pData;
}


bool CSocketHelper::SendData(char *pData,int totalLength)	//����ѭ������sendֱ���������
{
	bool ret=true;
	int sentDataLength=0;
	sentDataLength=send(m_playerSocket,pData,totalLength,0);
	ret=(sentDataLength>0);
	return ret;
}


/************************************************************************/
/*                   �����ǵ��÷���ʵ�ֹ��ܵĺ���                       */
/************************************************************************/

bool CSocketHelper::SendSetPkMode(int mode)	//�趨pkģʽ
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
			TRACE_OUTPUT(_T("--------------------------------��������pkģʽʧ��,�����:%d---------------------------!!\n"),WSAGetLastError());
			ret=false;
		}
		SAFE_DELETE_ARRAY(pData);
	}
	return ret;
}








//////////////////////////////////////////////////////////////////////////
////////////////////////////////static functions//////////////////////////////////////////

// DWORD WINAPI CSocketHelper::ThreadReceive(LPVOID pParam)	//���ڽ��հ��Լ�����
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

