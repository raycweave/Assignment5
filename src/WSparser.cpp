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

vector<Waypoints*> WSParser::parseMapGraphFileWaypoints(string filename) {

	fstream inputFile;
	vector<Waypoints*> result1;
	string line;
	inputFile.open(filename.c_str());
	Waypoints *temp = NULL;

	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			getline(inputFile, line);

			/*Skips the line if it contains "WAYPOINTS"*/
			if (line.find("WAYPOINTS:") != string::npos) { continue; }

			/*goes to the end*/
			if (line == ""){ break; }
	
			temp = WSParser::parseGraphFileSentenceWaypoints(line);
				
			if (temp)
			{
				result1.push_back(temp);
			}

			temp = NULL;
		}
	}

	return result1;
}

vector<Streets*> WSParser::parseMapGraphFileStreets(string filename) {

	fstream inputFile;
	vector<Streets*> result2;
	string line;
	inputFile.open(filename.c_str());
	Streets *temp = NULL;
	int count = 0;

	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			if (count == 0) 
			{
				getline(inputFile, line);
				if (line == "STREETS:") 
				{ 
					count++;
				}
			}
			
			if (count == 1) 
			{
				getline(inputFile, line);
				temp = WSParser::parseGraphFileSentenceStreets(line);
				if (temp)
				{
					result2.push_back(temp);
				}
				temp = NULL;
			}	
		}
	}

	return result2;
}


Waypoints* WSParser::parseGraphFileSentenceWaypoints(string sentence) {

	Waypoints *result = new Waypoints(sentence);
	return result;

}


Streets* WSParser::parseGraphFileSentenceStreets(string sentence) {

	Streets *result = new Streets(sentence);
	return result;

}