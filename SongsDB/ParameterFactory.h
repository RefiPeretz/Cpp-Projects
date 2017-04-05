/**********************************************************************************************//**
 * @file	ParameterFactory.h
 *
 * @brief	Declares the parameter factory class. Reading the parameters file parsed it and
 * 			creating the parameters file object.
 **************************************************************************************************/

#ifndef PARAMETER_FACTORY_H
#define PARAMETER_FACTORY_H

#include "Parameters.h"

#include <vector>
#include <map>



/***********************************************************************************************//**
 * @class	ParameterFactory
 *
 * @brief	A parameter factory.
 *
 * @author	Refi 950
 * @date	9/2/2015
 **************************************************************************************************/

class ParameterFactory
{

public:

	/*******************************************************************************************//**
	 *
	 * @brief	Reads parameters from file. parsed them and creates the parameters object
	 *
	 * @author	Refi 950
	 * @date	9/2/2015
	 *
	 * @param	parametersFileName	Filename of the parameters file.
	 *
	 * @return	null if it fails, else the parameters from file.
	 **********************************************************************************************/

	Parameters* readParametersFromFile(std::string parametersFileName);



};

#endif
