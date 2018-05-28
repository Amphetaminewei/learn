#pragma once

#include<utility>

#include"hash.h"

template<class K,class E>
class hashTable {

private:
	//hash表
	std::pair<const K, E>** table;
	//把string映射成整数
	hash hash;
	//数对个数
	int dSize;
	//hash函数的D
	int divisor;

public:
	hashTable();
	//emmmmmm书上没给析构函数，跳表的析构函数也没给。。。
	int search() const;
	std::pair<const K, E>* find(const K &theKey) const;
	void insert(const std::pair<const K, E> &thePair);
	void erase(const K &theKey);
};