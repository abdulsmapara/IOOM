#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED
#include "ComplexInteger.hpp"

class Matrix
{
private:
	int rows,columns;
	ComplexInteger** matrix;
public:
	//constructors
	Matrix();
	Matrix(int n_rows,int n_cols);
	Matrix(int n_rows,int n_cols,ComplexInteger init);

	//copy constructor
	Matrix(const Matrix& mat);

	//setter methods
	void setMatrix(int row_index,int col_index,const ComplexInteger& complex);

	//getter methods
	const ComplexInteger& getMatrix(int row_index,int col_index) const;
	//operator overloading
	//addition and subtraction
	friend const Matrix operator+(const Matrix& mat,const ComplexInteger& complex);
	friend const Matrix operator+(const Matrix& mat,const int real_part);
	friend const Matrix operator+(const ComplexInteger& complex,const Matrix& mat);
	friend const Matrix operator+(const int real_part,const Matrix& mat);
	const Matrix operator+(const Matrix& mat) const;
	friend const Matrix operator-(const Matrix& mat,const ComplexInteger& complex);
	friend const Matrix operator-(const Matrix& mat,const int real_part);
	friend const Matrix operator-(const ComplexInteger& complex,const Matrix& mat);
	friend const Matrix operator-(const int real_part,const Matrix& mat);
	const Matrix operator-(const Matrix& mat) const;
	friend const Matrix operator*(const Matrix& mat,const ComplexInteger& complex);
	friend const Matrix operator*(const Matrix& mat,const int real_part);
	friend const Matrix operator*(const ComplexInteger& complex,const Matrix& mat);
	friend const Matrix operator*(const int real_part,const Matrix& mat);
	const Matrix operator*(const Matrix& mat) const;
	//^ operator defined as -it Replaces the element at the specified no. from the beginning in natural counting order with 0+0i. (if it exists)
	friend const Matrix& operator^(const Matrix& mat,const int num);
	//above method is made global because it should work with matrix^7 as well as 7^matrix
	friend const Matrix& operator^(const int num,const Matrix& mat);

	//Assignment operator-Assigns a Matrix Object to another Matrix reference (when called with 2 Matrix objects)
	Matrix& operator=(const Matrix& mat);
	//Assignment operator
	//Creates a fresh List from a 2D array of ComplexInteger Objects. (when called from a matrix object and passed a 2D array of objects). 
	//friend functions
	Matrix& operator=(ComplexInteger arr[1000][1000]);
	friend void displayMatrix(const Matrix& mat);
	friend bool searchMatrix(const Matrix& mat,ComplexInteger complex);



	friend ostream& operator<<(ostream& out,const Matrix& mat);
	friend istream& operator>>(istream& in,Matrix& mat);

	//destructor
	~Matrix();
	
};
#endif