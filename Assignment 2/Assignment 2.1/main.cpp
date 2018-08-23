#include "stdbst.hpp"
/*
	IOOM ASSIGNMENT 2.1 Dt.19th Aug, 2018
	SUBMITTED BY:ABDUL SATTAR MAPARA
				 R3 BATCH
	 		     BT16CSE053
	 GUIDED BY:  M.M.DHABU MA'AM
	 		     CSE,VNIT
	Object Oriented Programming in C++
*/
int main(){
	
	bool done=false;
	int choice,num,total_marks;
	char student_name[NAME_SIZE];
	stdbst bst;

	//print menu
	cout << "MENU" << endl;
	cout << "1. Add student details" << endl;
	cout << "2. Remove student details" << endl;
	cout << "3. View details of all students" << endl;

	while(!done)
	{
		cout<<"Enter your choice"<<"\t";
		cin >> choice;
		switch(choice)
		{
			case INSERT:
						cout<<"Enter the number of students"<<endl;
						cin >> num;
						while(num--)
						{
							cout<<"Student Name: "<<"\t";
							cin >> student_name;
							cout<<"Total Marks"<<"\t";
							cin >> total_marks;
							try{
								bst.insert_in_bst(student_name,total_marks);
							}catch(const char* msg){
								if(msg != NULL){
									cout<<"Exception: "<<msg<<endl;
								}
							}

						}
						break;
			case DELETE:
						cout<<"Student Name: "<<"\t";
						cin >> student_name;
						cout<<"Total Marks"<<"\t";
						cin >> total_marks;
						try{
							bst.delete_from_bst(student_name,total_marks,true);
						}catch(const char* msg){
							if(msg != NULL){
								cout<<"Exception: "<<msg<<endl;
							}
						}
						break;
			case TRAVERSE:
						bst.traverse();
						break;
			case EXIT:
						done=true;
						cout<<"Thank You!"<<endl;
						break;
			default:
						cout<<"Please enter a valid choice"<<endl;
						break;
		}
	}

	return 0;
}