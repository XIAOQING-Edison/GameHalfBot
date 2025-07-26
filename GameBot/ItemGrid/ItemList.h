#pragma once

#include "../Global/public.h"
#include "../Enums.h"

#include "Item.h"
#include "../Struct/ItemInfoHelper.h"
#include "../ObjectList/SyncObjectList.h"
class CItemList : public CSyncObjectList
{
public:
	CItemList(void);
	~CItemList(void);

	void SetType(E_ITEM_GRID_TYPE type){m_type=type;}
	E_ITEM_GRID_TYPE GetType();

	void InitItemListCount(int count);

	void AddItemsToItemList(void *items);

	void AddOneItemtoItemList(void *pInfoItem);

	void UpdateItemsWhenChanged(void *items,void * removes);
	void RemoveItemsFromItemList(void* removes);

	void OnMoveItemRes(void *item);	//移动物品，这里先要找出物品所在的格子，删除，再把新的物品赋到目标格子里

	void UpdateItemToItemList(int pos,CItem &item);
	void DeleteItemByPos(int pos);	//这里把对应格置成空对象即可，不真正删除
	CItem *GetItemByPos(int pos);

	CItem *GetItemByObjectId(INT64 id);
	int GetPosByItemObjectId(INT64 id);
	vector<CItem*> GetEquipmentsByExcellentAttrAndStarCount(int attrCount,int starCount);//卓越属性,和几星

	int GetRemainIdleGridCount();	//得到空闲的格子

	void SetAvailableSize(int sz){m_availableSize=sz;}
	int GetAvailableSize(){return m_availableSize;}

	INT64 GetItemCountByNameBindOrNot(const STRING &name,bool bind);	//从名字取得绑定或非绑定的物品

	void EmptyAllItems();	//将全部item标记为空的item,一般是断线后掉用

	void PrintInfo();	//test,测试输出
private:
	vector<CItem*> GetItemByNameBindOrNot(const STRING& name,bool bind);	//取得是否绑定的物品

	vector<CItem*> GetItemsByItemType(EItemType type);
	vector<CItem*> GetItemsByName(const STRING &name);
	vector<CItem*> GetItemsByConfigId(int id);


	void ClearItemList(){m_itemList.clear();}



private:
	E_ITEM_GRID_TYPE m_type;
	vector<CItem> m_itemList;
	int m_availableSize;	//这个是可用的大小
};
