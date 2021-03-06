// Capturing thiswith lambdas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Test {
private:
	int one{ 1 };
	int two{ 2 };

public:
	void run() {
		int three{ 3 };
		int four{ 4 };

		auto pLambda = [&,this]() {
			one = 7;
			cout << three<<endl;
			cout << four << endl;
			cout << one << endl;

		};

		pLambda();
	}
};

int main()
{
	Test test;
	test.run();

    return 0;
}

