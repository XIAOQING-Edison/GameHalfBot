#pragma once
#include "../Global/public.h"

struct _KEY_VALUE_
{
	_KEY_VALUE_()
	{
	}
	STRING strKey;
	STRING strValue;
};


class CConfigStruct
{
public:
	CConfigStruct(void);
	~CConfigStruct(void);
	_KEY_VALUE_ *GetStructByKeyName(STRING &key);
	void SetStructValue(STRING &key,int value);
	void SetStructValue(STRING &key,STRING &value);

	void AddStructValue(STRING &key,int value);
	void AddStructValue(STRING &key,STRING &value);
private:
	vector<_KEY_VALUE_> m_keyValueList;
};


class CConfigSection
{
public:
	CConfigSection();
	~CConfigSection();
	void SetConfigSection(STRING &section){m_sectionName=section;}
	STRING GetConfigSection(){return m_sectionName;}

	_KEY_VALUE_ *GetStructByKeyName(STRING &key){return m_configStruct.GetStructByKeyName(key);}
	void SetStructValue(STRING &key,int value){m_configStruct.SetStructValue(key,value);}
	void SetStructValue(STRING &key,STRING &value){m_configStruct.SetStructValue(key,value);}

	void AddStructValue(STRING &key,int value){m_configStruct.AddStructValue(key,value);}
	void AddStructValue(STRING &key,STRING &value){m_configStruct.AddStructValue(key,value);}

private:
	STRING m_sectionName;
	CConfigStruct m_configStruct;
};

