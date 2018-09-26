#include "Tape.hpp"

Tape::Tape():Publication(),playing_time(0.0){}

Tape::Tape(const char* pub_title,double pub_price,double rup_sales[],int size,double time):Publication(pub_title,pub_price),Sales(rup_sales,size){
	if(time < 0.0){
		throw "Illegal Values Exception";
	}else{
		playing_time = time;
	}
}
Tape::Tape(const Tape& tape):Publication(tape),Sales(tape){
	if(tape.playing_time < 0.0){
		throw "Illegal Values Exception";
	}
	playing_time = tape.playing_time;
}
double Tape::getPlayingTime() const{
	if(playing_time < 0.0){
		throw "Illegal Values Exception";
	}else{
		return playing_time;
	}
}
void Tape::displayData() const{
	Publication::displayInfo();
	cout << "Playing Time: " << this->getPlayingTime() << " minutes" << endl;
	Sales::displayData();
}
void Tape::setData(){
	cout << "TAPE: "<<endl;
	Publication::setInfo();
	double time;
	cout << "Enter playing time of tape in minutes\n";
	cin >> time;
	setPlayingTime(time);
	Sales::setData();
}
void Tape::setPlayingTime(double time){
	if(time < 0.0){
		throw "Illegal Values Exception";
	}else{
		playing_time = time;
	}
}

Tape::~Tape(){}