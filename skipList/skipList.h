#pragma once
/*
����ʵʵ�ĳ�һ������ɡ�
��������о��Լ���ˮƽ�����д������
���糭��ѧѧ
*/

#include<utility>

#include"skipNode.h"

template<class K,class E>
class skipList {
private:
	float cutOff;                  //��ȷ������
	int levels;				       //��ǰ���ǿ�����
	int dSize;                     //�ֵ�����Ը���
	int maxLevel;                  //�����������
	K tailKey;                     //���ؼ���
	skipNode<K, E>* headerNode;    //ͷ�ڵ�ָ��
	skipNode<K, E>* tailNode;      //β�ڵ�ָ��
	skipNode<K, E>** last;         //last[i]��ʾ��i���β�ڵ�

public:
	skipList(K largeKey, int maxParis, float prob);
	std::pair<const K, E>* find(const K& theKey) const;
	int level() const;
	skipNode<K, E>* search(const K& theKey) const;
	void insert(const pair<const K, E>& thePair);
	void erase(const K& theKey);
	int size() const;
	bool empty() const;
};