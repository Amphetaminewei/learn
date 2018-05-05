#include"linkedStack.h"

template<class T>
linkedStack<T>::linkedStack() {
	stackSize = 0;
	stackTop = NULL;
}

template<class T>
linkedStack<T>::~linkedStack() {
	while (stackTop->next == NULL) {
		//����һ���ڵ㴢��stackTop����һ���ڵ�λ��
		chainNode<T>* nextNode = stackTop->next;
		//�ͷ�stackTop
		delete stackTop;
		stackTop = nextNode;
	}
}

template<class T>
bool linkedStack<T>::empty() const {
	if (stackSize == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

template<class T>
int linkedStack<T>::size() const {
	return stackSize;
}

template<class T>
T& linkedStack<T>::top() {
	return stackTop->element;
}

template<class T>
void linkedStack<T>::pop() {
	chainNode<T>* nextNode = stackTop->next;
	delete stackTop;
	stackTop = nextNode;
	stackSize = stackSize - 1;
}

template<class T>
void linkedStack<T>::push(const T& theElement) {
	chainNode<T>* newNode = new chainNode<T>(theElement);
	newNode->next = stackTop;
	stackTop = newNode;
	stackSize = stackSize + 1;
	//����chainNode����һ�ֹ��캯��
	//stackTop = new chainNode<T>(theElement,stackTop);
	//stackSize = stackSize + 1
}