#pragma once
#include "../Global/public.h"
class CEncrypt
{
public:
	CEncrypt(void);
	~CEncrypt(void);

	void InitEncrypt();	//初始化加密函数

	void EncryptData(char *pBuf,int len);	//这个调用将pBuf转为int转为outputBuf

	char *GetEncryptData(){return (char*)magicBytes;}

	void Reset();

private:
	static BYTE magicBytes[4];// //{0x64,0x6e,0x73,0x77};

};
