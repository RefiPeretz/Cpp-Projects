#include "Parameters.h"

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

Parameters::Parameters(int tagMatchScore, int lyricsMatchScore, int instrumentsMatchScore, \
	                   int bpmLikelihoodWeight, std::vector<bpmParameter> bpmIndexes)
{

	_bpmLikelihoodWeight = bpmLikelihoodWeight;
	_tagMatchScore = tagMatchScore;
	_lyricsMatchScore = lyricsMatchScore;
	_instrumentMatchScore = instrumentsMatchScore;
	_bpmIndexes = bpmIndexes;

}

/**********************************************************************************************//**
*
* @brief	Gets tag score.
*
* @author	Refi 950
* @date	9/2/2015
*
* @return	The tag score.
**************************************************************************************************/

int Parameters::getTagScore() const
{
	return _tagMatchScore;
}

/**********************************************************************************************//**
 * @brief	Gets lyric score.
 *
 * @author	Refi 950
 * @date	9/2/2015
 *
 * @return	The lyric score.
 **************************************************************************************************/

int Parameters::getLyricScore() const
{
	return _lyricsMatchScore;
}

/**********************************************************************************************//**
 *
 * @brief	Gets instrument score.
 *
 * @author	Refi 950
 * @date	9/2/2015
 *
 * @return	The instrument score.
 **************************************************************************************************/

int Parameters::getInstrumentScore() const
{
	return _instrumentMatchScore;
}

/**********************************************************************************************//**
 *
 * @brief	Gets bpm score.
 *
 * @author	Refi 950
 * @date	9/2/2015
 *
 * @return	The bpm score.
 **************************************************************************************************/

int Parameters::getBpmScore() const
{
	return _bpmLikelihoodWeight;
	
}

/**********************************************************************************************//**
 * @brief	Gets bitmap parameter.
 *
 * @author	Refi 950
 * @date	9/2/2015
 *
 * @return	The bitmap parameter.
 **************************************************************************************************/

std::vector<bpmParameter> Parameters::getBmpParameter() const
{
	return _bpmIndexes;
}

/**********************************************************************************************//**
 * @fn	bool Parameters::isBmpIndexs()
 *
 * @brief	Query if this object is bitmap indexs.
 *
 * @author	Refi 950
 * @date	9/2/2015
 *
 * @return	true if bitmap indexs empty, false if not.
 **************************************************************************************************/

bool Parameters::isBmpIndexs()
{
	return _bpmIndexes.empty();
}