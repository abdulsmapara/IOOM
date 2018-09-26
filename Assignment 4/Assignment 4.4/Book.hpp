#ifndef BOOK_HPP_INCLUDED
#define BOOK_HPP_INCLUDED
#include "Publication.hpp"

#include "Sales.hpp"

class Book: public Publication,public Sales
{
private:
	int page_count;
public:
	Book();
	Book(const char* pub_title,double pub_price,double rup_sales[],int size,int pg_count);
	Book(const Book& book);
	int getPageCount() const;
	void displayInfo() const;
	void setInfo();
	void setPageCount(int pg_count);

	~Book();
	
};


#endif