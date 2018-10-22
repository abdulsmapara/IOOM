#include "Publication.hpp"
#include "Book.hpp"
#include "Tape.hpp"


int main(){

	int num_publications;
	cout << "Enter the number of publications" << endl;
	cin >> num_publications;
	Publication* arr_pub[num_publications];
	bool validity=true;
	for (int i = 0; i < num_publications; ++i)
	{
		cout << "1 = BOOK\tAny other number = TAPE" << endl;
		int ch;
		cin >> ch;
		if(ch == 1){
			arr_pub[i] = new Book();
			validity=true;
			do{
				try{
					arr_pub[i]->setInfo();
					validity=true;
				}catch(const char* exception){
					validity=false;
					cout << "Exception: "<<exception << endl;
				}
			}while(!validity);

		}else{
			arr_pub[i] = new Tape();
			validity=true;
			do{
				try{
					arr_pub[i]->setInfo();
					validity=true;
				}catch(const char* exception){
					validity=false;
					cout << "Exception: "<<exception << endl;
				}
			}while(!validity);			
		}
	}
	cout << "Here is what you have entered" << endl;
	for (int i = 0; i < num_publications; ++i)
	{
		try{
		arr_pub[i]->putdata();
		}catch(...){
			cout << "exception"<<endl;
		}
		delete arr_pub[i];
	}
	cout << "Thank You" << endl;
	return 0;
}