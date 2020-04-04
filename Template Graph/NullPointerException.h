#pragma once
#include<stdexcept>
class NullPointerException :public std::exception
{
public:
	NullPointerException(const char* message) :exception(message)
	{}
	~NullPointerException() {}
};

