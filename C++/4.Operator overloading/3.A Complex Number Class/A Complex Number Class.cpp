// A Complex Number Class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Complex.h"


int main()
{
	Complex c1(2, 3);
	Complex c2(3,4);

	Complex c3 = c1 + c2;
	Complex c4 = c2;

	cout << c1+c2 << endl;

	cout << c1 + 8 << endl;
	cout << 2 + c2 << endl;

	if (c4 == c2)
	{
		cout << "Equal" << endl;
	}
	else
	{
		cout << "not Equal" << endl;
	}

	cout << *c1 << endl;

    return 0;
}

