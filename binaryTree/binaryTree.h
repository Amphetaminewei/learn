#pragma once

//binaryTree抽象类

template<class T>
class binaryTree {

public:
	virtual ~binaryTree(){ }
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	//一个void类型的函数指针做参数,这个函数参数为一个T类型的指针
	virtual void preOrder(void(*) (T*)) = 0;
	virtual void inOrder(void(*)(T*)) = 0;
	virtual void postOrder(void(*)(T*)) = 0;
	//virtual void levelOrder(void(*)(T*)) = 0;
};