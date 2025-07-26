#include "Item.h"
#include "../GameData/ItemHelper.h"	//从itemhelper里直接读取
#include "../GameData/EquipHelper.h"
#include "../Protocol/Bag/InfoItemInfo.h"

#include "../GameUtility/ItemUtility.h"
#include "../GlobalObject/GlobalObject.h"


CItem::CItem(void)
{
	Init();
}

CItem::~CItem(void)
{
	m_excellentAttrs.clear();
	m_excellentStarAttrs.clear();
	m_regenerateAttrs.clear();
}

void CItem::Init()
{
	SetId(0);
	SetPos(0);
	SetCount(0);
	SetIsOcccupied(false);
}






//解析物品格里的物品
//这里需要直接是CInfoItemInfo指针，不能是其它指针
bool CItem::ParseInfoItemToItem(void *pInfoItem)
{
	bool ret=true;
	CInfoItemInfo *pItem=(CInfoItemInfo*)pInfoItem;
	TCHAR buf[MAX_PATH];
	STRING str;

	if(!pInfoItem)
	{
		Init();	//变成空格
		return ret;
	}
	SetPos(pItem->GetIndexInBag());
	SetId(pItem->GetId());
	m_itemInfo.itemId=pItem->GetConfigId();
	SetCount(pItem->GetCount());
	m_bIsBind=pItem->IsBind();	//是否绑定
	int i=0;
	_ITEM_INFO_ *pItemInfo=CItemHelper::GetInstance()->GetItemInfoById(pItem->GetConfigId());
	if(pItemInfo)
	{			
		m_itemInfo=*pItemInfo;	//复制属性
		if(m_itemInfo.IsEquipItem())	//装备还要将属性存起来
		{
			ParseInfoItemToEquip(pInfoItem);
// 			m_excellentAttrs=pItem->;
// 			m_excellentStarAttrs=pEquip->m_exStarAttrs.m_attributes;
// 			m_regenerateAttrs=pEquip->m_rebirthAttr.m_attributes;
			
		}
		

	}
	else
	{
		ret=false;
		{
			TRACE_OUTPUT(_T("物品配置:%d\t找不到信息!!!!!!!\n"),pItem->GetConfigId());
		}
	}

// 	TRACE(_T("update %s stack:%d\n"),m_name.c_str(),m_stack);
	return ret;
}

bool CItem::ParseInfoItemToEquip(void *pInfoItem)
{
	bool ret=false;
	CInfoItemInfo *pItem=(CInfoItemInfo*)pInfoItem;
	_EQUIPMENT_INFO_ *pEquipInfo=CEquipHelper::GetInstance()->GetEquipInfoById(pItem->GetConfigId());
	if(pEquipInfo)
	{
		m_equipInfo=*pEquipInfo;
	}

	return ret;
}

bool CItem::IsMaterial()	//是否材料
{
	return GetItemInfo()->itemType==EItemTypeMaterial;
}


bool CItem::IsLowestEquip()	//是否最低级装备
{
	CItemUtility *pItemUtility= CGlobalObject::GetInstance()->GetItemUtility();
	_ITEM_INFO_ *pItemInfo=GetItemInfo();
	return pItemUtility->IsEquipType(pItemInfo->itemType) && pItemInfo->quality<=1;
}
//////////////////////////////////////////////////////////////////////////
bool CItem::IsMountEquipType()//是否坐骑装备
{
	return (m_itemInfo.itemType==EItemTypeEquipe && m_itemInfo.itemSubType==EItemSubTypeMount);
}


bool CItem::IsEquipSuit()	//是否套装?
{
	return m_equipInfo.GetExtraInfo()->strSuitId.length()>0;
}