#pragma once

#include<utility>

//����Ľڵ���

template<class K, class E>
class skipNode {

public:
	//��pair����Ҫ�����ֵ�͹ؼ���
	std::pair<const K, E> element;
	skipNode<K, E> **next;

	skipNode(const std::pair<K, E>& thePair, int size):element(thePair) {
		next = new skipNode<K, E>* [size];
		//�ⶫ����ɶʱ��֧���±�����ġ�����
	}
};