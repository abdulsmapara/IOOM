#ifndef BOOK_HPP_INCLUDED
#define BOOK_HPP_INCLUDED
#include "Publication.hpp"

class Book: public Publication
{
private:
	int page_count;
public:
	Book();
	Book(const char* pub_title,double pub_price,int pg_count);
	Book(const Book& book);
	int getPageCount() const;
	void setPageCount(int pg_count);

	virtual void putdata() const;
	virtual void setInfo();
	~Book();
	
};


#endif