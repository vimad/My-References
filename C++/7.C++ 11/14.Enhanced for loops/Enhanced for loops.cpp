// Enhanced for loops.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	auto texts = { "one","two","three" };

	for (auto text : texts) {
		cout << text << endl;
	}

	string str = "vinod";

	for (auto s : str) {
		cout << s << endl;
	}

    return 0;
}

