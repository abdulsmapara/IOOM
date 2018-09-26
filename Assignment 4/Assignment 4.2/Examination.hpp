#ifndef EXAMINATION_HPP_INCLUDED
#define EXAMINATION_HPP_INCLUDED
#include "Student.hpp"

class Examination:virtual public Student
{
private:
	double test1,test2;
public:
	Examination();
	Examination(const char* name,int roll,double t1,double t2);
	Examination(const Student& student,double t1,double t2);
	Examination(const Examination& exam);
	double cal_average() const;
	double get_total() const;
	void setTest1(double t1);
	void setTest2(double t2);
	double getTest1() const;
	double getTest2() const;
	void display_average() const;
	~Examination();
	
};


#endif