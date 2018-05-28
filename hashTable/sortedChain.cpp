#include<utility>
#include<iostream>

#include"sortedChain.h"

using namespace std;

template<class K,class E>
sortedChain<K, E>::sortedChain() {
	//初始化一个空的链字典
	firstNode = NULL;
	lastNode = NULL;
	dSize = 0;
}

template<class K,class E>
sortedChain<K, E>::sortedChain(const sortedChain<const K, E>* theChain) {
	//复制构造函数
	if (theChain->dSize == 0) {
		cout << "the sortedChain is empty" << endl;
		return;
	}
	dSize = theChain->dSize;
	//还是那句话，头指针不能乱动
	firstNode = new sortedNode<K, E>;
	firstNode->element = theChain->firstNode->element;
	sortedNode<K, E>* tempNode = theChain->firstNode;
	sortedNode<K, E>* itemNode = firstNode;	
	while (tempNode != NULL) {
		itemNode->next = new sortedNode<K, E>(tempNode->element);
		tempNode = tempNode->next;
		itemNode = itemNode->next;
	}
}

template<class K,class E>
sortedChain<K, E>::~sortedChain() {
	//析构函数
	while (firstNode != NULL) {
		//要有一个指针来保存头节点的下一个节点位置
		sortedNode<K, E>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}

template<class K,class E>
bool sortedChain<K, E>::empty() const {
	if (dSize == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

template<class K,class E>
int sortedChain<K, E>::size() const {
	return dSize;
}