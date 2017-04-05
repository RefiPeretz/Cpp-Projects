#include <stdlib.h>
#include "IntMatrix.h"
#include <iostream>
#include<string.h>
#include<stdio.h>
#include <sstream>



#define EMPTY_CHOISE -1
#define OPENING_STATEMENT "Choose operation:\n"
#define OPTIONS "1. add\n2. sub\n3. mul\n4. trans\n5. trace\n"
#define GET_MATRIX_MESSAGE_TWO(command) "Operation " << command << " requires 2 operand matrices."
#define GET_MATRIX_MESSAGE_ONE(command) "Operation " << command << " requires 1 operand matrix."
#define ERROR_MESSAGE_DIM(operation) "Error: " << operation << " failed - different dimensions."
#define TWO_MATRIX_OPERAND 2
#define ONE_MATRIX_OPERAND 1
#define CHOISE_UPPERBOUD 5
#define CHOISE_LOWERBOUND 1
#define CHOISE_LOWERBOUND_TWO_MATRIX 1
#define CHOISE_UPPERBOUND_TWO_MATRIX 3



#define ADD_SIGN '+'
#define SUB_SIGN '-'
#define ADD_OP "add"
#define SUB_OP "sub"
#define MUL_OP "mul"
#define TRANS_OP "trans"
#define TRACE_OP "trace"



enum operation
{
	ADD = 1,
	SUB = 2,
	MUL = 3,
	TRANS = 4,
	TRACE = 5

};
using namespace std;




/**
* @brief Check if string is a pure number
*
*@param string to check
*
* @return true in case of a number false otherwise
*/

bool isNumber(const std::string & checkString)
{
	if (checkString.empty() || ((!isdigit(checkString[0])) && \
		(checkString[0] != SUB_SIGN) && (checkString[0] != ADD_SIGN))) 
	{
		return false;
	}

	char * index;
	strtol(checkString.c_str(), &index, 10);

	return (*index == 0);
}

/**
* @brief Creatre the matrix for the main program calls for the
*Int matrix object
*
*
* @return The new matrix
*/

IntMatrix createMatrix()
{
	string rowsInput, colsInput;
	//TODO row and cols values check
	cout << "number of rows:" ;
	getline(cin, rowsInput);
	cout << "number of columns:";
	getline(cin, colsInput);
	//Empty matrix, we will receive data stragiht to the matrix
	//and save memory.
	IntMatrix newMatrix = IntMatrix(stoi(rowsInput), stoi(colsInput));
	newMatrix.fillMatrix();
	
	return newMatrix;
}

/**
* @brief doing the add operation for matrix including errors
* checking
*
*@param IntMatrix matrixA 
*@param IntMatrix matrixB
*@param IntMatrix& update - update the resultMatrix
*
* @return matrixA + matrixB
*/
void addMatrix(IntMatrix matrixA, IntMatrix matrixB, IntMatrix& update)
{
	if(matrixA.getRowSize() != matrixB.getRowSize() || matrixA.getColSize() != matrixB.getColSize())
	{
		cout << ERROR_MESSAGE_DIM(ADD_OP) << endl;
		return;
	}

	update = (matrixA + matrixB);
}

/**
* @brief doing the sub operation for matrix including errors
* checking
*
*@param IntMatrix matrixA 
*@param IntMatrix matrixB
*@param IntMatrix& update - update the resultMatrix
*
* @return matrixA - matrixB
*/

void subMatrix(IntMatrix matrixA, IntMatrix matrixB, IntMatrix& update)
{
	if(matrixA.getRowSize() != matrixB.getRowSize() ||\
	   matrixA.getColSize() != matrixB.getColSize())
	{
		cout << ERROR_MESSAGE_DIM(SUB_OP) << endl;
		return;
	}
	update = (matrixA - matrixB);
}

/**
* @brief doing the mul operation for matrix including errors
* checking
*
*@param IntMatrix matrixA 
*@param IntMatrix matrixB
*@param IntMatrix& update - update the resultMatrix
*
* @return matrixA * matrixB
*/

void mulMatrix(IntMatrix matrixA, IntMatrix matrixB, IntMatrix& update)
{
	if(matrixA.getColSize() != matrixB.getRowSize())
	{
		cout << ERROR_MESSAGE_DIM(MUL_OP) << endl;
		return;
	}
	update = (matrixA * matrixB);
}

