#pragma once

#include"chainNode.h"
#include"linearList.h"
#include"illegalParameterValue.h"
#include<iostream>

//�������Ա��������
template<class T>
class chain : public linearList<T> {
public:
	//���캯��
	chain(int initialCapacity);
	//���ƹ���
	chain(const chain<T>&);
	~chain();

	//�ж������Ƿ�Ϊ��
	bool empty();

	//����Ԫ�صĸ���
	int size();

	//��������ΪtheIndex��Ԫ��
	T& get(int theIndex);

	//����Ԫ��theElement��һ�γ��ֵ�����
	int indexOf(const T& theElement);

	//ɾ������Ϊindex��Ԫ��
	void erase(int theIndex);

	//��theElement��������Ϊindex��λ��
	void insert(int theIndex, const T& theElement);

	//���������out
	void output(std::ostream& out);

protected:
	chainNode<T>* firstNode;
	int listSize;
	
	//�ж������Ƿ���Ч
	void checkIndex(int theIndex) const;

};
	