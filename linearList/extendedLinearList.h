#pragma once

#include"linearList.h"

//������չ���Ա�ĳ�����
template<class T>
class extendedLinearList : linearList<T> {

public:
	virtual ~extendedLinearList(){ }
	virtual void clear();
	virtual push_back(const T& theElement);
};