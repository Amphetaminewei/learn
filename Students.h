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
	//构造函数
	Students() = default;
	Students(const string &s):Name(s),Id(s),Sex(s){ }

	//如果对象的Id和参数的重复返回1
	bool ifSameId(vector<Students> &i);

	//返回值为对象的Id
	string Students_Num() const {
		return Id;
	}

private:
	string Id;
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

//作为谓词
bool smallId(const Students &s1,const Students &s2);


#endif // !STUDENT_H