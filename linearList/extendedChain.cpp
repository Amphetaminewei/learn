#include"extendedChain.h"
#include"chainNode.h"

using namespace std;

//这个版本的链表没定义checkIndex函数，检查index是否有效都用的if；
//发现了之前的版本在循环中索引和表长的问题
//统一改成了索引从0开始，也就是chain[listSize - 1]为最后一个元素

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
	listSize = 0;
}

template<class T>
void extendedChain<T>::clear() {
	if (listSize == 0) {
		cout << "the list is empty" << endl;
	}
	else {
		//直接调用析构函数
		~extendedChain();
		cout << "the list is cleared" << endl;
	}
}

template<class T>
void extendedChain<T>::push_back(const T& theElement) {
	//建立新节点，数据域等于theElement
	chainNode<T>* newNode = new chainNode<T>(theElement);
	//尾指针指向的节点的地址域指向新节点
	lastNode->next = newNode;
	lastNode = newNode;
	listSize = listSize + 1;
}

template<class T>
int extendedChain<T>::size() {
	return listSize;
}

template<class T>
T& extendedChain<T>::get(int theIndex) {
	if (theIndex < 0 || theIndex > listSize - 1) {
		cout << "the index shuold > 0 & < listSize+1" << endl;
	}
	else {
		chainNode<T>* itemNode = firstNode;
		for (int i = 0;i < theIndex;i++) {
			itemNode = itemNode->next;
		}
		return itemNode->element;
	}
}

template<class T>
int extendedChain<T>::indexOf(const T& theElement) {
	//如果该元素不存在则返回-1
	if (listSize < 1) {
		cout << "the list is empty" << endl;
	}
	else {
		chainNode<T>* itemNode = firstNode;
		int theIndex = 0;
		while (itemNode->element != theElement || itemNode != NULL) {
			itemNode = itemNode->next;
			theIndex = theIndex + 1;
		}
		if (itemNode == NULL) {
			return -1;
		}
		else {
			return theIndex;
		}
	}
}

template<class T>
bool extendedChain<T>::empty() {
	if (linearList == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

template<class T>
void extendedChain<T>::erase(int theIndex) {
	if (theIndex<0 || theIndex>listSize - 1) {
		cout << "the index shuold > 0 & <= listSize - 1" << endl;
	}
	else {
		chainNode<T>* delNode = firstNode;
		if (theIndex == 0) {
			//如果删除首节点
			firstNode = firstNode->next;
			listSize = listSize - 1;
		}
		else if (theIndex == listSize - 1) {
			//如果删除尾节点
			for (int ií < listSize - 1;i++) {
				delNode = delNode->next;
			}
			lastNode = delNode;
			delete delNode->next;
			listSize = listSize - 1;
		}
		else {
			//定位到要删除的前一个节点,这里索引是从零开始的
			for (int i = 0;i < theIndex;i++) {
				delNode = delNode->next;
			}
			//让the index的前一个节点的地址域指向the index的地址域
			delNode->next = delNode->next->next;
			delete delNode;
			listSize = listSize - 1;
		}
	}
}

template<class T>
void extendedChain<T>::insert(int theIndex, const T& theElement) {
	if (theIndex<0 || theIndex>listSize - 1) {
		cout << "the index shuold > 0 & <= listSize - 1" << endl;
	}
	else {
		if (theIndex == 0) {
			//如果在首节点插入
			chainNode<T>* newNode = new chainNode<T>(theElement, firstNode);
			firstNode = newNode;
		}
		else if (theIndex == listSize - 1) {
			//如果在尾后插入
			chainNode<T>* newNode = new chainNode<T>(theElement);
			lastNode->next = newNode;
			lastNode = newNode;
		}
		else {
			//如果在非表头和表尾处插入
			chainNode<T>* itemNode = firstNode;
			for (int i = 0;i < theIndex;i++) {
				itemNode = itemNode->next;
			}
			chainNode<T>* newNode = new chainNode<T>(theElement, itemNode->next);
			itemNode->next = newNode;
		}
		listSize = listSize + 1;
	}
}

template<class T>
void extendedChain<T>::output(ostream& out) {
	if (listSize == 0) {
		out << "the list is empty" << endl;
	}
	else {
		chainNode<T>* itemNode = firstNode;
		for (i = 0;i < listSize;i++) {
			out << itemNode->element << endl;
			itemNode = itemNode->next;
		}
	}
}