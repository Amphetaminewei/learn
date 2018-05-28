#pragma once

#include<utility>

template<class K,class E>
class sortedNode {
	//�������ֵ�Ľڵ㣬������chainNode
public:
	std::pair<K, E> element;
	sortedNode<K, E>* next;

	sortedNode(const std::pair<K, E>& theElement) {
		element = theElement;
		next = NULL;
	}
	sortedNode(const std::pair<K, E>& theElement, sortedNode<K, E>* nextNode) {
		element = theElement;
		next = nextNode;
	}
};