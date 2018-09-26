#ifndef COMPANY_HPP_INCLUDED
#define COMPANY_HPP_INCLUDED

#include <iostream>
#include <string.h>
#include <string>
#include "defines.hpp"
using namespace std;
class Company
{
private:
	char* company_name;
	int num_engineers;
	double amount_invested;
public:
	Company();
	Company(const char* company_name,int num_engineers,double amount_invested);
	Company(const Company& company);
	void display() const;

	//getter methods
	const char* getCompanyName() const;
	int getNumEngineers() const;
	double getAmountInvested() const;

	//setter methods
	void setCompanyName(const char* name_company);
	void setNumEngineers(int num_of_engineers);
	void setAmountInvested(double invested_amount);
	~Company();
	
};



#endif