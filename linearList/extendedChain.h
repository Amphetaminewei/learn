#pragma once

#include"extendedLinearList.h"
#include"chainNode.h"
//����չ���Ա��������������չ�������

template<class T>
class extendedChain : public extendedLinearList<T> {
private:
	chainNode<T>* firstNode;
	chainNode<T>* lastNode;
	int listSize;

	//��������Ƿ���Ч
	void checkIndex(const int& theIndex);

public:
	//���캯��
	extendedChain(int initialCapacity);
	//���ƹ��캯��
	extendedChain(const extendedChain<T>& theChain);
	//��������
	~extendedChain();

	//��ձ�
	void clear();
	//����������ΪtheElement���½ڵ㵽��β
	void push_back(const T& theElement);

	//�ж������Ƿ�Ϊ��
	bool empty();

	//����Ԫ�صĸ���
	int size();

	//��������ΪtheIndex��Ԫ��
	T& get(int theIndex);

	//����Ԫ��theElement��һ�γ��ֵ�����,���������򷵻�-1
	int indexOf(const T& theElement);

	//ɾ������Ϊindex��Ԫ��
	void erase(int theIndex);

	//��theElement��������Ϊindex��λ��
	void insert(int theIndex, const T& theElement);

	//���������out
	void output(std::ostream& out);

};