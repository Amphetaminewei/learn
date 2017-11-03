#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include<conio.h>
#include<vector>
#include<stdexcept>
#include<fstream>
#include<algorithm>
#include<numeric>

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

//�ǳ�Ա��������
//�������ѧ����Ϣ
void Put(vector<Students> &i);

//��ȡ�ļ��е���Ϣ
void Read_Doc(vector<Students> &item1);

//�����ļ�������
void Put_Doc(vector<Students> &i);

#endif // !STUDENT_H
