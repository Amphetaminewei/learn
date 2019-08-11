#include"auto_ptr.h"
#include<iostream>

int main() {
	
	auto_ptr<int> autoPtr1(new int(10));
	auto_ptr<int> autoPtr2(new int(3));

	//����autoPtr2�Ѿ�����Ϊ�գ�����Ȩ�Ѿ�ת�Ƶ���autoPtr1
	autoPtr1 = autoPtr2;
	std::cout << *autoPtr1 << std::endl;
	
	//����Ȼ������ô���µ�����
	int* i = autoPtr1.getPtr();
	std::cout << *i << std::endl;

	//ͬ�����µ���
	int* j = &(*autoPtr1);
	std::cout << *j;

	//�����µ����
	int a = 10;
	int* b = &a;
	auto_ptr<int>p(b);


	std::cin.get();
	std::cin.get();
	return 0;
}