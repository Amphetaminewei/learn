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
	lastNode = new sortedNode<K, E>(theChain->lastNode->element);
	lastNode->next = NULL;
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

template<class K,class E>
pair<const K, E>* sortedChain<K, E>::find(const K &theKey) const {
	//搜索函数，搜索成功返回数对，失败返回NULL；
	sortedNode<K, E>* itemNode = firstNode;
	while (itemNode->element.first != theKey && itemNode->next != NULL) {
		itemNode = itemNode->next;
	}
	if (itemNode->next != NULL) {
		return itemNode->element;
	}
	else {
		//cout << "without this element " << endl;
		//尽量不要替用户输出，方便未来的调用
		return NULL;
	}
}

template<class K,class E>
void sortedChain<K, E>::erase(const K &theKey) {
	//链式的字典解构在中间删除时不需要移动首尾节点
	if (theKey == firstNode->element.first) {
		//如果删除的是头节点
		sortedNode<K, E>* tempNode = firstNode;
		firstNode = firstNode->next;
		delete tempNode;
		dSize--;
		return;
	}
	sortedNode<K, E>* itemNode = firstNode;
	while (itemNode->next->element.first != theKey && itemNode->next != NULL) {
		//定位到所要删除节点的上个节点
		itemNode = itemNode->next;
	}
	if (itemNode->next == NULL) {
		return;
	}
	else if (itemNode->next == lastNode) {
		//如果要删除的是尾节点
		sortedNode<K, E>* tempNode = firstNode;
		while (tempNode->next != lastNode) {
			tempNode = tempNode->next;
		}
		delete lastNode;
		lastNode = tempNode;
		dSize--;
	}
	else {
		//如果既不是头节点也不是尾节点
		delete itemNode->next;
		itemNode->next = itemNode->next->next;
		dSize--;
	}
}

template<class K,class E>
void sortedChain<K, E>::insert(const pair<const K, E> &thePair) {
	//书上给的这个定义鬼知道是要我插入到哪去
	//没要求插在哪我就怎么简单怎么来了
	//单项链头节点后面插入最简单了似乎？
	sortedNode<K, E>* itemNode = firstNode;
	while (itemNode->element.first != thePair.first && itemNode->next != NULL) {
		//判断是否这个key已经存在
		//如果已经存在，定位到存放这个数对的节点
		itemNode = itemNode->next;
	}
	if (itemNode->next == NULL) {
		if (thePair.first == lastNode->element.first) {
			lastNode->element == thePair;
		}
		//如果遍历到最后了而且尾节点也不是要替换的元素
		//就插在头节点后面
		sortedNode<K, E>* tempNode = firstNode->next;
		sortedNode<K, E>* newNode = new sortedNode<K, E>(thePair, tempNode);
		firstNode->next = newNode;
	}
	else {
		//如果这个关键字已经出现过了,则修改原先的值
		itemNode->element.second = thePair.second;
	}
}