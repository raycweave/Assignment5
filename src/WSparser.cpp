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
	DGraph *tempp = g;

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
				if (checkPossibleWaypointErrors(tempp, temp) == false)
				{
					exit(EXIT_FAILURE);
				}

			}

			temp = NULL;
		}
	}

	return result1;
}

bool WSParser::parseMapGraphFileStreets(DGraph *g, string filename) {

	fstream inputFile;
	bool result2 = true;
	bool condition = true;
	string line;
	inputFile.open(filename.c_str());
	Street *temp = NULL;
	int count = 0;
	DGraph *tempp = g;

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
					if ((checkPossibleStreetErrors(tempp, temp)) == false)
					{
						exit(EXIT_FAILURE);
					}

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

/*
this function checks if there are errors within the list of streets and
their attributes
*/
bool WSParser::checkPossibleStreetErrors(DGraph *g, Street* street)
{
	bool result = true;
	vector<Waypoint*> temp = g->getWaypoints();

	/*
	checking the possibility that there is an unrealistic start and end time
	*/
	if ((street->getMinTravelTime() < 0) || (street->getMaxTravelTime() < 0))
	{
		cout << "Terminating program: Min or max travel time is invalid." << endl;
		result = false;
	}

	/*
	checking the possibility the minimum travel time is greater than the max travel time
	*/
	else if (street->getMinTravelTime() > street->getMaxTravelTime())
	{
		cout << "Terminating program: Max travel time is less than the minimum travel time." << endl;
		result = false;
	}

	/*
	checking the possibility that an id does not exist
	*/
	for (vector<Waypoint*>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		if (((*it)->getId() != street->getStartId()) || ((*it)->getId() != street->getEndId()))
		{
			cout << "Terminating program: Waypoint id does not exist." << endl;
			result = false;
		}
	}


		return result;
}

/*
this function checks if there are errors within the list of waypoints
*/
bool WSParser::checkPossibleWaypointErrors(DGraph *g, Waypoint* waypoint)
{
	bool result = true;
	vector<Waypoint*> temp = g->getWaypoints();

	/*
	checking the possibility of a duplicate waypoint id
	*/
	for (vector<Waypoint*>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		if ((*it)->getId() == waypoint->getId())
		{
			cout << "Terminating program: Duplicate waypoint id" << endl;
			result = false;
		}
	}
	


	return result;
}