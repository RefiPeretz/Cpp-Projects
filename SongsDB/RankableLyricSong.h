/**********************************************************************************************//**
 * @file	RankableLyricSong.h
 *
 * @brief	Declares the rankable lyric song class.
 **************************************************************************************************/

#ifndef RANKABLE_LYRIC_SONG_H
#define RANKABLE_LYRIC_SONG_H

#include "RankableSong.h"

/**********************************************************************************************//**
 * @class	RankableLyricSong
 *
 * @brief	A rankable lyric song.
 *
 * @author	Refi 950
 * @date	9/5/2015
 **************************************************************************************************/

class RankableLyricSong : public RankableSong
{
public:
	typedef RankableSong super;

/**********************************************************************************************//**
* 
* @brief	Constructor. for the lyric song class. calls rankableSong ctor as father
* 			class and define special parameters of the lyric song class.
* 			
* @author	Refi 950
* @date	9/5/2015
*
* @param	lyricFreqList	List of lyric frequencies.
* @param	lyricsBy	 	Describes who lyrics this object.
* @param	songTitle	 	The song title.
* @param	songTags	 	The song tags.
**************************************************************************************************/

	RankableLyricSong(std::map<std::string, int> lyricFreqList, \
	                  std::string lyricsBy, std::string songTitle,\
		              std::map<std::string, int> songTags);

	/*******************************************************************************************//**
	 *
	 * @brief	Destructor.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 **********************************************************************************************/

	~RankableLyricSong();

	/*******************************************************************************************//**
	 * @fn	void RankableLyricSong::rankSong(string queryWord, Parameters currentParameters);
	 *
	 * @brief	Rank song. implementation of the virtual rankSong method, calling fucntion
	 * 			unique to the ranking of an lyric song. and updates the song grade located
	 * 			in the father class.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 *
	 * @param	queryWord		 	The query word.
	 * @param	currentParameters	Options for controlling the current.
	 **********************************************************************************************/

	void rankSong(std::string queryWord, Parameters currentParameters);

	/*******************************************************************************************//**
	 *
	 * @brief	another implemntation of virtual method which print the songs to the
	 * 			user according to the pdf instructions.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 **********************************************************************************************/

	void printRankedSong();


private:

	/** @brief	List of lyric frequencies. */
	std::map<std::string, int> _lyricFreqList;

	/** @brief	Describes who lyrics this object. */
	std::string _lyricsBy;


};

#endif
