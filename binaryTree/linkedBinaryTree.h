#pragma once

#include<iostream>

#include"binaryTree.h"
#include"binaryTreeNode.h"

template<class E>
class linkedBinaryTree :public binaryTree<binaryTreeNode<E>> {
	//�Ϳα���д�İ汾��̫һ��Ҳ����ô����⵫�������˶������������
	//ͨ��������һ��visit���ó���������ʵ����
	//���Ǻ�����һ�������ö����뵫�Ǹо��Լ�����д������~
	//emmmmm��ʵ��ϰ����Ҳ���Ǻ���
	//ֻ�Ǻ��ٿ�������ָ��ͻȻ�������е���
	//��ϰ��ϰ����ָ��о�������ܶ�
private:
	binaryTreeNode<E>* root;	//����ָ��ڵ�
	int treeSize;
	//�����˽�б�����ʵ����ִ�еݹ����������
	//�ڽ��б���ʱͨ�����صĹ��г�Ա��������˽�г�Աʵ��
	//����ָ��visit����ȷ���ڱ�����ʱ��Ҫ�Է��ʵĽڵ�ִ�еĲ���

	//�����visit����ͨ�����룬
	//ȥ��Ĺ�������һ�£����߸��Ľ������ʱ����
	//����ͨ�����������д��E�����������
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

//ģ�����Ա���������Ͷ���д��ͷ�ļ���
//������linkedBinaryTree.cpp��ʵ�����.cpp�޷�����Ŀ���ļ��Ӷ�����Ĵ���
//����һ�ֽ���������ڲ����ļ���include��Ҫ��.cpp�ļ�


//˽�к�������

template<class E>
void linkedBinaryTree<E>::preOrder(binaryTreeNode<E> *t) {
	//ʵ�ʵ����������������visit��ȷ����Ҫ�������ʵĽڵ���еĲ���
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

//���к�������

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