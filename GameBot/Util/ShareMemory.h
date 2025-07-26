#pragma once
#include "../Global/public.h"

//use file maping
class CShareMemory
{
public:
	CShareMemory(int sz,bool bCreator=true);
	~CShareMemory(void);

	
	
	bool CreateShareMemory(const TCHAR *szName);
	
	bool OpenShareMemory(const TCHAR *szName);

	void SetMemorySize(int sz){m_memorySize=sz;}
	int GetMemorySize(){return m_memorySize;}

	void SetMemoryAddress(char *add){m_pMemoryAddress=add;}
	char *GetMemoryAddress(){return m_pMemoryAddress;}

	void SetIsCreator(bool b){m_bCreator=b;}
	bool IsCreator(){return m_bCreator;}

	bool WriteSharedMemory(void *data,int len);
	bool ReadSharedMemory(void *data,int len);

	bool WriteSharedMemoryByOffset(void *data,int offset,int len);
	bool ReadShreadMemoryByOffset(void *data,int offset,int len);
protected:
	void FillSharedMemory(int value);	//将内存默认置某值
	void Init();
private:
	HANDLE m_hFileMap;
	int m_memorySize;
	char *m_pMemoryAddress;
	bool m_bCreator;	//是否是创建者，创建者需要最后释放这个memory
};
