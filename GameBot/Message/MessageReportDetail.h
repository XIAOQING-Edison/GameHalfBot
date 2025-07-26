#pragma once
#include "basemessage.h"

enum E_REPORT_TYPE{
	e_report_coin=0,//币
	e_report_diamond,//钻
	e_report_creativeStone,//创
	e_report_feather,//羽
	e_report_soulStone,//灵魂
	e_report_refineStone,//打造石
	e_report_anglesTear,//天使泪
	e_report_regeneration_stone,	//再生原石
	e_report_rev//保留

};

class CMessageReportDetail :
	public CBaseMessage
{
public:
	CMessageReportDetail(void);
	virtual ~CMessageReportDetail(void);


	virtual bool Encode(CStreamReadWrite *pStreamBuf);
	virtual int Decode(CStreamReadWrite *pStreamBuf);

	int GetPlayerIndex(){return m_playerIndex;}
	int GetCoin(){return m_reportData[e_report_coin];}
	int GetDiamond(){return m_reportData[e_report_diamond];}
	int GetCreativeStone(){return m_reportData[e_report_creativeStone];}
	int GetFeather(){return m_reportData[e_report_feather];}
	int GetSoulStone(){return m_reportData[e_report_soulStone];}
	int GetRefineStone(){return m_reportData[e_report_refineStone];}
	int GetAngleTear(){return m_reportData[e_report_anglesTear];}
	int GetRegenerationStone(){return m_reportData[e_report_regeneration_stone];}
	void MakeReportDetailMessage(int playerIndex,INT64 *arr,int count);
	int GetReportDataCount(){return CalcCount();}
	INT64* GetReportData(){return m_reportData;}
	static int CalcCount(){return e_report_rev-e_report_coin+1;}
private:	//以下上报非绑定的数量
	int m_playerIndex;
	INT64 m_reportData[64];	//保留
};
