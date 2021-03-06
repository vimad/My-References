// Vectors and Memory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<double> numbers(0);

	int capacity = numbers.capacity();
	cout << "capacity: " << capacity << endl;

	for (int i = 0; i < 10000;i++) {
		if (capacity != numbers.capacity()) {
			capacity = numbers.capacity();
			cout << "capacity: " << capacity << endl;
		}
		numbers.push_back(i);
	}

	//numbers.resize(100); //resize to 100 elements capacity doesnt change
	//numbers.clear(); //clear elements size 0 capacity same
	numbers.reserve(16000); //change capacity
	cout << numbers[2] << endl;
	cout << "size: " << numbers.size() << endl;
	cout << "capacity: " << numbers.capacity() << endl;


    return 0;
}

