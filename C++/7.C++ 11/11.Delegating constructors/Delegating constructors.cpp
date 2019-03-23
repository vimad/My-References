// Delegating constructors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Parent {
public:
	Parent():Parent("hello") {
		cout << "no params" << endl;
	}

	Parent(string s) {
		cout << "with params" << endl;
	}
};

class Child {
public:
	Child() = default;
};

int main()
{
	Parent p;
	Child c;


    return 0;
}

