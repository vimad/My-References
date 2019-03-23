// Basic Exeptions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void mightGetWrong() {
	bool error1 = false;
	bool error2 = true;

	if (error1) {
		throw "wrong here";
	}
	if (error2) {
		throw string("vinod");
	}
}

void usesofWrong() {
	mightGetWrong();
}

int main()
{
	try
	{
		usesofWrong();
	}
	catch (int e)
	{
		cout << "error code : " << e << endl;
	}
	catch (char const * e)
	{
		cout << "error message : " << e << endl;
	}
	catch (string &e)
	{
		cout << "error string : " << e << endl;
	}

    return 0;
}

