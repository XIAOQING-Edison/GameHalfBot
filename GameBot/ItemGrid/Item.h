#pragma once
#include "../Global/public.h"
#include "../Struct/ItemInfoHelper.h"
#include "../Struct/EquipInfoHelper.h"

class CItem
{
public:
	CItem(void);
	~CItem(void);

	void Init();
	
	bool ParseInfoItemToItem(void *pInfoItem);
	bool ParseInfoItemToEquip(void *pInfoItem);
// 	bool ParseDropItemToItem(void *pDropItem);

	void UpdateInfoItemToItem(void *pInfoItem);

	bool IsEmptyItem(){return ((GetConfigId()==0) || (GetCount()==0)) && !IsOccupied();}	//空的格子是不会被占用
	bool IsOccupied(){return m_bIsOccupied;}	//是否被占用，因为物品有些占用不止一个格子
	bool IsBind(){return m_bIsBind;}
	void SetIsOcccupied(bool b){m_bIsOccupied=b;}

	int GetXOccupied(){return m_itemInfo.GetXTranslate();}	//x方向占用
	int GetYOccupied(){return m_itemInfo.GetYTranslate();}	//y方向占用

	bool IsMaterial();	//是否材料
	bool IsEquip(){return m_itemInfo.IsEquipItem();}
	bool IsLowestEquip();	//是否最低级装备
public:
	void SetPos(int pos){m_pos=pos;}
	int GetPos(){return m_pos;}

	void SetId(INT64 id){m_id=id;}
	INT64 GetId(){return m_id;}

	int GetConfigId(){return m_itemInfo.itemId;}

	STRING GetName(){return m_itemInfo.itemName;}

	void SetCount(int count){m_count=count;}
	int GetCount(){return m_count;}

	int GetQuality(){return m_itemInfo.quality;}

	_ITEM_INFO_ *GetItemInfo(){return &m_itemInfo;}
	_EQUIPMENT_INFO_ *GetEquipmentInfo(){return &m_equipInfo;}

	bool IsMountEquipType();	//是否坐骑装备
	bool IsEquipSuit();	//是否套装?
private:
	bool m_bIsBind;
	bool m_bIsOccupied;	//是否占用

	int m_pos;
	INT64 m_count;	//叠加数量
	INT64 m_id;	//这个是游戏中物编编号ID
	_ITEM_INFO_ m_itemInfo;	//从配置里读到的物品数据
	_EQUIPMENT_INFO_ m_equipInfo;	//从配置中读到的装备数据
public:
	vector<int> additionalAttribute;// = 10;//追加属性
	vector<int> lucky;// = 11;//幸运属性

	map<int,INT64> m_excellentAttrs;	//普通卓越
	map<int,INT64> m_excellentStarAttrs;	//带星卓越
	map<int,INT64> m_regenerateAttrs;	//重生属性
};
