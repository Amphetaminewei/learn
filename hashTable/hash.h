#pragma once

#include<string>

//����ֻ������д�˰�stringת���ɹ�ϣֵ�ķ�����

class hash {
public:
	size_t operator()(const std::string theKey) const {
		//��theKeyת���ɷǸ�����;
		unsigned long hashValue = 0;
		int length = (int)theKey.length();
		for (int i = 0;i < length;i++) {
			hashValue = 5 * hashValue + theKey.at(i);
		}
		return size_t(hashValue);
	}
};