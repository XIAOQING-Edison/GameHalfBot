#include "ItemList.h"
#include "../GameData/ItemHelper.h"
#include "../Protocol/Bag/InfoItemInfo.h"
static const int g_boxColPerRow=8;	//每行8格
CItemList::CItemList(void)
{
	SetType(e_item_grid_type_none);	//初始类型为非法
	SetAvailableSize(0);
}

CItemList::~CItemList(void)
{
	Lock();
	ClearItemList();
	Unlock();
}


void CItemList::InitItemListCount(int count)
{
	Lock();
	if(count>m_itemList.size())
	{
		m_itemList.resize(count);
	}
	Unlock();
}


void CItemList::AddItemsToItemList(void *items)
{
	vector<CInfoItemInfo> *pItems=(vector<CInfoItemInfo> *)items;
	Lock();
	vector<CInfoItemInfo>::iterator it=pItems->begin();
	while(it != pItems->end())
	{
		AddOneItemtoItemList(&*it);
		++it;
	}
	Unlock();
}


 
void CItemList::AddOneItemtoItemList(void *pInfoItem)
{
	CItem item;
	int pos=-1;
	if(item.ParseInfoItemToItem(pInfoItem))
	{
		int itemConfigId=item.GetConfigId();
		pos=item.GetPos();	
		UpdateItemToItemList(pos,item);

	}
	else
	{
		CInfoItemInfo *pItem=(CInfoItemInfo*)pInfoItem;
		TRACE_OUTPUT(_T("增加物品id:%d出错---没找到相关信息!!!!!!\n"),pItem->GetConfigId());
	}
// 	Lock();
// 	if(pos>=0 && pos<m_itemList.size())
// 	{
// 		TRACE_OUTPUT(_T("得到物品%s!\n"),item.GetName().c_str());
// 		m_itemList[pos]=item;
// 	}
// 	else
// 	{
// 		TRACE_OUTPUT(_T("增加物品位置:%d出错，超出背包数量!!!\n"),pos);
// 	}
// 	Unlock();
}

void CItemList::UpdateItemsWhenChanged(void *items,void * removes)
{
	AddItemsToItemList(items);
	RemoveItemsFromItemList(removes);
}

void CItemList::RemoveItemsFromItemList(void* removes)
{
	vector<INT64>* pRemoves=(vector<INT64>*)removes;
	Lock();
	vector<INT64>::iterator it=pRemoves->begin();
	while(it != pRemoves->end())
	{
		CItem *pItem=GetItemByObjectId(*it);
		if(pItem)
		{
			DeleteItemByPos(pItem->GetPos());
		}
		else
		{
			TRACE_OUTPUT(_T("删除时找不到id:%I64d的物品信息!!!!!!!\n"),*it);
		}
		++it;
	}
	Unlock();
}

void CItemList::UpdateItemToItemList(int pos,CItem &item)
{
// 	CItem item;
// 	item.ParseInfoItemToItem(pInfoItem);
	//前面已解析完
	Lock();
	if(pos>=0 && pos<m_itemList.size())
	{
		//m_itemList[pos]=item;
		CItem *pItem=&item;
		int xOccupied=pItem->GetXOccupied();
		int yOccupied=pItem->GetYOccupied();
		int i;
		int row=pos/g_boxColPerRow;
		int col=pos%g_boxColPerRow;	//算出列
		_ITEM_INFO_ *pItemConfigInfo=NULL;
		CItem *pCurItem=NULL;
		for(i=0;i<xOccupied;++i)
		{
			
			pCurItem=&m_itemList[pos+i];
			if(i==0)
			{
				*pCurItem=item;
			}
			else
			{
				//其它位置是占位的
				pItemConfigInfo=pCurItem->GetItemInfo();
				*pItemConfigInfo=*(pItem->GetItemInfo());
				pCurItem->SetIsOcccupied(true);
			}
			for(int j=1;j<yOccupied;++j)
			{
				int yOccupiedPos=(row+j)*g_boxColPerRow+col+i;
				pCurItem=&m_itemList[yOccupiedPos];
				pItemConfigInfo=pCurItem->GetItemInfo();
				*pItemConfigInfo=*(pItem->GetItemInfo());
				pCurItem->SetIsOcccupied(true);

			}
		}
	}
	else
	{
		TRACE_OUTPUT(_T("更新物品%d位置出错，超出背包数量:%d!!!!!\n"),pos,m_itemList.size());
	}
	Unlock();
}

// 
void CItemList::DeleteItemByPos(int pos)
{
	CItem emptyItem;
	Lock();
	if(pos>=0 && pos<m_itemList.size())
	{
		CItem *pItem=&m_itemList[pos];
		int xOccupied=pItem->GetXOccupied();
		int yOccupied=pItem->GetYOccupied();
		int i;
		int row=pos/g_boxColPerRow;
		int col=pos%g_boxColPerRow;	//算出列
		for(i=0;i<xOccupied;++i)
		{
			m_itemList[pos+i]=emptyItem;
			for(int j=1;j<yOccupied;++j)
			{
				int yOccupiedPos=(row+j)*g_boxColPerRow+col+i;
				m_itemList[yOccupiedPos]=emptyItem;
			}
		}
		

	}
	else
	{
		TRACE_OUTPUT(_T("删除%d位置出错，超出背包数量!\n"),pos);
	}
	Unlock();
}


