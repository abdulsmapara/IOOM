#include "Publication.hpp"
#include "Book.hpp"
#include "Tape.hpp"

void setDetails(Book& book,Tape& tape,bool& validity){
	int choice;
	char cont;
	double price;
	int pg_count;
	double play_time;

	char title[TITLE_SIZE];
	
	validity = true;

	try{
		book.setInfo();
		do{
			cout << "Have a look: \n"; book.displayInfo() ;
			cout << "Do you want to edit book's information ?(0/1)" << endl;
			cin >> choice;
			if(choice){
				cout << "Want to change Publication Title? (Y or N)\n";
				cin >> cont;
				if(cont == 'Y'){
					cout << "Enter title\n";cin >> title;
					book.setTitle(title);
				}
				cout << "Want to change price? (Y or N)\n";
				cin >> cont;
				if(cont == 'Y'){
					cout << "Enter price\n";cin >>price;
					book.setPrice(price);
				}
				cout << "Want to change Page count? (Y or N)" << endl;
				cin >> cont;
				if(cont == 'Y'){
					cout << "Enter page count\n";
					cin >> pg_count;
					book.setPageCount(pg_count);
				}
			

			}
		}while(choice != 0);
		tape.setInfo();
		do{
			cout << "Have a look\n";tape.displayInfo();
			cout << "Do you want to edit tape's information ?(0/1)" << endl;
			cin >> choice;
			if(choice){
				cout << "Want to change Publication Title? (Y or N)\n";
				cin >> cont;
				if(cont == 'Y'){
					cout << "Enter title\n";cin >> title;
					tape.setTitle(title);
				}
				cout << "Want to change price? (Y or N)\n";
				cin >> cont;
				if(cont == 'Y'){
					cout << "Enter price\n";cin >>price;
					tape.setPrice(price);
				}
				cout << "Want to change playing time? (Y or N)" << endl;
				cin >> cont;
				if(cont == 'Y'){
					cout << "Enter play time in minutes\n";
					cin >> play_time;
					tape.setPlayingTime(play_time);
				}
				
			}
		}while(choice != 0);

	}catch(const char* exception){
		validity = false;
		if(exception){
			cout << "Exception: " << exception << endl;
		}
	}
}
int main(){

	
	int choice;

	Book book1,book2;
	Tape tape1,tape2;
	bool valid1,valid2;
	setDetails(book1,tape1,valid1);
	//displaying data
	if(valid1){
		cout << "==============DATA BOOK:==================" << endl;
		book1.displayInfo();
		cout << "==============DATA TAPE:==================" << endl;
		tape1.displayInfo();
	}else{
		cout << "Invalid data" <<endl;
	}
	/*setDetails(book2,tape2,valid2);

	if(valid2){
		cout << "==============DATA BOOK:==================" << endl;
		book2.displayInfo();
		cout << "==============DATA TAPE:==================" << endl;
		tape2.displayInfo();
	}else{
		cout << "Invalid data" <<endl;
	}*/
	return 0;
}