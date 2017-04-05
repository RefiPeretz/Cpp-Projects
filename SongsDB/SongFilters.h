/**********************************************************************************************//**
 * @file	SongFilters.h
 *
 * @brief	Declares the song filters class.
 **************************************************************************************************/

#ifndef SONG_FILTERS_H
#define SONG_FILTERS_H

#include "Parameters.h"
#include <string>
#include <fstream> 
#include <iostream>
#include <vector>
#include <map>
#include <math.h>



/**********************************************************************************************//**
 * @class	SongFilters
 *
 * @brief	A song filters. A class full with static classes. The purpose of the class
 * 			is to avoid redudent code which mean if tomarrow we will add a rap song with
 * 			special calculations we will have to change only this class (add the function)
 * 			and rap song itself, which means that rankableSong will remain untouched
 * 			and we will maintain speration between Songs to the ranking itself.
 *
 * @author	Refi 950
 * @date	9/5/2015
 **************************************************************************************************/

class SongFilters
{
public:

	/*******************************************************************************************//**
	 *
	 * @brief	Rank tags.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 *
	 * @param	queryWord		 	The query word.
	 * @param	currentParameters	parameters to score by.
	 * @param	songTags		 	The song tags.
	 *
	 * @return	tags score.
	 **********************************************************************************************/

	static int rankTags(std::string queryWord , Parameters currentParameters , \
	                    std::map<std::string, int> songTags);

	/*******************************************************************************************//**
	 *
	 * @brief	Rank lyrics.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 *
	 * @param	queryWord		 	The query word.
	 * @param	currentParameters	parameters to score by.
	 * @param	songLyrics		 	The song lyrics.
	 *
	 * @return	lyrics score.
	 *********************************************************************************************/

	static int rankLyrics(std::string queryWord, Parameters currentParameters, \
	                      std::map<std::string, int> songLyrics);

	/******************************************************************************************//**
	 *
	 * @brief	Rank instruments.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 *
	 * @param	queryWord		 	The query word.
	 * @param	currentParameters	parameters to score by.
	 * @param	instruments		 	The instruments.
	 *
	 * @return	instruments score.
	 **********************************************************************************************/

	static int rankInstruments(std::string queryWord, \
	                           Parameters currentParameters, std::vector<std::string> instruments);

	/*******************************************************************************************//**
	 *
	 * @brief	Rank bpm liklihood score.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 *
	 * @param	queryWord		 	The query word.
	 * @param	songBpm			 	The song bpm.
	 * @param	currentParameters	parameters to score by.
	 *
	 * @return	bpm score.
	 **********************************************************************************************/

	static int rankBpmLiklihoodScore(std::string queryWord, double songBpm, \
	                                 Parameters currentParameters);

	

};

#endif