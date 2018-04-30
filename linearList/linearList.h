#pragma once
#include<iostream>

//线性表的抽象类
template <class T>
class linearList
{
public:
	~linearList();

	//返回元素个数
	virtual int size();

	//返回索引为index的元素
	virtual T& get(int theIndex);

	//返回元素theElement第一次出现的索引
	virtual int indexOf(const T& theElement);

	//删除索引为index的元素
	virtual void erase(int theIndex);

	//把theElement插入索引为index的位置
	virtual void insert(int theIndex, const T& theElement);

	//插入输出流out
	virtual void output(std::ostream& out);
};