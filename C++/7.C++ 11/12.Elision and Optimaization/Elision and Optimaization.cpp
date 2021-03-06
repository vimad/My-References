// Elision and Optimaization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Test {
public:
	Test() {
		cout << "constructor" << endl;
	}

	Test(int i) {
		cout << "parameterized constructor" << endl;
	}

	Test(const Test &other) {
		cout << "copy constructor" << endl;
	}

	Test &operator=(const Test &other) {
		cout << "assignment" << endl;
		return *this;
	}

	~Test() {
		cout << "destructor" << endl;
	}

	friend ostream &operator<<(ostream &out, const Test &other);
};

ostream &operator<<(ostream &out, const Test &other) {
	out << "Hello from test";
	return out;
}

Test get() {
	return Test();
}

int main()
{
	Test test1 = get();
	cout << test1 << endl;

    return 0;
}

