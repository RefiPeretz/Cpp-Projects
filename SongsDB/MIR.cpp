#include "SongDataBase.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#define ERROR 1




/*******************************************************************************************//**
 *
 * @brief	The main function createing the data base and call the relevant functions
 *			according to the pdf instructions.
 *
 * @author	Refi 950
 * @date	9/5/2015
 *
 * @param	argc	arguments counter.
 * @param	argv[] arguments
 **********************************************************************************************/
int main(int argc, char* argv[])
{

	if(argc != 4)
	{
		std::cerr << "Usage: MIR < songs file name > < parameters file name >"\
		 " < queries file name >" << std::endl;
		return (ERROR);
	}


	std::string queryFileName = (std::string)argv[3];

	std::ifstream instream(queryFileName.c_str());
	if (!instream.is_open())
	{
		std::cerr << "Error! Can't open file: " << queryFileName << "." << std::endl;

	}

    
	SongDataBase* newDataBase = new SongDataBase(argv[1], argv[2]);


	std::string queryWord = "";


	while (instream.good() && getline(instream, queryWord))
	{
		if(!queryWord.empty())
		{

			newDataBase->rankSortPrintSongs(queryWord);
		}

	}


	delete(newDataBase);
}