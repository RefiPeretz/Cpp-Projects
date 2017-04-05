#include "RankableSong.h"


/***********************************************************************************************//**
*
* @brief	Constructor. create the RankableSong object with its commen parameters
* 			like songTitle and song tags.
*
* @author	Refi 950
* @date	9/2/2015
*
* @param	songTitle	The song title.
* @param	songTags 	The song tags.
**************************************************************************************************/

RankableSong::RankableSong(std::string songTitle, std::map<std::string, int> songTags) :\
                           Song(songTitle, songTags), Rankable()
{

}

/**********************************************************************************************//**
 * @fn	RankableSong::~RankableSong()
 *
 * @brief	Destructor.
 *
 * @author	Refi 950
 * @date	9/6/2015
 *************************************************************************************************/

RankableSong::~RankableSong()
{

}



/**********************************************************************************************//**
* @brief	Rank song virtual so each son rankable song will be able to
* 			rank its unique field, this method implemnt what is currently
* 			in common with all sons which is rank tags.
*
* @author	Refi 950
* @date	9/5/2015
*
* @param	queryWord		 	The query word.
* @param	currentParameters	Options for controlling the current.
**************************************************************************************************/
void RankableSong::rankSong(std::string queryWord , Parameters currentParameters)
{
	_score += SongFilters::rankTags(queryWord, currentParameters, _songTags);
	

}






