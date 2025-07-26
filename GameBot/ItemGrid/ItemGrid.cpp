#include "ItemGrid.h"

CItemGrid::CItemGrid(void)
{
}

CItemGrid::~CItemGrid(void)
{
}

void CItemGrid::InitGridCount(E_ITEM_GRID_TYPE type,int count)
{
	CItemList *pItemList=GetItemListByType(type);
	if(pItemList)
	{
		pItemList->InitItemListCount(count);
	}
}


CItemList *CItemGrid::GetItemListByType(E_ITEM_GRID_TYPE type)
{
	CItemList *pItemList=NULL;
	if(type==e_item_grid_type_bag)
	{
		pItemList=&m_itemBagList;
	}
	else if(type==e_item_grid_type_warehose)
	{
		pItemList=&m_itemStorageList;
	}
	else if(type==e_item_grid_type_equipment)
	{
		pItemList=&m_itemEquipList;
	}
	if(pItemList)
	{
	}
	else
	{
		TRACE_OUTPUT(_T("背包类型:%d没找到!!查看调用者!!\n"),type);
	}
	return pItemList;
}

void CItemGrid::AddItemToItemList(E_ITEM_GRID_TYPE type,void *pInfoItem)	//type说明是哪个物品格类型
{
	CItemList *pItemList=GetItemListByType(type);
	if(pItemList)
	{
		pItemList->AddOneItemtoItemList(pInfoItem);
	}
	else
	{
		TRACE_OUTPUT(_T("背包类型:%d不在这里处理!!查看调用者!!\n"),type);
	}
}


// 
// void CItemGrid::AddOneItemtoItemList(CAbstractItem *pItem)
// {
// 	
// }
