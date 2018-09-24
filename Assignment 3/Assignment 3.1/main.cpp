#include "ComplexInteger.hpp"
#include "defines.hpp"
#include "utils.hpp"
// instructions to compile and execute
// g++ -std=c++14 -o complex ComplexInteger.cpp functions.cpp util.cpp main.cpp
// ./complex
signed main()
{
	int choice,real_part;
	ComplexInteger complex1 = scan_complex();
	ComplexInteger complex2,ans;
	do{
		displayMenu();
		choice = scan_choice();
		switch(choice)
		{
			case ADD:
					complex2 = scan_complex();
					ans = complex1 + complex2;
					#ifdef USER_INTERFACE 
						cout << "Addition is ";
					#endif
					cout << ans << endl;
					break;
			case MULTIPLY:
					complex2 = scan_complex();
					ans = complex1 * complex2;
					#ifdef USER_INTERFACE 
						cout << "Multiplication is ";
					#endif
					cout << ans << endl;
					break;
			case SUBTRACT:
					complex2 = scan_complex();
					ans = complex1 - complex2;
					#ifdef USER_INTERFACE 
						cout << "Subtraction is ";
					#endif
					cout << ans << endl;
					break;
			case DIVIDE:
					complex2 = scan_complex();
					try{
						ans = complex1 / complex2;
						#ifdef USER_INTERFACE
							cout << "Division is ";
						#endif
						cout << ans << endl;
					}catch(const char* exception){
						if(exception != NULL){
							#ifdef USER_INTERFACE
								cout << "Exception: " << exception << endl;
							#endif
						}
					}
					break;
			case ASSIGN:
					#ifdef USER_INTERFACE
						cout << "Enter a complex integer / real integer to assign" << endl;
					#endif
					complex2=scan_complex();
					if(complex2.getImaginary() == 0)
					{
						real_part = complex2.getReal();
						#ifdef USER_INTERFACE
							cout << "Assigning real integer to complex integer object" << endl;

						#endif
						ans = real_part;
						cout << ans << endl;
					}
					else
					{
						#ifdef USER_INTERFACE
							cout << "Assigning a complex integer to complex integer object" << endl;
						#endif
						ans = complex2;
						cout << ans << endl;
					}
					break;
			case SWAP:
					#ifdef USER_INTERFACE
					cout << "Swapping the real and imaginary part" << endl;
					#endif
					cout << (++complex1) << endl;
					break;
			case MULT_CONJUGATE:
					#ifdef USER_INTERFACE
						cout << "Multiplying the complex integer object with its conjugate" << endl;
					#endif
					cout << (--complex1) << endl;
					break;
			case EXIT:
					#ifdef USER_INTERFACE
						cout << "Thank You!" << endl;
					#endif
					break;
			default:
					#ifdef USER_INTERFACE
						cout << "Enter a valid choice" << endl;
					#endif
					break;
		}

	}while(choice != EXIT);

	return 0;
}