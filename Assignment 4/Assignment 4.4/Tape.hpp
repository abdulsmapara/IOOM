#ifndef TAPE_HPP_INCLUDED
#define TAPE_HPP_INCLUDED

#include "Publication.hpp"
#include "Sales.hpp"

class Tape:public Publication,public Sales
{
private:
	double playing_time;//minutes
public:
	Tape();
	Tape(const char* pub_title,double pub_price,double rup_sales[],int size,double time);
	Tape(const Tape& tape);
	double getPlayingTime() const;
	void displayData() const;
	void setData();
	void setPlayingTime(double time);
	~Tape();
	
};

#endif