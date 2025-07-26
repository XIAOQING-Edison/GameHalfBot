#include "Item.h"
#include "../GameData/ItemHelper.h"	//��itemhelper��ֱ�Ӷ�ȡ
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






//������Ʒ�������Ʒ
//������Ҫֱ����CInfoItemInfoָ�룬����������ָ��
bool CItem::ParseInfoItemToItem(void *pInfoItem)
{
	bool ret=true;
	CInfoItemInfo *pItem=(CInfoItemInfo*)pInfoItem;
	TCHAR buf[MAX_PATH];
	STRING str;

	if(!pInfoItem)
	{
		Init();	//��ɿո�
		return ret;
	}
	SetPos(pItem->GetIndexInBag());
	SetId(pItem->GetId());
	m_itemInfo.itemId=pItem->GetConfigId();
	SetCount(pItem->GetCount());
	m_bIsBind=pItem->IsBind();	//�Ƿ��
	int i=0;
	_ITEM_INFO_ *pItemInfo=CItemHelper::GetInstance()->GetItemInfoById(pItem->GetConfigId());
	if(pItemInfo)
	{			
		m_itemInfo=*pItemInfo;	//��������
		if(m_itemInfo.IsEquipItem())	//װ����Ҫ�����Դ�����
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
			TRACE_OUTPUT(_T("��Ʒ����:%d\t�Ҳ�����Ϣ!!!!!!!\n"),pItem->GetConfigId());
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

bool CItem::IsMaterial()	//�Ƿ����
{
	return GetItemInfo()->itemType==EItemTypeMaterial;
}


bool CItem::IsLowestEquip()	//�Ƿ���ͼ�װ��
{
	CItemUtility *pItemUtility= CGlobalObject::GetInstance()->GetItemUtility();
	_ITEM_INFO_ *pItemInfo=GetItemInfo();
	return pItemUtility->IsEquipType(pItemInfo->itemType) && pItemInfo->quality<=1;
}
//////////////////////////////////////////////////////////////////////////
bool CItem::IsMountEquipType()//�Ƿ�����װ��
{
	return (m_itemInfo.itemType==EItemTypeEquipe && m_itemInfo.itemSubType==EItemSubTypeMount);
}


bool CItem::IsEquipSuit()	//�Ƿ���װ?
{
	return m_equipInfo.GetExtraInfo()->strSuitId.length()>0;
}