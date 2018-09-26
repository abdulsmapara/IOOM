#include "Book.hpp"

Book::Book():Publication(),Sales(),page_count(0){}
Book::Book(const char* pub_title,double pub_price,double rup_sales[],int size,int pg_count):Publication(pub_title,pub_price),Sales(rup_sales,size){
	if(pg_count < 0){
		throw "Illegal Values Exception";
	}else{
		page_count = pg_count;
	}
}
Book::Book(const Book& book):Publication(book.getTitle(),book.getPrice()),Sales(book){
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

void Book::displayInfo() const{
	Publication::displayInfo();
	cout << "Page Count " << this->getPageCount() << endl;
	Sales::displayData();
}
void Book::setPageCount(int pg_count){
	if(pg_count < 0){
		throw "Illegal Values Exception";
	}else{
		page_count = pg_count;
	}
}
void Book::setInfo(){
	cout<<"Book" << endl;
	Publication::setInfo();
	Sales::setData();
	int page_cnt;
	cout << "Enter Page Count of the book\n";
	cin >> page_cnt;
	setPageCount(page_cnt);
}
Book::~Book(){
	//this->~Publication();
}
