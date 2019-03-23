// Maps.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main()
{

	map<string, int> ages;
	ages["vinod"] = 24;
	ages["gayani"] = 19;
	ages["raj"] = 50;

	cout << ages["vinod"] << endl;

	ages.insert(make_pair("peter", 100));

	if (ages.find("raj") != ages.end())
	{
		cout << "found key" << endl;
	}
	else
	{
		cout << "key not found" << endl;
	}

	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
	{
		pair<string, int> age = *it;
		cout << age.first << " : " << age.second << endl;
	}

	for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
	{
		cout << it->first << " : " << it->second << endl;
	}


    return 0;
}

