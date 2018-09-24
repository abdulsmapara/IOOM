#include "Matrix_vec.hpp"


Matrix::Matrix():rows(0),cols(0){}
Matrix::Matrix(size_t n_rows,size_t n_cols):rows(n_rows),cols(n_cols){}
Matrix::Matrix(size_t n_rows,size_t n_cols,ComplexInteger init):rows(n_rows),cols(n_cols)
{
	for(int i = 0;i < rows;i++)
	{
		matrix.push_back(std::vector<ComplexInteger>() );
		for (int j = 0;j < cols; ++j)
		{
			matrix[i].push_back(init);
		}
	}
}

