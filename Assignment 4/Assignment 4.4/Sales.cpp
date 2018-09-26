#include "Sales.hpp"

Sales::Sales(){
	for (int i = 0; i < NUM_MONTHS; ++i)
	{
		rupee_sales[i] = 0.0;
	}
}
Sales::Sales(double rup_sales[],int size){
	if(size != NUM_MONTHS){
		throw "Illegal Values Exception";
	}else{
		for (int i = 0; i < NUM_MONTHS; ++i)
		{
			rupee_sales[i] = rup_sales[i];
		}
	}
}
Sales::Sales(const Sales& sales){

		for (int i = 0; i < NUM_MONTHS; ++i)
		{
			rupee_sales[i] = sales.rupee_sales[i];
		}
	
}
void Sales::setData(double rup_sales[],int size){
	if(size != NUM_MONTHS){
		throw "Illegal Values Exception";
	}else{
		for (int i = 0; i < NUM_MONTHS; ++i)
		{
			rupee_sales[i] = rup_sales[i];
		}
	}
}
void Sales::setData(double m3,double m2,double m1){ //CHANGE THIS ON CHANGING NUM_MONTHS	
	rupee_sales[0] = m1;
	rupee_sales[1] = m2;
	rupee_sales[2] = m3;
}
void Sales::setData(){
	cout << "Enter sales info for the past " << NUM_MONTHS << "months (Most Recent First)" << endl;
	for (int i = 0; i < NUM_MONTHS; ++i)
	{
		cin >> rupee_sales[i];
	}
}
const double* Sales::getData() const{
	return rupee_sales;
}
void Sales::displayData() const{	//display purpose
	cout << "Sales in Rupees(Most Recent first)" << endl;
	for (int i = 0; i < NUM_MONTHS; ++i)
	{
		cout << rupee_sales[i] << " ";
	}
	cout << endl;
}

Sales::~Sales(){
	cout << endl << "Sales info deleted" << endl;
}