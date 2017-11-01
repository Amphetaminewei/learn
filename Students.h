#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include<conio.h>
#include<vector>
#include<stdexcept>
#include<fstream>

using namespace std;

class Students {
	friend ostream &operator << (ostream &os, Students &item);
	friend istream &operator >> (istream &os, Students &item);
	friend bool operator == (Students &lhs, Students &rhs);
public:
	//���캯��
	Students() = default;
	Students(const string &s):Name(s),Id(s),Sex(s){ }

	//�ж���Ϣ�Ƿ��ظ�����
	bool Same(vector<Students> &i);

	//Ϊ��ȡѧ��ѧ�����Ľӿ�
	string Students_Num() const {
		return Id;
	}

private:
	string Id;
	string Name;
	string Sex;
};



#endif // !STUDENT_H
