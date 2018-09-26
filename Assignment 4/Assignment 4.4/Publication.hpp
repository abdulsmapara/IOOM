#ifndef PUBLICATION_HPP_INCLUDED
#define PUBLICATION_HPP_INCLUDED

#include <bits/stdc++.h>
using namespace std;
#define TITLE_SIZE 53

class Publication
{
private:
	char* title;
	double price;
public:
	Publication();
	Publication(const char* pub_title,double pub_price);
	Publication(const Publication& pub);
	//getter methods
	const char* getTitle() const;
	double getPrice() const;
	//setter methods
	void setTitle(const char* pub_title);
	void setPrice(double pub_price);
	void setInfo();
	void displayInfo() const;
	~Publication();
	
};


#endif