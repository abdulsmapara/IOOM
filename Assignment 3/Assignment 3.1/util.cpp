#include "ComplexInteger.hpp"
#include "defines.hpp"

/*

	Helping functions to main()

*/
void displayMenu()
{
	#ifdef USER_INTERFACE
	printf("MENU\n1] Add two complex numbers\n2] Subtract two complex numbers\n3] Multiply two complex numbers\n4] Divide two complex numbers\n5] Assign a complex Integer or real integer to a complex integer object\n6] Swaps real and imaginary part\n7] Multiply with its conjugate\n0] EXIT\n");
	#endif
	return;
}
void instruct(int operation)
{
	#ifdef USER_INTERFACE
	if(operation == SCAN_COMPLEX)
	{
		cout << "Enter a complex integer" << endl;
		cout << "Enter the real part and then the imaginary part. For real number, enter imaginary part as 0\n";
	}
	else if(operation == SCAN_CHOICE)
	{
		cout << "Enter your choice" << endl;
	}
	#endif
}
ComplexInteger scan_complex()
{
	ComplexInteger complex;
	instruct(SCAN_COMPLEX);
	cin >> complex;
	return complex;
}
int scan_choice(){
	instruct(SCAN_CHOICE);
	int choice;
	cin >> choice;
	return choice;
}
