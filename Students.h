#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include<conio.h>
#include<vector>
#include<stdexcept>
using namespace std;

class Students {
	friend ostream &operator << (ostream &os, Students &item);
	friend istream &operator >> (istream &os, Students &item);
	friend bool operator == (Students &lhs, Students &rhs);
public:
	//构造函数
	Students() = default;
	Students(const string &s):Name(s),Id(s),Sex(s){ }

	//未实现 等学了内存管理再来实现
	//Students operator = (Students lhs,Students rhs);
	string Students_Num() const {
		return Id;
	}

private:
	string Id;
	string Name;
	string Sex;
};

istream &operator >> (istream &is, Students &item) {
	is >> item.Id >> item.Name >> item.Sex;
	return is;
}
ostream &operator << (ostream &os, Students &item) {
	os << item.Id << " " << item.Name << " " << item.Sex;
	return os;
}
bool operator == (Students &lhs, Students &rhs) {
	return lhs.Id == rhs.Id || lhs.Name == rhs.Name;
}

#endif // !STUDENT_H
