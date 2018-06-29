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


class Students {
	friend std::ostream &operator << (std::ostream &os, Students &item);
	friend std::istream &operator >> (std::istream &os, Students &item);
	friend bool operator == (Students &lhs, Students &rhs);
public:
	//构造函数
	Students() = default;
	Students(const std::string &s,const int &i):Name(s),Id(i),Sex(s){ }

	//如果对象的Id和参数的重复返回1
	bool ifSameId(std::vector<Students> &i);

	//返回值为对象的Id
	int getStudentsNum() const {
		return Id;
	}
	std::string getStudentsName() const {
		return Name;
	}

private:
	int Id;
	std::string Name;
	std::string Sex;
};

//非成员函数声明

//输出参数中储存的学生信息
void putStudentsInformation(std::vector<Students> &i);

//传入一个Students类型的vector，将文件中的信息存到其中，目前只实现了存到固定文件中
void readDoc(std::vector<Students> &item1);

//传入一个Students类型的vector，将其中的信息保存到文件
void putDoc(std::vector<Students> &item);

//清空 C:\\Student_Information.txt中的内容
void openDoc();


//删除信息中多余的空项
void delEmpty(std::vector<Students> &item);

#endif // !STUDENT_H