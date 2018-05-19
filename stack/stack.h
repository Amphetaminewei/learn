#pragma once

template<class T>
class stack {
	virtual ~stack() { };

	//ջΪ��ʱ����true
	virtual bool empty() const = 0;

	//����ջ��Ԫ�ظ���
	virtual int size() const = 0;

	//����ջ��Ԫ�ص�����
	virtual T& top() = 0;

	//ɾ��ջ��Ԫ��
	virtual void pop() = 0;

	//��Ԫ��theElementѹ��ջ
	virtual void push(const T& theElement) = 0;
};