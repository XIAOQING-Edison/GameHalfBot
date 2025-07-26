#include "ProtocolMap.h"


CProtocolMap *CProtocolMap::s_pProtocolMap=NULL;

CProtocolMap::CProtocolMap(void)
{
	SetCurrentPlayer(NULL);
}

CProtocolMap::~CProtocolMap(void)
{
	DeleteProtocolMap();
}


void CProtocolMap::DeleteInstance()
{
	SAFE_DELETE_POINTER(s_pProtocolMap);
}



CProtocolMap *CProtocolMap::GetInstance()
{
	if(CProtocolMap::s_pProtocolMap==NULL)
	{
		CProtocolMap::s_pProtocolMap=new CProtocolMap();
	}
	return CProtocolMap::s_pProtocolMap;
}


CProtocol *CProtocolMap::GetProtocolById(DWORD id)
{
	map<DWORD,CProtocol*>::iterator it=m_protolcolMap.find(id);
	CProtocol *p=NULL;
	if(it !=m_protolcolMap.end())
	{
		p=it->second;
	}
	return p;

}

int CProtocolMap::DecodeProtocol(BYTE *p,int len)	//利用map来处理,循环处理数据，能解析的协议都解析了
{
	int handleLength=0;
	int pos=0;	//指向缓冲位置	
	CProtocol protocol;
	if(len<protocol_header_length)
	{
		printf("data len:%d < protocol header length\n",len);
		goto EXT;
	}

 EXT:
	handleLength=pos;
	return handleLength;
}

//len是调用decodeFirst返回的包长度
int CProtocolMap::DecodeProtocolOnce(DWORD protocolId,int len,CStreamReadWrite *pStreamBuf)	//利用map来处理,每次只处理一个协议长度
{
	int handleLength=0;
	int pos=0;	//指向缓冲位置	
	
	CProtocol *pProtocol=GetProtocolById(protocolId);
	CProtocol *pProtocolDst=NULL;
	short realProtocolId=(short)protocolId;

	if(pProtocol)
	{
		//pProtocol->Clone(&pProtocolDst);
		//TRACE_OUTPUT(_T("找到协议id:%d的对象进行解析\n"),protocolId);
		CProtocol *pProtocolDst=pProtocol;
		pProtocol->SetPackageLengthInRes(len);	//得到实际包长度
		pProtocolDst->SetCurrentPlayer(m_pPlayer);
		pos=pProtocolDst->Decode(pStreamBuf);
	}
	else	//找不到协议处理，可能未完成，则跳过剩下的字节
	{
		//TRACE_OUTPUT(_T("跳过协议%d\n"),protocolId);
		pos=len-protocol_header_length;	//
		pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+pos);	//跳过
		//TRACE(_T("unhandle protocol id:%d\n"),(short)protocolId);
	}
	


EXT:
	handleLength=pos;
	return handleLength;
}

bool CProtocolMap::InitProtocolMap()
{
	bool ret=false;
	DeleteProtocolMap();
	CProtocol *pProtocol=NULL;


	//login
	//user
	pProtocol=new CProtocolLoginRes;
	m_protolcolMap[pProtocol->GetProtocolIdResOrSyn()]=pProtocol;

	pProtocol=new CProtocolEnterGameRes;
	m_protolcolMap[pProtocol->GetProtocolIdResOrSyn()]=pProtocol;

	pProtocol=new CProtocolGetRoleListRes;	//解析ok，先屏蔽掉
	m_protolcolMap[pProtocol->GetProtocolIdResOrSyn()]=pProtocol;


	pProtocol=new CProtocolPlayerInfoRes;
	m_protolcolMap[pProtocol->GetProtocolIdResOrSyn()]=pProtocol;

	pProtocol=new CProtocolSetPkModeReq;
	m_protolcolMap[pProtocol->GetProtocolIdReq()]=pProtocol;


	
	pProtocol=new CProtocolBagInfoRes;
	m_protolcolMap[pProtocol->GetProtocolIdResOrSyn()]=pProtocol;

	pProtocol=new CProtocolStorageInfoRes;
	m_protolcolMap[pProtocol->GetProtocolIdResOrSyn()]=pProtocol;
	
	InitProtocolMapInTianShiZhiZhanPc();

	return ret;

}


void CProtocolMap::AddToProtocolMap(DWORD id,CProtocol *p)	//将protocolId和指针存到map中
{
	if(p)
	{
		m_protolcolMap.insert(make_pair(id,p));
	}
}


bool CProtocolMap::DeleteProtocolMap()
{
	bool ret=true;

	map<DWORD,CProtocol*>::iterator it=m_protolcolMap.begin();
	while( it !=m_protolcolMap.end())
	{
		CProtocol *p=it->second;
		delete p;
		++it;
	}

	return ret;
}



bool CProtocolMap::InitProtocolMapInTianShiZhiZhan()	//这里初始化一些MU1才用到的协议
{
	bool ret=true;
	CProtocol *pProtocol=NULL;

	//bag
	pProtocol=new CProtocolConstellationBagInfoRes;
	m_protolcolMap[pProtocol->GetProtocolIdResOrSyn()]=pProtocol;

	return ret;
}


bool  CProtocolMap::InitProtocolMapInTianShiZhiZhanPc()	//天使之战PC端才用到的
{
	bool ret=true;
	CProtocol *pProtocol=NULL;

	//bag
	pProtocol=new CProtocolAllStorageInfoRes;
	m_protolcolMap[pProtocol->GetProtocolIdResOrSyn()]=pProtocol;

	return ret;
}