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

	Person(string name, int age) :name(name), age(age)
	{
	}

	Person(const Person &other)
	{
		//cout << "copy constructor called" << endl;
		name = other.name;
		age = other.age;
	}

	void print() const
	{
		cout << name << " : " << age << flush;
	}
	
	bool operator<(const Person &other) const
	{
		if (name == other.name)
		{
			return age < other.age;
		}
		else
		{
			return name < other.name;
		}
	}
};


int main()
{

	map<Person,int> people;

	people[Person("vinod", 24)] = 0;
	people[Person("vinod", 44)] = 0;
	people[Person("gayani", 19)] = 1;
	people[Person("peter", 50)] = 2;

	for (map<Person,int>::iterator it = people.begin(); it != people.end();it++)
	{
		cout << it->second << " - " << flush;
		it->first.print();
		cout << endl;
	}

	return 0;
}

