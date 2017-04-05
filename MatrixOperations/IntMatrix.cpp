
#include "IntMatrix.h"

#define GET_INPUT_MATRIX_MESSAGE "Now insert the values of the matrix, row by row.\n" \
<< "After each cell add the char ',' (including after the last cell of a row).\n" \
<< "Each row should be in a separate line."

#define LINE_SPLITER ','

using namespace std;

/**
*@brief Deafult constructor empty
*
* @return newMatrix object
*/

IntMatrix::IntMatrix()
{

}


/**
*@brief Constructor, get row and cols and build an empty matrix.
*
*
*@param int rows
*@param int cols
*
* @return newMatrix object
*/
IntMatrix::IntMatrix(int rows, int cols)
{

	buildMatrix(rows, cols);
}


/**
*@brief copy constructor, make a new indipandet and copied IntMatrix.
* object
*
*
*@param IntMatrix& copy refrence to a matrix to copy
*
*
* @return copy matrix.
*/
IntMatrix::IntMatrix(const IntMatrix &copy)
{

	buildMatrix(copy._rowSizeMatrix, copy._colSizeMatrix);
	copyMatrix(&_matrix, copy._matrix);

}

/**
*@brief copy destructor, delete the matrix of the object.
*
*@param IntMatrix& copy refrence to a matrix to copy
*/
IntMatrix::~IntMatrix()
{
	deleteMatrix();

}

/**
*@brief getter of the row Size.
*
*
*@return _rowSizeMatrix
*/
int IntMatrix::getRowSize()
{

	return _rowSizeMatrix;
}

/**
*@brief getter of the col Size.
*
*
*@return _colSizeMatrix
*/
int IntMatrix::getColSize()
{
	return _colSizeMatrix;	

}

/**
*@brief helper function for deleting the int**
* we intialized in build function.
*
*
*/
void IntMatrix::deleteMatrix()
{
	if(_matrix != NULL)
	{
		for (int i = 0; i < _rowSizeMatrix; ++i)
		{
			delete[](_matrix[i]);

		}

		delete[](_matrix);

	}

}

/**
*@brief Get the row size and col size and build an empty matrix.
* with 0s as deafult.
*
*@param int newRows - new row size
*@param int newCols - newColSize
*/

void IntMatrix::buildMatrix(int newRows, int newCols)
{

	//if there is already a matrix intialized first we delete it
	// with its old row and col size and than we initalize the new one.
	if(_matrix != NULL)
	{
		deleteMatrix();

	}
	_rowSizeMatrix = newRows;
	_colSizeMatrix = newCols;

	_matrix = new(nothrow) int*[_rowSizeMatrix];
	assert(_matrix != nullptr);
	for (int i = 0; i < _rowSizeMatrix; ++i)
	{
		_matrix[i] = new(nothrow) int[_colSizeMatrix]();
        assert(_matrix[i] != nullptr);
		
	}

}



/**
*@brief Helper function perform deep copy to int** matrix.
*
*@param int*** matrix to copy to sent as a pointer
*@param int** matrix to copy from.
*
*
*/
void IntMatrix::copyMatrix(int*** copyToMatrix, int** copyFromMatrix)
{
	assert(copyToMatrix != nullptr && copyFromMatrix != nullptr);

	for (int i = 0; i < _rowSizeMatrix; i++)
	{
		for (int j = 0; j < _colSizeMatrix; j++)
		{
		
			(*(copyToMatrix))[i][j] = copyFromMatrix[i][j];

		}

	}

}



/**
*@brief overloading for = operator run over the left variable matrix
*        and perform deep copy..
*
*@param refernce to the matrix we need to copy.
*
*
*@return the matrix with the new matrix table copied from rhs.
*/
IntMatrix& IntMatrix::operator=(const IntMatrix &rhs)
{

	
	bool isBuildMatrix = false;
	//We need to create a new matrix.
	if(_matrix == NULL || _rowSizeMatrix != rhs._rowSizeMatrix ||\
	   rhs._colSizeMatrix != _colSizeMatrix)
	{
		isBuildMatrix = true;
	}

	// _rowSizeMatrix = rhs._rowSizeMatrix;
	// _colSizeMatrix = rhs._colSizeMatrix;
	if(isBuildMatrix)
	{
		buildMatrix(rhs._rowSizeMatrix, rhs._colSizeMatrix);
	}
	
	copyMatrix(&_matrix, rhs._matrix);

	return *this;

}




/**
*@brief overloading for - perform a - action between matrix
* and return a new IntMatrix object using the =- operator.
*
*@param refernce to the matrix we to sub from.
*
*
*@return new IntMatrix object which is table as a-b
*/
IntMatrix IntMatrix::operator-(const IntMatrix &rhs)
{

	assert(rhs._matrix != NULL && _matrix !=NULL);

	IntMatrix newMatrix = IntMatrix(*this);
	newMatrix -= rhs;
	return  newMatrix;

}


/**
*@brief does the same thing as - the differnce is that we
* perform the sub operation on the matrix of the calling object.
*
*@param refernce to the matrix we to sub from.
*
*
*@return this which is table as a-b
*/

IntMatrix& IntMatrix::operator-=(const IntMatrix &rhs)
{

	assert(rhs._matrix != NULL && _matrix !=NULL);
	for (int i = 0; i < _rowSizeMatrix; i++)
	{
		for (int j = 0; j < _colSizeMatrix; j++)
		{

			_matrix[i][j] = _matrix[i][j] - rhs._matrix[i][j];

		}

	}
	return *this;
}


