// Initialization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int value{ 5 };
	cout << value << endl;

	string name{ "vinod" };
	cout << name << endl;

	int *nums = new int[3]{ 1,2,3 };
	cout << nums[1] << endl;

	int value2{ };
	cout << value2 << endl;

	vector<string> strings{ "one","two","three" };
	cout << strings[2] << endl;

    return 0;
}

