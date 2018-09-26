#include "Result.hpp"
#include "defines.hpp"

int main(){
	double pass;
	char name[NAME_SIZE];
	int roll_number;
	double test1,test2,crafts,music;
	cout << "Enter name of the student" << endl;
	cin >> name;
	cout << "Enter roll number of the student" << endl;
	cin >> roll_number;


	cout << "Enter exam details:" << endl;
	cout << "All marks are out of 100.0 " << endl;
	cout << "Test1: ";
	cin >> test1;
	cout << "Test2: ";
	cin >> test2;

	cout << "Enter extra curricular details" << endl;
	cout << "crafts: " ;
	cin >> crafts;
	cout << "music: ";
	cin >> music;
	
	cout << "=========RESULT===========" << endl;
	try{
		Result res(name,roll_number,test1,test2,crafts,music);

		cout << "DETAILS===\n";
		res.Student::displayDetails();
		cout << "EXAM AVERAGE: ";
		cout << res.Examination::cal_average();
		cout << endl;
		res.Extracurricular::display_total();
		cout << "Enter pass marks" << endl;
		cin >> pass;
		
		cout << "RESULT FINAL: " << res.cal_total() << endl;
		
		res.Comment(pass);
		
		cout << endl;
	}catch(const char* exception){
		if(exception){
			cout << exception << endl;
		}
	}catch(...){
		cout << "Exception !" << endl;
	}
	return 0;
}