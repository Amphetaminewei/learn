#include"Students.h"

//���ѧ����Ϣ�Ƿ��ظ�
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

//���� >> ���������Ϣ
istream &operator >> (istream &is, Students &item) {
	is >> item.Id >> item.Name >> item.Sex;
	return is;
}

//���� << ���������Ϣ
ostream &operator << (ostream &os, Students &item) {
	os << item.Id << " " << item.Name << " " << item.Sex;
	return os;
}

//���� == ��������Same�����ƺ���û����
bool operator == (Students &lhs, Students &rhs) {
	return lhs.Id == rhs.Id || lhs.Name == rhs.Name;
}

//�ǳ�Ա��������

//�����Ϣ����
void Put(vector<Students> &item) {
	for (auto i = item.begin();i != item.end();++i) {
		operator<<(cout, *i) << endl;
	}
}
