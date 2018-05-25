#include<utility>
#include<iostream>
#include<sstream>

#include"skipList.h"
#include"skipNode.h"

using namespace std;

template<class K,class E>
skipList<K, E>::skipList(K largeKey, int maxPairs, float prob) {
	//���캯�����ؼ���С��largeKey��size���ΪmaxPairs��0 < prod < 1

	cutOff = prob * RAND_MAX;
	//rand_max��һ����׼����������
	maxLevel = (int)ceil(logf((float)maxPairs) / logf(1 / prob)) - 1;
	levels = 0;
	dSize = 0;
	tailKey = largeKey;

	pair<K, E> tailPair;
	tailPair.first = tailKey;

	//����ͷ�ڵ�
	headerNode = new skipNode<K, E>(tailPair, maxLevel + 1);
	//����β�ڵ�
	tailNode = new skipNode<K, E>(tailPair, 0);
	last = new skipNode<K, E> *[maxLevel + 1];

	for (int i = 0;i <= maxLevel;i++) {
		//����Ϊ��ʱ���Լ�����ͷָ�붼ָ��β�ڵ�s
		headerNode->next[i] = tailNode;
	}
}

template<class K,class E>
pair<const K, E>* skipList<K, E>::find(const K& theKey) const {
	if (theKey >= tailKey) {
		//���û��ƥ�������
		//��Ҫ���������Դ����������
		return NULL;
	}
	skipNode<K, E>* beforeNode = headerNode;
	//beforeNode��λ����theKey�Ľڵ�֮ǰ���ұߵ�λ��;
	//����ô����������ߵġ�����
	for (int i = levels;i >= 0;i--) {
		//����i������ָ��
		while (beforeNode->next[i]->element.first < theKey) {
			beforeNode = beforeNode->next[i];
		}
	}
	if (beforeNode->next[0]->element.first == theKey) {
		return &beforeNode->next[0]->element
	}
	return NULL;
}

template<class K,class E>
int skipList<K, E>::level() const {
	//����һ���������������maxLevel
	int lev = 0;
	while (rand() <= cutOff) {
		lev++;
	}
	return (lev <= maxLevel) ? lev : maxLevel;
}

template<class K,class E>
skipNode<K,E>* skipList<K, E>::search(const K& theKey) const {
	skipNode<K, E>* beforeNode = headerNode;
	for (int i = levels;i >= 0;i--) {
		while (beforeNode->next[i]->element.first < theKey) {
			beforeNode = beforeNode->next[i];
		}
		last[i] = beforeNode;
	}
	return beforeNode->next[0];
}

template<class K,class E>
void skipList<K,E>::insert(const pair<const K, E>& thePair){
	if (thePair.first >= tailKey) {
		ostringstream s;
		s << "key = " << thePair.first << "must <" << tailKey;
	}
	skipNode<K, E>* theNode = search(thePair.first);
	if (theNode->element.first == thePair.first) {
		theNode->element.second = thePair.second;
		return;
	}
	int theLevel = level();
	if (theLevel > levels) {
		theLevel = ++levels;
		last[theLevel] = headerNode;
	}
	skipNode<K, E>* newNode = new skipNode<K, E>(thePair, theLevel + 1);
	for (int i = 0;i <= theLevel;i++) {
		newNode->next[i] = last[i]->next[i];
		last[i]->next[i] = newNode;
	}
	dSize++;
	return;
}

template<class K,class E>
void skipList<K, E>::erase(const K& theKey) {
	if (theKey >= tailKey) {
		return;
	}
	skipNode<K, E>* theNode = search(theKey);
	if (theNode->element.first != theKey) {
		return;
	}
	for (int i = 0;i <= levels && last[i]->next[i] == theKey;i++) {
		last[i]->next[i] = theNode->next[i];
	}
	while (levels > 0 && headerNode->next[levels] == tailKey) {
		levels--;
		delete theNode;
		dSize--;
	}
}

template<class K,class E>
int skipList<K, E>::size() const {
	return dSize;
}

template<class K,class E>
bool skipList<K, E>::empty() const {
	if (dSize != 0) {
		return 0;
	}
	else {
		return 1;
	}
}