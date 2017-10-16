#include<iostream>
#include<string>
#include<vector>
#include"Students.h"

using namespace std;


int main() {

	cout << "■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　 欢迎使用学生信息管理系统 　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■★      ★      ★      ★      ★■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■          请按提示操作            ■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■★      ★      ★      ★      ★■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■    1.录入            2.显示      ■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■    3.修改            4.删除      ■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■    5.查询            6.追加      ■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■    7.排序            8.退出      ■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "" << endl;
	cout << "使用前请先录入信息" << endl;
	cout << "" << endl;

	int select = 0;
	cout << "请按提示选择功能:";
	cin >> select;
	cout << "" << endl;
	Students total;
	if (1 == select) {
		string features = "欢迎使用信息录入功能";
		string Num = "请输入想录入的人数";
		Students trans;
		int num = 0;
		hello(features);
		hello(Num);
		read(cin, num);
		for (int i = 0;i < num;i++) {
			read(cin, trans);
			//将trans加到total上↓
			
		}
		print(cout, trans);
	}

	cin.get();
	cin.get();
	return 0;

}
