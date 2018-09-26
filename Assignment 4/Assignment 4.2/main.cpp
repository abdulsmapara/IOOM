#include "Result.hpp"
#include "defines.hpp"

int main(){

	char name[NAME_SIZE];
	int roll_number;
	double test1,test2,crafts,music;
	cout << "Enter name of the student" << endl;
	cin >> name;
	cout << "Enter roll number of the student" << endl;
	cin >> roll_number;

	cout << "====STUDENT DETAILS====" << endl;
	Student student(name,roll_number);
	student.displayDetails();


	cout << "Enter exam details:" << endl;
	cout << "Test1: ";
	cin >> test1;
	cout << "Test2: ";
	cin >> test2;
	Examination exam(student,test1,test2);
	cout << "AVERAGE = " ;
	exam.display_average();

	cout << "Enter extra curricular details" << endl;
	cout << "crafts: " ;
	cin >> crafts;
	cout << "music: ";
	cin >> music;
	Extracurricular extra_curr(student,crafts,music);
	extra_curr.display_total();
	
	cout << "=========RESULT===========" << endl;
	Result res(exam,extra_curr);

	cout << res.cal_total() << endl;
	res.Comment();
	cout << endl;
	return 0;
}