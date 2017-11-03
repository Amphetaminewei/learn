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

	//判断信息是否重复函数
	bool Same(vector<Students> &i);

	//为获取学生学号留的接口
	string Students_Num() const {
		return Id;
	}

private:
	string Id;
	string Name;
	string Sex;
};

//非成员函数声明
//输出现有学生信息
void Put(vector<Students> &i);

//读取文件中的信息
void Read_Doc(vector<Students> &item1);

//更新文件的内容
void Put_Doc(vector<Students> &i);

#endif // !STUDENT_H
