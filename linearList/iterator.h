#pragma once
#include"chainNode.h"
#include"chain.h"

//���������ǰ��������ֻ�ܵ������

template<class T>
class iterator {

private:
	chainNode<T>* node;

public:
	//���캯��
	iterator(chainNode<T>* theNode = NULL);
	//ǰ��
	iterator& operator++();
	//���
	iterator operator++(int);
	//������
	T& operator*() const;
	T* operator->() const;
	//���/����
	bool operator!=(const iterator item) const;
	bool operator==(const iterator item) const;
};