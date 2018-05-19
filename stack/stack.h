#pragma once

template<class T>
class stack {
	virtual ~stack() { };

	//栈为空时返回true
	virtual bool empty() const = 0;

	//返回栈中元素个数
	virtual int size() const = 0;

	//返回栈顶元素的引用
	virtual T& top() = 0;

	//删除栈顶元素
	virtual void pop() = 0;

	//将元素theElement压入栈
	virtual void push(const T& theElement) = 0;
};