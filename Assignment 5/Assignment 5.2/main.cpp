/*
 *	Assignment 5.2
 *	IOOM
 *	Submitted by: ABDUL SATTAR MAPARA
 *	https://github.com/abdulsmapara/IOOM
 *	
 *	~$ g++ -o matrix -std=c++14 -Wall -DUSER_INTERFACE Matrix.cpp main.cpp
 *	~$ ./matrix
 *
*/
#include "MatrixLib.hpp"
#define EXIT 0
#define INT 1
#define FLOAT 2
#define LONG 3
#define SET_ELEMENT 1
#define SET_MATRIX 2
#define ADD_SELF 3
#define ADD 4
int main(){

	int row,col;
	#ifndef USER_INTERFACE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int choice;
	int r1,c1;
	
	do{
		cout << "Create a matrix object" << endl;
		cout << "1. for INT\t2.for FLOAT\tAny Other No. for LONG" << endl;
		int internal;
		cin >> internal;
		if(internal == 1){
			//int
			int val;
			cout << "Enter the number of rows" << endl;
			cin >> row;
			cout << "Enter the number of columns" << endl;
			cin >> col;
			try{
				Matrix<int> mat(row,col);
				int temp_2d[MAXROWS][MAXCOLS];
				int temp_2d_[MAXROWS][MAXCOLS];
				cout << "Enter the elements" << endl;
				for (int i = 0; i < row; ++i)
				{
					for(int j=0;j<col;j++){
						cin >> temp_2d[i][j];
					}
				}
				mat.setMatrix(temp_2d);
				cout << "You just entered" << endl;
				mat.printMatrix();
				choice = !EXIT;
				while(choice != EXIT){
					cout << "1] Set Element \n2] Set Matrix\n3] Add a matrix with it\n4] Add two matrices and assign the result to current matrix\n0] EXIT\n";
					cout << "Enter your choice" << endl;
					cin >> choice;

					switch(choice){

						case SET_ELEMENT:
								try{
									cout << "Enter row, column and the new value" << endl;
									cin >> r1 >> c1 >> val;
									mat.setElement(r1,c1,val);
									cout << "The updated matrix is" << endl;
									mat.printMatrix();

								}catch(std::bad_alloc& e){
									cout << "Exception: " << e.what() << endl << "Possible cause: " << "Memory insufficient" << endl;
								}catch(std::bad_function_call& e){
									cout << "Exception: " << e.what() << endl << "Possible cause: " << "Error in function arguments" << endl; 

								}catch(...){
									cout << "Exception" << endl;

								}
								break;
						case SET_MATRIX:
								row = mat.getRows();
								col = mat.getCols();
								cout << "Enter the elements" << endl;
								for (int i = 0; i < row; ++i)
								{
									for(int j=0;j<col;j++){
										cin >> temp_2d[i][j];
									}
								}
								mat.setMatrix(temp_2d);
								cout << "Updated matrix" << endl;
								mat.printMatrix();
								break;
						case ADD_SELF:
								row = mat.getRows();
								col = mat.getCols();
								cout << "Enter the elements" << endl;
								for (int i = 0; i < row; ++i)
								{
									for(int j=0;j<col;j++){
										cin >> temp_2d[i][j];
									}
								}
								mat.addMatrix(temp_2d);

								cout << "Updated matrix" << endl;
								mat.printMatrix();

								break;
						case ADD:
								row = mat.getRows();
								col = mat.getCols();
								cout << "Enter the elements of 1st matrix" << endl;
								for (int i = 0; i < row; ++i)
								{
									for(int j=0;j<col;j++){
										cin >> temp_2d[i][j];
									}
								}
								cout << "Enter the elements of 2nd matrix" << endl;
								for (int i = 0; i < row; ++i)
								{
									for(int j=0;j<col;j++){
										cin >> temp_2d_[i][j];
									}
								}
								mat.addMatrix(temp_2d,temp_2d_);

								cout << "Updated matrix" << endl;
								mat.printMatrix();
								break;
						default:
								cout << "Enter a valid choice" << endl;
					}
				}

			}catch(std::bad_alloc& e){
				cout << "Exception: " << e.what() << endl << "Possible cause: " << "Memory insufficient" << endl;
			}catch(std::bad_function_call& e){
				cout << "Exception: " << e.what() << endl << "Possible cause: " << "Error in function arguments" << endl; 

			}catch(...){
				cout << "Exception" << endl;

			}

		}else if(internal == 2){
			//float
			float val;
			cout << "Enter the number of rows" << endl;
			cin >> row;
			cout << "Enter the number of columns" << endl;
			cin >> col;
			try{
				Matrix<float> mat(row,col);
				float temp_2d[MAXROWS][MAXCOLS];
				float temp_2d_[MAXROWS][MAXCOLS];
				cout << "Enter the elements" << endl;
				for (int i = 0; i < row; ++i)
				{
					for(int j=0;j<col;j++){
						cin >> temp_2d[i][j];
					}
				}
				mat.setMatrix(temp_2d);
				cout << "You just entered" << endl;
				mat.printMatrix();
				choice = !EXIT;
				while(choice != EXIT){
					cout << "1] Set Element \n2] Set Matrix\n3] Add a matrix with it\n4] Add two matrices and assign the result to current matrix\n0] EXIT\n";
					cout << "Enter your choice" << endl;
					cin >> choice;

					switch(choice){

						case SET_ELEMENT:
								try{
									cout << "Enter row, column and the new value" << endl;
									cin >> r1 >> c1 >> val;
									mat.setElement(r1,c1,val);
									cout << "The updated matrix is" << endl;
									mat.printMatrix();

								}catch(std::bad_alloc& e){
									cout << "Exception: " << e.what() << endl << "Possible cause: " << "Memory insufficient" << endl;
								}catch(std::bad_function_call& e){
									cout << "Exception: " << e.what() << endl << "Possible cause: " << "Error in function arguments" << endl; 

								}catch(...){
									cout << "Exception" << endl;

								}
								break;
						case SET_MATRIX:
								row = mat.getRows();
								col = mat.getCols();
								cout << "Enter the elements" << endl;
								for (int i = 0; i < row; ++i)
								{
									for(int j=0;j<col;j++){
										cin >> temp_2d[i][j];
									}
								}
								mat.setMatrix(temp_2d);
								cout << "Updated matrix" << endl;
								mat.printMatrix();
								break;
						case ADD_SELF:
								row = mat.getRows();
								col = mat.getCols();
								cout << "Enter the elements" << endl;
								for (int i = 0; i < row; ++i)
								{
									for(int j=0;j<col;j++){
										cin >> temp_2d[i][j];
									}
								}
								mat.addMatrix(temp_2d);

								cout << "Updated matrix" << endl;
								mat.printMatrix();

								break;
						case ADD:
								row = mat.getRows();
								col = mat.getCols();
								cout << "Enter the elements of 1st matrix" << endl;
								for (int i = 0; i < row; ++i)
								{
									for(int j=0;j<col;j++){
										cin >> temp_2d[i][j];
									}
								}
								cout << "Enter the elements of 2nd matrix" << endl;
								for (int i = 0; i < row; ++i)
								{
									for(int j=0;j<col;j++){
										cin >> temp_2d_[i][j];
									}
								}
								mat.addMatrix(temp_2d,temp_2d_);

								cout << "Updated matrix" << endl;
								mat.printMatrix();
								break;
						default:
								cout << "Enter a valid choice" << endl;
					}
				}

			}catch(std::bad_alloc& e){
				cout << "Exception: " << e.what() << endl << "Possible cause: " << "Memory insufficient" << endl;
			}catch(std::bad_function_call& e){
				cout << "Exception: " << e.what() << endl << "Possible cause: " << "Error in function arguments" << endl; 

			}catch(...){
				cout << "Exception" << endl;

			}
		}else{	//if(internal == 3)
			//long
			long val;
			cout << "Enter the number of rows" << endl;
			cin >> row;
			cout << "Enter the number of columns" << endl;
			cin >> col;
			try{
				Matrix<long> mat(row,col);
				long temp_2d[MAXROWS][MAXCOLS];
				long temp_2d_[MAXROWS][MAXCOLS];
				cout << "Enter the elements" << endl;
				for (int i = 0; i < row; ++i)
				{
					for(int j=0;j<col;j++){
						cin >> temp_2d[i][j];
					}
				}
				mat.setMatrix(temp_2d);
				cout << "You just entered" << endl;
				mat.printMatrix();
				choice = !EXIT;
				while(choice != EXIT){
					cout << "1] Set Element \n2] Set Matrix\n3] Add a matrix with it\n4] Add two matrices and assign the result to current matrix\n0] EXIT\n";
					cout << "Enter your choice" << endl;
					cin >> choice;

					switch(choice){

						case SET_ELEMENT:
								try{
									cout << "Enter row, column and the new value" << endl;
									cin >> r1 >> c1 >> val;
									mat.setElement(r1,c1,val);
									cout << "The updated matrix is" << endl;
									mat.printMatrix();

								}catch(std::bad_alloc& e){
									cout << "Exception: " << e.what() << endl << "Possible cause: " << "Memory insufficient" << endl;
								}catch(std::bad_function_call& e){
									cout << "Exception: " << e.what() << endl << "Possible cause: " << "Error in function arguments" << endl; 

								}catch(...){
									cout << "Exception" << endl;

								}
								break;
						case SET_MATRIX:
								row = mat.getRows();
								col = mat.getCols();
								cout << "Enter the elements" << endl;
								for (int i = 0; i < row; ++i)
								{
									for(int j=0;j<col;j++){
										cin >> temp_2d[i][j];
									}
								}
								mat.setMatrix(temp_2d);
								cout << "Updated matrix" << endl;
								mat.printMatrix();
								break;
						case ADD_SELF:
								row = mat.getRows();
								col = mat.getCols();
								cout << "Enter the elements" << endl;
								for (int i = 0; i < row; ++i)
								{
									for(int j=0;j<col;j++){
										cin >> temp_2d[i][j];
									}
								}
								mat.addMatrix(temp_2d);

								cout << "Updated matrix" << endl;
								mat.printMatrix();

								break;
						case ADD:
								row = mat.getRows();
								col = mat.getCols();
								cout << "Enter the elements of 1st matrix" << endl;
								for (int i = 0; i < row; ++i)
								{
									for(int j=0;j<col;j++){
										cin >> temp_2d[i][j];
									}
								}
								cout << "Enter the elements of 2nd matrix" << endl;
								for (int i = 0; i < row; ++i)
								{
									for(int j=0;j<col;j++){
										cin >> temp_2d_[i][j];
									}
								}
								mat.addMatrix(temp_2d,temp_2d_);

								cout << "Updated matrix" << endl;
								mat.printMatrix();
								break;
						default:
								cout << "Enter a valid choice" << endl;
					}
				}

			}catch(std::bad_alloc& e){
				cout << "Exception: " << e.what() << endl << "Possible cause: " << "Memory insufficient" << endl;
			}catch(std::bad_function_call& e){
				cout << "Exception: " << e.what() << endl << "Possible cause: " << "Error in function arguments" << endl; 

			}catch(...){
				cout << "Exception" << endl;

			}
		}

	}while(choice != EXIT);



	cout << "Thank You !" << endl;
	return 0;
}