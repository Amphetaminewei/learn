#pragma once

#include<iostream>

#include"binaryTree.h"
#include"binaryTreeNode.h"

template<class E>
class linkedBinaryTree :public binaryTree<binaryTreeNode<E>> {
	//和课本上写的版本不太一样也不那么好理解但是增加了二叉树的灵活性
	//通过增加了一个visit来让程序增加了实用性
	//还是和跳表一样，看得懂代码但是感觉自己绝对写不出来~
	//emmmmm其实自习看看也不是很难
	//只是很少看到函数指针突然看到会有点懵
	//复习复习函数指针感觉会好理解很多
private:
	binaryTreeNode<E>* root;	//用来指向节点
	int treeSize;
	//这里的私有变量是实际上执行递归遍历操作的
	//在进行遍历时通过重载的共有成员函数调用私有成员实现
	//函数指针visit可以确定在遍历的时候要对访问的节点执行的操作

	//这里的visit不能通过编译，
	//去书的官网查了一下，作者给的解决方案时这样
	//可以通过在下面具体写出E的类型来解决
	static void(*visit)(binaryTreeNode<E> *);
	static void preOrder(binaryTreeNode<E> *t);
	static void inOrder(binaryTreeNode<E> *t);
	static void postOrder(binaryTreeNode<E> *t);
	static void dispose(binaryTreeNode<E> *t);
	static int height(binaryTreeNode<E> *t);

public:
	linkedBinaryTree();
	~linkedBinaryTree();
	bool empty() const;
	int size() const;
	void preOrder(void(*theVisit)(binaryTreeNode<E>*));
	void inOrder(void(*theVisit)(binaryTreeNode<E>*));
	void postOrder(void(*theVisit)(binaryTreeNode<E>*));
	void erase();	
	int height() const;

};

//模板类成员函数声明和定义写在头文件中
//避免在linkedBinaryTree.cpp中实现造成.cpp无法生成目标文件从而引起的错误
//还有一种解决方法是在测试文件中include需要的.cpp文件


//私有函数定义

template<class E>
void linkedBinaryTree<E>::preOrder(binaryTreeNode<E> *t) {
	//实际的先序遍历函数，用visit来确定需要对所访问的节点进行的操作
	if (t != NULL) {
		linkedBinaryTree<E>::visit(t);
		preOrder(t->leftChild);
		preOrder(t->rightChild);
	}
}

template<class E>
void linkedBinaryTree<E>::inOrder(binaryTreeNode<E> *t) {
	if (t != NULL) {
		inOrder(t->leftChild);
		linkedBinaryTree<E>::visit(t);
		inOrder(t->rightChild);
	}
}

template<class E>
void linkedBinaryTree<E>::postOrder(binaryTreeNode<E> *t) {
	if (t != NULL) {
		postOrder(t->leftChild);
		postOrder(t->rightChild);
		linkedBinaryTree<E>::visit(t);
	}
}

template<class E>
void linkedBinaryTree<E>::dispose(binaryTreeNode<E> *t) {
	delete t;
}

template<class E>
int linkedBinaryTree<E>::height(binaryTreeNode<E> *t) {
	if (t == NULL) {
		return 0;
	}
	else {
		int hl = height(t->leftChild);
		int hr = height(t->rightChild);
		if (hl > hr) {
			return ++hl;
		}
		else {
			return ++hr;
		}
	}
}

//公有函数定义

template<class E>
linkedBinaryTree<E>::linkedBinaryTree() {
	root = NULL;
	treeSize = 0;
}

template<class E>
linkedBinaryTree<E>::~linkedBinaryTree() {
	erase();
}

template<class E>
bool linkedBinaryTree<E>::empty() const {
	return treeSize == 0;
}

template<class E>
int linkedBinaryTree<E>::size() const {
	return treeSize;
}

template<class E>
void linkedBinaryTree<E>::preOrder(void(*theVisit)(binaryTreeNode<E>*)) {
	visit = theVisit;
	preOrder(root);
}

template<class E>
void linkedBinaryTree<E>::inOrder(void(*theVisit)(binaryTreeNode<E>*)) {
	visit = theVisit;
	inOrder(root);
}

template<class E>
void linkedBinaryTree<E>::postOrder(void(*theVisit)(binaryTreeNode<E>*)) {
	visit = theVisit;
	postOrder(root);
}

template<class E>
void linkedBinaryTree<E>::erase() {
	postOrder(dispose);
	root = NULL;
	treeSize = 0;
}

template<class E>
int linkedBinaryTree<E>::height() const {
	return height(root);
}