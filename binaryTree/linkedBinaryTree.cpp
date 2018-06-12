#include"linkedBinaryTree.h"

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