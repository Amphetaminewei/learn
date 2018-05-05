#pragma once
#include"stack.h"

//数组描述的栈

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
	int stackTop;          //栈顶元素的索引
	int arrayLength;       //数组长度
	T *stack;              //用作栈的数组
};