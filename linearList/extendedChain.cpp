#include"extendedChain.h"
#include"chainNode.h"

using namespace std;

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