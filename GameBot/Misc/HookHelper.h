#pragma once
#include "../Global/public.h"
#include "../MemoryStream/StreamReadWrite.h"
class CPlayer;
class CProtocol;
//����͵Ĳ���Ҫ����࣬�ѻ�����Ҫ
//��Ҫ�޸�һ�εİ���������
enum E_MODIFY_PACKAGE_INDEX
{
	e_modify_package_secretary_time=0,	//С����ʱ��
};


class CHookHelper
{
public:
	CHookHelper(void);
	~CHookHelper(void);

	void SetPlayer(CPlayer *p){m_pPlayer=p;}
	CPlayer *GetPlayer(){return m_pPlayer;}

	bool IsInGameServer();

	static CHookHelper *GetInstance();
	static void DeleteInstance();

	bool IsMainSocketValid(){return (GetMainServerSocket()!=INVALID_SOCKET);}

	void SetMainServerIp(const char *ip){m_mainServerIp=ip;}
	string GetMainServerIp(){return m_mainServerIp;}

	void SetMainServerPort(WORD port){m_mainServerPort=port;}
	WORD GetMainServerPort(){return m_mainServerPort;}

	void SetCrossServerIp(const char *ip){m_crossServerIp=ip;}
	string GetCrossServerIp(){return m_crossServerIp;}

	void SetCrossServerPort(WORD port){m_crossServerPort=port;}
	WORD GetCrossServerPort(){return m_crossServerPort;}


	void SetMainServerSocket(SOCKET s){m_mainServerSocket=s;}
	SOCKET GetMainServerSocket(){return m_mainServerSocket;}


	void SetCrossServerSocket(SOCKET s){m_crossServerSocket=s;}
	SOCKET GetCrossServerSocket(){return m_crossServerSocket;}


	void Reset();	//ʵʼ�����ֱ��������������Ҫ�ⲿ����
	
	bool IsHooked(){return m_bHooked;}
	void SetHooked(bool b){m_bHooked=b;}

	//------------�������޸�,��ʼ
	//���͵��޸�
	int ModifyRecycleItemMessage(const char *data,int len,char **newBuf,bool &bModify);	//�޸ķ��ͻ�����Ϣ,�����³���,newBuf������buf
	int CheckIsSendVipMemberInfoMessage(const char *data,int len,char **newBuf,bool &bModify);	//���δ�������������ͻ�ȡvip��Ա��Ϣ���޸�Ϊ��������
	int CheckAndModifyCreateRoleMessage(const char *data,int len,char **newBuf,bool &bModify);	//�޸Ĵ�����ɫ����

	//���յ��޸�,�����޸ĵĺ��������ܳ���bufLength!!!!!
	//-------------�������޸ģ�����


	//ע��!!�����޸ĵĳ��Ȳ��ܳ���bufLength,������������
	int HandleRecv(SOCKET s,char *buf,int len,int bufLength,char **newBuf,bool &bIsModify);	//���������޸Ļ��������,����newlen,bisModify=trueʱ�����޸��˷���

	int HandleSend(SOCKET s,char *buf,int len,char **newBuf,bool &bIsModify);	//������޸ķ��Ͳ���,����newlen

	int DecodeBuffer(SOCKET s,char *buf,int len);

	void ResetCrossServerStreamBuffer();	//����

	void ResetCrossServerSocket();	//�˳����ʱ����

	void ResetSocketAndStreamBuf();	//�Ͽ�ʱ���ж�������

	void CheckSocketState(SOCKET s);	//���socket״̬

	bool IsMainGameRedirectUrl(STRING &url);	//�Ƿ�������ϷURL
	
	void CheckAndSetSocket(SOCKET s,const char *ip,WORD port);	//�趨����Ҫ��socket

	//���send����
	bool CheckIsSendLoginMessage(const char *data,int len);	//����Ƿ��ǵ�½��
	bool CheckSendChooseRoleMessage(const char *data,int len);//��鷢�͵Ľ�ɫѡ���

	bool IsSameMainGameSocket(SOCKET s);	//�Ƿ�����socket,�����ǵ�½�õ�socket
private:
	int MakeNewRecvData(CProtocol *pProtocol,char **newBuf,int preLength,const char *orgRecvData,int orgRecvLength);	//����һ��new recv data,�����³���
	char *GetRecvBuf(){return m_pRecvBuf;}
	char *GetSendBuf(){return m_pSendBuf;}
private:
	SOCKET m_mainServerSocket;
	SOCKET m_crossServerSocket;
	SOCKET m_duplicateSocket;	//���ƹ�����sockect
	CPlayer *m_pPlayer;
	string m_mainServerIp;
	WORD m_mainServerPort;
	string m_crossServerIp;
	WORD m_crossServerPort;

	static CHookHelper *s_pHookHelperInstance;
	CStreamReadWrite *m_pStreamBufRecv;
	CStreamReadWrite *m_pStreamBufSend;
	char *m_pRecvBuf;	//�޸Ľ��յĻ���
	char *m_pSendBuf;	//�޸ķ��͵Ļ���
	char *m_pTmpRecvBuf;	//��ʱ����޸ĺ�Ļ���

	WSAPROTOCOL_INFO m_duplicateSocketInfo;	//������Ҫ���Ƶ�socket��Ϣ

	bool m_bHooked;	//�Ƿ��ѹҹ�
	bool m_bSecetaryWorkFine;	//С���鹤���Ƿ�����
};
