/**************************************************************************************************/

/*
* File: Streets.h
* Author: Ray Weaver
* NetID: rayweaver
* Date: December 10, 2014
*/

/**************************************************************************************************/
#include <string>

using namespace std;

#ifndef Streets_H
#define Streets_H

class Waypoint;

class Street 
{

public:

	Street(Waypoint* adjWaypoint);

	Street(string sentence);

	Waypoint* adjWaypoint;

	int getStartId() { return startId; }

	int getEndId() { return endId; }

private:

	int startId;
	int endId;
	float minTravelTime;
	float maxTravelTime;

};

#endif