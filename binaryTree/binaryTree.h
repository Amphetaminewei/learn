#pragma once

//binaryTree������

template<class T>
class binaryTree {

public:
	virtual ~binaryTree(){ }
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	//һ��void���͵ĺ���ָ��������,�����������Ϊһ��T���͵�ָ��
	virtual void preOrder(void(*) (T*)) = 0;
	virtual void inOrder(void(*)(T*)) = 0;
	virtual void postOrder(void(*)(T*)) = 0;
	//virtual void levelOrder(void(*)(T*)) = 0;
};