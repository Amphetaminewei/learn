#include<utility>
#include<iostream>

#include"sortedChain.h"

using namespace std;

template<class K,class E>
sortedChain<K, E>::sortedChain() {
	//��ʼ��һ���յ����ֵ�
	firstNode = NULL;
	lastNode = NULL;
	dSize = 0;
}

template<class K,class E>
sortedChain<K, E>::sortedChain(const sortedChain<const K, E>* theChain) {
	//���ƹ��캯��
	if (theChain->dSize == 0) {
		cout << "the sortedChain is empty" << endl;
		return;
	}
	dSize = theChain->dSize;
	//�����Ǿ仰��ͷָ�벻���Ҷ�
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
	//��������
	while (firstNode != NULL) {
		//Ҫ��һ��ָ��������ͷ�ڵ����һ���ڵ�λ��
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