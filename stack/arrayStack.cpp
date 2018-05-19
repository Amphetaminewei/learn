#include"arrayStack.h"
#include<iostream>
#include<algorithm>

using namespace std;

template<class T>
arrayStack<T>::arrayStack(int initalCapacity) {
	if (initalCapacity < 1) {
		cout << "the initalCapacity shuold > 1" << endl;
	}
	else {
		arrayLength = initalCapacity;
		stack = new T[arrayLength];
		stackTop = -1;//空栈还没有元素
	}
}

template<class T>
arrayStack<T>::~arrayStack() {
	delete[] stack;
}

template<class T>
bool arrayStack<T>::empty() const {
	if (stackTop == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

template<class T>
int arrayStack<T>::size() const {
	return stackTop + 1;
}

template<class T>
T& arrayStack<T>::top() {
	if (stackTop == -1) {
		cout << "the stack is empty" << endl;
	}
	else {
		return stack[stackTop];
	}
}

template<class T>
void arrayStack<T>::pop() {
	if (stackTop == -1) {
		cout << "the stack is empty" << endl;
	}
	else {
		stack[stackTop].~T();
		stackTop = stackTop - 1;
	}
}

template<class T>
void arrayStack<T>::push(const T& theElement) {
	if (stackTop == arrayLength - 1) {
		//如果栈已满
		//建立一个新数组
		T* newArray = new T[arrayLength * 2];
		for (int i = 0;i < arrayLength;i++) {
			newArray[i] = stack[i];
		}
		//释放掉原来stack指向的空间
		delete[]stack;
		//让stack指向newArray的空间
		stack = newArray;
		arrayLength *= 2;
	}
	stack[++stackTop] = theElement;
}