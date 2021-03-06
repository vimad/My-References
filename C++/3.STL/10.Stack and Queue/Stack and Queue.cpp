// Stack and Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class Test {
private:
	string name;

public:

	Test(string name) :name(name) {

	}

	~Test() {
		//cout << "object destroyed "<<name << endl;
	}

	void print() {
		cout << name << endl;
	}
};

int main()
{
	//LIFO
	stack<Test> testStack;

	testStack.push(Test("vinod"));
	testStack.push(Test("gayani"));
	testStack.push(Test("peter"));

	/*
	 *this is invalid code. Object is detroyed
	Test &test1 = testStack.top();
	testStack.pop();
	test1.print(); //reference refered todestroyed object
	*/
	
	while (testStack.size() > 0)
	{
		Test &test1 = testStack.top();
		test1.print();
		testStack.pop();
	}

	cout << endl;

	//LIFO
	queue<Test> testQueue;

	testQueue.push(Test("vinod"));
	testQueue.push(Test("gayani"));
	testQueue.push(Test("peter"));

	testQueue.back().print();

	cout << endl;

	while (testQueue.size() > 0)
	{
		Test &test1 = testQueue.front();
		test1.print();
		testQueue.pop();
	}

    return 0;
}

