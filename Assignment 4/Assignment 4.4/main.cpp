#include "Publication.hpp"
#include "Book.hpp"
#include "Tape.hpp"
#include "Sales.hpp"
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
				cout << "Want to change Sales Details ?" << endl;
				cin >> cont;
				if(cont == 'Y'){
					book.Sales::setData();
				}

			}
		}while(choice != 0);

		tape.setData();
		do{
			cout << "Have a look\n";tape.displayData();
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
				cout << "Want to change Sales Details ?" << endl;
				cin >> cont;
				if(cont == 'Y'){
					tape.Sales::setData();
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

	Book book;
	Tape tape;
	bool valid;
	setDetails(book,tape,valid);

	//displaying data
	if(valid){
		cout << "=================DATA:======================" << endl;
		book.displayInfo();
		tape.displayData();
	}else{
		cout << "Invalid data" <<endl;
	}
	return 0;
}