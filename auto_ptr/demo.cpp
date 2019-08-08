#include"auto_ptr.h"
#include<iostream>

int main() {
	
	auto_ptr<int> autoPtr1(new int(10));
	auto_ptr<int> autoPtr2(new int(3));

	autoPtr1 = autoPtr2;
	std::cout << *autoPtr1 << std::endl;
	
	//����Ȼ������ô���µ�����
	int* i = autoPtr1.getPtr();
	std::cout << *i << std::endl;

	//ͬ�����µ���
	int* j = &(*autoPtr1);
	std::cout << *j;


	std::cin.get();
	std::cin.get();
	return 0;
}