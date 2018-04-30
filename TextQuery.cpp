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
				解决了一切问题
				按单词读取，读取每个单词的时候检查是不是已经在map中
				如果不在map中的添加到map里并将map.second设置成当前的line_num值
				如果已经在map里的将line_num添加到map.second
				这里的map.second都是指的map的value也就是那个set<int>;
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
		//输出用来测试
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

