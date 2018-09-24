#include "Matrix.hpp"
#include "util.hpp"
#include "defines.hpp"
//g++ -std=c++14 -o a ComplexInteger.cpp Matrix.cpp functions.cpp util.cpp main.cpp
signed main(){
	int choice,internal_choice,s_index;
	int trow,tcol;
	ComplexInteger complex2,val;
	Matrix matrix2,ans;
	Matrix matrix_center = scan_matrix();
	#ifdef USER_INTERFACE
		cout << "You just entered\n";
	#endif
	displayMatrix(matrix_center);
	//vector<vector<ComplexInteger> > complex_no;
	ComplexInteger complex_no[ROWS][COLS];
	do{
		displayMenu();
		choice=scan_choice();
		switch(choice){

			case ADD:
					internal_menu();
					internal_choice = scan_choice();
					switch(internal_choice)
					{
						case COMPLEX:
										complex2 = scan_complex();
										try{
											ans= matrix_center + complex2;
											displayMatrix(ans);
										}catch(const char* exception){
												if(exception != NULL){
													#ifdef USER_INTERFACE
														cout << "Exception: "<<exception << endl;
													#endif
												}
										}
										break;
						case MATRIX:
										matrix2 = scan_matrix();
										try{
											ans = matrix_center + matrix2;
											displayMatrix(ans);
										}catch(const char* exception){
												if(exception != NULL){
													#ifdef USER_INTERFACE
														cout << "Exception: "<<exception << endl;
													#endif
												}
										}
										break;

						default:
										#ifdef USER_INTERFACE
											cout << "Invalid choice\n";
										#endif
										break;
					}
					break;	
			case SUBTRACT:
					internal_menu();
					internal_choice = scan_choice();
					switch(internal_choice)
					{
						case COMPLEX:
										complex2 = scan_complex();
										try{
											ans= matrix_center - complex2;
											displayMatrix(ans);
										}catch(const char* exception){
												if(exception != NULL){
													#ifdef USER_INTERFACE
														cout << "Exception: "<<exception << endl;
													#endif
												}
										}
										break;
						case MATRIX:
										matrix2 = scan_matrix();
										try{
											ans = matrix_center - matrix2;
											displayMatrix(ans);
										}catch(const char* exception){
												if(exception != NULL){
													#ifdef USER_INTERFACE
														cout << "Exception: "<<exception << endl;
													#endif
												}
										}
										break;
										
						default:
										#ifdef USER_INTERFACE
											cout << "Invalid choice\n";
										#endif
										break;
					}
					break;	

			case REPLACE:
					try{
						s_index = scan_index();
						matrix_center^s_index;
						displayMatrix(matrix_center);
					}catch(const char* exception){
						if(exception != NULL){
							#ifdef USER_INTERFACE
								cout << "Exception: "<<exception << endl;
							#endif
						}	
					}
					break;
			
			case MULTIPLY:
					internal_menu();
					internal_choice = scan_choice();
					switch(internal_choice)
					{
						case COMPLEX:
										complex2 = scan_complex();
										try{
											ans= matrix_center * complex2;
											displayMatrix(ans);
										}catch(const char* exception){
												if(exception != NULL){
													#ifdef USER_INTERFACE
														cout << "Exception: "<<exception << endl;
													#endif
												}
										}
										break;
						case MATRIX:
										matrix2 = scan_matrix();
										try{
											ans = matrix_center * matrix2;
											displayMatrix(ans);
										}catch(const char* exception){
												if(exception != NULL){
													#ifdef USER_INTERFACE
														cout << "Exception: "<<exception << endl;
													#endif
												}
										}
										break;
										
						default:
										#ifdef USER_INTERFACE
											cout << "Invalid choice\n";
										#endif
										break;
					}
					break;				
			case DISPLAY:
					displayMatrix(matrix_center);
					break;
			case ASSIGN_MATRIX:
					matrix2 = matrix_center;//Assignment operator
					displayMatrix(matrix2);
					break;
			case ASSIGN_COMPLEX:
					#ifdef USER_INTERFACE
						cout << "Enter the number of rows, columns and then the values of 2d-array in row-major form\n";
					#endif
					
					#ifdef USER_INTERFACE
						cout << "Assigned to other matrix and not the one on which all other operations are also performed\n";
					#endif
					matrix2 = complex_no;
					displayMatrix(matrix2);
					break;
			case SEARCH:
					
					complex2 = scan_complex();
					if(searchMatrix(matrix_center,complex2)){
						#ifdef USER_INTERFACE
							cout << "FOUND\n";
						#endif
					}else{
						#ifdef USER_INTERFACE
							cout << "NOT FOUND\n";
						#endif
					}
					break;
			case EXIT:
					#ifdef USER_INTERFACE
						cout << "Thank You!" << endl;
					#endif
					break;
			default:
					#ifdef USER_INTERFACE
						cout << "Invalid choice" << endl;
					#endif
					break;


		}

	} while(choice != EXIT);	

	

	//===============
	//DOUBT BEGINS
	//==============
	/*vector<vector<ComplexInteger> > complex_no;
	for(int i=0;i<2;i++)
	{
		complex_no.push_back(vector<ComplexInteger>());
		for (int j=0;j<3; ++j)
		{
			ComplexInteger c(10,20);
			complex_no[i].push_back(c);
		}
	}

	ne = complex_no;
	displayMatrix(ne);*/

	return 0;
}