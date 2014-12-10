/**************************************************************************************************/

/*
* File: Streets.cpp
* Author: Ray Weaver
* NetID: rayweaver
* Date: December 10, 2014
*/

/**************************************************************************************************/

#include "Streets.h"
#include "Waypoints.h"

#include <iostream>
#include <string>
#include <sstream>

Street::Street(Waypoint* adjWaypoint)
: adjWaypoint(adjWaypoint)
{
	// nothing to do
}

Street::Street(string sentence) {

	string junk = "";


	istringstream inSS;
	inSS.clear();
	inSS.str(sentence);

	inSS >> startId;
	inSS >> endId;
	inSS >> minTravelTime;
	inSS >> maxTravelTime;

	return;

}