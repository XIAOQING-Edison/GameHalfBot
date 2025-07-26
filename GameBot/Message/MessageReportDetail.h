#pragma once
#include "basemessage.h"

enum E_REPORT_TYPE{
	e_report_coin=0,//��
	e_report_diamond,//��
	e_report_creativeStone,//��
	e_report_feather,//��
	e_report_soulStone,//���
	e_report_refineStone,//����ʯ
	e_report_anglesTear,//��ʹ��
	e_report_regeneration_stone,	//����ԭʯ
	e_report_rev//����

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
private:	//�����ϱ��ǰ󶨵�����
	int m_playerIndex;
	INT64 m_reportData[64];	//����
};