CItem *CItemList::GetItemByPos(int pos)
{
	CItem *pItem=NULL;
	Lock();
	if(pos>=0 && pos<m_itemList.size())
	{
		pItem=&m_itemList.at(pos);
	}
	else
	{
		TRACE_OUTPUT(_T("取背包格%d位置出错，超出背包数量!\n"),pos);
	}
	Unlock();
	return pItem;
}


CItem *CItemList::GetItemByObjectId(INT64 id)
{
	CItem *pItem=NULL;
	Lock();
	vector<CItem>::iterator it=m_itemList.begin();
	while(it !=m_itemList.end())
	{
		if(it->GetId()==id)
		{
			pItem=(CItem*)&*it;
			break;
		}
		++it;
	}
	Unlock();

	return pItem;
}


int CItemList::GetPosByItemObjectId(INT64 id)
{
	int pos=-1;
	Lock();
	vector<CItem>::iterator it=m_itemList.begin();
	int i=0;
	while(it !=m_itemList.end())
	{
		if(it->GetId()==id && !it->IsEmptyItem()&& !it->IsOccupied())
		{
			pos=i;
			break;
		}
		++i;
		++it;
	}
	Unlock();
	return pos;
}

INT64 CItemList::GetItemCountByNameBindOrNot(const STRING &name,bool bind)	//从名字取得绑定或非绑定的物品
{
	INT64 count=0;
	Lock();
	vector<CItem*> items=GetItemByNameBindOrNot(name,bind);
	vector<CItem*>::iterator it=items.begin();
	while(it != items.end())
	{
		CItem *pItem=*it;
		count+=pItem->GetCount();
		++it;
	}
	Unlock();
	return count;
}

//会有多个项，因为有可能一个格重叠数量有限会分组
vector<CItem*> CItemList::GetItemByNameBindOrNot(const STRING& name,bool bind)	//取得是否绑定的物品
{
	vector<CItem*> result;
	Lock();
	vector<CItem*> itemsInSameName=GetItemsByName(name);
	vector<CItem*>::iterator it=itemsInSameName.begin();
	while(it != itemsInSameName.end())
	{
		CItem *pTmpItem=*it;
		if(pTmpItem->IsBind()==bind && !pTmpItem->IsOccupied())	//判断占用
		{
			result.push_back(pTmpItem);
		}
		++it;
	}
	Unlock();
	return result;
}

//返回一个item指针数组，如果是空的item，count=0，但仍然在内存中有位置
//同名字的会有多个
vector<CItem*> CItemList::GetItemsByName(const STRING &name)
{
	vector<CItem*> result;
	Lock();
	vector<CItem>::iterator it=m_itemList.begin();
	while(it != m_itemList.end())
	{
		if(it->GetName()==name && !it->IsOccupied())
		{
			result.push_back(&*it);
		}
		++it;
	}
	Unlock();
	return result;
}
 

int CItemList::GetRemainIdleGridCount()	//得到空闲的格子
{
	int res=0;
	Lock();
	vector<CItem>::iterator it=m_itemList.begin();
	int queryTimes=0;
	while(it != m_itemList.end())
	{
		if(it->IsEmptyItem()&& !it->IsOccupied())	//非占用才统计
		{
			++res;
		}
		++queryTimes;
		if(queryTimes>=GetAvailableSize())
		{
			break;
		}
		++it;
	}
	Unlock();
	return res;

}

void CItemList::EmptyAllItems()	//将全部item标记为空的item,一般是断线后掉用
{
	Lock();
	for(int i=0;i<m_itemList.size();++i)
	{
		DeleteItemByPos(i);
	}
	Unlock();
}

void CItemList::OnMoveItemRes(void *item)	//移动物品，这里先要找出物品所在的格子，删除，再把新的物品赋到目标格子里
{
	CInfoItemInfo *pInfoItem=(CInfoItemInfo*)item;
	int orgPos=GetPosByItemObjectId(pInfoItem->GetId());
	DeleteItemByPos(orgPos);
	CItem newItem;
	if(newItem.ParseInfoItemToItem(item))
		UpdateItemToItemList(newItem.GetPos(),newItem);
	else
		TRACE_OUTPUT(_T("移动物品更新找不到id:%d的物品信息!!!!!!\n"),pInfoItem->GetConfigId());
}


void CItemList::PrintInfo()	//test,测试输出
{
	for(int i=0;i<m_itemList.size();++i)
	{
		CItem *pItem=GetItemByPos(i);
		STRING name=_T("无");
		int count=0;
		if(!pItem->IsEmptyItem())
		{
			count=pItem->GetCount();
			name=pItem->GetName();
		}
		if(!pItem->IsOccupied())
			TRACE_OUTPUT(_T("物品名称:%s---位置:%d---数量:%d\n"),name.c_str(),i,count);
		else
			TRACE_OUTPUT(_T("物品名称:%s---位置:%d---####占位####\n"),name.c_str(),i);
	}	
}