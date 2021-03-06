// Custom Objects as Map Values.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Person {
private:
	string name;
	int age;

public:

	Person() :name(""), age(0)
	{
	}

	Person(string name, int age):name(name),age(age)
	{
	}

	Person(const Person &other)
	{
		cout << "copy constructor called" << endl;
		name = other.name;
		age = other.age;
	}

	void print()
	{
		cout << name << " : " << age << endl;
	}
};


int main()
{

	map<int, Person> people;

	people[0] = Person("vinod", 24);
	people[1] = Person("gayani", 19);
	people[2] = Person("peter", 50);

	people.insert(make_pair(3, Person("bob", 25)));
	people.insert(make_pair(4, Person("sue", 20)));

	for (map<int, Person>::iterator it = people.begin(); it != people.end();it++)
	{
		cout << it->first << " - " << flush;
		it->second.print();
	}

    return 0;
}

