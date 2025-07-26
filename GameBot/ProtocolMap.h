#pragma once
#include "Protocol/Protocol.h"
#include <map>

//user
#include "Protocol/User/ProtocolLoginRes.h"
#include "Protocol/User/ProtocolEnterGameRes.h"
#include "Protocol/User/ProtocolGetRoleListRes.h"

//map




//drop




//role
#include "Protocol/Role/ProtocolPlayerInfoRes.h"
#include "Protocol/Role/ProtocolSetPkModeReq.h"



//bag
#include "Protocol/Bag/ProtocolStorageInfoRes.h"	//�ֿ�
#include "Protocol/Bag/ProtocolBagInfoRes.h"	//����

//mu1ʹ��
#include "Protocol/Bag/ProtocolConstellationBagInfoRes.h"

//mu1 PCʹ��
#include "Protocol/Bag/ProtocolAllStorageInfoRes.h"




using namespace std;
class CProtocolMap
{
public:
	CProtocolMap(void);
	virtual ~CProtocolMap(void);

	static void DeleteInstance();
	static CProtocolMap *GetInstance();

	CProtocol *GetProtocolById(DWORD id);

	int DecodeProtocol(BYTE *p,int len);	//����map������,ѭ���������ݣ��ܽ�����Э�鶼������

	int DecodeProtocolOnce(DWORD protocolId,int len,CStreamReadWrite *pStreamBuf);	//����map������,ÿ��ֻ����һ��Э�鳤��

	bool InitProtocolMap();


	bool DeleteProtocolMap();

	void SetCurrentPlayer(CPlayer *p){m_pPlayer=p;}

	void AddToProtocolMap(DWORD id,CProtocol *p);	//��protocolId��ָ��浽map��

	int GetSize(){return m_protolcolMap.size();}

private:
	bool InitProtocolMapInTianShiZhiZhan();	//�����ʼ��һЩ��ʹ��ս���õ���Э��
	bool InitProtocolMapInTianShiZhiZhanPc();	//��ʹ֮սPC�˲��õ���
	bool InitProtocolMapInTianShiShenYu();	//����,to do
	bool InitProtocolMapInYongHengZhiDian();//����֮��,to do
private:
	CPlayer *m_pPlayer;
	map<DWORD,CProtocol*>	m_protolcolMap;
	static CProtocolMap *s_pProtocolMap;
};
