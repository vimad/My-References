// Initializer Lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <initializer_list>
#include <iostream>
#include <string>

using namespace std;

class Test {
public:
	Test(initializer_list<string> texts) {
		for (auto s : texts) {
			cout << s << endl;
		}
	}

	void print(initializer_list<string> texts) {
		for (auto s : texts) {
			cout << s << endl;
		}
	}
};

int main()
{

	Test test{ "apple","banana","orange" };

	test.print({ "one", "two", "three" });

    return 0;
}

