#pragma once
template<class T>
class chainNode {
//����һ��chainNode������Ϊ����ڵ�
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