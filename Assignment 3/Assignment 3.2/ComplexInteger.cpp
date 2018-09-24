#include "ComplexInteger.hpp"

//Constructors
ComplexInteger::ComplexInteger()
{
	real = imaginary = 0;
}
ComplexInteger::ComplexInteger(int real,int imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}
//Copy constructor
ComplexInteger::ComplexInteger(const ComplexInteger& complex)
{
	this->real = complex.real;
	this->imaginary = complex.imaginary;
}
//setter methods
void ComplexInteger::setReal(int real)
{
	this->real=real;
}
void ComplexInteger::setImaginary(int imaginary)
{
	this->imaginary = imaginary;
}
void ComplexInteger::setComplex(int real,int imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

//getter methods
int ComplexInteger::getReal() const
{
	return this->real;
}
int ComplexInteger::getImaginary() const
{
	return this->imaginary;
}
ComplexInteger ComplexInteger::conjugate() const
{
	return ComplexInteger(this->real,(-1)*(this->imaginary));
}
ComplexInteger::operator double() const
{
	return sqrt(real*real+imaginary*imaginary);
}
//destructor
ComplexInteger::~ComplexInteger(){}

const ComplexInteger ComplexInteger::operator+(const ComplexInteger& complex) const
{
	return ComplexInteger(this->real+complex.real,this->imaginary+complex.imaginary);
}
const ComplexInteger ComplexInteger::operator-(const ComplexInteger& complex) const
{
	return ComplexInteger((this->real)-(complex.real),(this->imaginary)-(complex.imaginary));
}
const ComplexInteger ComplexInteger::operator*(const ComplexInteger& complex) const
{
	int real_part = (this->real)*(complex.real) + (this->imaginary)*(complex.imaginary)*(-1);
	int imaginary_part = (this->real)*(complex.imaginary) + (this->imaginary)*(complex.real);
	return ComplexInteger(real_part,imaginary_part);
}
const ComplexInteger ComplexInteger::operator/(const ComplexInteger& complex) const
{
	if(complex.real == 0 and complex.imaginary == 0)
	{
		throw "Division by zero exception";
	}
	else
	{
		const ComplexInteger conjugate = complex.conjugate();
		ComplexInteger denominator = conjugate*complex;
		assert(denominator.imaginary == 0);
		//denominator is real
		ComplexInteger numerator = (*this)*(conjugate);
		return ComplexInteger(numerator.real/(denominator.real),numerator.imaginary/(denominator.real)); 
	}
}
ComplexInteger& ComplexInteger::operator=(const ComplexInteger& complex)
{
	//self assignment check
	if(this != &complex)
	{
		this->real = complex.real;
		this->imaginary = complex.imaginary;
	}
	return *this;
}
ComplexInteger& ComplexInteger::operator=(int real_part)
{
	this->real = real_part;
	this->imaginary = 0;
	return *this;
}

bool ComplexInteger::operator==(const ComplexInteger& complex) const
{
	return (this->real == complex.real and this->imaginary == complex.imaginary);
}
bool ComplexInteger::operator!=(const ComplexInteger& complex) const
{
	return (!((*this) == complex));
}

ComplexInteger& ComplexInteger::operator++()
{
	int temp = this->real;
	this->real = this->imaginary;
	this->imaginary = temp;
	return *this;
}
ComplexInteger ComplexInteger::operator++(int){
	ComplexInteger temp_complex(*this);
	++(*this);
	return temp_complex;
}
ComplexInteger& ComplexInteger::operator--()
{
	ComplexInteger conj = this->conjugate();
	ComplexInteger ans = (*this) * (conj);
	this->real = ans.real;
	this->imaginary = ans.imaginary;
	return (*this);
}
ComplexInteger ComplexInteger::operator--(int){
	ComplexInteger temp_complex(*this);
	--(*this);
	return temp_complex;
}