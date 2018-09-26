#include "Project.hpp"

Project::Project():University(),Company(){
	type=NONE;
	duration.years=duration.months=duration.days=0;
	amount_granted = 0;
}
Project::Project(const char* university_name,Department dept,const char* person,const char* company_name,int num_engineers,double amount_invested,Type type,Duration dur,double amount_granted):University(university_name,dept,person),Company(company_name,num_engineers,amount_invested){
	this->type = type;
	duration.years=dur.years;
	duration.months=dur.months;
	duration.days=dur.days;
	this->amount_granted = amount_granted;
}
Project::Project(const Project& project){
	try{
		setUniversityName(project.getUniversityName());
		setPerson(project.getPersonAssigned());
		setDepartment(project.getDepartment());
		setCompanyName(project.getCompanyName());
		setNumEngineers(project.getNumEngineers());
		setAmountInvested(project.getAmountInvested());
		if(project.type == NONE){
			throw "Illegal Values Exception";
		}
		type = project.type;
		if(project.duration.years < 0 or project.duration.months < 0 or project.duration.days < 0){
			throw "Illegal Values Exception";
		}
		duration.years = project.duration.years;
		duration.months = project.duration.months;
		duration.days = project.duration.days;

		if(project.amount_granted < 0.0){
			throw "Illegal Values Exception";
		}

		amount_granted = project.amount_granted;

	}catch(const char* exception){
		throw exception;
	}catch(...){
		throw "Exception occured !";
	}
}
void Project::display() const{
	University::display();
	
	cout << "Company:\t" << getCompanyName() << endl;
	cout << "Number of Engineers:\t"<<getNumEngineers()<<endl;

	cout << "Type:\t" << i_to_type(type) << endl;
	cout << "Duration:\t" << duration.years << " years " << duration.months << " months " << duration.days << " days " << endl;
	cout << "Amount Granted:\t" << amount_granted << endl;
}
//setter methods
void Project::setType(Type type){
	if(type == NONE){
		throw "Illegal Values Exception";
	}else{
		this->type=type;
	}
}
void Project::setDuration(Duration dur){
	if(dur.years < 0 or dur.months < 0 or dur.days < 0){
		throw "Illegal Values Exception";
	}else{
		duration.years = dur.years;
		duration.months = dur.months;
		duration.days = dur.days;
	}
}
void Project::setAmountGranted(double amount){
	if(amount < 0.0){
		throw "Illegal Values Exception";
	}else{
		this->amount_granted = amount;
	}
}
//getter methods
Type Project::getType() const{
	if(type == NONE){
		throw "Illegal Values Exception";
	}else{
		return type;
	}
}
Duration Project::getDuration() const{
	if(duration.years < 0 or duration.months < 0 or duration.days < 0){
		throw "Illegal Values Exception";
	}else{
		return duration;
	}
	
}
double Project::getAmountGranted() const{
	if(amount_granted < 0.0){
		throw "Illegal Values Exception";
	}else{
		return amount_granted;
	}
}
Project::~Project(){
	cout << "Project info deleted\n";
}
