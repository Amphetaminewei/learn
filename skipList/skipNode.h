#pragma once

#include<utility>

//跳表的节点类

template<class K, class E>
class skipNode {

public:
	//用pair储存要保存的值和关键字
	std::pair<const K, E> element;
	skipNode<K, E> **next;

	skipNode(const std::pair<K, E>& thePair, int size):element(thePair) {
		next = new skipNode<K, E>* [size];
		//这东西是啥时候支持下表操作的。。。
	}
};