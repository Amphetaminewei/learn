#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Students {

	//构造函数
	Students() = default;
	Students(const string &I, const string &N) :
		ID(I), Name(N) { }

	Students combine(const Students &rhs) {
		Name += rhs.Name;
		ID += rhs.ID;
		return *this;
	}

	string student_ID() const {
		return ID;
	}

	//将两个数据相加
	Students add(const Students &lhs, const Students &rhs) {
		Students sum = lhs;
		sum.combine(rhs);
		return sum;
	}

	string Results;
	string ID;
	string Name;
};

istream &read(istream &is, Students &item) {

}

ostream &print(ostream &os, Students &item) {

}


#endif // !STUDENT_H
