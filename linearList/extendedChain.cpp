#include"extendedChain.h"
#include"chainNode.h"

using namespace std;

template<class T>
extendedChain<T>::extendedChain(int initalCapacity) {
	if (initalCapacity < 1) {
		//如果初始容量小于一
		cout << "the initalCapacity must > 1" << endl;
		return;
	}
	else {
		firstNode = NULL;
		lastNode = NULL;
		listSize = 0;
	}
}

template<class T>
extendedChain<T>::extendedChain(const extendedChain<T>& theList) {
	listSize = theList.listSize;
	if (listSize < 1) {
		return;
	}
	else {
		//尾指针指向最后的元素，最后的元素地址域都为空
		lastNode = new chainNode<T>(theList.lastNode->element);
		//用itemNode来代替theList的头指针移动
		chainNode<T>* itemNode = theList.firstNode;
		//new一个头指针,chainNode构造函数chainNode(const T& element),指针域目前为空
		firstNode = new chainNode<T>(itemNode->element);
		itemNode = itemNode->next;
		//用temporary来代替this->firstNode移动
		chainNode<T>* temporary = firstNode;
		while (itemNode != NULL) {
			//为新的链表申请一个新的节点，数据等于theList的数据
			temporary->next = new chainNode<T>(itemNode->element);
			itemNode = itemNode->next;
			temporary->next = itemNode;
		}
	}
}

template<class T>
extendedChain<T>::~extendedChain() {
	while (firstNode != NULL) {
		chainNode<T>* itemNode = firstNode->next;
		delete firstNode;
		firstNode = itemNode;
	}
}

template<class T>
void extendedChain<T>::empty() {
	if (linearList == 0) {
		return 1;
	}
	else {
		return 0;
	}
}