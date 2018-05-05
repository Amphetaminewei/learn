#pragma once
#include<iostream>

//���Ա�ĳ�����
template <class T>
class linearList
{
public:
	virtual ~linearList() { };

	//�����Ƿ�Ϊ��
	virtual bool empty() const = 0;

	//����Ԫ�ظ���
	virtual int size() const = 0;

	//��������Ϊindex��Ԫ��
	virtual T& get(int theIndex) const = 0;

	//����Ԫ��theElement��һ�γ��ֵ�����
	virtual int indexOf(const T& theElement) const = 0;

	//ɾ������Ϊindex��Ԫ��
	virtual void erase(int theIndex) = 0;

	//��theElement��������Ϊindex��λ��
	virtual void insert(int theIndex, const T& theElement) = 0;

	//���������out
	virtual void output(std::ostream& out) = 0;
};