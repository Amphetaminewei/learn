#include"chain.h"
//ǰ����ʵ�ֵ�������ֱ���������ˣ�
//��ûд�꣬û������������
#include<iostream>
#include<string>


using namespace std;

class Student {
private:
	int Id;
	string name;
	int score;
public:
	Student() {
		Id = 0;
		name = " ";
		score = 0;
	}
	Student(int i, string n, int s){
		Id = i;
		name = n;
		score = s;
	}
	Student(int i) {
		Id = i;
		name = " ";
		score = 0;
	}
	Student(string n) {
		Id = 0;
		name = n;
		score = 0;
	}
	void set() {
		cout << "pls print Id name and score :";
		cin >> Id >> name >> score;
	}
};

int main() {
	chain<Student>stu(3);
	for (int i = 0;i < 3;i++) {
		//����
		Student item;
		item.set();
		stu.insert(i, item);
	}

	//���
	stu.output(cout);

	//�����ֵõ���Ϣ
	string N = "��ΰ��";
	int index = stu.indexOf(N);
	Student wang = stu.get(index);

	//�������õ���Ϣ
	Student s = stu.get(1);

	//���
	stu.insert(1, (16103217, "��ΰ��", 90));

	//ɾ��
	stu.erase(1);

	//���ر�
	int length = stu.size();
}