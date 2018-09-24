#include "ComplexInteger.hpp"
#include "Matrix.hpp"

//function to display the contents of the object of ComplexInteger
void displayComplex(const ComplexInteger& complex)
{
	cout << complex ;
}

ostream& operator<<(ostream& out,const ComplexInteger& complex)
{
	out << complex.real << " + " << complex.imaginary << "i";
	return out;
}
istream& operator>>(istream& in,ComplexInteger& complex)
{
	in >> complex.real;
	in >> complex.imaginary;
	return in;
}

void displayMatrix(const Matrix& mat)
{
	if(mat.matrix == NULL){
		throw "Null Pointer Exception";
	}
	
	for(int i=0;i< mat.rows;i++){

		for(int j=0;j<mat.columns;j++){
			cout << mat.matrix[i][j] << " ";
		}
		cout << endl;
	}
}
bool searchMatrix(const Matrix& mat,ComplexInteger complex)
{
	if(mat.matrix == NULL){
		throw "Null Pointer Exception";
	}
	bool found = false;
	for(int i=0;i< mat.rows and !found;i++){

		for(int j=0;j<mat.columns and !found ;j++){
			if(mat.matrix[i][j] == complex){
				found=true;
			}
		}
	}
	return found;
}
const Matrix operator+(const Matrix& mat,const ComplexInteger& complex)
{
	Matrix n_matrix(mat.rows,mat.columns); 
	for(int i=0;i<mat.rows;i++)
	{
		for(int j=0;j<mat.columns;j++)
		{
			n_matrix.matrix[i][j] = mat.matrix[i][j] + complex;
		}
	}
	return n_matrix;
}
const Matrix operator+(const ComplexInteger& complex,const Matrix& mat){ return mat+complex; }

const Matrix operator+(const Matrix& mat,const int real_part)
{
	ComplexInteger complex(real_part,0);
	Matrix n_matrix(mat.rows,mat.columns); 
	n_matrix = mat + complex;
	return n_matrix;
}
const Matrix operator+(const int real_part,const Matrix& mat){ return mat+real_part; }
const Matrix operator-(const Matrix& mat,const ComplexInteger& complex)
{
	Matrix n_matrix(mat.rows,mat.columns); 
	for(int i=0;i<mat.rows;i++)
	{
		for(int j=0;j<mat.columns;j++)
		{
			n_matrix.matrix[i][j] = mat.matrix[i][j] - complex;
		}
	}
	return n_matrix;
}
const Matrix operator-(const ComplexInteger& complex,const Matrix& mat){ return mat-complex; }

const Matrix operator-(const Matrix& mat,const int real_part){
	ComplexInteger complex(real_part,0);
	Matrix n_matrix(mat.rows,mat.columns); 
	for(int i=0;i<mat.rows;i++)
	{
		for(int j=0;j<mat.columns;j++)
		{
			n_matrix.matrix[i][j] = mat.matrix[i][j] - complex;
		}
	}
	return n_matrix;
}
const Matrix operator-(const int real_part,const Matrix& mat){ return mat-real_part; }
const Matrix operator*(const Matrix& mat,const ComplexInteger& complex)
{
	Matrix n_matrix(mat.rows,mat.columns); 
	for(int i=0;i<mat.rows;i++)
	{
		for(int j=0;j<mat.columns;j++)
		{
			n_matrix.matrix[i][j] = mat.matrix[i][j] * complex;
		}
	}
	return n_matrix;
}
const Matrix operator*(const ComplexInteger& complex,const Matrix& mat){ return mat*complex; }

const Matrix operator*(const Matrix& mat,const int real_part)
{
	ComplexInteger complex(real_part,0);
	Matrix n_matrix(mat.rows,mat.columns); 
	for(int i=0;i<mat.rows;i++)
	{
		for(int j=0;j<mat.columns;j++)
		{
			n_matrix.matrix[i][j] = mat.matrix[i][j] * complex;
		}
	}
	return n_matrix;
}
const Matrix operator*(const int real_part,const Matrix& mat){ return mat*real_part; }
const Matrix& operator^(const Matrix& mat,const int num)
{
	int index_ = num-1;
	if(mat.rows == 0 or mat.columns ==0)
	{
		throw "Empty matrix Exception";
	}
	if(num > (mat.rows)*(mat.columns))
	{
		throw "Out of Bounds Exception";
	}
	int num_rows=mat.rows;
	int num_columns=mat.columns;
	int row_number = (index_/num_columns);
	int col_number = (index_%num_columns);
	ComplexInteger nil(0,0);
	try{
		if(row_number>=0 and col_number>=0 and row_number<num_rows and col_number<num_columns)
			mat.matrix[row_number][col_number] = nil;
		else
			throw "Error in input value";
	}catch(...){
		throw "Error in input value";
	}
	return mat;
}
const Matrix& operator^(const int num,const Matrix& mat)
{
	return mat^num;
}

ostream& operator<<(ostream& out,const Matrix& mat){
	for (int i = 0; i < mat.rows; ++i)
	{
		for(int j=0;j<mat.columns;++j)
		{
			out << mat.matrix[i][j]<<" ";
		}
		out << endl;
	}
	return out;
}
istream& operator>>(istream& in,Matrix& mat)
{
	in >> mat.rows >> mat.columns;
	for (int i = 0; i < mat.rows; ++i)
	{
		for (int j=0;j < mat.columns; ++j)
		{
			in >> mat.matrix[i][j];
		}
	}
	return in;
}