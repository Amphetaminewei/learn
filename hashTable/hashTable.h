#pragma once

#include<utility>

#include"hash.h"
#include"sortedChain.h"

//����������ʽ�ṹʵ��,д��һ��ֻ�ܰ�string���size_t��hash��

template<class K,class E>
class hashTable {

private:
	//hash��
	sortedChain<K, E>** table;
	//��stringӳ�������
	hash hash;
	//���Ը���
	int dSize;
	//hash������D
	int divisor;

public:
	hashTable(const int divisor);
	~hashTable();
	//emmmmmm����û�������������������������Ҳû��������
	int search(const K &theKey) const;
	std::pair<const K, E>* find(const K &theKey) const;
	void insert(const std::pair<const K, E> &thePair);
	void erase(const K &theKey);
};