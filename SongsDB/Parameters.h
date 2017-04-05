/**********************************************************************************************//**
* @file	Parameters.h
*
* @brief	Declares the parameters class. An object which contains parameters of the data base.
* 			with we will know that scores of each parameters.
**************************************************************************************************/

#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <string>
#include <vector>



/**********************************************************************************************//**
* @struct	bpmParameter
*
* @brief	A bpm parameter. holds the fields of the bpm query word average and std values.
*
* @author	Refi 950
* @date	9/2/2015
**************************************************************************************************/

struct bpmParameter
{
	std::string wordIndex;
	double average;
	double std;
};

/***********************************************************************************************//**
 * @class	Parameters
 *
 * @brief	Holds the parameters of the ex see README for more information.
 *
 * @author	Refi 950
 * @date	9/5/2015
 **************************************************************************************************/
class Parameters
{
public:

/**********************************************************************************************//**
*
* @brief	Constructor. of the parameters object
*
* @author	Refi 950
* @date	9/2/2015
*
* @param	tagMatchScore		 	The tag match score.
* @param	lyricsMatchScore	 	The lyrics match score.
* @param	instrumentsMatchScore	The instruments match score.
* @param	bpmLikelihoodWeight  	The bpm likelihood weight.
* @param	bpmIndexes			 	The bpm indexes.
**************************************************************************************************/

	Parameters(int tagMatchScore, int lyricsMatchScore, int instrumentsMatchScore,\
	           int bpmLikelihoodWeight, std::vector<bpmParameter> bpmIndexes);

/**********************************************************************************************//**
*
* @brief	Gets tag score.
*
* @author	Refi 950
* @date	9/2/2015
*
* @return	The tag score.
**************************************************************************************************/

	int getTagScore() const;

/**********************************************************************************************//**
*
* @brief	Gets lyric score.
*
* @author	Refi 950
* @date	9/2/2015
*
* @return	The lyric score.
**************************************************************************************************/

	int getLyricScore() const;

/**********************************************************************************************//**
*
* @brief	Gets instrument score.
*
* @author	Refi 950
* @date	9/2/2015
*
* @return	The instrument score.
**************************************************************************************************/

	int getInstrumentScore() const;

/**********************************************************************************************//**
*
* @brief	Gets bpm score.
*
* @author	Refi 950
* @date	9/2/2015
*
* @return	The bpm score.
**************************************************************************************************/

	int getBpmScore() const;

/**********************************************************************************************//**
*
* @brief	Query if this object is bitmap indexs.
*
* @author	Refi 950
* @date	9/2/2015
*
* @return	true if bitmap indexs, false if not.
**************************************************************************************************/

	bool isBmpIndexs();

/**********************************************************************************************//**
*
* @brief	Gets bitmap parameter.
*
* @author	Refi 950
* @date	9/2/2015
*
* @return	The bitmap parameter.
**************************************************************************************************/

	std::vector<bpmParameter> getBmpParameter() const;


private:

	/** @brief	The bpm likelihood weight. */

	int _bpmLikelihoodWeight;

	/** @brief	The tag match score. */
	int _tagMatchScore;

	/** @brief	The lyrics match score. */
	int _lyricsMatchScore;

	/** @brief	The instrument match score. */
	int _instrumentMatchScore;

	/** @brief	The bpm indexes. */
	std::vector<bpmParameter> _bpmIndexes;




};

#endif
