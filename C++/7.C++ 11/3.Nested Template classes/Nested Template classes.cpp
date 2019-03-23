// Nested Template classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ring.h"

using namespace std;

int main()
{
	ring<int>::iterator it;
	it.print();

	ring<string> r(3);

	r.add("one");
	r.add("two");
	r.add("three");
	r.add("four");

	for (int i = 0;i < r.size();i++) {
		cout << r.get(i) << endl;
	}


    return 0;
}

