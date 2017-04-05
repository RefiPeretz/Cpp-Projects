/**********************************************************************************************//**
 * @file	SongDataBase.h
 *
 * @brief	Declares the song data base class.
 **************************************************************************************************/

#ifndef SONG_DATA_BASE_H
#define SONG_DATA_BASE_H

#include <string>
#include "Parameters.h"
#include "SongFactory.h"
#include "ParameterFactory.h"
#include "RankableSong.h"
#include <algorithm>  

/**********************************************************************************************//**
 * @class	SongDataBase
 *
 * @brief	A song data base. the class is kind of a manager which manage the data base of
 * 			songs it knows how to parsed the song and parameters and using
 * 			uinque functions and featuers to rank songs according to the pdf demands.
 * 			more elaborate explnations you can find in README class.
 *
 * @author	Refi 950
 * @date	9/5/2015
 **************************************************************************************************/

class SongDataBase
{
public:

	/*******************************************************************************************//**
	 * @fn	SongDataBase::SongDataBase(string songsFileName, string parametersFileName);
	 *
	 * @brief	Constructor. get songs file name and parameters file name to create
	 * 			the song database.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 *
	 * @param	songsFileName	  	Filename of the songs file.
	 * @param	parametersFileName	Filename of the parameters file.
	 **********************************************************************************************/

	SongDataBase(std::string songsFileName, std::string parametersFileName);

	/*******************************************************************************************//**
	 * @fn	SongDataBase::~SongDataBase();
	 *
	 * @brief	Destructor.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 **********************************************************************************************/

	~SongDataBase();

	/*******************************************************************************************//**
	 *
	 * @brief	Rank sort print songs. Since we want to keep the main clean from all
	 * 			 the process of ranking and printing songs. The SongDataBase has a uniqe
	 * 			 function which do all this tasks completely unknow to the user.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 *
	 * @param	queryWord	The query word.
	 **********************************************************************************************/

	void rankSortPrintSongs(std::string queryWord);

	/*******************************************************************************************//**
	 *
	 * @brief	Song sort copmerator. static because its not SongDataBase per say
	 * 			more a way to sort RankedSong so its static so other user that don't
	 * 			want the SongDataBase but want to sort ranked song could use it.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 *
	 * @param [in,out]	a	If non-null, the RankableSong to process.
	 * @param [in,out]	b	If non-null, the RankableSong to process.
	 *
	 * @return	true if it succeeds, false if it fails.
	 **********************************************************************************************/

	static bool songSortCopmerator(RankableSong* a, RankableSong* b);

	/*******************************************************************************************//**
	 *
	 * @brief	Stable sort songs. static because its not SongDataBase per say
	 * 			more a way to sort RankedSong so its static so other user that don't
	 * 			want the SongDataBase but want to sort ranked song could use it.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 *
	 * @param [in,out]	songsToSort	If non-null, the songs to sort.
	 **********************************************************************************************/

	static void stableSortSongs(std::vector<RankableSong*>* songsToSort);


	 

private:

	/*******************************************************************************************//**
	 *
	 * @brief	Helper function, should be private , knows how to print the database according
	 * 			to the pdf demands.
	 *
	 * @author	Refi 950
	 * @date	9/5/2015
	 *
	 * @param [in,out]	sortedSongs	If non-null, the sorted songs.
	 * @param	queryWord		   	The query word.
	 **********************************************************************************************/

	void _printRankedSongs(std::vector<RankableSong*> sortedSongs, std::string queryWord);

	/** @brief	The song container. */
	std::vector<RankableSong*> _songContainer;

	/** @brief	Options for controlling the data base. */
	Parameters* _dataBaseParameters;


};

#endif
