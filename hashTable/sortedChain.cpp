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
	lastNode = new sortedNode<K, E>(theChain->lastNode->element);
	lastNode->next = NULL;
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

template<class K,class E>
pair<const K, E>* sortedChain<K, E>::find(const K &theKey) const {
	//���������������ɹ��������ԣ�ʧ�ܷ���NULL��
	sortedNode<K, E>* itemNode = firstNode;
	while (itemNode->element.first != theKey && itemNode->next != NULL) {
		itemNode = itemNode->next;
	}
	if (itemNode->next != NULL) {
		return itemNode->element;
	}
	else {
		//cout << "without this element " << endl;
		//������Ҫ���û����������δ���ĵ���
		return NULL;
	}
}

template<class K,class E>
void sortedChain<K, E>::erase(const K &theKey) {
	//��ʽ���ֵ�⹹���м�ɾ��ʱ����Ҫ�ƶ���β�ڵ�
	if (theKey == firstNode->element.first) {
		//���ɾ������ͷ�ڵ�
		sortedNode<K, E>* tempNode = firstNode;
		firstNode = firstNode->next;
		delete tempNode;
		dSize--;
		return;
	}
	sortedNode<K, E>* itemNode = firstNode;
	while (itemNode->next->element.first != theKey && itemNode->next != NULL) {
		//��λ����Ҫɾ���ڵ���ϸ��ڵ�
		itemNode = itemNode->next;
	}
	if (itemNode->next == NULL) {
		return;
	}
	else if (itemNode->next == lastNode) {
		//���Ҫɾ������β�ڵ�
		sortedNode<K, E>* tempNode = firstNode;
		while (tempNode->next != lastNode) {
			tempNode = tempNode->next;
		}
		delete lastNode;
		lastNode = tempNode;
		dSize--;
	}
	else {
		//����Ȳ���ͷ�ڵ�Ҳ����β�ڵ�
		delete itemNode->next;
		itemNode->next = itemNode->next->next;
		dSize--;
	}
}

template<class K,class E>
void sortedChain<K, E>::insert(const pair<const K, E> &thePair) {
	//���ϸ�����������֪����Ҫ�Ҳ��뵽��ȥ
	//ûҪ��������Ҿ���ô����ô����
	//������ͷ�ڵ�������������ƺ���
	sortedNode<K, E>* itemNode = firstNode;
	while (itemNode->element.first != thePair.first && itemNode->next != NULL) {
		//�ж��Ƿ����key�Ѿ�����
		//����Ѿ����ڣ���λ�����������ԵĽڵ�
		itemNode = itemNode->next;
	}
	if (itemNode->next == NULL) {
		if (thePair.first == lastNode->element.first) {
			lastNode->element == thePair;
		}
		//�������������˶���β�ڵ�Ҳ����Ҫ�滻��Ԫ��
		//�Ͳ���ͷ�ڵ����
		sortedNode<K, E>* tempNode = firstNode->next;
		sortedNode<K, E>* newNode = new sortedNode<K, E>(thePair, tempNode);
		firstNode->next = newNode;
	}
	else {
		//�������ؼ����Ѿ����ֹ���,���޸�ԭ�ȵ�ֵ
		itemNode->element.second = thePair.second;
	}
}