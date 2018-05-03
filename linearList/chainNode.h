#pragma once
template<class T>
class chainNode {
//创建一个chainNode类型作为链表节点
public:
	T element;
	chainNode<T> *next;

	chainNode() { };
	chainNode(const T& element) {
		this->element = element;
	}
	chainNode(const T& element, chainNode<T> *next) {
		this->element = element;
		this->next = next;
	}

};