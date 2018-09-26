#include "Book.hpp"

Book::Book():Publication(),page_count(0){}
Book::Book(const char* pub_title,double pub_price,int pg_count):Publication(pub_title,pub_price){
	if(pg_count < 0){
		throw "Illegal Values Exception";
	}else{
		page_count = pg_count;
	}
}
Book::Book(const Book& book):Publication(book.getTitle(),book.getPrice()){
	if(book.page_count < 0){
		throw "Illegal Values Exception";
	}
	page_count = book.page_count;
}
int Book::getPageCount() const{
	if(page_count < 0){
		throw "Illegal Values Exception";
	}
	return page_count;
}
void Book::setPageCount(int pg_count){
	if(pg_count < 0){
		throw "Illegal Values Exception";
	}else{
		page_count = pg_count;
	}
}

void Book::displayInfo() const{
	Publication::displayInfo();
	cout << "Book Page Count " << getPageCount() << endl;
}

void Book::setInfo(){
	cout << "Book " << endl;
	Publication::setInfo();
	cout << "Enter Page count of the book" << endl;
	cin >> page_count;
	setPageCount(page_count);
	
}
Book::~Book(){
	//this->~Publication();
}
