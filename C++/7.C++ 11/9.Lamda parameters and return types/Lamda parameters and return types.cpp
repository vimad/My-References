// Lamda parameters and return types.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void devide(double (*pDevide)(double a, double b))
{
	auto rval = pDevide(10, 2);
	cout << rval << endl;
}

int main()
{
	auto pdevide = [](double a, double b) -> double {
		if (b == 0) {
			return 0;
		}
		return a / b;
	};

	devide(pdevide);

    return 0;
}

