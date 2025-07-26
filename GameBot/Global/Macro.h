#ifndef _MACRO_H_
#define _MACRO_H_

#define ERROR_CODE_NO_ERROR	0	//正确的返回值
#define ERROR_CODE_NONE	-1		//默认的不是错误也没有正确
#define ERROR_CODE_SOME_ERROR	-2	//用来代替有错误产生


/************************************************************************/
/* 一些置位和清除某些位的定义                                                                     */
/************************************************************************/
#define  SET_BIT(a,b)	(a |=(1<<b))
#define  CLR_BIT(a,b)	(a &=(~(1<<b)))
#define  IS_BIT_SET(a,b)	((a&(1<<b)))



// #ifdef _UNICODE
#define INSERT_ENUM(m,a,b){m[__T(#a)]=b;}

#define INSERT_SAME_FIELD(m,a) INSERT_ENUM(m,a,a)

#define INSERT_TO_ENUM_MAP(a)	INSERT_ENUM(m_mapEnums,a,a)

// #else
// #define INSERT_ENUM(m,a,b){m[#a]=b;}
// #endif // _UNICODE

#define	ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#endif