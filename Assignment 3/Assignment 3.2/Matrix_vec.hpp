#include "ComplexInteger.hpp"

class Matrix
{
private:
	size_t rows,columns;
	std::vector<std::vector<ComplexInteger> > matrix;
public:
	//constructors
	Matrix();
	Matrix(size_t n_rows,size_t n_cols);
	Matrix(size_t n_rows,size_t n_cols,ComplexInteger init);

	//copy constructor
	Matrix(const Matrix& matrix);

	

	//destructor
	~Matrix();
	
};