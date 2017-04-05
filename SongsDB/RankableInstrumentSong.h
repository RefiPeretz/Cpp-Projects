/**********************************************************************************************//**
 * @file	RankableInstrumentSong.h
 *
 * @brief	Declares the rankable instrument song class. including virtual classes of
 * 			rankable songs,you can read more in th README file.
 **************************************************************************************************/
#ifndef INSTRUMENT_SONG_H
#define INSTRUMENT_SONG_H

#include "RankableSong.h"
#define EMPTY_BPM -1

/***********************************************************************************************//**
 * @class	RankableInstrumentSong
 *
 * @brief	A rankable instrument song.
 *
 * @author	Refi 950
 * @date	9/5/2015
 **************************************************************************************************/

class RankableInstrumentSong : public RankableSong
{
public:

	/*******************************************************************************************//**
	 * @typedef	RankableSong super
	 *
	 * @brief	Defines an alias representing the super.
	 **********************************************************************************************/

	typedef RankableSong super; 

	/*******************************************************************************************//**
	 *
	 * @brief	Constructor. for the intrument song class. calls rankableSong ctor as father
	 * 			class and define special parameters of the instrument song class.
	 * @author	Refi 950
	 * @date	9/5/2015
	 *
	 * @param	instruments	The instruments.
	 * @param	performedBy	Describes who performed this object.
	 * @param	songTitle  	The song title.
	 * @param	songTags   	The song tags.
	 * @param	bpm		   	The bpm.
	 **********************************************************************************************/

	RankableInstrumentSong(std::vector<std::string> instruments, \
	                       std::string performedBy, std::string songTitle,\
		                   std::map<std::string, int> songTags, double bpm = EMPTY_BPM);

	/*******************************************************************************************//**
	 *
	 * @brief	Destructor. for the instrument song class.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 **********************************************************************************************/

	~RankableInstrumentSong();

	/*******************************************************************************************//**
	 *
	 * @brief	Rank song. implementation of the virtual rankSong method, calling fucntion
	 * 			unique to the ranking of an instrument song. and updates the song grade located
	 * 			in the father class.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 *
	 * @param	queryWord		 	The query word.
	 * @param	currentParameters	Options for controlling the current.
	 **********************************************************************************************/

	void rankSong(std::string queryWord, Parameters currentParameters);

	/******************************************************************************************//**
	 *
	 * @brief	another implemntation of virtual method which print the songs to the
	 * 			user according to the pdf instructions.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 **********************************************************************************************/

	void printRankedSong();


private:

	/** @brief	The instruments. */
	std::vector<std::string> _instruments;

	/** @brief	Describes who performed this object. */
	std::string _performedBy;

	/** @brief	The bpm. */
	double _bpm;


};

#endif
