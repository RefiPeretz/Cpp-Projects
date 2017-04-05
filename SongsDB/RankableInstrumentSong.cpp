#include "RankableInstrumentSong.h"

typedef RankableSong super;

/**********************************************************************************************//**
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
**************************************************************************************************/
RankableInstrumentSong::RankableInstrumentSong(std::vector<std::string> instruments, \
	                                           std::string performedBy, std::string songTitle, \
	                                           std::map<std::string, int> songTags, \
	                                           double bpm) : RankableSong(songTitle, songTags)
{
	_instruments = instruments;
	_performedBy = performedBy;
	_bpm = bpm;
}

/**********************************************************************************************//**
*
* @brief	Destructor. for the instrument song class.
*
* @author	Refi 950
* @date	9/5/2015
**************************************************************************************************/
RankableInstrumentSong::~RankableInstrumentSong()
{
	
}


/**********************************************************************************************//**
*
* @brief	another implemntation of virtual method which print the songs to the
* 			user according to the pdf instructions.
*
* @author	Refi 950
* @date	9/5/2015
**************************************************************************************************/
void RankableInstrumentSong::printRankedSong()
{
	if (super::_score > 0)
	{
		std::cout << super::_songTitle << '\t' << super::_score << '\t' << "performed by: " \
		<< _performedBy << std::endl;
	}

}


/**********************************************************************************************//**
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
**************************************************************************************************/
void RankableInstrumentSong::rankSong(std::string queryWord, Parameters currentParameters)
{
	super::rankSong(queryWord, currentParameters);

	super::_score += SongFilters::rankInstruments(queryWord, currentParameters, _instruments);

	super::_score += SongFilters::rankBpmLiklihoodScore(queryWord, _bpm, currentParameters);
}