// Functional types.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

bool check(string &s) {
	return s.size() == 5;
}

class Check {
public:
	bool operator()(const string &s) {
		return s.size() == 5;
	}
} check1;

void run(function<bool(string &s)> check) {
	string s = "stars";
	cout<<check(s)<<endl;
}

int main()
{
	vector<string> strings{ "one","two","three" };

	auto lambda = [](string &t) {return t.size() == 5;};

	int count = count_if(strings.begin(), strings.end(), lambda);
	cout << count << endl;

	count = count_if(strings.begin(), strings.end(), check);
	cout << count << endl;

	count = count_if(strings.begin(), strings.end(), check1);
	cout << count << endl;

	cout << endl;

	run(lambda);
	run(check);
	run(check1);

	function<int(int, int)> add = [](int a, int b) {return a + b;};
	cout << add(3, 7) << endl;

    return 0;
}

