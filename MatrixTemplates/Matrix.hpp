#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Complex.h"
#include <thread>
#include <stdexcept>
#define DEAFULT_MATRIX_VALUE 1




#define DIM_EQUAL_ERROR "The Matrces should be with same dimensions"
#define MUL_ERROR "The Matrices has not fit dimensions."
#define BORDERS_ERROR "Outoff bound matrix"
#define SQU_ERROR "Matrix should be squared"
#define UNLOGICAL_DIMESNSIONS "Matrix dimensions of Rows/Cols cannot be " << \
 "set one to 0 and the other positive"
#define PARALLEL_MESSAGE(parallelMode) "Generic Matrix mode changed to " << parallelMode << " mode."
#define PARALLEL "parallel"
#define NON_PARALLEL "non-parallel"
#define CTOR_ARGUMENTS_ERROR "The arguments supplied to ctor are invalid"


template<class T>
/*******************************************************************************************//**
 *
 * @brief	The Matrix Class
 *
 * @author	Refi 950
 * @date	9/9/2015
 *
 **********************************************************************************************/
class Matrix
{
public:

	static bool s_isParallel;

	//-------------------Constructors---------------------------------------------

	/*******************************************************************************************//**
	 * @fn	Matrix::Matrix()
	 *
	 * @brief	Default constructor. initialize the matrix with deafult values.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 **********************************************************************************************/

	Matrix() : Matrix<T>(DEAFULT_MATRIX_VALUE, DEAFULT_MATRIX_VALUE) {}





	/*******************************************************************************************//**
	 * @fn	Matrix::Matrix(unsigned int row, unsigned int col) 
	 *      try : Matrix<T>(row, col, std::vector<T>(row * col))
	 *
	 * @brief	Constructor. create matrix with The rows and cols we got as input.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param	row	The row.
	 * @param	col	The col.
	 **********************************************************************************************/

	Matrix(unsigned int row, unsigned int col) : Matrix<T>(row, col,
		std::vector<T>(row * col))
	{}


	/*******************************************************************************************//**
	 * @fn	Matrix::Matrix(unsigned int row, unsigned int col, const std::vector<T> &matrix)
	 *
	 * @brief	Constructor. constructor for rows and cols which gets a full vector
	 * 			of matrix and initialize it. This consturctor is the base constructor
	 * 			for all other constructors.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param	row   	The row.
	 * @param	col   	The col.
	 * @param	matrix	The matrix.
	 *********************************************************************************************/

	Matrix(unsigned int row, unsigned int col, const std::vector<T>& matrix)
	{
		if(!_constructorArgumentsChecker(row, col, matrix))
		{
			throw std::invalid_argument(CTOR_ARGUMENTS_ERROR);
		}


		_matrixRow = row;
		_matrixCol = col;
		_matrix = matrix;



	}

	/*******************************************************************************************//**
	 * @fn	Matrix::Matrix<T>(const Matrix<T> &matrixCopy)
	 *
	 * @brief	Constructor.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @tparam	T	Generic type parameter.
	 * @param	matrixCopy	The matrix copy.
	 **********************************************************************************************/

	Matrix<T>(const Matrix<T> &matrixCopy) : Matrix<T>(matrixCopy._matrixRow,
		matrixCopy._matrixCol, matrixCopy._matrix) 
	{
	}

	/*******************************************************************************************//**
	 * @fn	Matrix::Matrix(Matrix<T>&& moveMatrix) 
	 *: _matrixRow(std::move(moveMatrix._matrixRow)),
	 * _matrixCol(std::move(moveMatrix._matrixCol)), _matrix(std::move(moveMatrix._matrix))
	 *
	 * @brief	Constructor.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param [in,out]	moveMatrix	The move matrix.
	 **********************************************************************************************/

	Matrix(Matrix<T> && moveMatrix) : _matrixRow(std::move(moveMatrix._matrixRow)),
		_matrixCol(std::move(moveMatrix._matrixCol)),
		_matrix(std::move(moveMatrix._matrix))
	{}

	/*******************************************************************************************//**
	 * @fn	Matrix::~Matrix()
	 *
	 * @brief	Destructor.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 **********************************************************************************************/

	~Matrix()
	{}

	//-------------------Constructors---------------------------------------------

	/*******************************************************************************************//**
	 * @fn	T& Matrix::operator()(unsigned int row, unsigned int col)
	 *
	 * @brief	Function call operator. matrix values can be modified by it.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param	row	The row.
	 * @param	col	The col.
	 *
	 * @return	The result of the operation.
	 **********************************************************************************************/

	T& operator()(unsigned int row, unsigned int col)
	{
		if (row > _matrixRow || col > _matrixCol)
		{
			throw std::invalid_argument(BORDERS_ERROR);
		}
		return _matrix.at(row * _matrixCol + col);
	}

