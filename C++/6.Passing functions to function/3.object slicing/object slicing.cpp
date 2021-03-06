// object slicing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Parent {
private:
	int one;

public:
	Parent() {

	}

	Parent(const Parent & other) :one(0) {
		cout << "copy constructor called" << endl;
	}

	virtual void print()
	{
		cout << "parent" << endl;
	}
};

class Child :public Parent {
private:
	int two;

public:

	Child():two(0){}

	void print()
	{
		cout << "child" << endl;
	}
};

int main()
{
	
	Child c;
	Parent &p1 = c;
	p1.print();

	Parent p2 = Child();
	p2.print();

    return 0;
}

