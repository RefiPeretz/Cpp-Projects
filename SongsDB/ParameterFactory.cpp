/**********************************************************************************************//**
* @file	ParameterFactory.cpp
*
* @brief	Implements the parameter factory class.
**************************************************************************************************/

#include "ParameterFactory.h"
#include <fstream>
#include <iostream>
#include <sstream>

#define TAG_SPERATOR ' '
#define BPM_SONG_INDEX_SPERATOR ':'
#define AVERAGE_STD_SPERATOR ','
#define ERROR 1

const std::string TAG = "tagMatchScore";
const std::string LYRICS = "lyricsMatchScore";
const std::string INSTRUMENT = "instrumentMatchScore";
const std::string BPM = "bpmLikelihoodWeight";


/**********************************************************************************************//**
*
* @brief	Reads parameters from file. parsed them and creates the parameters object
*
* @author	Refi 950
* @date	9/2/2015
*
* @param	parametersFileName	Filename of the parameters file.
*
* @return	null if it fails, else the parameters from file.
**************************************************************************************************/

Parameters* ParameterFactory::readParametersFromFile(std::string parametersFileName)
{
	//Open the parameters file.
	std::ifstream instream(parametersFileName.c_str());
	if (!instream.is_open())
	{
		std::cerr << "Error! Can't open file: " << parametersFileName << "." << std::endl;
		exit(ERROR);
	}

	std::string line = "";
	//Parsing the parameters file.
	getline(instream, line);
	size_t pos = TAG.size() + 2;
	int tagScore = stoi(line.substr(pos));

	getline(instream, line);
	pos = LYRICS.size() + 2;
	int lyricsScore = stoi(line.substr(pos));

	getline(instream, line);
	pos = INSTRUMENT.size() + 2;
	int instrumentScore = stoi(line.substr(pos));

	getline(instream, line);
	pos = BPM.size() + 2;
	int bpmScore = stoi(line.substr(pos));

	std::stringstream stream;
	std::vector<bpmParameter> bpmIndexes;

	std::string bpmIndexName;
	std::string averageValue;
	std::string stdValue;
	//Check if there is bpm parameters.
	while(getline(instream, line))
	{
		if(!line.empty())
		{

			stream << line << std::endl;
			getline(stream, bpmIndexName, BPM_SONG_INDEX_SPERATOR);
			getline(stream, averageValue, AVERAGE_STD_SPERATOR);
			getline(stream, stdValue, '\n');

			struct bpmParameter newBpmParameter;
			newBpmParameter.wordIndex = bpmIndexName;
			newBpmParameter.average = stod(averageValue);
			newBpmParameter.std = stod(stdValue);

			bpmIndexes.push_back(newBpmParameter);

			stream.clear();

		}


	}
	//Returning the parameters object contains the parameters of the song data base.
	return new Parameters(tagScore, lyricsScore, instrumentScore, bpmScore, bpmIndexes);



}

