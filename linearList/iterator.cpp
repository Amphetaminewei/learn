#include"iterator.h"

//������һ����㷭��������
//std�����ռ���Ҳ��һ��iterator
//������Ȼ����ͷ�ļ���
//�����using namepsace std
//Ҳ����Ϊ�����ظ��������µ�����

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
//���ﲢû�����ع�chainNode���ͣ�
//����chainNode<T>* ����Ҳ��ָ��
//�����Ҳ�ǵ�ַ�����Կ���ֱ����==��!=