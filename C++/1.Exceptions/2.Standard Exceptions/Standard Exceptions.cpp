// Standard Exceptions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class CanGoWrong {
public:
	CanGoWrong() {
		char *a = new char[9999999999999];
		delete a;
	}
};


int main()
{
	try {
		CanGoWrong wrong;
	}
	catch (bad_alloc &e)
	{
		cout << "cought error: " << e.what() << endl;

	}
	

    return 0;
}

