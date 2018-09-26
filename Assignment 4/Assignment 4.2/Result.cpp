#include "Result.hpp"




Result::Result():Examination(),Extracurricular(),Student(){
	total = 0.0;
}
Result::Result(const char* name,int roll,double t1,double t2,double crafts_marks,double music_marks):Examination(name,roll,t1,t2),Extracurricular(name,roll,crafts_marks,music_marks),Student(name,roll)
{
	total = Examination::get_total()+Extracurricular::get_score();
}
double Result::cal_total() {
	return (total=(Examination::get_total()+Extracurricular::get_score()));
}
void Result::displayTotal() const{
	cout << "TOTAL RESULT = " << (Examination::get_total()+Extracurricular::get_score()) << endl;
}
Result::Result(const Examination& exam,const Extracurricular& extra):Student(){
	if(strcmp(exam.getName(),extra.getName()) != 0){
		throw "Diamond Inheritance Problem!";
	}else if(exam.getRollNumber() != extra.getRollNumber()){
		throw "Diamond Inheritance Problem!";		
	}
	setTest1(exam.getTest1());
	setTest2(exam.getTest2());
	setCraft(extra.get_score(CRAFT));
	setMusic(extra.get_score(MUSIC));
}
void Result::Comment(double pass_marks){
	cal_total();
	if(total >= pass_marks){
		cout << "Passed!!" << endl;
	}else{
		cout << "Not Passed!!" << endl;
	}
}
Result::~Result(){}