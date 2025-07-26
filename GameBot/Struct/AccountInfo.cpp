#include "AccountInfo.h"

CAccountInfo::CAccountInfo(void)
{
	Reset();
}

CAccountInfo::~CAccountInfo(void)
{
}

void CAccountInfo::Reset()
{
	SetPlatformIndex(0);
	SetServerId(0);
	SetIndex(-1);
}