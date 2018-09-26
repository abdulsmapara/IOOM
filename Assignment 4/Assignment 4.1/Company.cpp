#include "Company.hpp"

Company::Company()
{
	company_name = NULL;
	num_engineers = 0;
	amount_invested = 0.0;
}
Company::Company(const char* company_name,int num_engineers,double amount_invested){
	if(company_name == NULL or amount_invested < 0.0 or num_engineers < 0){
		throw "Illegal Values Exception";
	}else{
		this->company_name = new char[NAME_SIZE];
		strcpy(this->company_name,company_name);
		this->num_engineers = num_engineers;
		this->amount_invested = amount_invested;
	}
}
Company::Company(const Company& company){
	if(company.company_name == NULL or company.num_engineers < 0 or company.amount_invested < 0.0){
		throw "Illegal Values Exception";
	}else{
		//memory management
		company_name = new char[NAME_SIZE];
		strcpy(this->company_name,company.company_name);
		this->num_engineers = company.num_engineers;
		this->amount_invested = company.amount_invested;
	}
}
void Company::display() const
{
	if(company_name == NULL or num_engineers < 0 or amount_invested < 0.0){
		throw "Illegal Values Exception";
	}else{
		cout << "Company:\t" << company_name << endl;
		cout << "Number of Engineers:\t" << num_engineers << endl;
		cout << "Amount Invested:\t" << amount_invested << endl;
	}
}
//getter methods
const char* Company::getCompanyName() const{
	if(company_name == NULL){
		throw "Null Pointer Exception";
	}else{
		return company_name;
	}
}
int Company::getNumEngineers() const{
	if(num_engineers < 0){
		throw "Illegal Values Exception";
	}else{
		return num_engineers;
	}
}
double Company::getAmountInvested() const{
	if(amount_invested < 0.0){
		throw "Illegal Values Exception";
	}else{
		return amount_invested;
	}
}
//setter methods
void Company::setCompanyName(const char* name_company){
	if(name_company == NULL){
		throw "Illegal Values Exception";
	}else{
		if(company_name == NULL){
			company_name = new char[NAME_SIZE];
		}
		strcpy(company_name,name_company);
	}
}
void Company::setNumEngineers(int num_of_engineers){
	if(num_of_engineers < 0){
		throw "Illegal Values Exception";
	}else{
		num_engineers = num_of_engineers;
	}
}
void Company::setAmountInvested(double invested_amount){
	if(invested_amount < 0.0){
		throw "Illegal Values Exception";
	}else{
		amount_invested = invested_amount;
	}
}
Company::~Company(){
	delete[] company_name;
	cout << "Company info deleted\n";
}