	/*******************************************************************************************//**
	 * @fn	const T& Matrix::operator()(unsigned int row, unsigned int col) const
	 *
	 * @brief	Function call operator. Doesn't allows to modify matrix values.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param	row	The row.
	 * @param	col	The col.
	 *
	 * @return	The result of the operation.
	 **********************************************************************************************/

	const T& operator()(unsigned int row, unsigned int col) const
	{
		if (row > _matrixRow || col > _matrixCol)
		{
			throw std::invalid_argument(BORDERS_ERROR);
		}
		return _matrix.at(row * _matrixCol + col);
	}

	/*******************************************************************************************//**
	 * @fn	friend void Matrix::swap(Matrix<T>& swapA, Matrix<T>& swapB)
	 *
	 * @brief	Swaps. overloading swap for matrix.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param [in,out]	swapA	The swap a.
	 * @param [in,out]	swapB	The swap b.
	 **********************************************************************************************/

	friend void swap(Matrix<T>& swapA, Matrix<T>& swapB)
	{
		std::swap(swapA._matrixRow, swapB._matrixRow);
		std::swap(swapA._matrixCol, swapB._matrixCol);
		std::swap(swapA._matrix, swapB._matrix);
	}

	/*******************************************************************************************//**
	 * @fn	Matrix<T>& Matrix::operator=(Matrix rhs)
	 *
	 * @brief	Assignment operator. fit to move and to copy according to the lectures instructions.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param	rhs	The right hand side.
	 *
	 * @return	A shallow copy of this object.
	 **********************************************************************************************/

	Matrix<T>& operator=(Matrix rhs)
	{
		swap(*this, rhs);

		return *this;
	}



	



	/*******************************************************************************************//**
	 * @fn	Matrix<T> Matrix::operator+(const Matrix<T>& rhs) const
	 *
	 * @brief	Addition operator. can be seq or multithreaded.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param	rhs	The right hand side.
	 *
	 * @return	The result of the operation.
	 **********************************************************************************************/

	Matrix<T> operator+(const Matrix<T>& rhs) const
	{
		if (!this->_dimEqualCheck(rhs))
		{
			throw std::invalid_argument(DIM_EQUAL_ERROR);
		}


		Matrix newMatrix(rhs);
		if (s_isParallel)
		{
			std::vector<std::thread> addThreads(_matrixRow);
			for (unsigned int i = 0; i < _matrixRow; i++)
			{

				addThreads[i] = std::thread(&Matrix<T>::_addDaemonFunc, this,
				                            std::ref(newMatrix), i);

			}

			for (unsigned int i = 0; i < _matrixRow; i++)
			{
				((addThreads).at(i)).join();
			}


		}
		else
		{


			for (unsigned int i = 0; i < _matrixCol*_matrixRow; i++)
			{
				newMatrix._matrix[i] += this->_matrix[i];
			}


		}


		return newMatrix;

	}

	/*******************************************************************************************//**
	 * @fn	const Matrix<T> Matrix::operator-(const Matrix<T>& rhs)
	 * const throw (std::invalid_argument)
	 *
	 * @brief	Subtraction operator.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @exception	std::invalid_argument	Thrown when an invalid argument error condition occurs.
	 *
	 * @param	rhs	The right hand side.
	 *
	 * @return	The result of the operation.
	 *********************************************************************************************/

	const Matrix<T> operator-(const Matrix<T>& rhs) const throw (std::invalid_argument)
	{
		if (!this->_dimEqualCheck(rhs))
		{
			throw std::invalid_argument(DIM_EQUAL_ERROR);
		}

		Matrix newMatrix(rhs._matrixRow, rhs._matrixCol);
		//Same as add.
		for (unsigned int i = 0; i < _matrixCol*_matrixRow; i++)
		{
			newMatrix._matrix[i] = this->_matrix[i] - rhs._matrix[i];
		}
		return newMatrix;
	}




	/*******************************************************************************************//**
	 * @fn	const Matrix<T> Matrix::operator*(const Matrix<T>& rhs) const
	 *
	 * @brief	Multiplication operator. Again implements a seq and parallel calculations.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param	rhs	The right hand side.
	 *
	 * @return	The result of the operation.
	 **********************************************************************************************/

	const Matrix<T> operator*(const Matrix<T>& rhs) const
	{

		if (!this->_checkDimMul(rhs))
		{

			throw std::invalid_argument(MUL_ERROR);

		}

		Matrix newMatrix(this->_matrixRow, rhs._matrixCol);

		if (s_isParallel)
		{

			std::vector<std::thread> mulThreads(_matrixRow);
			for (unsigned int i = 0; i < _matrixRow; i++)
			{

				mulThreads[i] = std::thread(&Matrix<T>::_mulDaemonFunc, this,
				 							std::ref(newMatrix), std::ref(rhs), i);

			}

			for (unsigned int i = 0; i < _matrixRow; i++)
			{
				((mulThreads).at(i)).join();
			}


		}

		else
		{
		
			for (unsigned int i = 0; i < _matrixRow; i++)
			{
				_mulDaemonFunc(std::ref(newMatrix), std::ref(rhs), i);

			}

		}

		return newMatrix;
	}

