/**************************************************************************************************/

/*
* File: WSParser.cpp
* Author: Ray Weaver
* NetID: rayweaver
* Date: December 10, 2014
*/

/**************************************************************************************************/

#include "WSparser.h"
#include "Waypoints.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

vector<Waypoints*> WSParser::parseWaypointsGraphFile(string filename) {

	fstream inputFile;
	vector<Waypoints*> result;
	string line;
	inputFile.open(filename.c_str());
	Waypoints *temp = NULL;

	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			getline(inputFile, line);
			if (line.find("WAYPOINTS:") != string::npos)
			{
				continue;
			}

			if (line.find("STREETS:") != string::npos)
			{
				break;
			}

		temp = WSParser::parseGraphFileSentence(line);
				

				//FIXME
				/*
				store in junk to waypoints 
				while line.find != ("STREETS") store items into waypoints
				*/
				
				if (temp)
				{
					result.push_back(temp);
				}

				/*
				else
				if line find == streeets
				store rest into streets
				*/
		}

			

	
	}
	return result;
}

Waypoints* WSParser::parseGraphFileSentence(string sentence) {

	Waypoints *result = new Waypoints(sentence);
	return result;

}