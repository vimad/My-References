// function pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void test(int n) {
	cout << "hello " << n << endl;
}

int main()
{
	test(7);

	void(*pTest)(int) = test;

	pTest(4);

    return 0;
}

