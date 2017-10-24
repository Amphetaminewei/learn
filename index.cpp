#include"Students.h"

using namespace std;
using std::cin;
using std::cout;

//vector<Students> total;
vector<Students> *total = new vector<Students>;

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
	cout << "■    7.排序      8.退出并保存      ■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "" << endl;
	cout << "使用前请先录入信息" << endl;
	cout << "" << endl;

	/*
	ifstream in("C:\\shit,txt");
	ofstream out("C:\\shit.txt");
	if (out) {
		out << "the fuck fstream" << endl;
	}
	*/

	int select = 0;
	cout << "请按提示选择功能:";
	cin >> select;
	cout << "" << endl;

	if (1 == select) {
		string features = "欢迎使用信息录入功能";
		string Num = "输入(三次)stop停止"; 
		cout << features << endl;
		cout << Num << endl;
		Students trans;
		Students pre = trans;  //为了用if实现对于输入同一个人的信息进行处理
		
		//em...是我想多了 但是呢 stop需要出入三次才能跳出循环
		while (operator>>(cin, trans)) {
			if (operator==(trans,pre)) {
				cout << "this ID has resisted" << endl;
				cout << "Try again? \n Entry y or n " << endl;
				string c;
				cin >> c;
				if (!cin || "n" == c) {
					break;
				}
				else {
					cout << "Let's try again!" << endl;
				}
			}
			else if (trans.Students_Num() == "stop") {
				break;
			}
			else {
				//可以将数据输出到Student_Iformation.txt  但是汉字会出乱码。。。
				(*total).push_back(trans);
				pre = trans;
				
			}
		}
		for (auto i = (*total).begin();i != (*total).end();++i) {
			operator<<(cout, *i) << endl;
		}
		


			//一个失败的异常处理，准备等到全部完成开始优化的时候再来考虑，目前就先用if凑合了
			/*
			while (operator>>(cin, trans)) {
				try {
					total.push_back(trans);
					if (trans.Students_Num() == total[i].Students_Num()) {
						throw runtime_error("You read same Id");
					}
				}
					catch(runtime_error err) {
						cout << err.what() << "This student's Id have exist" << "\nTry Again? Enter y or n" << endl;
						string c;
						cin >> c;
						if (!cin || c == "n") {
							break;
						}
					}
				 
			}
			*/

		
		cout << "按任意键返回" << endl;
		_getch();
		return main();
	}

	else if(8 == select) {
		
		for (auto i = (*total).begin();i != (*total).end();++i) {
			ofstream out("C:\\Student_Information.txt", ios::app);
			operator<<(out, *i) << endl;
			out.close();
		}
		

	}

	delete total;
	cin.get();
	cin.get();
	return 0;

}
