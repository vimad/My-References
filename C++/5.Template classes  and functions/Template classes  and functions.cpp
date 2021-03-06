// Template classes  and functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Test {
private:
	T obj;

public:
	Test(T obj)
	{
		this->obj = obj;
	}

	void print() {
		cout << obj << endl;
	}
};

template <class T>
void print(T n) {
	cout <<"with template "<< n << endl;
}

void print(int n) {
	cout << "with out template " << n << endl;
}

template <class T>
void show() {
	cout << T() << endl;
}

int main()
{
	Test<string> t("hello");
	t.print();

	print<string>("hello");
	print<int>(6);
	print(5);

	show<double>();

    return 0;
}

