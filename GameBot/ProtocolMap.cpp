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

int CProtocolMap::DecodeProtocol(BYTE *p,int len)	//����map������,ѭ���������ݣ��ܽ�����Э�鶼������
{
	int handleLength=0;
	int pos=0;	//ָ�򻺳�λ��	
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

//len�ǵ���decodeFirst���صİ�����
int CProtocolMap::DecodeProtocolOnce(DWORD protocolId,int len,CStreamReadWrite *pStreamBuf)	//����map������,ÿ��ֻ����һ��Э�鳤��
{
	int handleLength=0;
	int pos=0;	//ָ�򻺳�λ��	
	
	CProtocol *pProtocol=GetProtocolById(protocolId);
	CProtocol *pProtocolDst=NULL;
	short realProtocolId=(short)protocolId;

	if(pProtocol)
	{
		//pProtocol->Clone(&pProtocolDst);
		//TRACE_OUTPUT(_T("�ҵ�Э��id:%d�Ķ�����н���\n"),protocolId);
		CProtocol *pProtocolDst=pProtocol;
		pProtocol->SetPackageLengthInRes(len);	//�õ�ʵ�ʰ�����
		pProtocolDst->SetCurrentPlayer(m_pPlayer);
		pos=pProtocolDst->Decode(pStreamBuf);
	}
	else	//�Ҳ���Э�鴦������δ��ɣ�������ʣ�µ��ֽ�
	{
		//TRACE_OUTPUT(_T("����Э��%d\n"),protocolId);
		pos=len-protocol_header_length;	//
		pStreamBuf->SetHandlePos(pStreamBuf->GetHandlePos()+pos);	//����
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

	pProtocol=new CProtocolGetRoleListRes;	//����ok�������ε�
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


void CProtocolMap::AddToProtocolMap(DWORD id,CProtocol *p)	//��protocolId��ָ��浽map��
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



bool CProtocolMap::InitProtocolMapInTianShiZhiZhan()	//�����ʼ��һЩMU1���õ���Э��
{
	bool ret=true;
	CProtocol *pProtocol=NULL;

	//bag
	pProtocol=new CProtocolConstellationBagInfoRes;
	m_protolcolMap[pProtocol->GetProtocolIdResOrSyn()]=pProtocol;

	return ret;
}


bool  CProtocolMap::InitProtocolMapInTianShiZhiZhanPc()	//��ʹ֮սPC�˲��õ���
{
	bool ret=true;
	CProtocol *pProtocol=NULL;

	//bag
	pProtocol=new CProtocolAllStorageInfoRes;
	m_protolcolMap[pProtocol->GetProtocolIdResOrSyn()]=pProtocol;

	return ret;
}