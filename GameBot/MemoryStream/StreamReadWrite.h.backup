// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 STREAMREADWRITE_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// STREAMREADWRITE_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#pragma once
// #ifdef STREAMREADWRITE_EXPORTS
// #define STREAMREADWRITE_API __declspec(dllexport)
// #else
// #define STREAMREADWRITE_API __declspec(dllimport)
// #endif
#define STREAMREADWRITE_API
enum E_ENDIAN_TYPE
{
	E_ENDIAN_TYPE_LITTLE_ENDIAN=0,
	E_ENDIAN_TYPE_BIG_ENDIAN
};

// 此类是从 StreamReadWrite.dll 导出的
#include "../Global/public.h"
class CByte;
class STREAMREADWRITE_API CStreamReadWrite {
public:
	CStreamReadWrite(int type,int bufLength);
	~CStreamReadWrite();
	// TODO: 在此添加您的方法。
	
	void SetEndianType(int type);
	int GetEndianType();

public:
	void Reset(bool bSetBufNull);	//setBufNull时m_pBuf=NULL,否则只设置其它位置


	void CopyBufAndLength(char *buf,int len,bool showDebug=false);	//test,开启调试输出参数
	int GetRestBytesLength();

	char *GetBufHead();

	char *GetCurReadPositionBuf();

	char *GetCurWritePostionBuf();

	int GetCurWritePostion();
	void SetCurWritePosition(int pos);
	void ResetCurWritePosition();

	int GetBufLength();
	int GetHandlePos();

	int GetReadPos();
	void SetReadPos(int pos);
	void ResetReadPos();
	void ResetWritePosition();

	//这里作为一个特殊处理函数，一般情况不常使用
	void CopyBufAndLengthWithReadPos(char *buf,int len);
	void SetBufPos(int pos);	//这里为了特殊目的，平时不要使用!!!
	void SetHandlePos(int pos);//这里为了特殊目的，平时不要使用!!!
public:

	BYTE ReadUnsignedByte();	//读无符号一个字节
	char ReadSignedByte();	//有符号的字节

	bool ReadBoolean();//读一个boolean
	short ReadShort();	//读一个有符号short
	WORD ReadWord();//无符号short

	int ReadRawVarInt32();	//vint,并未zigzag
	__int64 ReadRawVarInt64();	//可变长度

	double ReadDouble();	//读一个double
	float ReadFloat();	//读一个float
	STRING ReadVarIntString();	//读一个string,这里的长度是varInt32的
	char* ReadArray();	//读一个array
	int ReadObject();	//读一个对象，待定


	STRING ReadUtfString();	//读一个string,这里的长度是固定2字节的

	STRING ReadBigString();//读一个string,这里的长度是fix32的,即固定4字节

	char* ReadUtfBytes(int len);	//读utfbytes,这里需要判定unicode,到时完善转换过程

	char *ReadBytes(int pos,int len);	//读从pos始长度为len的字节

	int ReadFixedInt32();//读固定4字节

	__int64 ReadFixedInt48();//读固定6字节

	__int64 ReadFixedInt64();	//固定8字节

	int WriteByte(char b);
	int WriteBool(bool b);
	int WriteShort(short s);
	int WriteFixedInt32(int i);

	int WriteFloat(float f);
	int WriteDouble(double d);
	int WriteFixedInt64(__int64 int64);

	int WriteBytes(const char *data,int len);

	int WriteUtfBytes(const char *data,int len=-1);

	int WriteUtfString(const TCHAR *data);	//长度固定2字节

	int WriteBigString(const TCHAR *data);	//长度固定4字节

	int WriteFixedInt48(__int64 int64);	//写一个48位的数字
	int WriteVarIntString(const TCHAR *data);	//长度是varInt32可变长度类型
	int WriteRawVariant32(int i);//写一个变长32位数字
	int WriteRawVariant64(__int64 int64);//varInt64
private:

	CByte *m_streamBuf;
};

extern STREAMREADWRITE_API int nStreamReadWrite;

STREAMREADWRITE_API int fnStreamReadWrite(void);
