#include "ComplexInteger.hpp"


//function to display the contents of the object of ComplexInteger
void displayComplex(const ComplexInteger& complex)
{
	cout << complex ;
}

ostream& operator<<(ostream& out,const ComplexInteger& complex)
{
	out << complex.real << " + " << complex.imaginary << "i";
	return out;
}
istream& operator>>(istream& in,ComplexInteger& complex)
{
	in >> complex.real;
	in >> complex.imaginary;
	return in;
}
