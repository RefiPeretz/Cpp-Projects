#include "Song.h"

/**********************************************************************************************//**
 *
 * @brief	Constructor.
 *
 * @author	Refi 950
 * @date	9/6/2015
 *
 * @param	songTitle	The song title.
 * @param	songTags 	The song tags.
 **************************************************************************************************/

Song::Song(std::string songTitle, std::map<std::string, int> songTags)
{
	_songTitle = songTitle;
	_songTags = songTags;
}

/**********************************************************************************************//**
 * @fn	Song::~Song()
 *
 * @brief	Destructor.
 *
 * @author	Refi 950
 * @date	9/6/2015
 **************************************************************************************************/

Song::~Song()
{

}