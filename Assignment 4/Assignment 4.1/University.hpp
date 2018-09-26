#ifndef UNIVERSITY_HPP_INCLUDED
#define UNIVERSITY_HPP_INCLUDED

#include <iostream>
#include <string.h>
#include <string>
#include "defines.hpp"
using namespace std;
class University
{
private:
	char* university_name;
	Department dept;
	char* person;
public:
	University();
	University(const char* university_name,Department dept,const char* person);
	University(const University& university);
	void display() const;

	//getter methods
	const char* getUniversityName() const;
	const char* getPersonAssigned() const;
	Department getDepartment() const;

	//setter methods
	void setUniversityName(const char*);
	void setPerson(const char*);
	void setDepartment(Department);

	~University();
	
};




#endif

