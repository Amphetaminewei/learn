#include"extendedChain.h"
#include"chainNode.h"

using namespace std;

//����汾������û����checkIndex���������index�Ƿ���Ч���õ�if��
//������֮ǰ�İ汾��ѭ���������ͱ�������
//ͳһ�ĳ���������0��ʼ��Ҳ����chain[listSize - 1]Ϊ���һ��Ԫ��

template<class T>
extendedChain<T>::extendedChain(int initalCapacity) {
	if (initalCapacity < 1) {
		//�����ʼ����С��һ
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
		//βָ��ָ������Ԫ�أ�����Ԫ�ص�ַ��Ϊ��
		lastNode = new chainNode<T>(theList.lastNode->element);
		//��itemNode������theList��ͷָ���ƶ�
		chainNode<T>* itemNode = theList.firstNode;
		//newһ��ͷָ��,chainNode���캯��chainNode(const T& element),ָ����ĿǰΪ��
		firstNode = new chainNode<T>(itemNode->element);
		itemNode = itemNode->next;
		//��temporary������this->firstNode�ƶ�
		chainNode<T>* temporary = firstNode;
		while (itemNode != NULL) {
			//Ϊ�µ���������һ���µĽڵ㣬���ݵ���theList������
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
		//ֱ�ӵ�����������
		~extendedChain();
		cout << "the list is cleared" << endl;
	}
}

template<class T>
void extendedChain<T>::push_back(const T& theElement) {
	//�����½ڵ㣬���������theElement
	chainNode<T>* newNode = new chainNode<T>(theElement);
	//βָ��ָ��Ľڵ�ĵ�ַ��ָ���½ڵ�
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
	//�����Ԫ�ز������򷵻�-1
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
			//���ɾ���׽ڵ�
			firstNode = firstNode->next;
			listSize = listSize - 1;
		}
		else if (theIndex == listSize - 1) {
			//���ɾ��β�ڵ�
			for (int i�� < listSize - 1;i++) {
				delNode = delNode->next;
			}
			lastNode = delNode;
			delete delNode->next;
			listSize = listSize - 1;
		}
		else {
			//��λ��Ҫɾ����ǰһ���ڵ�,���������Ǵ��㿪ʼ��
			for (int i = 0;i < theIndex;i++) {
				delNode = delNode->next;
			}
			//��the index��ǰһ���ڵ�ĵ�ַ��ָ��the index�ĵ�ַ��
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
			//������׽ڵ����
			chainNode<T>* newNode = new chainNode<T>(theElement, firstNode);
			firstNode = newNode;
		}
		else if (theIndex == listSize - 1) {
			//�����β�����
			chainNode<T>* newNode = new chainNode<T>(theElement);
			lastNode->next = newNode;
			lastNode = newNode;
		}
		else {
			//����ڷǱ�ͷ�ͱ�β������
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