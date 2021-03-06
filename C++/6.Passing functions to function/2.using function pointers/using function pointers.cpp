// using function pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool match(string test) {
	return test.size() == 3;
}

int count(vector<string> vec, bool(*match)(string test))
{
	int c = 0;
	for (int i = 0;i < vec.size();i++) {
		if (match(vec[i]))
		{
			c++;
		}
	}
	return c;

}
int main()
{
   
	vector<string> nums;

	nums.push_back("one");
	nums.push_back("two");
	nums.push_back("three");
	nums.push_back("one");
	nums.push_back("four");
	nums.push_back("two");
	nums.push_back("five");

	cout << match("one") << endl;

	cout << count_if(nums.begin(), nums.end(), match) << endl;

	cout << count(nums, match) << endl;

	return 0;
}

