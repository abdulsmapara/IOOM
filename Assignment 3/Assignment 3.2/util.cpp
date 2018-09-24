#include "ComplexInteger.hpp"
#include "defines.hpp"
#include "Matrix.hpp"
/*

	Helping functions to main()

*/
void displayMenu()
{
	#ifdef USER_INTERFACE
		cout << "\tMENU\n1] Add a scalar/matrix\n2] Subtract a scalar/matrix\n3] Multiply a scalar/matrix\n4] Replace index with zero complex integer\n5] Assign to another matrix\n6] Create a fresh list from a given 2d array of objects\n7] DISPLAY the matrix\n8] Search the matrix\n0] EXIT\n";
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
	else if(operation == SCAN_MATRIX)
	{
		cout << "Enter number of rows then number of columns and then the 2d matrix in row-major form\n";
	}
	else if(operation == SCAN_INDEX)
	{
		cout << "Enter the position (in natural counting order) in the matrix" << endl;
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


Matrix scan_matrix(){
	instruct(SCAN_MATRIX);
	int rows,cols;
	cin >> rows >> cols;
	Matrix scan(rows,cols);
	ComplexInteger val;
	for (int i = 0; i < rows; ++i)
	{
		for(int j=0;j<cols;j++)
		{
			instruct(SCAN_COMPLEX);
			cin >> val;
			scan.setMatrix(i,j,val);
		}
	}
	return scan;
}

void internal_menu(){
	cout << "Operation -\n1] With a matrix\n2] With a complex integer object/real integer\n";
}
int scan_index(){
	int ch;
	instruct(SCAN_INDEX);
	cin >> ch;
	return ch;
}