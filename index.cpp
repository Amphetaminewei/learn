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

	int select = 0;
	cout << "请按提示选择功能:";
	cin >> select;
	cout << "" << endl;


	if (1 == select) {

		readDoc(*total);

		//操作提示
		string features = "欢迎使用信息录入功能";
		string Num = "输入(三次)stop停止"; 
		cout << features << endl;
		cout << Num << endl;
		Students trans;
		Students pre = trans;  //为了用if实现对于输入重复的信息进行处理

		//输入信息
		//em...是我想多了 但是呢 stop需要出入三次才能跳出循环
again:
		while (operator>>(cin, trans)) {
			if (trans.getStudentsName() == "stop") {
				break;
			}
			else if (trans.ifSameId(*total)) {
				int hasBeenId = MessageBox(NULL, TEXT("Try again?"), TEXT("this ID has resisted"), MB_YESNO);
				if (IDYES == hasBeenId) {
					goto again;
				}
				else {
					MessageBox(NULL, TEXT("END OF PRINT"), TEXT("END"), MB_OK);
					break;
				}
				/*cout << "this ID has resisted" << endl;
				cout << "Try again? \n Entry y or n " << endl;
				string c;
				cin >> c;
				if (!cin || "n" == c) {
					cout << "end input" << endl;
					break;
				}
				else if("y" == c) {
					cout << "Let's try again!" << endl;
					goto again;
				}*/
			}
			(*total).push_back(trans);
			
		}
		auto i = (*total).begin();
		while (i != (*total).end()) {
			if ((*i).getStudentsName().empty()) {
				i = (*total).erase(i);
			}
			else {
				++i;
			}
		}

		putStudentsInformation(*total);
		
		openDoc();
		putDoc(*total);

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

		return main();
	}

	else if (2 == select) {
		if (!(*total).empty()) {
			//如果信息已经被输入total则直接输出
			putStudentsInformation(*total);
		}
		else {
			//否则将信息存到另一个vector中然后输出
			//防止了像total中重复录入信息
			vector<Students> *forPutInformation = new vector<Students>;
			readDoc(*forPutInformation);
			if (ifNotExitInformation(*forPutInformation)) {
				putStudentsInformation(*forPutInformation);
				delete forPutInformation;
			}
			else {
				delete forPutInformation;
				MessageBox(NULL, TEXT("Please read information befor"), TEXT("No Information"), MB_ICONEXCLAMATION | MB_OK);
				/*
				cout << "请先输入信息" << endl;
				_getch();
				*/
				return main();
			}
		}

		cout << "按任意键退出" << endl;
		_getch();
		return main();
	}

	else if (7 == select) {
		if (!(*total).empty()) {
			//如果之前已经将文件中的信息输入到了total
			//直接对total进行排序并更新文件内容
			stable_sort((*total).begin(), (*total).end(), [](const Students &a, const Students &b) {return a.getStudentsNum() < b.getStudentsNum();});
			putStudentsInformation(*total);
			openDoc();
			putDoc(*total);
		}
		else {
			//如果文件中的信息还没输入到total
			//将文件存到另一个Studennts类型的vector中
			//排序并更新文件信息
			vector<Students> *forSortInformation = new vector<Students>;
			readDoc(*forSortInformation);
			//判断文件是否是空的，如果是，提示录入信息
			if (ifNotExitInformation(*forSortInformation)) {
				//按照学号的升序排序
				stable_sort((*forSortInformation).begin(), (*forSortInformation).end(), [](const Students &a, const Students &b) {return a.getStudentsNum() < b.getStudentsNum();});
				putStudentsInformation(*forSortInformation);
				openDoc();
				putDoc(*forSortInformation);
				delete forSortInformation;
			}
			else {
				delete forSortInformation;
				int i = MessageBox(NULL, TEXT("Please read information befor"), TEXT("No Information"), MB_ICONEXCLAMATION | MB_OK);
				/*
				cout << "请先录入信息" << endl;
				*/
				return main();
			}
		}

		cout << "按任意键退出" << endl;
		_getch();
		return main();
	}

	else if(8 == select) {
		int theEnd = MessageBox(NULL, TEXT("谢谢使用"),TEXT("wlecome back"), MB_OK);
	}

	delete total;
	cin.get();
	cin.get();
	return 0;

}
