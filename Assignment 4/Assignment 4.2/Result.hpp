#ifndef RESULT_HPP_INCLUDED
#define RESULT_HPP_INCLUDED
#include "Examination.hpp"
#include "Extracurricular.hpp"
#include "defines.hpp"
class Result:public Examination,public Extracurricular
{
private:
	double total;
public:
	Result();
	Result(const char* name,int roll,double t1,double t2,double crafts_marks,double music_marks);
	Result(const Examination& exam,const Extracurricular& extra);
	double cal_total();
	void displayTotal() const; 
	void Comment(double pass_marks);
	~Result();
	
};


#endif