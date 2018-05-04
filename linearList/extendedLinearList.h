#pragma once

#include"linearList.h"

//用来扩展线性表的抽象类
template<class T>
class extendedLinearList : linearList<T> {

public:
	virtual ~extendedLinearList(){ }
	virtual void clear();
	virtual void push_back(const T& theElement);
};