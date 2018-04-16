#pragma once
#include<iostream>

template <class T>
class lineraList
{
public:
	~lineraList();
	virtual ~lineraList();

	//����Ԫ�ظ���
	virtual int size();

	//��������Ϊindex��Ԫ��
	virtual T& get(int theIndex);

	//����Ԫ��theElement��һ�γ��ֵ�����
	virtual int indexOf(const T& theElement);

	//ɾ������Ϊindex��Ԫ��
	virtual void erase(int theIndex);

	//��theElement��������Ϊindex��λ��
	virtual void insert(int theIndex, const T& theElement);

	//���������out
	virtual void output(std::ostream& out);
};