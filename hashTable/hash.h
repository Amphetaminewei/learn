#pragma once

#include<string>

//这里只照着书写了把string转换成哈希值的方法。

class hash {
public:
	size_t operator()(const std::string theKey) const {
		//把theKey转换成非负整数;
		unsigned long hashValue = 0;
		int length = (int)theKey.length();
		for (int i = 0;i < length;i++) {
			hashValue = 5 * hashValue + theKey.at(i);
		}
		return size_t(hashValue);
	}
};