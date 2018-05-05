#pragma once

#include"stack.h"
#include"chainNode.h"

template<class T>
class linkedStack :public stack<T> {

public:
	linkedStack();
	~linkedStack();

	//Ϊ���򷵻�1
	bool empty() const;

	//���ؽڵ���
	int size() const;

	//ȡջ��Ԫ��
	T& top();

	//ɾ��ջ��Ԫ��
	void pop();

	//��ջ
	void push(const T& theElement);

private:
	chainNode<T>* stackTop;      //ָ��ջ���ڵ�
	int stackSize;               //ջ�Ĵ�С
};