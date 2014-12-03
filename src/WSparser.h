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
	static vector<Waypoints*> parseWaypointsGraphFile(string filename);
	static Waypoints* parseGraphFileSentence(string sentence);
	static vector<Streets*> parseStreetGraphFile(string filename);

private:
	WSParser();
	~WSParser();
};

#endif