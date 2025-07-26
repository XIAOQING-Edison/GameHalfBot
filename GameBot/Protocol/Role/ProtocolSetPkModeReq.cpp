#include "ProtocolSetPkModeReq.h"

CProtocolSetPkModeReq::CProtocolSetPkModeReq(void)
{
	SetProtocolIdReq(ReqSetPKMode);
}

CProtocolSetPkModeReq::~CProtocolSetPkModeReq(void)
{
}


bool CProtocolSetPkModeReq::Encode(CStreamReadWrite *pStreamBuf)
{
	int len=0;//4+sizeof(sign_byte);

	CProtocol::Encode(pStreamBuf);
	ResetWritePostion();

	int count=1;	//要写入4个参数
	for(int i=1;i<=count;++i)
	{
		if(!(m_pkMode ==0 && i==1))
			pStreamBuf->WriteByte(i*(1<<3));
		if(i==1)
		{
			pStreamBuf->WriteRawVariant32(m_pkMode);
		}
	}


	len=m_pProtocolEncodeStreamBuf->GetCurWritePostion();	//

	return true;
}



void CProtocolSetPkModeReq::MakePkModeMessage(int m)//编码pk模式
{
	this->m_pkMode=m;
}
