#include"auto_ptr.h"
#include<iostream>

int main() {
	
	auto_ptr<int> autoPtr1(new int(10));
	auto_ptr<int> autoPtr2(new int(3));

	//这里autoPtr2已经被置为空，控制权已经转移到了autoPtr1
	autoPtr1 = autoPtr2;
	std::cout << *autoPtr1 << std::endl;
	
	//你仍然能做这么可怕的事情
	int* i = autoPtr1.getPtr();
	std::cout << *i << std::endl;

	//同样可怕的事
	int* j = &(*autoPtr1);
	std::cout << *j;

	//更可怕的情况
	int a = 10;
	int* b = &a;
	auto_ptr<int>p(b);


	std::cin.get();
	std::cin.get();
	return 0;
}