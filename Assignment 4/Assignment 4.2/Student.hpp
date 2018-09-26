#ifndef STUDENT_HPP_INCLUDED
#define STUDENT_HPP_INCLUDED

#include <iostream>
#include <string.h>
#include <string>
#include "defines.hpp"
using namespace std;

class Student
{
private:
	char* student_name;
	int roll_number;

public:
	Student();
	Student(const char* name,int roll);
	Student(const Student& student);
	//getter methods
	const char* getName() const;
	int getRollNumber() const;
	void displayDetails() const; 

	void setName(const char* name);
	void setRollNumber(int roll);
	//destructor
	~Student();
	
};

#endif