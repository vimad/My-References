// Sets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <set>

using namespace std;

class Test {
private:
	int id;
	string name;

public:
	Test(int id, string name):id(id),name(name){}

	void print() const {
		cout << id << " : " << name << endl;
	}

	bool operator<(const Test &other) const
	{
		return name < other.name;
	}
};

int main()
{
	set<int> numbers;

	numbers.insert(10);
	numbers.insert(50);
	numbers.insert(70);
	numbers.insert(20);
	numbers.insert(30);

	for (set<int>::iterator it = numbers.begin();it != numbers.end();it++)
	{
		cout << *it << endl;
	}

	set<int>::iterator it = numbers.find(30);

	if (it != numbers.end())
	{
		cout << "found " << *it << endl;
	}

	if (numbers.count(30))
	{
		cout << "found it" << endl;
	}

	set<Test> test;
	test.insert(Test(1, "vinod"));
	test.insert(Test(2, "gayani"));
	test.insert(Test(3, "peter"));
	test.insert(Test(4, "zoysa"));

	for (set<Test>::iterator it = test.begin();it != test.end();it++)
	{
		it->print();
	}

    return 0;
}

