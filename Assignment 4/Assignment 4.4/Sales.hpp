#ifndef SALES_HPP_INCLUDED
#define SALES_HPP_INCLUDED

#define NUM_MONTHS 3
#include <bits/stdc++.h>
using namespace std;

class Sales
{
private:
	double rupee_sales[NUM_MONTHS];
public:
	Sales();
	Sales(double rup_sales[],int size);
	Sales(const Sales& sales);
	void setData(double rup_sales[],int size);
	void setData(double m3,double m2,double m1); //CHANGE THIS ON CHANGING NUM_MONTHS
	void setData();
	const double* getData() const;
	void displayData() const;	//display purpose
	~Sales();
	
};



#endif