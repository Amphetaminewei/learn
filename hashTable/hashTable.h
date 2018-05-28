#pragma once

#include<utility>

#include"hash.h"

template<class K,class E>
class hashTable {

private:
	//hash��
	std::pair<const K, E>** table;
	//��stringӳ�������
	hash hash;
	//���Ը���
	int dSize;
	//hash������D
	int divisor;

public:
	hashTable();
	//emmmmmm����û�������������������������Ҳû��������
	int search() const;
	std::pair<const K, E>* find(const K &theKey) const;
	void insert(const std::pair<const K, E> &thePair);
	void erase(const K &theKey);
};