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

		readDoc(*total);

		//������ʾ
		string features = "��ӭʹ����Ϣ¼�빦��";
		string Num = "����(����)stopֹͣ"; 
		cout << features << endl;
		cout << Num << endl;
		Students trans;
		Students pre = trans;  //Ϊ����ifʵ�ֶ��������ظ�����Ϣ���д���

		//������Ϣ
		//em...��������� ������ stop��Ҫ�������β�������ѭ��
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

		return main();
	}

	else if (2 == select) {
		if (!(*total).empty()) {
			//�����Ϣ�Ѿ�������total��ֱ�����
			putStudentsInformation(*total);
		}
		else {
			//������Ϣ�浽��һ��vector��Ȼ�����
			//��ֹ����total���ظ�¼����Ϣ
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
				cout << "����������Ϣ" << endl;
				_getch();
				*/
				return main();
			}
		}

		cout << "��������˳�" << endl;
		_getch();
		return main();
	}

	else if (7 == select) {
		if (!(*total).empty()) {
			//���֮ǰ�Ѿ����ļ��е���Ϣ���뵽��total
			//ֱ�Ӷ�total�������򲢸����ļ�����
			stable_sort((*total).begin(), (*total).end(), [](const Students &a, const Students &b) {return a.getStudentsNum() < b.getStudentsNum();});
			putStudentsInformation(*total);
			openDoc();
			putDoc(*total);
		}
		else {
			//����ļ��е���Ϣ��û���뵽total
			//���ļ��浽��һ��Studennts���͵�vector��
			//���򲢸����ļ���Ϣ
			vector<Students> *forSortInformation = new vector<Students>;
			readDoc(*forSortInformation);
			//�ж��ļ��Ƿ��ǿյģ�����ǣ���ʾ¼����Ϣ
			if (ifNotExitInformation(*forSortInformation)) {
				//����ѧ�ŵ���������
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
				cout << "����¼����Ϣ" << endl;
				*/
				return main();
			}
		}

		cout << "��������˳�" << endl;
		_getch();
		return main();
	}

	else if(8 == select) {
		int theEnd = MessageBox(NULL, TEXT("ллʹ��"),TEXT("wlecome back"), MB_OK);
	}

	delete total;
	cin.get();
	cin.get();
	return 0;

}
