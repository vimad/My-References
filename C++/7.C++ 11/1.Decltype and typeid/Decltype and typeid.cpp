// Decltype and typeid.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

int main()
{
	string value = "vinod";
	decltype(value) bob = "bob";

	cout << typeid(value).name() << endl;
	cout << bob << endl;

    return 0;
}