/**
*@brief overloading for + perform a + action between matrix
* and return a new IntMatrix object using the =+ operator.
*
*@param refernce to the matrix we to add from.
*
*
*@return new IntMatrix object which is table as a+b
*/
IntMatrix IntMatrix::operator+(const IntMatrix &rhs) 
{
	assert(rhs._matrix != NULL && _matrix !=NULL);

	IntMatrix newMatrix = IntMatrix(*this);
	newMatrix += rhs;
	return  newMatrix;
	
}

/**
*@brief does the same thing as + the differnce is that we
* perform the add operation on the matrix of the calling object.
*
*@param refernce to the matrix we to add from.
*
*
*@return this which is table as a+=b
*/

IntMatrix& IntMatrix::operator+=(const IntMatrix &rhs)
{
	assert(rhs._matrix != NULL && _matrix !=NULL);

	for (int i = 0; i < _rowSizeMatrix; i++)
	{
		for (int j = 0; j < _colSizeMatrix; j++)
		{
			
			_matrix[i][j] = _matrix[i][j] + rhs._matrix[i][j];

		}

	}
	return *this;
}



/**
*@brief overloading for * perform a * action between matrix
* and return a new IntMatrix object using the =* operator.
*
*@param refernce to the matrix we to mul from.
*
*
*@return new IntMatrix object which is table as a*b
*/

IntMatrix IntMatrix::operator*(const IntMatrix& rhs)
{
	assert(rhs._matrix != NULL && _matrix !=NULL);

	IntMatrix newMatrix = IntMatrix(*this);
	newMatrix *= rhs;
	return newMatrix;

}


/**
*@brief does the same thing as * the differnce is that we
* perform the add operation on the matrix of the calling object.
*
*@param refernce to the matrix we to mul from.
*
*
*@return this which is table as a*=b
*/

IntMatrix& IntMatrix::operator*=(const IntMatrix& rhs)
{

	assert(rhs._matrix != NULL && _matrix !=NULL);

	int newRow = _rowSizeMatrix;
	int newCol = rhs._colSizeMatrix;
	int runningIndex = _colSizeMatrix;

	IntMatrix* originalMatrix = new IntMatrix(*this);


	buildMatrix(newRow, newCol);

	for (int i = 0; i < newRow; i++)
	{
		for (int j = 0; j < newCol; j++)
		{ 
			for (int k = 0; k < runningIndex; k++)
			{ 
				_matrix[i][j] += originalMatrix->_matrix[i][k] * rhs._matrix[k][j];
			}
		}
	}
	delete(originalMatrix);
	return *this;

}


/**
*@brief does the trans fucnton on the this object.
*
*
*
*
*@return a new object which is the trasnpose matrix of the this matrix,
*/


const IntMatrix IntMatrix::trans()
{

	assert(_matrix !=NULL);

	IntMatrix newMatrix = IntMatrix(_colSizeMatrix, _rowSizeMatrix);
	for (int i = 0; i < newMatrix._rowSizeMatrix; i++)
	{
		for (int j = 0; j < newMatrix._colSizeMatrix; j++)
		{
			newMatrix._matrix[i][j] = _matrix[j][i];
		}

	}
	return newMatrix;
}


/**
*@brief overloading to the << function. Basicly print the int** _matrix
* according to school solution.
*
*@param refernce to the matrix we need to print.
*@param refrence an output stream we need to update and return.
*
*@return ostream output stream this is the stream that cout will print.
*/



std::ostream& operator<<(std::ostream& output, IntMatrix& rhs)
{

	assert(rhs._matrix != NULL);

	//School solution bug add another \n.
	if(rhs._rowSizeMatrix == 0 && rhs._colSizeMatrix == 0)
	{
		output << endl;
	}

	for (int i = 0; i < rhs._rowSizeMatrix; i++)
	{
		for (int j = 0; j < rhs._colSizeMatrix; j++)
		{

			if(j != rhs._colSizeMatrix -1)
			{
				output << rhs._matrix[i][j] << " ";
			}
			else
			{
				output << rhs._matrix[i][j];
			}


		}

		output << "\n";

	}
	return output;

}


/**
*@brief The trace function return the trace on the matrix of the calling
* object.
*
*
*
*@return int value the sum of the diagnol.
*/

int IntMatrix::trace()
{
	 assert(_matrix != nullptr);

	int sum = 0;

	for (int i = 0; i < _rowSizeMatrix; i++)
	{
		sum += _matrix[i][i];
	}

	return sum;

}




/**
*@brief Reading the user Input, parsed and fill the object matrix.
*
*/


void IntMatrix::fillMatrix()
{
	string userInput;
	string cellValue;
	stringstream stream;

	cout << GET_INPUT_MATRIX_MESSAGE << endl;
	for (int i = 0; i < _rowSizeMatrix; i++)
	{
		getline(cin, userInput);
		
		stream << userInput << endl;
		
		for (int j = 0; j < _colSizeMatrix; j++)
		{
			getline(stream, cellValue, LINE_SPLITER);
			_matrix[i][j] = stoi(cellValue);
			
		}
		stream.clear();

	}
	
}



/**
*@brief Helper function to print the matrix according to 
* the school solution.
*
*
*/
void IntMatrix::printMatrix()
{
	for (int i = 0; i < _rowSizeMatrix; i++)
	{
		for (int j = 0; j < _colSizeMatrix; j++)
		{
			cout << _matrix[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;

}


/**
*@brief Verify if the matrix object is empty which means that is
* int** parameter is NULL
*
*
*@return true if _matrix is NULL false otherwise.
*/

bool IntMatrix::isMatrixEmpty()
{
	if(_matrix == NULL)
	{
		return true;
	}

	return false;
}








