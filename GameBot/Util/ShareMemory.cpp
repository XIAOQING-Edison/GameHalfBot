#include "ShareMemory.h"

//这个是文件无关的内存，所以hFile为-1;
CShareMemory::CShareMemory(int sz,bool bCreator)
{
	Init();
	SetMemorySize(sz);
	SetIsCreator(bCreator);
}

CShareMemory::~CShareMemory(void)
{
	if(m_pMemoryAddress && IsCreator())	//创建者才需要最后释放
	{
		UnmapViewOfFile(m_pMemoryAddress);
	}
	SAFE_CLOSE_HANDLE(m_hFileMap);

}


void CShareMemory::Init()
{
	SetMemoryAddress(NULL);
	SetMemorySize(0);
	m_hFileMap=NULL;
}



bool CShareMemory::CreateShareMemory(const TCHAR *szName)
{
	bool ret=false;
	if(m_hFileMap==NULL)
	{
		m_hFileMap=CreateFileMapping(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,m_memorySize,szName);
	}
	if(!m_hFileMap)
	{
		TRACE_OUTPUT(_T("create file map failed error:%x\n"),GetLastError());
	}
	else
	{
		m_pMemoryAddress=(char*)MapViewOfFile(m_hFileMap,FILE_MAP_READ|FILE_MAP_WRITE,0,0,0);
		if(!m_pMemoryAddress)
		{
			TRACE_OUTPUT(_T("map view of file failed,error:%x\n"),GetLastError());
		}
		else
		{
			if(IsCreator())
				FillSharedMemory(0xff);
		}
	}
	ret=(m_hFileMap !=NULL)&&(m_pMemoryAddress);
	return ret;
}


bool CShareMemory::OpenShareMemory(const TCHAR *szName)
{
	bool ret=true;
	HANDLE hFileMap=OpenFileMapping(FILE_MAP_READ,FALSE,szName);
	if(hFileMap)
	{
		m_pMemoryAddress=(char*)MapViewOfFile(hFileMap,FILE_MAP_READ,0,0,0);
		if(!m_pMemoryAddress)
		{
			ret=false;
		}
	}
	else
	{
		TRACE_OUTPUT(_T("打开名字为:%s的共享内存错误:%x\n"),szName,GetLastError());
		ret=false;
	}
	SAFE_CLOSE_HANDLE(hFileMap);
	return ret;
}

bool CShareMemory::WriteSharedMemory(void *data,int len)
{
	bool ret=false;
	if(len>m_memorySize)
	{
		//TRACE(_T("写的大小大于内存尺寸!!!!\n"));
		goto EXT;
	}
	else
	{
		if(!m_pMemoryAddress)
		{
			//TRACE(_T("写时内存地址还没映射!!!!\n"));
			goto EXT;
		}
		memcpy(m_pMemoryAddress,data,len);
		ret=true;
	}

EXT:
	return ret;
}


bool CShareMemory::ReadSharedMemory(void *data,int len)
{
	bool ret=false;
	if(len>m_memorySize)
	{
		//TRACE(_T("读的大小大于内存尺寸!!!!\n"));
		goto EXT;
	}
	else
	{
		if(!m_pMemoryAddress)
		{
			//TRACE(_T("读时内存地址还没映射!!!!\n"));
			goto EXT;
		}
		memcpy(data,m_pMemoryAddress,len);
		ret=true;
	}

EXT:
	return ret;
}


bool CShareMemory::WriteSharedMemoryByOffset(void *data,int offset,int len)
{
	bool ret=false;
	if(len>m_memorySize || (offset+len)>m_memorySize)
	{
		//TRACE(_T("写的大小大于内存尺寸!!!!\n"));
		goto EXT;
	}
	else
	{
		if(!m_pMemoryAddress)
		{
			//TRACE(_T("写时内存地址还没映射!!!!\n"));
			goto EXT;
		}
		memcpy(m_pMemoryAddress+offset,data,len);
		ret=true;
	}

EXT:
	return ret;
}


bool CShareMemory::ReadShreadMemoryByOffset(void *data,int offset,int len)
{
	bool ret=false;
	if(len>m_memorySize || (offset+len)>m_memorySize)
	{
		//TRACE(_T("读的大小大于内存尺寸!!!!\n"));
		goto EXT;
	}
	else
	{
		if(!m_pMemoryAddress)
		{
			//TRACE(_T("读时内存地址还没映射!!!!\n"));
			goto EXT;
		}
		memcpy(data,m_pMemoryAddress+offset,len);
		ret=true;
	}

EXT:
	return ret;
}


void CShareMemory::FillSharedMemory(int value)	//将内存默认置某值
{
	if(m_pMemoryAddress && m_memorySize>0)
		memset(m_pMemoryAddress,value,m_memorySize);
}