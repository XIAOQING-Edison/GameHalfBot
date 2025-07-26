#pragma once
template <class TYPE>
class CSingleton
{
public:
	CSingleton(void);
	~CSingleton(void);

	static TYPE *GetInstance();
	static void *DeleteInstance();

private:
	static TYPE *s_pInst;

};

template<class TYPE>
TYPE* CSingleton<TYPE>::GetInstance()
{
	TYPE *pInst=CSingleton<TYPE>::s_pInst;
	if(!pInst)
	{
		pInst=new TYPE;
		CSingleton<TYPE>::s_pInst=pInst;
	}
	return pInst;
}


template<class TYPE>
void CSingleton<TYPE>::DeleteInstance()
{
	TYPE *pInst=CSingleton<TYPE>::s_pInst;
	if(pInst)
	{
		SAFE_DELETE_POINTER(pInst);
	}
	CSingleton<TYPE>::s_pInst=NULL;
}