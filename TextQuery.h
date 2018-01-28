#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<set>
#include<map>

class TextQuery {
public:
	TextQuery();
	void query_Rerult();
	void print_Result();
private:
	std::map<std::string,std::set<int>> all_words;
	std::vector<std::string> all_text;
};