#include "SongFilters.h"

/**********************************************************************************************//**
 *
 * @brief	Rank tags.
 *
 * @author	Refi 950
 * @date	9/5/2015
 *
 * @param	queryWord		 	The query word.
 * @param	currentParameters	parameters to score by.
 * @param	songTags		 	The song tags.
 *
 * @return	An int.
 **************************************************************************************************/

int SongFilters::rankTags(std::string queryWord , Parameters currentParameters , \
	                      std::map<std::string, int> songTags)
{
	for (std::map<std::string, int>::iterator it = songTags.begin(); it != songTags.end(); ++it)
	{
		if((it->first).compare(queryWord) == 0)
		{

			return (currentParameters.getTagScore())*it->second;

		}
	}
	
	return 0;
}

/**********************************************************************************************//**
*
* @brief	Rank lyrics.
*
* @author	Refi 950
* @date	9/5/2015
*
* @param	queryWord		 	The query word.
* @param	currentParameters	parameters to score by.
* @param	songLyrics		 	The song lyrics.
*
* @return	lyrics score.
**************************************************************************************************/

int SongFilters::rankLyrics(std::string queryWord, Parameters currentParameters, \
	                        std::map<std::string, int> songLyrics)
{
	for (std::map<std::string, int>::iterator it = songLyrics.begin(); it != songLyrics.end(); ++it)
	{
		if ((it->first).compare(queryWord) == 0)
		{

			return (currentParameters.getLyricScore())*it->second;

		}
	}
	return 0;

}
/**********************************************************************************************//**
*
* @brief	Rank instruments.
*
* @author	Refi 950
* @date	9/5/2015
*
* @param	queryWord		 	The query word.
* @param	currentParameters	parameters to score by.
* @param	instruments		 	The instruments.
*
* @return	instruments score.
**************************************************************************************************/

int SongFilters::rankInstruments(std::string queryWord, \
	                             Parameters currentParameters, \
	                             std::vector<std::string> instruments)
{
	for (std::vector<std::string>::iterator it = instruments.begin(); it != instruments.end(); ++it)
	{

		if ((*it).compare(queryWord) == 0)
		{
			return (currentParameters.getInstrumentScore());

		}

	}
	return 0;
}


/**********************************************************************************************//**
*
* @brief	Rank bpm liklihood score.
*
* @author	Refi 950
* @date	9/5/2015
*
* @param	queryWord		 	The query word.
* @param	songBpm			 	The song bpm.
* @param	currentParameters	parameters to score by.
*
* @return	bpm score.
**************************************************************************************************/
int SongFilters::rankBpmLiklihoodScore(std::string queryWord, \
	                                   double songBpm, Parameters currentParameters)
{

	if(songBpm < 0 || currentParameters.isBmpIndexs())
	{
		return 0;
	}
	std::vector<bpmParameter> bmpParameters = currentParameters.getBmpParameter();

	for (std::vector<bpmParameter>::iterator it = bmpParameters.begin(); \
		it != bmpParameters.end(); ++it)
	{

		if (((*it).wordIndex).compare(queryWord) == 0)
		{
		

			return floor(exp(-(pow(songBpm - (*it).average, 2) / (2 * pow((*it).std, 2)))) \
				   * currentParameters.getBpmScore());

		}

	}

	return 0;

}