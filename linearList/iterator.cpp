#include"iterator.h"

//这里有一个差点翻车的问题
//std命名空间中也有一个iterator
//所以虽然不在头文件中
//如果用using namepsace std
//也会因为命名重复发生可怕的事情

template<class T>
iterator<T>::iterator(chainNode<T>* theNode = NULL) {
	node = theNode;
}

template<class T>
iterator<T> iterator<T>::operator++(int) {
	iterator oldNode = *this;
	node = node->next;
	return oldNode;
}

template<class T>
iterator<T>& iterator<T>::operator++() {
	node = node->next;
	return node;
}

template<class T>
T& iterator<T>::operator*() const {
	return node->element;
}

template<class T>
T* iterator<T>::operator->() const {
	return &node->element;
}

template<class T>
bool iterator<T>::operator!=(const iterator item) const {
	if (node != item.node) {
		return 1;
	}
	else {
		return 0;
	}
}

template<class T>
bool iterator<T>::operator==(const iterator item) const {
	if (node == item.node) {
		return 1;
	}
	else {
		return 0;
	}
}
//这里并没有重载过chainNode类型，
//但是chainNode<T>* 本质也是指针
//储存的也是地址，所以可以直接用==和!=