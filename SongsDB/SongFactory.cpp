#include "SongFactory.h"

#define TAG_SPERATOR ' '


const std::string SEPARATOR = "=";
const std::string END_OF_SONGS = "***";
const std::string TITLE = "title";
const std::string TAGS = "tags";
const std::string LYRICS = "lyrics";
const std::string LYRICS_BY = "lyricsBy";
const std::string INSTRUMENTS = "instruments";
const std::string PERFORMED_BY = "performedBy";
const std::string BPM = "bpm";



/**********************************************************************************************//**
*
* @brief	Instruments list. simple vector of instruments list.
*
* @author	Refi 950
* @date	9/5/2015
*
* @param	instruments	The instruments.
*
* @return	A vector&lt;string&gt;
**************************************************************************************************/

std::vector<std::string> SongFactory::_instrumentsList(std::string instruments)
{
	std::stringstream stream;
	stream << instruments;
	std::string songInstrument;

	std::vector<std::string> songInstruments;

	while (getline(stream, songInstrument, TAG_SPERATOR))
	{

		songInstruments.push_back(songInstrument);

	}


	stream.clear();
	return songInstruments;

}

/**********************************************************************************************//**
*
* @brief	Creates lyrics frequency list. count the number if instances for
* 			each words in the lyrics and returns a map of wornd and count of
* 			instances.
*
* @author	Refi 950
* @date	9/5/2015
*
* @param	lyrics	The lyrics.
*
* @return	The new lyrics frequency list.
**************************************************************************************************/
std::map<std::string, int> SongFactory::_createLyricsFreqList(std::string lyrics)
{
	std::stringstream stream;
	stream << lyrics;
	//Order is not matter to us in this case.
	std::map<std::string, int> lyricsFreqList;
	std::map<std::string, int>::iterator it;

	std::string lyricsWord;
	while(getline(stream, lyricsWord, TAG_SPERATOR))
	{
		it = lyricsFreqList.find(lyricsWord);
		//The word already exist
		if(it != lyricsFreqList.end())
		{
			it->second += 1;
		}
		else
		{
			lyricsFreqList.insert(make_pair(lyricsWord, 1));
		}

	}

	stream.clear();
	return lyricsFreqList;

}
/**********************************************************************************************//**
* @fn	map<string, int> SongFactory::_createTagsMap(string tagsString);
*
* @brief	Creates tags map. tag and score of the tag
*
* @author	Refi 950
* @date	9/5/2015
*
* @param	tagsString	The tags string.
*
* @return	The new tags map.
**************************************************************************************************/
std::map<std::string , int> SongFactory::_createTagsMap(std::string tagsString)
{
	std::stringstream stream;
	std::string tagValue;
	std::string tagCounterValue;
	stream << tagsString;
	std::map<std::string, int> tagsMap;

	while(getline(stream, tagValue, TAG_SPERATOR))
	{
		//Now we need the count value of tag
		getline(stream, tagCounterValue, TAG_SPERATOR);
		tagsMap.insert(make_pair(tagValue, stoi(tagCounterValue)));

	}

	stream.clear();
	return tagsMap;


}
/**********************************************************************************************//**
* @fn	string SongFactory::_getWordList(const string line);
*
* @brief	Gets word list.
*
* @author	Refi 950
* @date	9/5/2015
*
* @param	line	The line.
*
* @return	The word list.
**************************************************************************************************/
std::string SongFactory::_getWordList(const std::string line)
{

	size_t pos1 = line.find("{");
	size_t pos2 = line.find("}");

	return line.substr(pos1 + 1, pos2 - pos1 - 1);
}



/**********************************************************************************************//**
*
* @brief	Reads songs from file, parsed them and returns the SONG Database songs vector.
*
* @author	Refi 950
* @date	9/5/2015
*
* @param	songsFileName	Filename of the songs file.
*
* @return	null if it fails, else the songs from file.
**************************************************************************************************/
std::vector<RankableSong*> SongFactory::readSongsFromFile(std::string songsFileName)
{

	std::ifstream instream(songsFileName.c_str());
	if (!instream.is_open())
	{
		std::cerr << "Error! Can't open file: " << songsFileName << "." << std::endl;
		
	}

	std::string line = "";

	std::vector<RankableSong*> songContainer;

	int lastSong = 0;

	while (instream.good() && !lastSong)
	{
		if (line.compare(SEPARATOR) != 0)
		{
			getline(instream, line);
			// Expect a line of "="
			if (END_OF_SONGS.compare(line) == 0)
			{
				lastSong = 1;
				break;
			}

		}

		getline(instream, line);
		// Expect a line of "title: ..."
		size_t pos = TITLE.size() + 2;
		std::string title = line.substr(pos);

		getline(instream, line);

		std::map<std::string, int> tagsMap = _createTagsMap(_getWordList(line));




		getline(instream, line);

		// Expect either lyrics or instruments.
		if (line.substr(0, LYRICS.size()).compare(LYRICS) == 0)
		{
			std::string lyrics = "";
			std::string lyricsBy = "";
			// Then we have a lyric song


			lyrics = _getWordList(line);
			// Lets get the lyrics:
			std::map<std::string, int> lyricFreqList = _createLyricsFreqList(lyrics);

			// Lets get the lyricsBy:
			getline(instream, line);
			pos = LYRICS_BY.size() + 2;
			lyricsBy = line.substr(pos);

			songContainer.push_back(new RankableLyricSong(lyricFreqList, lyricsBy, title, tagsMap));
		}
		else
		{
			// Then we have an instrumental song

			// Lets get the instruments:
			std::vector<std::string> instrumentsList = _instrumentsList((_getWordList(line)));

			// Lets get the performedBy:

			std::string performedBy = "";

			getline(instream, line);
			pos = PERFORMED_BY.size() + 2;
			performedBy = line.substr(pos);

			// Lets see if we have bpm:
			if (!instream.good())
			{
				break;
			}



			getline(instream, line);
			if (END_OF_SONGS.compare(line) == 0)
			{
				lastSong = 1;
			}

			std::string bpmStr = "";
			if (line.substr(0, BPM.size()).compare(BPM) == 0)
			{


				pos = BPM.size() + 2;
				bpmStr = line.substr(pos);
				//There is a bpm factor
				songContainer.push_back(new RankableInstrumentSong(instrumentsList, performedBy,\
				 title, tagsMap, stod(bpmStr)));
			}
			else
			{
				assert((line.compare(SEPARATOR) == 0) || (line.compare(END_OF_SONGS) == 0));
				songContainer.push_back(new RankableInstrumentSong(instrumentsList, performedBy,\
				 title, tagsMap));


				// TODO....
			}
		}
	}

	instream.close();

	return songContainer;
}

