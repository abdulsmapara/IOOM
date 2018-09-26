#include "University.hpp"
#include "utils.hpp"
University::University()
{
	//initialize to some values
	university_name=NULL;
	dept=CSE;
	person=NULL;
}
University::University(const char* university_name,Department dept,const char* person){
	if(university_name == NULL or person == NULL){
		throw "Illegal Values Exception";
	}else{
		//allocate memory
		this->university_name = new char[NAME_SIZE];
		this->person = new char[NAME_SIZE];

		strcpy(this->university_name,university_name);
		this->dept = dept;
		strcpy(this->person,person);

	}
}
University::University(const University& university)
{
	//involves memory management
	//self-pronouncing statement
	cout << "University::Copy constructor called" << endl;
	if(university.university_name == NULL or university.person == NULL){
		throw "Illegal Values Exception";
	}
	//Allocate new memory
	this->university_name = new char[NAME_SIZE];
	this->person = new char[NAME_SIZE];
	this->dept = university.dept;
	strcpy(this->university_name,university.university_name);
	strcpy(this->person,university.person);
}
void University::display() const{
	if(university_name == NULL or person == NULL){
		throw "Illegal Values Exception";
	}else{
		cout << "University:\t" << university_name << endl;
		cout << "Department:\t" << i_to_dept(dept) << endl;
		cout << "Person:\t" << person << endl;
	}
}
//getter methods
const char* University::getUniversityName() const{
	if(university_name==NULL){
		throw "Null Pointer Exception";
	}else{
		return university_name;
	}
}
const char* University::getPersonAssigned() const{
	if(person == NULL){
		throw "Null Pointer Exception";
	}else{
		return person;
	}
}
Department University::getDepartment() const{
	return dept;
}
//setter methods
void University::setUniversityName(const char* uni_name){
	if(uni_name == NULL){
		throw "Illegal Values Exception";
	}else{
		if(university_name == NULL){
			university_name = new char[NAME_SIZE];
		}
		//overwrite
		strcpy(university_name,uni_name);
	}
}
void University::setPerson(const char* p_name){

	if(p_name == NULL){
		throw "Illegal Values Exception";
	}else{
		if(person == NULL){
			person = new char[NAME_SIZE];
		}
		//overwrite
		strcpy(person,p_name);
	}
}
void University::setDepartment(Department dept){
	if(i_to_dept(dept) == "ILL"){
		throw "Illegal Values Exception";
	}else{
		this->dept = dept;
	}
}
University::~University(){
	//self-pronouncing statement
	cout << "University info deleted" << endl;
	delete[] university_name;
	delete[] person;
}

