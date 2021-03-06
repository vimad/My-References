// Custom Exeptions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <exception>

using namespace std;

class MyException : public exception {
public:
	virtual const char* what() const throw(){
		return "something bad happened";
	}
};

class Test {
public:
	void goWrong() {
		throw MyException();
	}
};

int main()
{
	Test test;

	try
	{
		test.goWrong();
	}
	catch (MyException &e)
	{
		cout << e.what() << endl;
	}

    return 0;
}

