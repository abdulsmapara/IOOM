#include "Matrix.hpp"
#include "defines.hpp"


#define TEST
Matrix::Matrix():rows(0),columns(0){
	matrix = NULL;
}
Matrix::Matrix(int n_rows,int n_cols):rows(n_rows),columns(n_cols){
	matrix = new ComplexInteger*[n_rows];
	for(int i=0;i < n_rows ;i++){
			matrix[i] = new ComplexInteger[n_cols];
	}
}

//setter methods
//getter methods

Matrix::Matrix(int n_rows,int n_cols,ComplexInteger init):rows(n_rows),columns(n_cols)
{
	matrix = new ComplexInteger*[n_rows];
	for(int i=0;i < n_rows ;i++){
			matrix[i] = new ComplexInteger[n_cols];
			for(int j=0;j<n_cols;j++){
				matrix[i][j] = init;
			}
	}
}
Matrix::Matrix(const Matrix& mat)
{
	//matrix is this->matrix
	rows = mat.rows;
	columns = mat.columns;
	matrix = new ComplexInteger*[rows];
	for(int i = 0; i < rows ; i++){
		matrix[i] = new ComplexInteger[columns];
		for(int j = 0; j < columns;j++){
			matrix[i][j] = mat.matrix[i][j];
		}
	}
}
const Matrix Matrix::operator+(const Matrix& mat) const
{
	if(this->rows != mat.rows or this->columns != mat.columns)
	{
		throw "Illegal Add operation";
	}
	Matrix n_matrix(rows,columns); 
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			n_matrix.matrix[i][j] = matrix[i][j] + mat.matrix[i][j];
		}
	}
	return n_matrix;
}
const Matrix Matrix::operator-(const Matrix& mat) const
{

	if(this->rows != mat.rows or this->columns != mat.columns)
	{
		throw "Illegal Subtract operation";
	}
	Matrix n_matrix(rows,columns); 
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			n_matrix.matrix[i][j] = matrix[i][j] - mat.matrix[i][j];
		}
	}
	return n_matrix;
}
const Matrix Matrix::operator*(const Matrix& mat) const
{
	//multiplication of matrices
	if(this->columns != mat.rows)
	{
		throw "Illegal Multiplication operation";
	}
	ComplexInteger nil(0,0);
	Matrix n_matrix(rows,mat.columns,nil);
	for(int i=0;i < rows;i++)
	{
		for(int j = 0;j < mat.columns;j++)
		{
			n_matrix.matrix[i][j] = ComplexInteger();
			for(int k = 0;k < columns;k++)
			{
				//replace by +=
				n_matrix.matrix[i][j] = n_matrix.matrix[i][j] + matrix[i][k]*mat.matrix[k][j];
			}
		}
		
	}
	return n_matrix;
}
Matrix::~Matrix()
{
	for(int i=0;i<rows;i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
Matrix& Matrix::operator=(const Matrix& mat)
{
	this->~Matrix();
	//take care of pointers
	#ifdef TEST
	cout << "Operator= called"<<endl;
	#endif
	if(this != &mat){
		rows = mat.rows;
		columns = mat.columns;
		matrix = new ComplexInteger*[rows];
		for(int i=0;i < rows ;i++){
				matrix[i] = new ComplexInteger[columns];
				for(int j=0;j<columns;j++){
					matrix[i][j] = mat.matrix[i][j];
				}
		}
	}
	return *this;	
}
Matrix& Matrix::operator=(ComplexInteger complex_no[][COLS])
{	
	if(complex_no == NULL)
	{
		throw "Null Pointer Exception";
	}
	else
	{
		int trow,tcol;
		cin >> trow >> tcol;
		for (int i = 0; i < trow; ++i)
		{
					
			for(int j = 0;j < tcol;j++)
			{
				ComplexInteger val;
				cin >> val;
				complex_no[i][j]=(val);
			}
		}
		int n_rows=trow;//arr.size()+1;
		int n_cols = tcol;//arr[0].size()+1;
		rows = n_rows;
		columns=n_cols;
		matrix = new ComplexInteger*[rows];
		for(int i=0;i < rows ;i++){
				matrix[i] = new ComplexInteger[columns];
				for(int j=0;j<columns;j++){
					try{
						matrix[i][j] = complex_no[i][j];
					}catch(...){
						throw "Null Pointer Exception";
					}
				}
		}
		return *this;
	}
}

const ComplexInteger& Matrix::getMatrix(int row_index,int col_index) const
{
	if(row_index < 0 or col_index < 0 or row_index >= rows or col_index >= columns)
		throw "Invalid index exception";
	else{
		return this->matrix[row_index][col_index];
	}
}
//setter
void Matrix::setMatrix(int row_index,int col_index,const ComplexInteger& complex){

	if(row_index < 0 or col_index < 0 or row_index >= rows or col_index >= columns)
		throw "Invalid index exception";
	else
	{
		this->matrix[row_index][col_index] = complex;
	}	
}
