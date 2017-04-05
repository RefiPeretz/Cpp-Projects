#include "Rankable.h"



/**********************************************************************************************//**
* @fn	Rankable::Rankable(int score = DEAFULT_SCORE);
*
* @brief	Constructor. deafult score for each rankable is zero.
*
* @author	Refi 950
* @date	9/6/2015
*
* @param	score	The score.
**************************************************************************************************/
Rankable::Rankable(int score)
{
	_score = score;

}

/**********************************************************************************************//**
 * @fn	Rankable::~Rankable()
 *
 * @brief	Destructor.
 *
 * @author	Refi 950
 * @date	9/6/2015
 **************************************************************************************************/

Rankable::~Rankable()
{

}

/**********************************************************************************************//**
* @fn	int Rankable::getScore();
*
* @brief	Gets the score. each rankable hase score so this is a getter to it.
*
* @author	Refi 950
* @date	9/6/2015
*
* @return	The score.
**************************************************************************************************/
int Rankable::getScore() const
{
	return _score;
}


/**********************************************************************************************//**
*
* @brief	Zero song rank so we could rank again in each query word.
*
* @author	Refi 950
* @date	9/5/2015
**************************************************************************************************/
void Rankable::zeroScore()
{
	_score = 0;
}