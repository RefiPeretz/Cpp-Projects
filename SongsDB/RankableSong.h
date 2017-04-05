/**********************************************************************************************//**
 * @file	RankableSong.h
 *
 * @brief	Declares the rankable song class.The primary object and the kind of the SongDataBase
 * 			this object has the featuers of a rankable song which mean we can rank it with its
 * 			unique functions. It holds all the functions which know how to rank a song like tag
 * 			ranking lyrics ranking etc. that way we are saving a redudent code when
 * 			 we adds new songs with simialier demands to songs like lyric or instruments.
 * 			
 **************************************************************************************************/

#ifndef RANKABLE_SONG_H
#define RANKABLE_SONG_H

#include "Song.h"
#include "Rankable.h"
#include "SongFilters.h"
#include <string>
#include <fstream> 
#include <iostream>
#include <vector>
#include <map>
#include <math.h>



/**********************************************************************************************//**
 * @class	RankableSong
 *
 * @brief	A rankable song. Song which have the feasters of rankable object and song 
 * 			ofcurese.
 *
 * @author	Refi 950
 * @date	9/2/2015
 **************************************************************************************************/

class RankableSong : public Song, public Rankable
{
public:

	/*******************************************************************************************//**
	 *
	 * @brief	Constructor. create the RankableSong object with its commen parameters
	 * 			like songTitle and song tags.
	 *
	 * @author	Refi 950
	 * @date	9/2/2015
	 *
	 * @param	songTitle	The song title.
	 * @param	songTags 	The song tags.
	 **********************************************************************************************/

	RankableSong(std::string songTitle, std::map<std::string, int> songTags);

	/*******************************************************************************************//**
	 * @fn	virtual RankableSong::~RankableSong();
	 *
	 * @brief	Destructor.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 **********************************************************************************************/

	virtual ~RankableSong();



	/*******************************************************************************************//**
	 * @brief	Rank song virtual so each son rankable song will be able to 
	 * 			rank its unique field, this method implemnt what is currently 
	 * 			in common with all sons which is rank tags.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 *
	 * @param	queryWord		 	The query word.
	 * @param	currentParameters	Options for controlling the current.
	 **********************************************************************************************/

	virtual void rankSong(std::string queryWord, Parameters currentParameters);

	/*******************************************************************************************//**
	 * @fn	virtual void RankableSong::printRankedSong() = 0;
	 *
	 * @brief	Print ranked song according to pdf instrucons.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 **********************************************************************************************/

	virtual void printRankedSong() = 0;


	

	

	

};

#endif
