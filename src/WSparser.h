/**************************************************************************************************/

/*
* File: WSParser.h
* Author: Ray Weaver
* NetID: rayweaver
* Date: December 10, 2014
*/

/**************************************************************************************************/

#include "WAYPOINTS.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#ifndef WSParser_H
#define WSParser_H

class WSParser {
public:
	static vector<WAYPOINTS*> parseMapGraphFile(string filename);

private:
	WSParser();
	~WSParser();
};

#endif