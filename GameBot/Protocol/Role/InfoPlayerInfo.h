#pragma once
#include "../protocol.h"
#include "InfoPlayerBasicInfo.h"
//��һ�������
class CInfoPlayerInfo :
	public CProtocol
{
public:
	CInfoPlayerInfo(void);
	virtual ~CInfoPlayerInfo(void);


	virtual bool Encode(CStreamReadWrite *pStreamBuf){return true;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);

	void Reset();

	INT64 GetRoleId(){return basic.GetRoleId();}
	STRING GetName(){return basic.GetName();};
	int GetLevel(){return basic.GetLevel();;}
	STRING GetUnionName(){return basic.GetUnionName();}	//ս������
	int GetTotalFight(){return basic.GetTotalFight();}	//ս��
	int GetServerId(){return basic.GetServerId();}
	int GetMapId(){return basic.GetMapId();}
	int GetCareer(){return basic.GetCareer();}
	
	int GetPkMode(){return basic.GetPkMode();}
	int GetAttributePoint(){return basic.GetAttributePoint();}//ȡ��ʣ��δ�ӵ���



private:	
	//��ʹ֮ս�������汾���в�ͬ
	CInfoPlayerBasicInfo basic;
#if (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) || (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||(_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_)||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
	
#endif

#if _GAME_VERSION_== _TIAN_SHI_ZHI_ZHAN_MOBILE_
#elif (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_) || (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_) ||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
#elif _GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_
#endif
	

#if _GAME_VERSION_== _TIAN_SHI_ZHI_ZHAN_MOBILE_
#elif _GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_
	bool unionVoiceOpen;//=12;//����Ȩ���Ƿ���
#elif _GAME_VERSION_ ==_YONG_HENG_LIAN_MENG_	
#elif _GAME_VERSION_ == _TIAN_SHI_SHEN_YU_
#elif (_GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_)
#endif

};
