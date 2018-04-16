#pragma once
template<class T>
class chainNode {
//����һ��chainNode������Ϊ����ڵ�
private:
	T element;
	chainNode<T> *next;

public:
	chainNode() { };
	chainNode(const T& element) {
		this->element = element;
	}
	chainNode(const T& element, chainNode<T> *next) {
		this->element = element;
		this->next = next;
	}

};