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
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class WSParser {
public:
	static vector<Waypoints*> parseMapGraphFile(string filename);
	static Waypoints* parseGraphFileSentence(string sentence);

private:
	WSParser();
	~WSParser();
};

#endif