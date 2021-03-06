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
	Test() :id(0), name("") {}

	Test(int id, string name) :id(id), name(name) {}

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

	friend ostream &operator<<(ostream &out, const Test &test) {
		out << test.id << ": " << test.name << flush;
		return out;
	}
};

int main()
{
	Test test1(1, "vinod");
	Test test2(2, "ishara");
	cout << test1 << " " << test2 << endl;

	return 0;
}

