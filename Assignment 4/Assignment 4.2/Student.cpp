#include "Student.hpp"

Student::Student()
{
	cout << "Student default constructor\n";
	student_name = NULL;
	roll_number = -1;
}
Student::Student(const char* name,int roll)
{
	cout << "Student's parametrized constructor\n";
	if(name == NULL or roll <= 0){
		throw "Illegal Values Exception";
	}
	student_name = new char[NAME_SIZE];
	strcpy(student_name,name);
	roll_number = roll;
}
Student::Student(const Student& student)
{

	cout << "Student's copy constructor\n";
	//memory management involved
	if(student.student_name == NULL or student.roll_number <= 0)
		throw "Illegal Values Exception";
	student_name = new char[NAME_SIZE];
	strcpy(student_name,student.student_name);
	roll_number = student.roll_number;
}
const char* Student::getName() const{
	if(student_name == NULL){
		throw "NULL POINTER EXCEPTION";
	}else{
		return student_name;
	}
}	
int Student::getRollNumber() const{ 
	if(roll_number <= 0){
		throw "Illegal Values Exception";
	}else{
		return roll_number;
	}
}
void Student::displayDetails() const{
	if(student_name == NULL or roll_number <= 0){
		throw "NULL POINTER EXCEPTION";
	}else{
		cout << "Name: " << student_name << endl;
		cout << "Roll No. " << roll_number << endl;
	}
}

void Student::setName(const char* name){

	if(name == NULL){
		throw "Illegal Values Exception";
	}else{
		if(student_name == NULL){
			student_name = new char[NAME_SIZE];
		}
		strcpy(student_name,name);
	}
}
void Student::setRollNumber(int roll){
	if(roll <= 0){
		throw "Illegal Values Exception";
	}
	roll_number = roll;
}
Student::~Student(){
	delete[] student_name;
	cout << "Student info deleted" << endl;
}