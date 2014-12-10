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

#include "DGraph.h"
#include "Waypoints.h"
#include "Streets.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class WSParser {
public:

	bool parseMapGraphFileWaypoints(DGraph *g, string filename);
	static Waypoint* parseGraphFileSentenceWaypoints(string sentence);

	bool parseMapGraphFileStreets(DGraph *g, string filename);
	static Street* parseGraphFileSentenceStreets(string sentence);

	 bool checkPossibleStreetErrors(DGraph *g, Street* street);
	 bool checkPossibleWaypointErrors(DGraph *g, Waypoint* waypoint);
};

#endif