	/*******************************************************************************************//**
	 * @fn	bool Matrix::operator==(const Matrix<T>& rhs) const
	 *
	 * @brief	Equality operator. using the != operator.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param	rhs	The right hand side.
	 *
	 * @return	true if the parameters are considered equivalent.
	 **********************************************************************************************/

	bool operator==(const Matrix<T>& rhs) const
	{
		return !(*this != rhs);
	}

	/*******************************************************************************************//**
	 * @fn	bool Matrix::operator!=(const Matrix<T>& rhs) const
	 *
	 * @brief	Inequality operator.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param	rhs	The right hand side.
	 *
	 * @return	true if the parameters are not considered equivalent.
	 **********************************************************************************************/

	bool operator!=(const Matrix<T>& rhs) const
	{
		if (!this->_dimEqualCheck(rhs))
		{
			return true;
		}

		for (unsigned int i = 0; i < _matrixCol*_matrixRow; i++)
		{
			if (_matrix.at(i) != rhs._matrix.at(i))
			{
				return true;
			}
		}
		return false;
	}

	/*******************************************************************************************//**
	 * @fn	friend std::ostream& Matrix::operator<<(std::ostream& outstream, Matrix<T> rhs)
	 *
	 * @brief	Stream insertion operator. implements the print function of matrix.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param [in,out]	outstream	The outstream.
	 * @param	rhs				 	The right hand side.
	 *
	 * @return	The shifted result.
	 **********************************************************************************************/

	friend std::ostream& operator<<(std::ostream& outstream, Matrix<T> rhs)
	{

		for (unsigned int i = 0; i < rhs._matrixRow; i++)
		{
			for (unsigned int j = 0; j< rhs._matrixCol - 1; j++)
			{
				outstream << rhs(i, j) << "\t";
			}
			outstream << rhs(i, rhs._matrixCol - 1) << "\t" << std::endl;
		}
		return outstream;
	}

	/*******************************************************************************************//**
	 * @fn	const Matrix<T> Matrix::trans()
	 *
	 * @brief	Gets the transaction.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @return	A Matrix&lt;T&gt;
	 **********************************************************************************************/

	Matrix<T> trans() const
	{
		Matrix newMatrix(this->_matrixCol, this->_matrixRow);
		for (unsigned int i = 0; i < this->_matrixCol; i++)
		{
			for (unsigned int j = 0; j < this->_matrixRow; j++)
			{
				newMatrix(i, j) = (*this)(j, i);
			}
		}
		return newMatrix;
	}



	/*******************************************************************************************//**
	 * @fn	T Matrix::trace() const
	 *
	 * @brief	Gets the trace matrix.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @return	A T represents sum.
	 **********************************************************************************************/

	T trace() const
	{

		if (!this->isSquareMatrix())
		{
			throw std::invalid_argument(SQU_ERROR);
		}

		T sum = T(0); // start with zero value
		for (unsigned int i = 0; i < _matrixRow; i++)
		{
			sum += (*this)(i, i);

		}
		return sum;
	}


	typedef typename std::vector<T>::const_iterator const_iterator;

	/*******************************************************************************************//**
	 * @fn	const_iterator Matrix::begin() const
	 *
	 * @brief	Gets the begin.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @return	A const_iterator.
	 **********************************************************************************************/

	const_iterator begin() const
	{
		return _matrix.cbegin();
	}

	/*******************************************************************************************//**
	 * @fn	const_iterator Matrix::end() const
	 *
	 * @brief	returning iterator to end.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @return	A const_iterator.
	 **********************************************************************************************/

	const_iterator end() const
	{
		return _matrix.cend();
	}

	/*******************************************************************************************//**
	 * @fn	static void Matrix::setParallel(bool setParallel)
	 *
	 * @brief	Sets a parallel. set the parallel mode.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param	setParallel	true to set parallel.
	 **************************************************************************************************/

	static void setParallel(bool setParallel)
	{
		if (s_isParallel != setParallel)
		{
			s_isParallel = setParallel;
			std::string status;

			if (s_isParallel)
			{
				status = PARALLEL;
			}
			else
			{
				status = NON_PARALLEL;
			}


			std::cout << PARALLEL_MESSAGE(status) << std::endl;

		}
	}

	/*******************************************************************************************//**
	 * @fn	unsigned int Matrix::cols()
	 *
	 * @brief	Gets the cols.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @return	An int.
	 **********************************************************************************************/

	unsigned int cols() const
	{
		return _matrixCol;
	}

