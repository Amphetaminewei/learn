#pragma once

#include<vcruntime.h>

template<class T>
class binaryTreeNode {
	//�����������Ľڵ�
public:
	T element;
	binaryTreeNode<T>* leftChild;
	binaryTreeNode<T>* rightChild;

	//�޲ι��캯��
	binaryTreeNode() {
		leftChild = NULL;
		rightChild = NULL;
	}
	//һ�������Ĺ��캯��
	binaryTreeNode(const T &theElement) {
		element = theElement;
		leftChild = NULL;
		rightChild = NULL;
	}
	//�����ڵ���������������ݵĹ��캯��
	binaryTreeNode(const T &theElement, binaryTreeNode<T>* theLiftChild, binaryTreeNode<T>* theRightChild) {
		element = theElement;
		leftChild = theLiftChild;
		rightChild = theRightChild;
	}
};