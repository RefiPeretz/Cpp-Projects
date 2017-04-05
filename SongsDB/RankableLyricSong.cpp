#include "RankableLyricSong.h"



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
RankableLyricSong::RankableLyricSong(std::map<std::string, int> lyricFreqList, \
                                     std::string lyricsBy,\
	                                 std::string songTitle, std::map<std::string, int> songTags) \
	                                 : RankableSong(songTitle, songTags)
{
	_lyricFreqList = lyricFreqList;
	_lyricsBy = lyricsBy;
}

/*******************************************************************************************//**
 *
 * @brief	Destructor.
 *
 * @author	Refi 950
 * @date	9/5/2015
 **********************************************************************************************/

RankableLyricSong::~RankableLyricSong()
{

}

/*******************************************************************************************//**
 *
 * @brief	another implemntation of virtual method which print the songs to the
 * 			user according to the pdf instructions.
 *
 * @author	Refi 950
 * @date	9/5/2015
 **********************************************************************************************/
void RankableLyricSong::printRankedSong()
{
	if(super::_score > 0)
	{
		std::cout << super::_songTitle << '\t' << super::_score << '\t' << "lyrics by: " \
		<< _lyricsBy << std::endl;
	}

}


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
void RankableLyricSong::rankSong(std::string queryWord, Parameters currentParameters)
{
	super::rankSong(queryWord, currentParameters);

	super::_score += SongFilters::rankLyrics(queryWord, currentParameters, _lyricFreqList);

}