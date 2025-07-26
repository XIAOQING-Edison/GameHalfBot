#pragma once

#include "ItemList.h"

//这个类包含了所有的物品格，背包，装备栏，仓库等
class CItemGrid
{
public:
	CItemGrid(void);
	~CItemGrid(void);

 	CItemList *GetItemEquipList(){return GetItemListByType(e_item_grid_type_equipment);}	//装备
	CItemList *GetItemStorageList(){return GetItemListByType(e_item_grid_type_warehose);}	//仓库
	CItemList *GetItemBagList(){return GetItemListByType(e_item_grid_type_bag);}	//背包
// 	CItemList *GetItemGemList(){return &m_itemGemList;}

	void AddItemToItemList(E_ITEM_GRID_TYPE type,void *pInfoItem);	//type说明是哪个物品格类型
	void InitGridCount(E_ITEM_GRID_TYPE type,int count);	//初始化某类型背包

	//test,打印输出,背包
	void PrintInfo(){m_itemBagList.PrintInfo();}
private:
	CItemList *GetItemListByType(E_ITEM_GRID_TYPE type);
private:
 	CItemList m_itemEquipList;
	CItemList m_itemStorageList;	//仓库	
	CItemList m_itemBagList;	//背包
// 	CItemList m_itemBadgeList;	//微章
// 	CItemList m_itemGemList;	//宝石
// 	CItemList m_itemSealList;	//印章
// 	CItemList m_itemDemoEquipList;	//时装
// 	CItemList m_itemBrandList;	//印记
// 	CItemList m_itemStorageExList;	//额外仓库?
// 	CItemList m_itemSvipSthengthList;	//VIP加强?
// 	CItemList m_itemTreasureList;	//宝物

};
