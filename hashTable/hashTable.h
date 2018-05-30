#pragma once

#include<utility>

#include"hash.h"
#include"sortedChain.h"

//尝试着用链式结构实现,写了一个只能把string变成size_t的hash；

template<class K,class E>
class hashTable {

private:
	//hash表
	sortedChain<K, E>** table;
	//把string映射成整数
	hash hash;
	//数对个数
	int dSize;
	//hash函数的D
	int divisor;

public:
	hashTable(const int divisor);
	~hashTable();
	//emmmmmm书上没给析构函数，跳表的析构函数也没给。。。
	int search(const K &theKey) const;
	std::pair<const K, E>* find(const K &theKey) const;
	void insert(const std::pair<const K, E> &thePair);
	void erase(const K &theKey);
};