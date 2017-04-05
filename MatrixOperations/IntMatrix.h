#ifndef _INT_MATRIX_H
#define _INT_MATRIX_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <assert.h>


using namespace std;



/**
*@brief The IntMatrix class. contain the parameter and all
* relevant function to matrix operation.
*
*/

class IntMatrix
{
public:

/**
*@brief Deafult constructor empty
*
* @return newMatrix object
*/
	IntMatrix();
/**
*@brief Constructor, get row and cols and build an empty matrix.
*
*
*@param int rows
*@param int cols
*
* @return newMatrix object
*/
	IntMatrix(int rows, int cols);
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
	IntMatrix (const IntMatrix &copy);
/**
*@brief copy destructor, delete the matrix of the object.
*
*@param IntMatrix& copy refrence to a matrix to copy
*/
	~IntMatrix();
/**
*@brief Get the row size and col size and build an empty matrix.
* with 0s as deafult.
*
*@param int newRows - new row size
*@param int newCols - newColSize
*/
	void buildMatrix(int newRows, int newCols);
/**
*@brief Reading the user Input, parsed and fill the object matrix.
*
*/
	void fillMatrix();
/**
*@brief Helper function to print the matrix according to 
* the school solution.
*
*
*/
	void printMatrix();
/**
*@brief overloading for - perform a - action between matrix
* and return a new IntMatrix object using the =- operator.
*
*@param refernce to the matrix we to sub from.
*
*
*@return new IntMatrix object which is table as a-b
*/
	IntMatrix operator-(const IntMatrix &rhs);
/**
*@brief overloading for + perform a + action between matrix
* and return a new IntMatrix object using the =+ operator.
*
*@param refernce to the matrix we to add from.
*
*
*@return new IntMatrix object which is table as a+b
*/
	IntMatrix operator+(const IntMatrix &rhs);

/**
*@brief overloading for = operator run over the left variable matrix
*        and perform deep copy..
*
*@param refernce to the matrix we need to copy.
*
*
*@return the matrix with the new matrix table copied from rhs.
*/
	IntMatrix& operator=(const IntMatrix &rhs);
	/**
*@brief does the same thing as - the differnce is that we
* perform the sub operation on the matrix of the calling object.
*
*@param refernce to the matrix we to sub from.
*
*
*@return this which is table as a-b
*/

	IntMatrix& operator-=(const IntMatrix &rhs);
/**
*@brief does the same thing as + the differnce is that we
* perform the add operation on the matrix of the calling object.
*
*@param refernce to the matrix we to add from.
*
*
*@return this which is table as a+=b
*/
	IntMatrix& operator+=(const IntMatrix &rhs);

/**
*@brief overloading for * perform a * action between matrix
* and return a new IntMatrix object using the =* operator.
*
*@param refernce to the matrix we to mul from.
*
*
*@return new IntMatrix object which is table as a*b
*/

	IntMatrix operator*(const IntMatrix& rhs);
/**
*@brief does the same thing as * the differnce is that we
* perform the add operation on the matrix of the calling object.
*
*@param refernce to the matrix we to mul from.
*
*
*@return this which is table as a*=b
*/

	IntMatrix& operator*=(const IntMatrix& rhs);
/**
*@brief does the trans fucnton on the this object.
*
*@return a new object which is the trasnpose matrix of the this matrix,
*/

	const IntMatrix trans();
/**
*@brief Helper function perform deep copy to int** matrix.
*
*@param int*** matrix to copy to sent as a pointer
*@param int** matrix to copy from.
*
*
*/
	void copyMatrix(int*** copyToMatrix, int** copyFromMatrix);

/**
*@brief getter of the row Size.
*
*
*@return _rowSizeMatrix
*/
	int getRowSize();
/**
*@brief getter of the col Size.
*
*
*@return _colSizeMatrix
*/
	int getColSize();
/**
*@brief overloading to the << function. Basicly print the int** _matrix
* according to school solution.
*
*@param refernce to the matrix we need to print.
*@param refrence an output stream we need to update and return.
*
*@return ostream output stream this is the stream that cout will print.
*/

	friend std::ostream& operator<<(std::ostream& output, IntMatrix& rhs);
/**
*@brief helper function for deleting the int**
* we intialized in build function.
*
*
*/
	void deleteMatrix();
/**
*@brief The trace function return the trace on the matrix of the calling
* object.
*
*
*
*@return int value the sum of the diagnol.
*/

	int trace();

/**
*@brief Verify if the matrix object is empty which means that is
* int** parameter is NULL
*
*
*@return true if _matrix is NULL false otherwise.
*/
bool isMatrixEmpty();
	
	



private:
/**
*@brief The _matrix hold the values it self.
*/
	int** _matrix = NULL;
/**
*@brief rowSize
*/
	int _rowSizeMatrix;
/**
*@brief colSize
*/
	int _colSizeMatrix;



};


#endif
