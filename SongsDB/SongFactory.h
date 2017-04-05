/**********************************************************************************************//**
 * @file	SongFactory.h
 *
 * @brief	Declares the song factory class.
 **************************************************************************************************/

#ifndef SONG_FACTORY_H
#define SONG_FACTORY_H

#include <string>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include "RankableInstrumentSong.h"
#include "RankableLyricSong.h"
#include <vector>
#include <map>




/**********************************************************************************************//**
* @class	SongFactory
*
* @brief	A song factory. parsing the songs file and creating the songs the vector
* 			of rankable songs for the data base currently only lyric and instrument songs.
* 			see more in README file.
*
* @author	Refi 950
* @date	9/5/2015
**************************************************************************************************/

class SongFactory
{
public:

/**********************************************************************************************//**
*
* @brief	Reads songs from file, parsed them and returns the SONG Database songs vector.
*
* @author	Refi 950
* @date	9/5/2015
*
* @param	songsFileName	Filename of the songs file.
*
* @return	null if it fails, else the songs from file.
**************************************************************************************************/

	std::vector<RankableSong*> readSongsFromFile(std::string songsFileName);
	


private:

/**********************************************************************************************//**
*
* @brief	Creates lyrics frequency list. count the number if instances for
* 			each words in the lyrics and returns a map of wornd and count of
* 			instances.
*
* @author	Refi 950
* @date	9/5/2015
*
* @param	lyrics	The lyrics.
*
* @return	The new lyrics frequency list.
**************************************************************************************************/

	std::map<std::string, int> _createLyricsFreqList(std::string lyrics);

/**********************************************************************************************//**
* @fn	string SongFactory::_getWordList(const string line);
*
* @brief	Gets word list.
*
* @author	Refi 950
* @date	9/5/2015
*
* @param	line	The line.
*
* @return	The word list.
**************************************************************************************************/

	std::string _getWordList(const std::string line);

/**********************************************************************************************//**
* @fn	map<string, int> SongFactory::_createTagsMap(string tagsString);
*
* @brief	Creates tags map. tag and score of the tag
*
* @author	Refi 950
* @date	9/5/2015
*
* @param	tagsString	The tags string.
*
* @return	The new tags map.
**************************************************************************************************/

	std::map<std::string, int> _createTagsMap(std::string tagsString);

/**********************************************************************************************//**
*
* @brief	Instruments list. simple vector of instruments list.
*
* @author	Refi 950
* @date	9/5/2015
*
* @param	instruments	The instruments.
*
* @return	A vector&lt;string&gt;
**************************************************************************************************/

	std::vector<std::string> _instrumentsList(std::string instruments);



};

#endif
