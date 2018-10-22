#ifndef TAPE_HPP_INCLUDED
#define TAPE_HPP_INCLUDED

#include "Publication.hpp"

class Tape:public Publication
{
private:
	double playing_time;//minutes
public:
	Tape();
	Tape(const char* pub_title,double pub_price,double time);
	Tape(const Tape& tape);
	double getPlayingTime() const;
	virtual void setInfo();
	virtual void putdata() const;
	void setPlayingTime(double time);
	~Tape();
	
};

#endif