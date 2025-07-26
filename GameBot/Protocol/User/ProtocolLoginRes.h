#pragma once
#include "../protocol.h"

class CProtocolLoginRes :
	public CProtocol
{
public:
	CProtocolLoginRes(void);
	virtual ~CProtocolLoginRes(void);

	virtual bool Encode(CStreamReadWrite *pStreamBuf){return false;}
	virtual int Decode(CStreamReadWrite *pStreamBuf);

private:
	UINT64 m_openServerTime;
	UINT64 m_combineServerTime;
	UINT64 m_serverCurTime;
	bool m_bNeedInviteCode;	//暂时未见
#if (_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_MOBILE_) ||(_GAME_VERSION_ == _TIAN_SHI_ZHI_ZHAN_PC_)
	int combineServerCount;// = 5; //合服次数
	vector<int> unlockCareer;	//6
#elif (_GAME_VERSION_ == _YONG_HENG_LIAN_MENG_)
#elif (_GAME_VERSION_ == _TIAN_SHI_SHEN_YU_)
	int combineServerCount;// = 5; //合服次数
#elif _GAME_VERSION_ == _YONG_HENG_ZHI_DIAN_

#endif
};
