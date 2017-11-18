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
	//���캯��
	Students() = default;
	Students(const std::string &s,const int &i):Name(s),Id(i),Sex(s){ }

	//��������Id�Ͳ������ظ�����1
	bool ifSameId(std::vector<Students> &i);

	//����ֵΪ�����Id
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

//�ǳ�Ա��������

//��������д����ѧ����Ϣ
void putStudentsInformation(std::vector<Students> &i);

//����һ��Students���͵�vector�����ļ��е���Ϣ�浽���У�Ŀǰֻʵ���˴浽�̶��ļ���
void readDoc(std::vector<Students> &item1);

//����һ��Students���͵�vector�������е���Ϣ���浽�ļ�
void putDoc(std::vector<Students> &item);

//��� C:\\Student_Information.txt�е�����
void openDoc();


//ɾ����Ϣ�ж���Ŀ���
void delEmpty(std::vector<Students> &item);

#endif // !STUDENT_H