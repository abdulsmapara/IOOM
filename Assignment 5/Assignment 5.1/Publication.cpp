#include "Publication.hpp"


Publication::Publication(){
	title = NULL;
	price = 0.0;
}
Publication::Publication(const char* pub_title,double pub_price){
	if(pub_title == NULL or pub_price < 0.0){
		throw "Illegal Values Exception";
	}else{
		title = new char[TITLE_SIZE];
		strcpy(title,pub_title);
		price = pub_price;
	}
}
Publication::Publication(const Publication& pub){
	if(pub.title == NULL or pub.price < 0.0){
		throw "Illegal Values Exception";
	}else{
		title = new char[TITLE_SIZE];
		strcpy(title,pub.title);
		price = pub.price;
	}
}
//getter methods
const char* Publication::getTitle() const{
	if(title == NULL){
		throw "Null Pointer Exception";
	}
	return title;
}
double Publication::getPrice() const{
	if(price < 0.0){
		throw "Illegal Values Exception";
	}else{
		return price;
	}
}
//setter methods
void Publication::setTitle(const char* pub_title){
	if(pub_title == NULL){
		throw "Illegal Values Exception";
	}else{
		if(title == NULL){
			title = new char[TITLE_SIZE];
		}
		strcpy(title,pub_title);
	}
}
void Publication::setPrice(double pub_price){
	if(pub_price < 0.0){
		throw "Illegal Values Exception";
	}else{
		price = pub_price;
	}
}
void Publication::setInfo(){
	char tit[TITLE_SIZE];
	double pri;
	cout << "Enter the title of the Publication" << endl;
	cin >> tit;
	cout << "Enter the Price of the Publication" << endl;
	cin >> pri;
	setTitle(tit);
	setPrice(pri);
}
void Publication::putdata() const{
	cout << "Title " << getTitle() << endl;
	cout << "Price " << getPrice() << endl;
}
Publication::~Publication(){
	cout << endl << "Publication info deleted" << endl;
	//if(title != NULL){
		delete[] title;
	//}
}
