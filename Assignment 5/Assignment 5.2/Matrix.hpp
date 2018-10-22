#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <new>
using namespace std;
#define MAXCOLS 100
#define MAXROWS 100

template <class T>
class Matrix
{
private:
	T doubleArray[MAXROWS][MAXCOLS];
	int rows;
	int cols;
public:
	Matrix();
	Matrix(int size);
	Matrix(int n_rows,int n_cols);
	Matrix(const Matrix& matrix);

	int getRows() const;
	int getCols() const;
	
	void printMatrix() const;
	void setElement(int row,int col,T value);//set an element of the matrix
	void setMatrix(T mat1[][MAXCOLS]);//set the double array to what is sent
	void addMatrix(T mat1[][MAXCOLS]);
	void addMatrix(T mat1[][MAXCOLS],T mat2[][MAXCOLS]);
	~Matrix();
	
};





#endif