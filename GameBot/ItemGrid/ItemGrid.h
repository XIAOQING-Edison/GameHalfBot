#pragma once

#include "ItemList.h"

//�������������е���Ʒ�񣬱�����װ�������ֿ��
class CItemGrid
{
public:
	CItemGrid(void);
	~CItemGrid(void);

 	CItemList *GetItemEquipList(){return GetItemListByType(e_item_grid_type_equipment);}	//װ��
	CItemList *GetItemStorageList(){return GetItemListByType(e_item_grid_type_warehose);}	//�ֿ�
	CItemList *GetItemBagList(){return GetItemListByType(e_item_grid_type_bag);}	//����
// 	CItemList *GetItemGemList(){return &m_itemGemList;}

	void AddItemToItemList(E_ITEM_GRID_TYPE type,void *pInfoItem);	//type˵�����ĸ���Ʒ������
	void InitGridCount(E_ITEM_GRID_TYPE type,int count);	//��ʼ��ĳ���ͱ���

	//test,��ӡ���,����
	void PrintInfo(){m_itemBagList.PrintInfo();}
private:
	CItemList *GetItemListByType(E_ITEM_GRID_TYPE type);
private:
 	CItemList m_itemEquipList;
	CItemList m_itemStorageList;	//�ֿ�	
	CItemList m_itemBagList;	//����
// 	CItemList m_itemBadgeList;	//΢��
// 	CItemList m_itemGemList;	//��ʯ
// 	CItemList m_itemSealList;	//ӡ��
// 	CItemList m_itemDemoEquipList;	//ʱװ
// 	CItemList m_itemBrandList;	//ӡ��
// 	CItemList m_itemStorageExList;	//����ֿ�?
// 	CItemList m_itemSvipSthengthList;	//VIP��ǿ?
// 	CItemList m_itemTreasureList;	//����

};
