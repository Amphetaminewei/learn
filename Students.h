#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include<conio.h>
#include<vector>
using namespace std;

class Students {
	friend ostream &operator << (ostream &os, Students &item);
	friend istream &operator >> (istream &os, Students &item);
public:
	//¹¹Ôìº¯Êý
	Students() = default;
	Students(const string &N,const string &I,const string &S):Name(N),Id(I),Sex(S){ }

	string Students_Num() const {
		return Id;
	}

private:
	string Name;
	string Id;
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

#endif // !STUDENT_H
