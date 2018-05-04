#pragma once

#include"extendedLinearList.h"
#include"chainNode.h"
//从扩展线性表的类衍生来的扩展链表的类

template<class T>
class extendedChain : public extendedLinearList<T> {
private:
	chainNode<T>* firstNode;
	chainNode<T>* lastNode;
	int listSize;

	//检查索引是否有效
	void checkIndex(const int& theIndex);

public:
	//构造函数
	extendedChain(int initialCapacity);
	//复制构造函数
	extendedChain(const extendedChain<T>& theChain);
	//析构函数
	~extendedChain();

	//清空表
	void clear();
	//加入数据域为theElement的新节点到表尾
	void push_back(const T& theElement);

	//判断链表是否为空
	bool empty();

	//返回元素的个数
	int size();

	//返回索引为theIndex的元素
	T& get(int theIndex);

	//返回元素theElement第一次出现的索引,若不存在则返回-1
	int indexOf(const T& theElement);

	//删除索引为index的元素
	void erase(int theIndex);

	//把theElement插入索引为index的位置
	void insert(int theIndex, const T& theElement);

	//插入输出流out
	void output(std::ostream& out);

};