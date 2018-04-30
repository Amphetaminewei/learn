#pragma once

#include"chainNode.h"
#include"linearList.h"
#include"illegalParameterValue.h"
#include<iostream>

//基于线性表的链表定义
template<class T>
class chain : public linearList<T> {
public:
	//构造函数
	chain(int initialCapacity);
	//复制构造
	chain(const chain<T>&);
	~chain();

	//判断链表是否为空
	bool empty();

	//返回元素的个数
	int size();

	//返回索引为theIndex的元素
	T& get(int theIndex);

	//返回元素theElement第一次出现的索引
	int indexOf(const T& theElement);

	//删除索引为index的元素
	void erase(int theIndex);

	//把theElement插入索引为index的位置
	void insert(int theIndex, const T& theElement);

	//插入输出流out
	void output(std::ostream& out);

protected:
	chainNode<T>* firstNode;
	int listSize;
	
	//判断索引是否有效
	void checkIndex(int theIndex) const;

};
	