#include "Extracurricular.hpp"

Extracurricular::Extracurricular():Student(){
	craft = music = 0.0;
}
Extracurricular::Extracurricular(const char* stud_name,int roll,double craft_marks,double music_marks):Student(){
	setName(stud_name);
	setRollNumber(roll);
	craft=(craft_marks);
	music=(music_marks);
}

Extracurricular::Extracurricular(const Extracurricular& extra):Student(){
	setName(extra.getName());
	setRollNumber(extra.getRollNumber());
	craft = extra.craft;
	music = extra.music;
}
Extracurricular::Extracurricular(const Student& student,double craft_marks,double music_marks):Student(){
	setName(student.getName());
	setRollNumber(student.getRollNumber());
	craft = craft_marks;
	music = music_marks;
}
double Extracurricular::get_score(int field) const{
	double ret=0.0;
	if(field == MUSIC){
		ret = music;
	}else if(field == CRAFT){
		ret = craft;
	}else{
		throw "Illegal Values Exception";
	}
	return ret;
}
double Extracurricular::get_score() const{
	return (craft+music);
}
void Extracurricular::display_total() const{
	cout << "Total for Student  -"<< getName() << " Roll: " << getRollNumber() << "in Extracurricular is " << get_score() << endl;
}
void Extracurricular::setMusic(double music_){
	music = music_;
}
void Extracurricular::setCraft(double craft_){
	craft = craft_;
}
Extracurricular::~Extracurricular(){
	cout << "Extracurricular info deleted\n";
}