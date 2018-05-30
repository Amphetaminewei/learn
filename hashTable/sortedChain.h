#pragma once

#include<utility>

#include"sortedNode.h"

template<class K,class E>
class sortedChain {
//和链表类似的链字典，只是数据域变成了pair
//自己根据链表实现，可能会有问题，但是可能我并不会承认
private:
	sortedNode<K, E>* firstNode;
	sortedNode<K, E>* lastNode;
	int dSize;

public:
	sortedChain();
	sortedChain(const sortedChain<const K, E>* theChain); //复制构造函数
	~sortedChain();
	bool empty() const;
	int size() const;
	std::pair<const K, E>* find(const K &theKey) const;
	void erase(const K &theKey);
	void insert(const std::pair<const K, E> &thePair);
};