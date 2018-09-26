#include "Examination.hpp"


Examination::Examination():Student(),test1(0.0),test2(0.0){}
Examination::Examination(const char* name,int roll,double t1,double t2):Student(){
	setName(name);
	setRollNumber(roll);
	test1 = t1;
	test2 = t2;
}
Examination::Examination(const Examination& exam):Student(exam.getName(),exam.getRollNumber()){
	test1 = exam.test1;
	test2 = exam.test2;
}
Examination::Examination(const Student& student,double t1,double t2):Student(){
	setName(student.getName());
	setRollNumber(student.getRollNumber());
	test1 = t1;
	test2 = t2;
}
double Examination::cal_average() const{
	return ((test1+test2)/2.0);
}
void Examination::display_average() const{
	cout << "Average is " << cal_average() << endl;
}
double Examination::get_total() const{
	return test2+test1;
}
void Examination::setTest1(double t1){
	test1 = t1;
}
void Examination::setTest2(double t2){ test2 = t2; }
double Examination::getTest1() const{
	return test1;
}
double Examination::getTest2() const
{
	return test2;
}
Examination::~Examination(){
	cout << "Examination info deleted" << endl;
}
