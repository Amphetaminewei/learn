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
	vector<Students> total;
	if (1 == select) {
		string features = "��ӭʹ����Ϣ¼�빦��";
		string Num = "��������¼�������";
		int num = 0;
		cout << features << endl;
		cout << Num << endl;
		cin >> num;
		Students trans;
		for (int i = 0;i < num;++i) {
			operator>>(cin, trans);
			total.push_back(trans);
		}
		for (int i = 0;i < num;i++) {
			operator<<(cout, total[i]) << endl;
		}
		_getch();
		return main();
	}

	cin.get();
	cin.get();
	return 0;

}
