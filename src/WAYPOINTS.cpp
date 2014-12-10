/**************************************************************************************************/

/*
* File: Waypoints.cpp
* Author: Ray Weaver
* NetID: rayweaver
* Date: December 10, 2014
*/

/**************************************************************************************************/

#include "Waypoints.h"
#include "WSparser.h"
#include "Streets.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Waypoint::Waypoint(int id, string name)
	:distance(BIG_NUMBER), color(WHITE), id(id), waypointName(name)
{
	//nothing to see here;
}

bool Waypoint::addStreet(Street *street) {
	bool result = true;

	if (street)
	{
		for (vector<Street*>::iterator it = streets.begin(); it != streets.end(); it++)
		{
			Street *s = *it;
			if (s->adjWaypoint == street->adjWaypoint)
			{
				result = false;
			}
		}

		//only if we have a valid street do we add it
		if (result == true)
		{
			streets.push_back(street);
		}
	}
	return result;

}

Waypoint::Waypoint(string sentence) {

	string junk = "";
	

	istringstream inSS;	
	inSS.clear();
	inSS.str(sentence);

	inSS >> id;
	waypointName = sentence.substr(2);

	return;

}