#include "Tape.hpp"

Tape::Tape():Publication(),playing_time(0.0){}

Tape::Tape(const char* pub_title,double pub_price,double time):Publication(pub_title,pub_price){
	if(time < 0.0){
		throw "Illegal Values Exception";
	}else{
		playing_time = time;
	}
}
Tape::Tape(const Tape& tape):Publication(tape){
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
void Tape::setInfo() {
	cout << "Tape: " <<endl;
	Publication::setInfo();
	double time;
	cout << "Enter playing time of tape in minutes";
	cin >> time;
	setPlayingTime(time);
}
void Tape::setPlayingTime(double time){
	if(time < 0.0){
		throw "Illegal Values Exception";
	}else{
		playing_time = time;
	}
}
void Tape::displayInfo() const{
	Publication::displayInfo();
	cout << "playing time of tape : " << getPlayingTime() << endl;
}
Tape::~Tape(){}