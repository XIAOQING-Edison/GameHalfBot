#include "ConfigStruct.h"

CConfigStruct::CConfigStruct(void)
{
}

CConfigStruct::~CConfigStruct(void)
{
}



_KEY_VALUE_ *CConfigStruct::GetStructByKeyName(STRING &key)
{
	_KEY_VALUE_ *pRet=NULL;
	vector<_KEY_VALUE_>::iterator it=m_keyValueList.begin();
	while(it != m_keyValueList.end())
	{
		if(it->strKey==key)
		{
			pRet=&*it;
			break;
		}
		++it;
	}
	return pRet;
}


void CConfigStruct::SetStructValue(STRING &key,int value)
{
	TCHAR buf[64];
	_KEY_VALUE_ *pRet=GetStructByKeyName(key);
	if(pRet)
	{
		_stprintf(buf,_T("%u"),(DWORD)value);
		pRet->strValue=buf;
	}
	
}


void CConfigStruct::SetStructValue(STRING &key,STRING &value)
{
	_KEY_VALUE_ *pRet=GetStructByKeyName(key);
	if(pRet)
	{
		pRet->strValue=value;
	}
}



void CConfigStruct::AddStructValue(STRING &key,int value)
{
	_KEY_VALUE_ val;
	TCHAR buf[64];
	_stprintf(buf,_T("%u"),(DWORD)value);
	val.strKey=key;
	val.strValue=buf;
	m_keyValueList.push_back(val);
}


void CConfigStruct::AddStructValue(STRING &key,STRING &value)
{
	_KEY_VALUE_ val;
	val.strKey=key;
	val.strValue=value;
	m_keyValueList.push_back(val);
}







//////////////////////////////////////////////////////////////////////////
CConfigSection::CConfigSection()
{

}


CConfigSection::~CConfigSection()
{

}
