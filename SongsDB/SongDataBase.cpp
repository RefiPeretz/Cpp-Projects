#include "SongDataBase.h"



/**********************************************************************************************//**
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
 **************************************************************************************************/
SongDataBase::SongDataBase(std::string songsFileName, std::string parametersFileName)
{
	_songContainer = (SongFactory()).readSongsFromFile(songsFileName);
	_dataBaseParameters = (ParameterFactory()).readParametersFromFile(parametersFileName);
	
}

/**********************************************************************************************//**
 * @fn	SongDataBase::~SongDataBase();
 *
 * @brief	Destructor.
 *
 * @author	Refi 950
 * @date	9/5/2015
 **************************************************************************************************/

SongDataBase::~SongDataBase()
{
	delete(_dataBaseParameters);
	if(!_songContainer.empty())
	{
		for (std::vector<RankableSong*>::iterator it = _songContainer.begin();\
		 it != _songContainer.end(); ++it)
		{

			delete(*it);

		}
		_songContainer.clear();
	}
}


/**********************************************************************************************//**
 *
 * @brief	Rank sort print songs. Since we want to keep the main clean from all
 * 			 the process of ranking and printing songs. The SongDataBase has a uniqe
 * 			 function which do all this tasks completely unknow to the user.
 *
 * @author	Refi 950
 * @date	9/5/2015
 *
 * @param	queryWord	The query word.
 **************************************************************************************************/

void SongDataBase::rankSortPrintSongs(std::string queryWord)
{
	for (std::vector<RankableSong*>::iterator it = _songContainer.begin();\
	 it != _songContainer.end(); ++it)
	{
		//Cause we are doing new ranking with new query word
		(*it)->zeroScore();
		(*it)->rankSong(queryWord, *_dataBaseParameters);
		//Making a shallow copy of songs to sort
	

	}

	std::vector<RankableSong*> sortedSongs = _songContainer;
	stableSortSongs(&sortedSongs);
	_printRankedSongs(sortedSongs, queryWord);
	sortedSongs.clear();

}




/**********************************************************************************************//**
 *
 * @brief	Helper function, should be private , knows how to print the database according
 * 			to the pdf demands.
 *
 * @author	Refi 950
 * @date	9/5/2015
 *
 * @param [in,out]	sortedSongs	If non-null, the sorted songs.
 * @param	queryWord		   	The query word.
 **************************************************************************************************/

void SongDataBase::_printRankedSongs(std::vector<RankableSong*> sortedSongs, std::string queryWord)
{
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Query word: " << queryWord << "\n" << std::endl;
	for (std::vector<RankableSong*>::iterator it = sortedSongs.begin();\
	 it != sortedSongs.end(); ++it)
	{

		(*it)->printRankedSong();
		

	}
}

/**********************************************************************************************//**
 *
 * @brief	Song sort copmerator.
 *
 * @author	Refi 950
 * @date	9/5/2015
 *
 * @param [in,out]	a	If non-null, the RankableSong to process.
 * @param [in,out]	b	If non-null, the RankableSong to process.
 *
 * @return	true if it succeeds, false if it fails.
 **************************************************************************************************/

bool SongDataBase::songSortCopmerator(RankableSong* a, RankableSong* b)
{
	return a->getScore() > b->getScore();
}


void SongDataBase::stableSortSongs(std::vector<RankableSong*>* songsToSort)
{
	stable_sort(songsToSort->begin(), songsToSort->end(), songSortCopmerator);
}

