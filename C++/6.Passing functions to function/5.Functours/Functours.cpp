// Functours.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct Test {
	virtual bool operator()(string &text) = 0;
};

struct MatchTest :public Test {
	virtual bool operator()(string &text) {
		return text == "lion";
	}
};

void check(string text, Test &t) {
	if (t(text)) {
		cout << "text matches" << endl;
	}
	else
	{
		cout << "text does not matches" << endl;
	}
}


int main()
{
	MatchTest pred;
	string value = "lion";
	cout << pred(value) << endl;
	check("lion", pred);
    return 0;
}

