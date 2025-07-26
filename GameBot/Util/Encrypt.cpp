#include "Encrypt.h"


BYTE CEncrypt::magicBytes[4]={0x77,0x73,0x6e,0x64};// //{0x64,0x6e,0x73,0x77};

CEncrypt::CEncrypt(void)
{
	Reset();
}


void CEncrypt::Reset()
{
	InitEncrypt();
}

CEncrypt::~CEncrypt(void)
{

}


void CEncrypt::InitEncrypt()
{
}




void CEncrypt::EncryptData(char *pBuf,int len)
{

}