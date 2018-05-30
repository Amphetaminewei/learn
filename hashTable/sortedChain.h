#pragma once

#include<utility>

#include"sortedNode.h"

template<class K,class E>
class sortedChain {
//���������Ƶ����ֵ䣬ֻ������������pair
//�Լ���������ʵ�֣����ܻ������⣬���ǿ����Ҳ��������
private:
	sortedNode<K, E>* firstNode;
	sortedNode<K, E>* lastNode;
	int dSize;

public:
	sortedChain();
	sortedChain(const sortedChain<const K, E>* theChain); //���ƹ��캯��
	~sortedChain();
	bool empty() const;
	int size() const;
	std::pair<const K, E>* find(const K &theKey) const;
	void erase(const K &theKey);
	void insert(const std::pair<const K, E> &thePair);
};