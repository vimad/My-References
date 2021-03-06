// Iterable classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ring.h"

using namespace std;


int main()
{
	ring<string> texts(3);

	texts.add("one");
	texts.add("two");
	texts.add("three");

	for (ring<string>::iterator it = texts.begin(); it != texts.end();it++)
	{
		cout << *it << endl;
	}

	cout << endl;

	for (auto text : texts)
	{
		cout << text << endl;
	}

    return 0;
}

