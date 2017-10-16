#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include<conio.h>
#include<vector>
using namespace std;

class Students {
	friend void hello();
	friend istream &read(istream &is, Students &item);
	friend ostream &print(ostream &os, const Students &item);
	friend istream &read(istream &is, int &item);
public:
	//¹¹Ôìº¯Êý
	Students() = default;
	Students(const string &N,const int &I,const string &S):Name(N),Id(I),Sex(S){ }
	Students(istream &is) { read(is, *this); }
	Students(ostream &os) { print(os, *this); };

	int Students_Num() const {
		return Id;
	}


private:
	string Name;
	int Id;
	string Sex;
};

istream &read(istream &is, Students &item) {
	is >> item.Id >> item.Name >> item.Sex;
	return is;
}

ostream &print(ostream &os, const Students &item) {
	os << item.Id << " " << item.Name << " " << item.Sex;
	return os;
}
void hello(const string &a) {
	cout << a << endl;
}
istream &read(istream &is, int &item) {
	is >> item;
	return is;
}

#endif // !STUDENT_H
