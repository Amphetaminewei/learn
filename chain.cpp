#include"chain.h"
#include"chainNode.h"
#include"linearList.h"
#include"illegalParameterValue.h"

using namespace std;

//���캯��
template<class T>
chain<T>::chain(int initialCapacity) {
	if (initialCapacity < 1) {
		ostream s;
		s << "Initial capacity = " << initialCapacity << "Must be > 0";
		throw illegalParameterVaule(s.str());
	}
	firstNode = NULL;
	listSize = 0;
}
//���ƹ��캯��
template<class T>
chain<T>::chain(const chain<T>& theList) {
	listSize = theList.listSize;

	if (listSize == 0) {
		firstNode = NULL;
		return;
	}
	else {
		chainNode<T>* sourceNede = theList.firstNode;
		firstNode = new chainNode<T>(sourceNede->element);
		sourceNede = sourceNede->next;
		chainNode<T>* targetNode = firstNode;
		while (sourceNede != NULL) {
			targetNode->next = new chainNode<T>(sourceNede->element);
			targetNode = targetNode->next;
			sourceNede = sourceNede->next;
		}
	}
}

//��������
template<class T>
chain<T>::~chain() {
	while (firstNode != NULL) {
		chainNode<T>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}

//�ж��Ƿ�Ϊ��
template<class T>
bool chain<T>::empty() {
	if (firstNode = NULL) {
		return false;
	}
	else {
		return true;
	}
}

//����Ԫ�ظ���
template<class T>
int chain<T>::size() {
	return listSize;
}

//����index��ֵ
template<class T>
T& chain<T>::get(int theIndex){
	chackindex(theIndex);
	chainNode<T> *currentNode = firstNode;
	for (int i = 0;i < theIndex;i++) {
		currentNode = currentNode->next;
	}
	return currentNode->element;
}

template<class T>
int chain<T>::indexOf(const T& theElement) {
	chainNode<T> *currentNode = firstNode;
	for (int i = 0;i < listSize;i++) {
		currentNode = currentNode->next;
		if (currentNode->element == theElement) {
			return i;
		}
	}
	cout << "without this element" << endl;
	return 0;
}
