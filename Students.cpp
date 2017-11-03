#include"Students.h"

//检查学生信息是否重复
bool Students::Same(vector<Students> &i) {
	for (auto be = i.begin();be != i.end();++be) {
		if ((*be).Students_Num() == Id) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

//重载 >> 输入对象信息
istream &operator >> (istream &is, Students &item) {
	is >> item.Id >> item.Name >> item.Sex;
	return is;
}

//重载 << 输出对象信息
ostream &operator << (ostream &os, Students &item) {
	os << item.Id << " " << item.Name << " " << item.Sex;
	return os;
}

//重载 == 但是有了Same函数似乎就没用了
bool operator == (Students &lhs, Students &rhs) {
	return lhs.Id == rhs.Id || lhs.Name == rhs.Name;
}

//非成员函数定义

//输出信息函数
void Put(vector<Students> &item) {
	for (auto i = item.begin();i != item.end();++i) {
		operator<<(cout, *i) << endl;
	}
}
