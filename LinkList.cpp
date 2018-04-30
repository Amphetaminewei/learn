#include"chain.h"
//前两天实现的链表，就直接拿来用了，
//还没写完，没给它做迭代器
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
		//输入
		Student item;
		item.set();
		stu.insert(i, item);
	}

	//输出
	stu.output(cout);

	//按名字得到信息
	string N = "王伟男";
	int index = stu.indexOf(N);
	Student wang = stu.get(index);

	//按索引得到信息
	Student s = stu.get(1);

	//添加
	stu.insert(1, (16103217, "王伟男", 90));

	//删除
	stu.erase(1);

	//返回表长
	int length = stu.size();
}