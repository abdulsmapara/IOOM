#include "Project.hpp"
#include "utils.hpp"
#include <unordered_map>
#include <utility>
//g++ -std=c++14 -o a utils.cpp University.cpp Company.cpp Project.cpp main.cpp
int main()
{
	cout << "Projects" << endl;
	int choice;
	unordered_map<string,Project*> info;

	Project* project_ptr;
	char university_name[NAME_SIZE];
	char person[NAME_SIZE];
	Department dept;
	char company_name[NAME_SIZE];
	int num_engineers;
	double amount_invested;
	char project_name[NAME_SIZE];
	Type type_of_project;
	Duration duration_of_project;
	double amount_granted;
	string name_of_project;
	int val;
	do
	{
		cout << "MENU\n1] Create a new Project\n2] View an existing Project\n3] View all the projects\n0] EXIT\n";
		cout << "Enter your choice\n";
		cin >> choice;
		switch(choice)
		{
			case CREATE:
				cout << "Enter the name of the Project" << endl;
				cin >> name_of_project;
				if(info.find(name_of_project) != info.end())
				{
					cout << "The project with the same name already exists!" << endl;
				}
				else
				{
					try{
					cout << "Enter the name of the university" << endl;
					cin >> university_name;
					cout << "Enter the name of the person to whom the project is assigned" << endl;
					cin >> person;
					cout << "Enter the Department" << endl;
					display_dept();
					cin >> val;
					if(val < MIN_DEPARTMENT_ALLOWED or val > MAX_DEPARTMENT_ALLOWED){
						throw "Illegal Values Exception";
					}else{
						assign_dept(dept,val);
					}
					cout << "Enter the name of the Company" << endl;
					cin >> company_name ;
					cout << "Enter the number of engineers" << endl;
					cin >> num_engineers;
					if(num_engineers < 0){
						throw "Illegal Values Exception";
					}
					cout << "Enter the amount invested" << endl;
					cin >> amount_invested;
					if(amount_invested < 0.0){
						throw "Illegal Values Exception";
					}
					cout << "Enter the type of the project" << endl;
					display_types();
					cin >> val;
					if(val < MIN_TYPE_ALLOWED or val > MAX_TYPE_ALLOWED){
						throw "Illegal Values Exception";
					}else{
						assign_type(type_of_project,val);
					}
					cout << "Enter the duration of the Project in years, months, days" << endl;
					cin >> duration_of_project.years >> duration_of_project.months >> duration_of_project.days;
					if(duration_of_project.years < 0 or duration_of_project.months < 0 or duration_of_project.days < 0){
						throw "Illegal Values Exception";
					}
					cout << "Enter the amount_granted " << endl;
					cin >> amount_granted;
					if(amount_granted < 0.0){
						throw "Illegal Values Exception";
					}
						try{
							project_ptr = new Project(university_name,dept,person,company_name,num_engineers,amount_invested,type_of_project,duration_of_project,amount_granted);
							info.insert(make_pair(name_of_project,project_ptr));
							cout << "Success!" << endl;
						}catch(const char* exception){
							if(exception != NULL){
								cout << "Exception: " << exception << endl;
							}
						}
					}catch(const char* exception_main){
						if(exception_main != NULL){
							cout << "Exception: " << exception_main << endl;
						}
					}
				}
				break;
			case VIEW:
				cout << "Enter the name of the Project" << endl;
				cin >> name_of_project;
				if(info.find(name_of_project) == info.end())
				{
					cout << "The project with the name " << name_of_project << "does not exist!" << endl;
				}
				else
				{
					Project* ptr = info[name_of_project];
					ptr->display();
				}
				break;
			case VIEW_ALL:
				for(auto it = info.begin();it != info.end();it++)
				{
					cout << "Name: " << (it->first) << '\n';
				}
				break;
			case EXIT:
				cout << "Thank You" << endl;
				break;
			default:
				cout << "Enter a valid choice" << endl;
				break;
		}

	}while(choice != EXIT);
	
	//destruct
	for (auto it=info.begin();it != info.end();++it)
	{
		delete it->second;
	}

	return 0;
}