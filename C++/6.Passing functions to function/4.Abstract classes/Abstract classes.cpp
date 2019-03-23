// Abstract classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Animal {
public:
	virtual void run() = 0;
	virtual void speak() = 0;
};

class Dog :public Animal {
public:
	virtual void speak() {
		cout << "woof" << endl;
	}
};

class labrado :public Dog {
public:
	virtual void run() {
		cout << "librado running" << endl;
	}
};


int main()
{
	labrado lab;

	Animal *animals[5];
	animals[0] = &lab;

	animals[0]->speak();
	animals[0]->run();

    return 0;
}

