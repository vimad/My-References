// Sorting Vectors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Test {
private:
	int id;
	string name;

public:
	Test(int id, string name):id(id),name(name){}

	void print() {
		cout << id << " : " << name << endl;
	}

	/*
	bool operator<(const Test &other) const {
		return name < other.name;
	}
	*/

	friend bool comp(const Test &a, const Test &b);
};

bool comp(const Test &a, const Test &b)
{
	return a.name < b.name;
}

int main()
{
	vector<Test> tests;

	tests.push_back(Test(5, "mike"));
	tests.push_back(Test(10, "sue"));
	tests.push_back(Test(7, "raj"));
	tests.push_back(Test(3, "vikey"));

	sort(tests.begin(), tests.end(), comp);

	for (int i=0;i<tests.size();i++)
	{
		tests[i].print();
	}

    return 0;
}

