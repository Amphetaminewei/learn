#include<iostream>
#include<string>
#include<vector>
#include"Students.h"

using namespace std;


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
	cout << "��    7.����            8.�˳�      ��" << endl;
	cout << "��������������������������������������" << endl;
	cout << "��������������������������������������" << endl;
	cout << "" << endl;
	cout << "ʹ��ǰ����¼����Ϣ" << endl;
	cout << "" << endl;

	int select = 0;
	cout << "�밴��ʾѡ����:";
	cin >> select;
	cout << "" << endl;
	Students total;
	if (1 == select) {
		string features = "��ӭʹ����Ϣ¼�빦��";
		string Num = "��������¼�������";
		Students trans;
		int num = 0;
		hello(features);
		hello(Num);
		read(cin, num);
		for (int i = 0;i < num;i++) {
			read(cin, trans);
			//��trans�ӵ�total�ϡ�
			
		}
		print(cout, trans);
	}

	cin.get();
	cin.get();
	return 0;

}
