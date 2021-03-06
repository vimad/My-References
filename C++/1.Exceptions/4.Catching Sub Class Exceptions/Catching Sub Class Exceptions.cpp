// Catching Sub Class Exceptions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" 
#include <iostream>
#include <exception>

using namespace std;

void goWrong() {
	bool error1 = true;
	bool error2 = false;

	if (error1) {
		throw bad_alloc();
	}

	if (error2) {
		throw exception();
	}
}

int main()
{
	try
	{
		goWrong();
	}
	catch (exception &e)
	{
		cout << "catching exception: " << e.what() << endl;
	}
	catch (bad_alloc &e)
	{
		cout << "catching bad alloc: " << e.what() << endl;

	}
	//here order is important.
	//if exception in first palce that cath block runs because all other subclasses inherit exception class.
	//put exception in sub classes to parent classe downwords to get expected results.
	
    return 0;
}

