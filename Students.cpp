#include"Students.h"

//检查学生信息是否重复
bool Students::ifSameId(vector<Students> &i) {
	for (auto be = i.begin();be != i.end();++be) {
		if ((*be).Students_Num() == Id) {
			return 1;
			break;
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
//输出参数
void putStudentsInformation(vector<Students> &item) {
	for (auto i = item.begin();i != item.end();++i) {
		operator<<(cout, *i) << endl;
	}
}

//清空 C:\\Student_Information.txt中的内容
void openDoc() {
	ofstream del("C:\\Student_Information.txt", ios::out);
	del.clear();
	del.close();
}

//将vector中的信息保存到 C:\\Student_Information.txt
//传入一个Students类型的vector，将其中的信息保存到文件
void putDoc(vector<Students> &item) {
	//在循环之前打开文件更新文件内容
	ofstream out("C:\\Student_Information.txt", ios::app);
	for (auto i = item.begin();i != item.end();++i) {
		operator<<(out, *i) << endl;
	}
	//并在结束循环后关闭
	out.close();

}

//从C:\\Student_Information.txt中读取数据
//传入一个Students类型的vector，将文件中的信息存到其中，目前只实现了存到固定文件中
void readDoc(vector<Students> &item) {
	ifstream in("C:\\Student_Information.txt");
	if (in.is_open()) {
		while (!in.eof()) {
			Students i;
			operator>>(in, i);
			item.push_back(i);
		}
		in.close();
	}
	else {
		cout << "open error" << endl;
	}
}

//作为谓词
bool smallId(const Students &s1, const Students &s2) {
	return s1.Students_Num() < s2.Students_Num();
}

