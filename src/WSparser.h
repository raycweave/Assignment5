/**************************************************************************************************/

/*
* File: WSParser.h
* Author: Ray Weaver
* NetID: rayweaver
* Date: December 10, 2014
*/

/**************************************************************************************************/
#ifndef WSParser_H
#define WSParser_H

#include "Waypoints.h"
#include "Streets.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class WSParser {
public:
	static vector<Waypoints*> parseMapGraphFileWaypoints(string filename);
	static Waypoints* parseGraphFileSentenceWaypoints(string sentence);

	static vector<Streets*> parseMapGraphFileStreets(string filename);
	static Streets* parseGraphFileSentenceStreets(string sentence);

private:
	WSParser();
	~WSParser();
};

#endif