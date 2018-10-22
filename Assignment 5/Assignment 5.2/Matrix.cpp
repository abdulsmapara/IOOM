#include "Matrix.hpp"
#define TEMPLATE template <class T>

TEMPLATE
Matrix<T>::Matrix(){

	rows = cols = 0;

}

TEMPLATE
Matrix<T>::Matrix(int size){
	if(size < 0){
		throw bad_function_call();	//bad call to function
	}else if(size >= MAXROWS or size >= MAXCOLS){
		throw bad_alloc();	//failed to allocate memory

	}else{
		this->rows = this->cols = size;
		for (int i = 0; i < rows; ++i)
		{
			for(int j = 0; j < cols; ++j){
				doubleArray[i][j] = 0;
			}
		}
	}
}
TEMPLATE
Matrix<T>::Matrix(int n_rows,int n_cols){
	if(n_rows < 0 or n_cols < 0){
		throw bad_function_call();
	}
	else if(n_rows >= MAXROWS or n_cols >= MAXCOLS){
		throw bad_alloc();
	}
	else{
		this->rows = n_rows;
		this->cols = n_cols;
		for (int i = 0; i < rows; ++i)
		{
			for(int j = 0;j<cols;j++){
				doubleArray[i][j]= 0;
			}
		}
	}
}
TEMPLATE
Matrix<T>::Matrix(const Matrix& matrix){
	//copy constructor
	rows = matrix.rows;
	cols = matrix.cols;
	for (int i = 0; i < rows; ++i)
	{
		for(int j=0;j<cols;j++){
			doubleArray[i][j] = matrix.doubleArray[i][j];
		}
	}
}
TEMPLATE
void Matrix<T>::printMatrix() const{
	for (int i = 0; i < rows; ++i)
	{
		for(int j=0;j<cols;++j){
			cout << doubleArray[i][j] << " ";
		}
		cout << endl;
	}
}
TEMPLATE
void Matrix<T>::setElement(int row,int col,T value){//set an element of the matrix
	if(row <= 0 or col <= 0 or row > rows or col > cols){
		throw  bad_function_call();
	}else{
		doubleArray[row-1][col-1] = value;
	}
}
TEMPLATE
void Matrix<T>::setMatrix(T mat1[MAXROWS][MAXCOLS]){
	//set the double array to what is sent


	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			doubleArray[i][j] = mat1[i][j];
		}
	}

}
TEMPLATE
void Matrix<T>::addMatrix(T mat1[MAXROWS][MAXCOLS]){
	

		// add an array to double array
		for(int i=0; i<rows;i++){
			for(int j=0;j<cols;j++){
				doubleArray[i][j] += mat1[i][j];
			}
		}
	
}
TEMPLATE
void Matrix<T>::addMatrix(T mat1[][MAXCOLS],T mat2[][MAXCOLS]){
		
	// add an array to double array
	

	for(int i=0; i<rows;i++){
		for(int j=0;j<cols;j++){
			doubleArray[i][j] = (mat1[i][j]+mat2[i][j]);
		}
	}
	
	
}
TEMPLATE
int Matrix<T>::getRows() const{
	return rows;
}

TEMPLATE
int Matrix<T>::getCols() const{
	return cols;
}
TEMPLATE
Matrix<T>::~Matrix(){
	cout << endl << "Destructing matrix" << endl << endl;
}
