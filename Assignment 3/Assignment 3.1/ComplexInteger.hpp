#ifndef COMPLEX_INTGER_HPP_INCLUDED
#define COMPLEX_INTGER_HPP_INCLUDED

#include <bits/stdc++.h>
using namespace std;
class ComplexInteger
{
private:
	/*Data members*/
	int real;
	int imaginary;
public:
	//Constructor(s)
	ComplexInteger();
	ComplexInteger(int real,int imaginary);

	//copy constructor
	ComplexInteger(const ComplexInteger& complex);

	//setter methods
	void setReal(int real);
	void setImaginary(int imaginary);
	void setComplex(int real,int imaginary);

	//getter methods
	int getReal() const;
	int getImaginary() const;

	//returns conjugate
	ComplexInteger conjugate() const;
	//returns the modulus of the complex number 
	operator double() const;

	//Operator Overloading
	//Adds two complex numbers
	const ComplexInteger operator+(const ComplexInteger& complex) const;
	//Subtracts two Complex Numbers
	const ComplexInteger operator-(const ComplexInteger& complex) const;
	//Multiplies two complex numbers
	const ComplexInteger operator*(const ComplexInteger& complex) const;
	//Divides two complex numbers ???????
	const ComplexInteger operator/(const ComplexInteger& complex) const;
	//Assigns a complex Integer or a Real Integer to a ComplexInteger object (2 methods below)
	ComplexInteger& operator=(const ComplexInteger& complex);
	ComplexInteger& operator=(int real_part);
	//Swaps the real and imaginary values of the object-returns the same object passed as an implicit argument
	//prefix
	//const ComplexInteger& operator++();
	//postfix
	//const ComplexInteger& operator++(int);

	ComplexInteger& operator++();//prefix
	ComplexInteger operator++(int);//postfix


	//Multiplies the ComplexInteger object with its conjugate and stores it in the current object
	ComplexInteger& operator--();//prefix
	ComplexInteger operator--(int);//postfix


	//checks if two complex numbers are same or not
	//equality check
	bool operator==(const ComplexInteger& complex) const;
	bool operator!=(const ComplexInteger& complex) const;

	//destructor
	~ComplexInteger();

	//friend function to display the contents of the object
	friend void displayComplex(const ComplexInteger& complex);
	friend ostream& operator<<(ostream& out,const ComplexInteger& complex);
	friend istream& operator>>(istream& in,ComplexInteger& complex);

};


#endif