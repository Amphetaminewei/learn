#include"TextQuery.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>

using namespace std;

TextQuery::TextQuery() {
	ifstream in("D:\\Text.txt");
	if (in.is_open()) {
		string text;
		while (getline(in, text)) {
			all_text.push_back(text);
		}
		string one_word;                   
		int line_num = 1;
		for (auto i = all_text.begin();i != all_text.end();++i) {
			stringstream Split_the_word;
			Split_the_word << (*i);
			/*
				�����һ������
				�����ʶ�ȡ����ȡÿ�����ʵ�ʱ�����ǲ����Ѿ���map��
				�������map�е���ӵ�map�ﲢ��map.second���óɵ�ǰ��line_numֵ
				����Ѿ���map��Ľ�line_num��ӵ�map.second
				�����map.second����ָ��map��valueҲ�����Ǹ�set<int>;
			*/
			while (Split_the_word >> one_word) {
				set<int> line;
				auto word = all_words.find(one_word);
				if (word == all_words.end()) {
					line.insert(line_num);
					all_words[one_word] = line;
				}
				else {
					(*word).second.insert(line_num);
				}
				//se.insert(line_num);
				//all_words[one_word] = se;
				//se.erase(line_num);
			}
			++line_num;
		}
		//�����������
		for (auto i = all_words.begin(); i != all_words.end();++i) {
			cout << (*i).first;
			for (auto s = (*i).second.begin();s != (*i).second.end();++s) {
				cout << (*s);
			}
			cout << endl;
		}
		//for (auto i = all_text.begin();i != all_text.end();++i) {
		//	cout << *i << endl;
		//}
	}
	else {
		cout << "open error" << endl;
	}
	
}

