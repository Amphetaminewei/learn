#include"Students.h"

using namespace std;
using std::cin;
using std::cout;

//vector<Students> total;
vector<Students> *total = new vector<Students>;

int main() {
	cout << "��������������������������������������" << endl;
	cout << "��������������������������������������" << endl;
	cout << "������ ��ӭʹ��ѧ����Ϣ����ϵͳ ������" << endl;
	cout << "��������������������������������������" << endl;
	cout << "����      ��      ��      ��      ���" << endl;
	cout << "��������������������������������������" << endl;
	cout << "��          �밴��ʾ����            ��" << endl;
	cout << "��������������������������������������" << endl;
	cout << "����      ��      ��      ��      ���" << endl;
	cout << "��������������������������������������" << endl;
	cout << "��    1.¼��            2.��ʾ      ��" << endl;
	cout << "��������������������������������������" << endl;
	cout << "��    3.�޸�            4.ɾ��      ��" << endl;
	cout << "��������������������������������������" << endl;
	cout << "��    5.��ѯ            6.׷��      ��" << endl;
	cout << "��������������������������������������" << endl;
	cout << "��    7.����      8.�˳�������      ��" << endl;
	cout << "��������������������������������������" << endl;
	cout << "��������������������������������������" << endl;
	cout << "" << endl;
	cout << "ʹ��ǰ����¼����Ϣ" << endl;
	cout << "" << endl;

	int select = 0;
	cout << "�밴��ʾѡ����:";
	cin >> select;
	cout << "" << endl;


	if (1 == select) {

		//�ȴ��ļ��ж�ȡ��Ϣ
		ifstream in("C:\\Student_Information.txt");
		if (in.is_open()) {
			while (!in.eof()) {
				Students item;
				operator>>(in, item);
				(*total).push_back(item);
			}
			in.close();
		}
		else {
			cout << "open error" << endl;
		}

		//������ʾ
		string features = "��ӭʹ����Ϣ¼�빦��";
		string Num = "����(����)stopֹͣ"; 
		cout << features << endl;
		cout << Num << endl;
		Students trans;
		Students pre = trans;  //Ϊ����ifʵ�ֶ�������ͬһ���˵���Ϣ���д���

		//������Ϣ
		//em...��������� ������ stop��Ҫ�������β�������ѭ��
again:
		while (operator>>(cin, trans)) {
			//���ʱ��Щ���⡣����������ѭ����

			if (trans.Students_Num() == "stop") {
				break;
			}
			else if (trans.Same(*total)) {
				cout << "this ID has resisted" << endl;
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
				}
			}
			(*total).push_back(trans);
			
		}
		auto i = (*total).begin();
		while (i != (*total).end()) {
			if ((*i).Students_Num().empty()) {
				i = (*total).erase(i);
			}
			else {
				++i;
			}
		}

		for (auto i = (*total).begin();i != (*total).end();++i) {
			operator<<(cout, *i) << endl;
		}
		


			//һ��ʧ�ܵ��쳣����׼���ȵ�ȫ����ɿ�ʼ�Ż���ʱ���������ǣ�Ŀǰ������if�պ���
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

		
		cout << "�����������" << endl;
		_getch();
		return main();
	}

	else if(8 == select) {

		ofstream del("C:\\Student_Information.txt", ios::out);
		del.clear();
		del.close();

		//��ѭ��֮ǰ���ļ������ļ�����
		ofstream out("C:\\Student_Information.txt", ios::app);
		for (auto i = (*total).begin();i != (*total).end();++i) {
			operator<<(out, *i) << endl;
		}
		//���ڽ���ѭ����ر�
		out.close();
		
	}

	delete total;
	cin.get();
	cin.get();
	return 0;

}
