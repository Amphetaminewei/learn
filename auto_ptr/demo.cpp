#include"auto_ptr.h"
#include<iostream>

int main() {
	
	auto_ptr<int> autoPtr1(new int(10));
	auto_ptr<int> autoPtr2(new int(3));

	autoPtr1 = autoPtr2;
	std::cout << *autoPtr1 << std::endl;
	
	//你仍然能做这么可怕的事情
	int* i = autoPtr1.getPtr();
	std::cout << *i << std::endl;

	//同样可怕的事
	int* j = &(*autoPtr1);
	std::cout << *j;


	std::cin.get();
	std::cin.get();
	return 0;
}