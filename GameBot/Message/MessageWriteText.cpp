#include "MessageWriteText.h"
CMessageWriteText::CMessageWriteText(void)
{
	SetProtocolId(e_cmd_write_text);
}

CMessageWriteText::~CMessageWriteText(void)
{
}



bool CMessageWriteText::Encode(CStreamReadWrite *pStreamBuf)
{
	CBaseMessage::Encode(pStreamBuf);
	ResetWritePostion();

	pStreamBuf->WriteShort(GetProtocolId());	//协议ID
	pStreamBuf->WriteBigString(m_accountName.c_str());
	pStreamBuf->WriteFixedInt32(m_type);
	pStreamBuf->WriteBigString((TCHAR*)m_buf);
	//test
	//TRACE_OUTPUT(_T("编码客户写数据:%s\n"),HexArrayToString(pStreamBuf->GetBufHead(),pStreamBuf->GetCurWritePostion()).c_str());
	return true;
}


//这个是utf8编码，因为文本是用utf8来存，这里就不用readBigString转换，直接读取utf8编码
int CMessageWriteText::Decode(CStreamReadWrite *pStreamBuf)
{
	int handleLength=0;

	int orgPos=pStreamBuf->GetHandlePos();
	
	//收到信息后需要发送到主窗口写东西
	m_accountName=pStreamBuf->ReadBigString();
	m_type=pStreamBuf->ReadFixedInt32();
// 	int total=pStreamBuf->ReadFixedInt32();
// 	char *pUtfBytes=pStreamBuf->ReadUtfBytes(total);
// 	memcpy(m_buf,pUtfBytes,total);
	STRING str=pStreamBuf->ReadBigString();
	int total=str.length()*sizeof(TCHAR);
	memcpy(m_buf,str.c_str(),total);
	m_buf[total]=0;
	m_buf[total+1]=0;
	m_length=total;
EXT:
	handleLength=pStreamBuf->GetHandlePos()-orgPos;
	return handleLength;

}


void CMessageWriteText::MakeWriteDataMessage(int type,const STRING &account,const char *szBuf,int bufSize)
{
	m_type=type;
	m_accountName=account;
	memcpy(m_buf,szBuf,bufSize);
	m_length=bufSize;	//编码时没用到
	m_buf[bufSize]=0;
	m_buf[bufSize+1]=0;

}