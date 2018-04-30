#pragma once
#include"chainNode.h"
#include"chain.h"

//单链表的向前迭代器，只能单向遍历

template<class T>
class iterator {

private:
	chainNode<T>* node;

public:
	//构造函数
	iterator(chainNode<T>* theNode = NULL);
	//前加
	iterator& operator++();
	//后加
	iterator operator++(int);
	//解引用
	T& operator*() const;
	T* operator->() const;
	//相等/不等
	bool operator!=(const iterator item) const;
	bool operator==(const iterator item) const;
};