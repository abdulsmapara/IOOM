#ifndef EXTRACURRICULAR_HPP_INCLUDED
#define EXTRACURRICULAR_HPP_INCLUDED
#include "Student.hpp"

class Extracurricular: virtual public Student
{
private:
	double craft,music;
public:
	Extracurricular();
	Extracurricular(const char* stud_name,int roll,double craft_marks,double music_marks);
	Extracurricular(const Student& student,double craft_marks,double music_marks);
	Extracurricular(const Extracurricular& extra);
	double get_score(int field) const;
	double get_score() const;
	void setMusic(double music_);
	void setCraft(double craft_);
	void display_total() const;
	~Extracurricular();
	
};



#endif