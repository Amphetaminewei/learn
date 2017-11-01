#include"Students.h"


bool Students::Same(vector<Students> &i) {
	for (auto be = i.begin();be != i.end();++be) {
		if ((*be).Students_Num() == Id) {
			return 1;
		}
	}
}

istream &operator >> (istream &is, Students &item) {
	is >> item.Id >> item.Name >> item.Sex;
	return is;
}
ostream &operator << (ostream &os, Students &item) {
	os << item.Id << " " << item.Name << " " << item.Sex;
	return os;
}
bool operator == (Students &lhs, Students &rhs) {
	return lhs.Id == rhs.Id || lhs.Name == rhs.Name;
}
