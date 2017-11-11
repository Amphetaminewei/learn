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
	//���캯��
	Students() = default;
	Students(const string &s,const int &i):Name(s),Id(i),Sex(s){ }

	//��������Id�Ͳ������ظ�����1
	bool ifSameId(vector<Students> &i);

	//����ֵΪ�����Id
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

//�ǳ�Ա��������
//��������д����ѧ����Ϣ
void putStudentsInformation(vector<Students> &i);

//����һ��Students���͵�vector�����ļ��е���Ϣ�浽���У�Ŀǰֻʵ���˴浽�̶��ļ���
void readDoc(vector<Students> &item1);

//����һ��Students���͵�vector�������е���Ϣ���浽�ļ�
void putDoc(vector<Students> &item);

//��� C:\\Student_Information.txt�е�����
void openDoc();

//����һ��Students��vector�жϲ����Ƿ�Ϊ��
bool ifNotExitInformation(const vector<Students> &i);

#endif // !STUDENT_H