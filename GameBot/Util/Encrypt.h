#pragma once
#include "../Global/public.h"
class CEncrypt
{
public:
	CEncrypt(void);
	~CEncrypt(void);

	void InitEncrypt();	//��ʼ�����ܺ���

	void EncryptData(char *pBuf,int len);	//������ý�pBufתΪintתΪoutputBuf

	char *GetEncryptData(){return (char*)magicBytes;}

	void Reset();

private:
	static BYTE magicBytes[4];// //{0x64,0x6e,0x73,0x77};

};
