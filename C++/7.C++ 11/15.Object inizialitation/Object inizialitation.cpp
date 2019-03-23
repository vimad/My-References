// Object inizialitation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Test {
private:
	int a{ 3 };
	string b{ "vinod" };

public:
	Test() = default;
	Test(const Test &other) = delete;
	Test &operator=(const Test &other) = delete;

	Test(int a):a(a){}

	void print() {
		cout << a << ": " << b << endl;
	}

};

int main()
{

	Test test;
	test.print();

	Test test2(5);
	test2.print();

	/*
	 *this is not gonna work since it is delete
	 Test test3 =  test;
	 test2 = test;
	 */

	return 0;
}

