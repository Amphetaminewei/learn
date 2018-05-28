#pragma once

#include<utility>

template<class K,class E>
class sortedNode {
	//用作链字典的节点，类似于chainNode
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