#pragma once
#include "../protocol.h"
#include "InfoRoleSimpleInfo.h"
class CInfoRoleBasic :
	public CProtocol
{
public:
	CInfoRoleBasic(void);
	virtual ~CInfoRoleBasic(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);

	INT64 GetRoleId(){return info.GetRoleId();}
	STRING GetName(){return info.GetName();};
	int GetLevel(){return info.GetLevel();;}
	STRING GetUnionName(){return info.GetUnionName();}	//ս������
	int GetTotalFight(){return info.GetTotalFight();}	//ս��
	int GetServerId(){return info.GetServerId();}
	int GetMapId(){return info.GetMapId();}
	int GetCareer(){return info.GetCareer();}
	int GetPkMode(){return PKMode;}
	int GetAttributePoint(){return attributePoint;}

	void Reset();

private:
	CInfoRoleSimpleInfo info;// = 1 ;
	int createTime;// = 2; //����ʱ�� (s)
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_)	|| (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_)\
	||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
	INT64 exp;// = 3;
#elif _GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_
	STRING exp;
#endif
	int attributePoint;// = 4; //��ʹ���c��
	int PKMode;// = 7;
	int dailyOnlineTime;// = 8;//ÿ������ʱ�� (s)
	int logoutTime;// = 10;//����ʱ�������

#if _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_
#elif _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_
#elif _GAME_VERSION_ == _YONG_HENG_LIAN_MENG_	
#elif _GAME_VERSION_ == _TIAN_SHI_SHEN_YU_
#elif _GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_
#endif
};
