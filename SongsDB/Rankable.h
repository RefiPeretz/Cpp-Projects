/**********************************************************************************************//**
 * @file	Rankable.h
 *
 * @brief	Declares the rankable class.
 **************************************************************************************************/

#ifndef RANKABLE_H
#define RANKABLE_H

#define DEAFULT_SCORE 0

#include <string>
#include <map>  

/**********************************************************************************************//**
 * @class	Rankable
 *
 * @brief	A rankable. and abstract class which define a Rankable object. which has
 * 			a rankable object featuers like score. ofcurse this desgin is more
 * 			for feauture implementations and now its kind of naive see 
 * 			README.
 *
 * @author	Refi 950
 * @date	9/6/2015
 **************************************************************************************************/

class Rankable
{
public:

	/*******************************************************************************************//**
	 * @fn	Rankable::Rankable(int score = DEAFULT_SCORE);
	 *
	 * @brief	Constructor. deafult score for each rankable is zero.
	 *
	 * @author	Refi 950
	 * @date	9/6/2015
	 *
	 * @param	score	The score.
	 **********************************************************************************************/

	Rankable(int score = DEAFULT_SCORE);

	/*******************************************************************************************//**
	 * @fn	virtual Rankable::~Rankable();
	 *
	 * @brief	Destructor.
	 *
	 * @author	Refi 950
	 * @date	9/6/2015
	 **********************************************************************************************/

	virtual ~Rankable();

	/*******************************************************************************************//**
	 * @fn	int Rankable::getScore();
	 *
	 * @brief	Gets the score. each rankable hase score so this is a getter to it.
	 *
	 * @author	Refi 950
	 * @date	9/6/2015
	 *
	 * @return	The score.
	 **********************************************************************************************/

	int getScore() const;
/***********************************************************************************************//**
*
* @brief	Each rankable object has the ability to zero the score.
*
* @author	Refi 950
* @date	9/5/2015
**************************************************************************************************/

	void zeroScore();


protected:

	/** @brief	The score. */
	int _score;


};

#endif