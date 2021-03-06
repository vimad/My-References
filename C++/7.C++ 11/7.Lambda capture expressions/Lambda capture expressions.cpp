// Lambda capture expressions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int one = 1;
	int two = 2;
	int three = 3;

	//capture one and two by value
	[one, two]() {cout << one << two << endl;}();

	//capture all varibles by value
	[=]() {cout << one << two << endl;}();

	//capture all variables by value default and only three by refernece
	[=, &three]() {three = 7; cout << one << two << endl;}();
	cout << three << endl;

	//default capture all variables by reference
	[&]() {one = 8;two = 6;cout << one << two << endl;}();
	cout << one << endl;

	//capture all variables by reference default and only three by value
	[&, three]() {one = 7; cout << three << endl;}();
	cout << one << endl;

    return 0;
}

