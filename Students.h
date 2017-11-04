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

	//��������Id�Ͳ������ظ�����1
	bool ifSameId(vector<Students> &i);

	//����ֵΪ�����Id
	string Students_Num() const {
		return Id;
	}

private:
	string Id;
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

//��Ϊν��
bool smallId(const Students &s1,const Students &s2);


#endif // !STUDENT_H