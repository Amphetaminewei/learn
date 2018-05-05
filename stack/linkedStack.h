#pragma once

#include"stack.h"
#include"chainNode.h"

template<class T>
class linkedStack :public stack<T> {

public:
	linkedStack();
	~linkedStack();

	//为空则返回1
	bool empty() const;

	//返回节点数
	int size() const;

	//取栈顶元素
	T& top();

	//删除栈顶元素
	void pop();

	//入栈
	void push(const T& theElement);

private:
	chainNode<T>* stackTop;      //指向栈顶节点
	int stackSize;               //栈的大小
};