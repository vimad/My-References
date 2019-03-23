// The auto keyword.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

template <class T, class S>
auto test(T val, S val2) -> decltype(val + val2) {
	return val + val2;
}

int get() {
	return 777;
}

auto test2() ->decltype(get()) {
	return get();
}

int main()
{
	cout << test(2, 5) << endl;
	cout << test2() << endl;

    return 0;
}

