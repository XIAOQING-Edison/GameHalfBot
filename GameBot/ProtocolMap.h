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
#include "Protocol/Bag/ProtocolStorageInfoRes.h"	//仓库
#include "Protocol/Bag/ProtocolBagInfoRes.h"	//背包

//mu1使用
#include "Protocol/Bag/ProtocolConstellationBagInfoRes.h"

//mu1 PC使用
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

	int DecodeProtocol(BYTE *p,int len);	//利用map来处理,循环处理数据，能解析的协议都解析了

	int DecodeProtocolOnce(DWORD protocolId,int len,CStreamReadWrite *pStreamBuf);	//利用map来处理,每次只处理一个协议长度

	bool InitProtocolMap();


	bool DeleteProtocolMap();

	void SetCurrentPlayer(CPlayer *p){m_pPlayer=p;}

	void AddToProtocolMap(DWORD id,CProtocol *p);	//将protocolId和指针存到map中

	int GetSize(){return m_protolcolMap.size();}

private:
	bool InitProtocolMapInTianShiZhiZhan();	//这里初始化一些天使这战才用到的协议
	bool InitProtocolMapInTianShiZhiZhanPc();	//天使之战PC端才用到的
	bool InitProtocolMapInTianShiShenYu();	//神谕,to do
	bool InitProtocolMapInYongHengZhiDian();//永恒之颠,to do
private:
	CPlayer *m_pPlayer;
	map<DWORD,CProtocol*>	m_protolcolMap;
	static CProtocolMap *s_pProtocolMap;
};
