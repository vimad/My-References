#pragma once
#include <iostream>

using namespace std;

class Complex
{
private:
	double real;
	double imaginary;
public:
	Complex();
	Complex(double real, double imaginary);
	Complex(const Complex &other);

	const Complex &operator=(const Complex &other);
	bool operator==(const Complex &c) const;
	bool operator != (const Complex &c) const;
	Complex operator*() const;

	double getReal() const { return real; }
	double getImaginary() const { return imaginary; }

	~Complex();
	
};

ostream &operator<<(ostream &out, const Complex &complex);
Complex operator+(const Complex &c1, const Complex&c2);
Complex operator+(const Complex &c1, double d);
Complex operator+(double d, const Complex &c1);

