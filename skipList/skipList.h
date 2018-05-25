#pragma once
/*
老老实实的抄一个跳表吧。
看了两天感觉自己的水平真的是写不出来
不如抄抄学学
*/

#include<utility>

#include"skipNode.h"

template<class K,class E>
class skipList {
private:
	float cutOff;                  //来确定层数
	int levels;				       //当前最大非空链表
	int dSize;                     //字典的数对个数
	int maxLevel;                  //允许的最大层数
	K tailKey;                     //最大关键字
	skipNode<K, E>* headerNode;    //头节点指针
	skipNode<K, E>* tailNode;      //尾节点指针
	skipNode<K, E>** last;         //last[i]表示第i层的尾节点

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