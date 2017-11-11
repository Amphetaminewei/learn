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

	int iSelect = 0;

	cout << "�밴��ʾѡ����:";

	cin >> iSelect;



	if (1 == iSelect) {

		readDoc(*total);

		//������ʾ
		string features = "��ӭʹ����Ϣ¼�빦��";
		string Num = "����(����)0ֹͣ"; 
		cout << features << endl;
		cout << Num << endl;
		Students trans;
		Students pre = trans;  //Ϊ����ifʵ�ֶ��������ظ�����Ϣ���д���

		//������Ϣ
		//em...��������� ������ stop��Ҫ�������β�������ѭ��
again:
		while (operator>>(cin, trans)) {
			if (trans.getStudentsNum() == 0) {
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
			}
			else { 
				(*total).push_back(trans);
			}
			
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

		return main();
	}

	else if (2 == iSelect) {
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
				return main();
			}
		}

		cout << "��������˳�" << endl;
		_getch();
		return main();
	}

	else if (5 == iSelect) {
		//���ж���û�н���Ϣ¼��total
		//����Ѿ�����totalҲ����total��Ϊ��
		if (!(*total).empty()) {
			cout << "����������ҵ�ѧ��:";
			int item;
			cin >> item;
			//��total��Ѱ�Һ�itemѧ����ͬ����Ϣ�����
			auto findId = find_if((*total).begin(), (*total).end(), [item](const Students &i) {return i.getStudentsNum() == item;});
			cout << *findId << endl;
		}
		//���û����Ϣ����total
		else {
			//���ļ��е���Ϣ�浽һ����ʱ��forFindInformation
			vector<Students> forFindInformation;
			readDoc(forFindInformation);
			//���forFindInformation����Ϣ��Ϊ��
			if (!forFindInformation.empty()) {
				cout << "����������ҵ�ѧ��:";
				int item;
				cin >> item;
				//��forFindInformation��Ѱ����itemѧ����ͬ����Ϣ�����
				auto findId = find_if(forFindInformation.begin(), forFindInformation.end(), [item](const Students &i) {return i.getStudentsNum() == item;});
				cout << *findId << endl;
			}
			//���forFindInformationΪ�մ���ԭ���ļ��о�û����Ϣ��������ʾ��������Ϣ������������
			else {
				MessageBox(NULL, TEXT("Please read information befor"), TEXT("No Information"), MB_ICONEXCLAMATION | MB_OK);
				return main();
			}
		}
	}

	else if (7 == iSelect) {
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
			vector<Students> forSortInformation;
			readDoc(forSortInformation);
			//�ж��ļ��Ƿ��ǿյģ�����ǣ���ʾ¼����Ϣ
			if (ifNotExitInformation(forSortInformation)) {
				//����ѧ�ŵ���������
				stable_sort(forSortInformation.begin(), forSortInformation.end(), [](const Students &a, const Students &b) {return a.getStudentsNum() < b.getStudentsNum();});
				putStudentsInformation(forSortInformation);
				openDoc();
				putDoc(forSortInformation);
			}
			else {
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

	else if(8 == iSelect) {
		int theEnd = MessageBox(NULL, TEXT("ллʹ��"),TEXT("wlecome back"), MB_OK);
	}

	delete total;
	cin.get();
	cin.get();
	return 0;

}
