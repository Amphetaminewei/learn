#include"Students.h"

using namespace std;

//���ѧ����Ϣ�Ƿ��ظ�
bool Students::ifSameId(vector<Students> &i) {
	for (auto be = i.begin();be != i.end();++be) {
		if ((*be).getStudentsNum() == Id) {
			return 1;
			break;
		}
	}
}

//���� >> ���������Ϣ
istream &operator >> (std::istream &is, Students &item) {
	is >> item.Id >> item.Name >> item.Sex;
	return is;
}

//���� << ���������Ϣ
ostream &operator << (std::ostream &os, Students &item) {
	os << item.Id << " " << item.Name << " " << item.Sex;
	return os;
}

//���� == ��������Same�����ƺ���û����
bool operator == (Students &lhs, Students &rhs) {
	return lhs.Id == rhs.Id || lhs.Name == rhs.Name;
}

//�ǳ�Ա��������

//�����Ϣ����
//�������
void putStudentsInformation(vector<Students> &item) {
	for (auto i = item.begin();i != item.end();++i) {
		operator<<(cout, *i) << endl;
	}
}

//��� C:\\Student_Information.txt�е�����
void openDoc() {
	ofstream del("C:\\Student_Information.txt", ios::out);
	del.clear();
	del.close();
}

//��vector�е���Ϣ���浽 C:\\Student_Information.txt
//����һ��Students���͵�vector�������е���Ϣ���浽�ļ�
void putDoc(vector<Students> &item) {
	//��ѭ��֮ǰ���ļ������ļ�����
	ofstream out("C:\\Student_Information.txt", ios::app);
	for (auto i = item.begin();i != item.end();++i) {
		operator<<(out, *i) << endl;
	}
	//���ڽ���ѭ����ر�
	out.close();

}

//��C:\\Student_Information.txt�ж�ȡ����
//����һ��Students���͵�vector�����ļ��е���Ϣ�浽���У�Ŀǰֻʵ���˴浽�̶��ļ���
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

void delEmpty(vector<Students> &item) {
	auto i = item.begin();
	while (i != item.end()) {
		if ((*i).getStudentsName().empty()) {
			i = item.erase(i);
		}
		else {
			++i;
		}
	}
}