/***********************************************************************************************//**
 * @file	Song.h
 *
 * @brief	Declares the song class.
 **************************************************************************************************/

#ifndef SONG_H
#define SONG_H

#include <string>
#include <map>  

/***********************************************************************************************//**
 * @class	Song
 *
 * @brief	A song. Class Song an abstract class which holds the featers of a song.
 * 			common featuers like Title and TAGS.
 *
 * @author	Refi 950
 * @date	9/6/2015
 **************************************************************************************************/

class Song
{
public:

	/*******************************************************************************************//**
	 * @fn	Song::Song(std::string songTitle, std::map<std::string, int> songTags);
	 *
	 * @brief	Constructor.
	 *
	 * @author	Refi 950
	 * @date	9/6/2015
	 *
	 * @param	songTitle	The song title.
	 * @param	songTags 	The song tags.
	 **********************************************************************************************/

	Song(std::string songTitle, std::map<std::string, int> songTags);

	/*******************************************************************************************//**
	 * @fn	virtual Song::~Song();
	 *
	 * @brief	Destructor.
	 *
	 * @author	Refi 950
	 * @date	9/6/2015
	 **********************************************************************************************/

	virtual ~Song();




protected:
	/** @brief	The song title. */
	std::string _songTitle;
	/** @brief	The song tags. */
	std::map<std::string, int> _songTags;



};

#endif
