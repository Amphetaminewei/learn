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
#include<Windows.h>

using namespace std;

class Students {
	friend ostream &operator << (ostream &os, Students &item);
	friend istream &operator >> (istream &os, Students &item);
	friend bool operator == (Students &lhs, Students &rhs);
public:
	//构造函数
	Students() = default;
	Students(const string &s,const int &i):Name(s),Id(i),Sex(s){ }

	//如果对象的Id和参数的重复返回1
	bool ifSameId(vector<Students> &i);

	//返回值为对象的Id
	int getStudentsNum() const {
		return Id;
	}
	string getStudentsName() const {
		return Name;
	}

private:
	int Id;
	string Name;
	string Sex;
};

//非成员函数声明
//输出参数中储存的学生信息
void putStudentsInformation(vector<Students> &i);

//传入一个Students类型的vector，将文件中的信息存到其中，目前只实现了存到固定文件中
void readDoc(vector<Students> &item1);

//传入一个Students类型的vector，将其中的信息保存到文件
void putDoc(vector<Students> &item);

//清空 C:\\Student_Information.txt中的内容
void openDoc();

//接受一个Students的vector判断参数是否为空
bool ifNotExitInformation(const vector<Students> &i);

#endif // !STUDENT_H