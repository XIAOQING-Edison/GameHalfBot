#pragma once
#include "../protocol.h"

//��ʹ֮սʹ�ã������汾��ʹ��
//����ֻΪ�˵�½����жϣ����Թؼ����ֶ�û������
class CProtocolConstellationBagInfoRes :
	public CProtocol
{
public:
	CProtocolConstellationBagInfoRes(void);
	virtual ~CProtocolConstellationBagInfoRes(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);
private:

};
