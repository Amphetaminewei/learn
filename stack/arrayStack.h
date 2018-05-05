#pragma once
#include"stack.h"

//����������ջ

template<class T>
class arrayStack :public stack {

public:
	arrayStack(int initialCapacity);
	~arrayStack();
	bool empty() const;
	int size() const;
	T& top();
	void pop();
	void push();

private:
	int stackTop;          //ջ��Ԫ�ص�����
	int arrayLength;       //���鳤��
	T *stack;              //����ջ������
};