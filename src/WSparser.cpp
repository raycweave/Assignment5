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
#include "DGraph.h"
#include "Streets.h"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool WSParser::parseMapGraphFileWaypoints(DGraph *g, string filename) {

	bool result1 = true;
	fstream inputFile;
	string line;
	inputFile.open(filename.c_str());
	Waypoint *temp = NULL;

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
				g->addWaypoint(temp);
			}

			temp = NULL;
		}
	}

	return result1;
}

bool WSParser::parseMapGraphFileStreets(DGraph *g, string filename) {

	fstream inputFile;
	bool result2 = true;
	string line;
	inputFile.open(filename.c_str());
	Street *temp = NULL;
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
					
					g->addStreet(temp->getStartId(), temp->getEndId());
					//result2.push_back(temp);
				}
				temp = NULL;
			}	
		}
	}

	return result2;
}


Waypoint* WSParser::parseGraphFileSentenceWaypoints(string sentence) {

	Waypoint *result = new Waypoint(sentence);
	return result;

}


Street* WSParser::parseGraphFileSentenceStreets(string sentence) {

	Street *result = new Street(sentence);
	return result;

}