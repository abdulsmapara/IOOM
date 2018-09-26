#ifndef DEFINES_HPP_INCLUDED
#define DEFINES_HPP_INCLUDED

const int NAME_SIZE=53;
#define MIN_DEPARTMENT_ALLOWED 0
#define MAX_DEPARTMENT_ALLOWED 7
enum Department{CSE=0,ECE,MEC,ARC,CME,MET,EEE,MIN};//change here Affects utils.cpp,main.cpp

struct Duration
{
	int years,months,days;
};

#define MIN_TYPE_ALLOWED 0
#define MAX_TYPE_ALLOWED 3
enum Type{MINI_PROJECT,INTERNSHIP_PROJECT,GOVT_PROJECT,FUNDED_PROJECT,NONE};

#define CREATE 1
#define VIEW 2
#define VIEW_ALL 3
#define EXIT 0

#endif