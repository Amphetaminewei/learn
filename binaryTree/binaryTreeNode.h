#pragma once

#include<vcruntime.h>

template<class T>
class binaryTreeNode {
	//用做二叉树的节点
public:
	T element;
	binaryTreeNode<T>* leftChild;
	binaryTreeNode<T>* rightChild;

	//无参构造函数
	binaryTreeNode() {
		leftChild = NULL;
		rightChild = NULL;
	}
	//一个参数的构造函数
	binaryTreeNode(const T &theElement) {
		element = theElement;
		leftChild = NULL;
		rightChild = NULL;
	}
	//包括节点的左右子树及数据的构造函数
	binaryTreeNode(const T &theElement, binaryTreeNode<T>* theLiftChild, binaryTreeNode<T>* theRightChild) {
		element = theElement;
		leftChild = theLiftChild;
		rightChild = theRightChild;
	}
};