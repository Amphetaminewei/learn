#include"chain.h"
#include"chainNode.h"
#include"linearList.h"
#include"illegalParameterValue.h"

using namespace std;

//对于链表的实现

//构造函数
template<class T>
chain<T>::chain(int initialCapacity) {
	if (initialCapacity < 1) {
		ostream s;
		s << "Initial capacity = " << initialCapacity << "Must be > 0";
		throw illegalParameterVaule(s.str());
	}
	//链表是用一个就加上一个，所以直接初始化为空再一个一个往上加就行了
	firstNode = NULL;
	listSize = 0;
}
//复制构造函数
template<class T>
chain<T>::chain(const chain<T>& theList) {
	listSize = theList.listSize;

	if (listSize == 0) {
		firstNode = NULL;
		return;
	}
	else {
		chainNode<T>* sourceNode = theList.firstNode;    
		firstNode = new chainNode<T>(sourceNode->element);   //好像c++书上写过能用智能指针就别用普通指针，这里数据结构书里这样用指针是不是因为运行效率。
		sourceNode = sourceNode->next;
		chainNode<T>* targetNode = firstNode;
		while (sourceNede != NULL) {
			targetNode->next = new chainNode<T>(sourceNode->element);
			targetNode = targetNode->next;
			sourceNode = sourceNode->next;
			//注释里是书上的写法，看了好几遍没看懂，
			//后来发现就是新建了两个指针来代替theList.firstNode和this.firtsNode
			//书上也没写为什么要加两个中间变量，单纯为了看起来逻辑简单？

			//好了看懂了，是不能动头指针，不然头指针位置变了还得重置
		}
	}
}

//析构函数
template<class T>
chain<T>::~chain() {
	while (firstNode != NULL) {
		chainNode<T>* nextNode = firstNode->next;
		//用一个中间量临时储存下一个节点的地址然后释放当前节点
		delete firstNode;
		firstNode = nextNode;
	}
}

//判断是否为空
template<class T>
bool chain<T>::empty() {
	if (firstNode = NULL) {
		return false;
	}
	else {
		return true;
	}
}

//返回元素个数
template<class T>
int chain<T>::size() {
	return listSize;
}

//返回index的值
template<class T>
T& chain<T>::get(int theIndex){
	chackIndex(theIndex);
	chainNode<T>* tempNode = firstNode;
	//遍历到所需索引的时候返回当前数据域
	for (int i = 0;i < theIndex;i++) {
		tempNode = tempNode->next;
	}
	return tempNode->element;
}

template<class T>
int chain<T>::indexOf(const T& theElement) {
	chainNode<T>* tempNode = firstNode;
	for (int i = 0;i < listSize;i++) {
		//如果当前索引的数据域不为所需数据，进入下一个节点
		if (tempNode->element == theElement) {
			return i;
		}
		tempNode = tempNode->next;
	}
	cout << "without this element" << endl;
	return 0;
}

template<class T>
void chain<T>::erase(int theIndex) {
	chainNode<T>* delNode = firstNode;
	for (int i = 0;i < theIndex - 1;i++) {
		delNode = delNode->next;
	}
	chainNode<T>* tempNode = delNode->next;
	delNode->next = delNode->next->next;
	//通过循环定位到theindex的位置，然后释放节点并将表长减一
	delNode = NULL;
	delete delNode->next;
	listSize--;
}

template<class T>
void chain<T>::insert(int theIndex, const T& theElement) {
	//定位到theIndex的前一个节点
	chainNode<T>* tempNode = firstNode;
	for (int i = 0;i < theIndex - 1;i++) {
		tempNode = tempNode->next;
	}
	//创建一个新节点，地址域储存firstNode的下一个节点
	chainNode<T>* newNode = new chainNode<T>(theElement, tempNode->next);
	//将firstNode的地址域指向newNode
	tempNode->next = newNode;
	//表长加一
	listSize++;
}

template<class T>
void chain<T>::output(ostream& out) {
	chainNode<T>* tempNode = firstNode;
	//遍历整个表并输出所有元素
	if (listSize == 0) {
		out << "the linearList is empty" << endl;
	}
	for (i = 0;i < listSize;i++) {
		out << tempNode->element;
		tempNode = tempNode->next;
	}
}

template<class T>
void chain<T>::checkIndex(int theIndex)const {
	//异常类是抄来的。。。记得好像标准库也有差不多的。
	if (theIndex < 0) {
		throw illegalParameterVaule("theIndex should be >= 0");
	}
}

