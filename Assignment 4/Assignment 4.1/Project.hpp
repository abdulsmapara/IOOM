#ifndef PROJECT_HPP_INCLUDED
#define  PROJECT_HPP_INCLUDED

#include <iostream>
#include <string.h>
#include <string>
#include "defines.hpp"
#include "utils.hpp"
#include "University.hpp"
#include "Company.hpp"
using namespace std;


class Project:public University , public Company
{
private:
	Type type;
	Duration duration;
	double amount_granted;
public:
	Project();
	Project(const char* university_name,Department dept,const char* person,const char* company_name,int num_engineers,double amount_invested,Type type,Duration dur,double amount_granted);
	Project(const Project& project);
	void display() const;
	//setter methods
	void setType(Type type);
	void setDuration(Duration dur);
	void setAmountGranted(double amount);
	//getter methods
	Type getType() const;
	Duration getDuration() const;
	double getAmountGranted() const;
	~Project();
	
};


#endif