#pragma once

#include<string>
#include<iostream>

//异常类，用来抛出异常
class illegalParameterVaule {
private:
	std::string message;

public:
	illegalParameterVaule() :message("Illega parameter value") { }
	illegalParameterVaule(char* theMessage) {
		message = theMessage;
	}
	void outputMessage() {
		std::cout << message << std::endl;
	}
};