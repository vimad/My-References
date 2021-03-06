// Overloading assignment operator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Test {
private:
	int id;
	string name;

public:
	Test():id(0),name(""){}

	Test(int id, string name):id(id),name(name){}

	void print() {
		cout << id << ":" << name << endl;
	}

	const Test &operator=(const Test &other) {
		cout << "assignment running" << endl;
		id = other.id;
		name = other.name;

		return *this;
	}

	Test(const Test &other) {
		cout << "copy constructor running" << endl;
		*this = other;
	}
};

int main()
{
	Test test1(1, "vinod");
	cout << "test 1 " << flush;
	test1.print();

	Test test2(2, "ishara");
	test2 = test1;
	cout << "test 2 " << flush;
	test2.print();

	Test test3;
	test3.operator=(test2);
	cout << "test 3 " << flush;
	test3.print();

	Test test4 = test1; //copy initialization
	cout << "test 4 " << flush;
	test4.print();

    return 0;
}