/**
* @brief doing the trace operation for matrix including errors
* checking
*
*@param IntMatrix matrixA 

*
* @return trace of matrixA
*/
void traceMatrix(IntMatrix matrixA)
{
	if(matrixA.getRowSize() != matrixA.getColSize())
	{
		cout << "Error: trace failed - The matrix isn't square." << endl;
		return;
	}
	cout << "The matrix is square and its trace is " << matrixA.trace() << endl;
}


/**
* @brief doing the transpose operation for matrix including errors
* checking
*
*@param IntMatrix matrixA 
*@param IntMatrix& update - update the resultMatrix
*
* @return the transpose matrix of matrixA
*/
void transMatrix(IntMatrix matrixA, IntMatrix& update)
{
	update = matrixA.trans();
}

/**
* @brief Helper fucntion, mamaging the process of getting the matrix and
* activate the suitable operand
*
*@param int userChoise 
*@param int numberOfMatrix 2 or 1 
*
*/
void matrixOperation(int userChoise, int numberOfMatrix)
{
	//Creating empty matrix
	IntMatrix resultMatrix = IntMatrix();
	
	string command = "";
//We are 2 operand
	if(numberOfMatrix == 2)
	{
		void(*operandFuncTwoMatrix)(IntMatrix, IntMatrix, IntMatrix&) = NULL;
		
		switch (userChoise)
		{
			case ADD:
				command = ADD_OP;
				operandFuncTwoMatrix = &addMatrix;
				break;
			case SUB:
				command = SUB_OP;
				operandFuncTwoMatrix = &subMatrix;
				break;
			case MUL:
				command = MUL_OP;
				operandFuncTwoMatrix = &mulMatrix;
				break;
		}

		cout << GET_MATRIX_MESSAGE_TWO(command) << endl;

		cout << "Insert first matrix:" << endl;
		IntMatrix matrixA = createMatrix();
		cout << "Insert second matrix:" << endl;
		IntMatrix matrixB = createMatrix();
		cout << "--------\n" << "Got first matrix:\n" << endl;
		cout << matrixA << endl;
		cout << "--------\n" << "Got second matrix:\n" << endl;
		cout << matrixB << endl;
		
		operandFuncTwoMatrix(matrixA, matrixB, resultMatrix);
	}
	else
	{
		//Do we have result in a form of a matrix?
		bool isResultMatrix = false;
		void(*operandFuncOneMatrix)(IntMatrix, IntMatrix&) = NULL;
		switch(userChoise)
		{
			case TRANS:
				command = TRANS_OP;
				operandFuncOneMatrix = &transMatrix;
				isResultMatrix = true;
				break;
			case TRACE:
				//Special case now IntMatrix object is returned
				command = TRACE_OP;
				break;
		}

		cout << GET_MATRIX_MESSAGE_ONE(command) << endl;
		IntMatrix matrixA = createMatrix();
		cout << "--------\n" << "got matrix:\n" << endl;
		cout << matrixA << endl;

		//Since we have only two option we know but this design is
		//has future expend options

		if(!isResultMatrix)
		{

			traceMatrix(matrixA);
			return;
		}

		operandFuncOneMatrix(matrixA, resultMatrix);
		
	}

	//No matrix should be printed
	if(resultMatrix.isMatrixEmpty())
	{
		return;
	}


	cout << "==========\n" << "Resulted matrix:\n" << endl;
	cout << resultMatrix << endl;

	

	
}

int main()
{
	string userInput;
	int userChoise = EMPTY_CHOISE;

	while(userChoise < CHOISE_LOWERBOUND || userChoise > CHOISE_UPPERBOUD)
	{
		cout << OPENING_STATEMENT << OPTIONS;
		getline(cin, userInput);
		if(!isNumber(userInput))
		{
			continue;
		}
		userChoise = stoi(userInput);

	}

	if(userChoise >= CHOISE_LOWERBOUND_TWO_MATRIX && userChoise <= CHOISE_UPPERBOUND_TWO_MATRIX)
	{
		matrixOperation(userChoise, TWO_MATRIX_OPERAND);
	}
	else
	{
		matrixOperation(userChoise, ONE_MATRIX_OPERAND);
	}




	return 0;
}