	/*******************************************************************************************//**
	 * @fn	unsigned int Matrix::rows()
	 *
	 * @brief	Gets the rows.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @return	An int.
	 **********************************************************************************************/

	unsigned int rows() const
	{
		return _matrixRow;
	}

	/*******************************************************************************************//**
	 * @fn	bool Matrix::isSquareMatrix() const
	 *
	 * @brief	Query if this object is square matrix. Should be public according to the 
	 * 			ex instructions.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @return	true if square matrix, false if not.
	 **********************************************************************************************/

	bool isSquareMatrix() const
	{
		return (_matrixRow == _matrixCol);
	}

private:
	unsigned int _matrixRow, _matrixCol;

	std::vector<T> _matrix;
	//T val = T();

	/*******************************************************************************************//**
	 * @fn	bool Matrix::_dimEqualCheck(const Matrix<T>& checkMatrix) const
	 *
	 * @brief	Dim equal check.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param	checkMatrix	The check matrix.
	 *
	 * @return	true if it succeeds, false if it fails.
	 **********************************************************************************************/

	bool _dimEqualCheck(const Matrix<T>& checkMatrix) const
	{
		return ((checkMatrix._matrixRow == _matrixRow) && (checkMatrix._matrixCol == _matrixCol));
	}

	/*******************************************************************************************//**
	 * @fn	bool Matrix::_checkDimMul(const Matrix<T> &checkMatrix) const
	 *
	 * @brief	Check dim mul.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param	checkMatrix	The check matrix.
	 *
	 * @return	true if it succeeds, false if it fails.
	 **********************************************************************************************/

	bool _checkDimMul(const Matrix<T> &checkMatrix) const
	{

		return (_matrixCol == checkMatrix._matrixRow);
	}

	/*******************************************************************************************//**
	 * @fn	void Matrix::_addDaemonFunc(Matrix<T>& newMatrix, unsigned int row) const
	 *
	 * @brief	a daemon for the multithreading of the add operation.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param [in,out]	newMatrix	The new matrix.
	 * @param	row				 	The row.
	 **********************************************************************************************/

	void _addDaemonFunc(Matrix<T>& newMatrix, unsigned int row) const
	{

		for (unsigned int i = 0; i < _matrixCol; i++)
		{
			newMatrix(row, i) += (*this)(row, i);
		}
	}

	/*******************************************************************************************//**
	 * @fn	void Matrix::_mulDaemonFunc(Matrix<T>& newMatrix,
	 * const Matrix<T>& rhs, unsigned int row) const
	 *
	 * @brief	Mul daemon function. the fun of the multithreaded mul function. since
	 * 			it is exactly the same as the seq calculation we are using this function for
	 * 			the mul calculation.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param [in,out]	newMatrix	The new matrix.
	 * @param	rhs				 	The right hand side.
	 * @param	row				 	The row.
	 **********************************************************************************************/

	void _mulDaemonFunc(Matrix<T>& newMatrix, const Matrix<T>& rhs, unsigned int row) const
	{

		for (unsigned int j = 0; j < rhs._matrixCol; j++)
		{
			for (unsigned int k = 0; k <_matrixCol; k++)
			{
				newMatrix(row, j) += (*this)(row, k)*rhs(k, j);

			}

		}
	}
	/*******************************************************************************************//**
	 *
	 * @brief	Verify the arguments that the ctor gets. And validates them.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @param row
	 * @param col
	 * @param vector<T> matrix
	 *
	 * @return	true if the arguments are vaild false otherwise
	 **********************************************************************************************/

	bool _constructorArgumentsChecker(unsigned int row, unsigned int col,
	                                  const std::vector<T>& matrix) const
	{
		if ((row == 0 && col != 0) || ( col == 0 && row != 0))
        {
            return false;
        }

        else if (row * col != matrix.size())
        {
            return false;
        }

        return true;

	}


};



template<class T> bool Matrix<T>::s_isParallel = false;

	/*******************************************************************************************//**
	 * @fn	template <class Complex> Matrix<Complex> Matrix::trans()
	 *
	 * @brief	Gets trans function for complex numbers also calcuate the "zamud" matrix.
	 *
	 * @author	Refi 950
	 * @date	9/9/2015
	 *
	 * @tparam	Complex	Type of the complex.
	 *
	 * @return	A Matrix&lt;Complex&gt;
	 **********************************************************************************************/

	template<>
	Matrix<Complex> Matrix<Complex>::trans() const
	{
		Matrix newMatrix(this->_matrixCol, this->_matrixRow);
		for (unsigned int i = 0; i < this->_matrixCol; i++)
		{
			for (unsigned int j = 0; j < this->_matrixRow; j++)
			{
				newMatrix(i, j) = ((*this)(j, i)).conj();
			}
		}
		return newMatrix;
	}




#endif
