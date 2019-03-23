// mutable lambdas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a = 10;

	[a]() mutable {
		a = 5;
		cout << a << endl;
	}();

	cout << a << endl;

    return 0;
}

