/**************************************************************************************************/

/*
* File: WAYPOINTS.h
* Author: Ray Weaver
* NetID: rayweaver
* Date: December 10, 2014
*/

/**************************************************************************************************/


#include <iostream>

using namespace std;

#ifndef WAYPOINTS_H
#define WAYPOINTS_H

class WAYPOINTS {

public:
	WAYPOINTS();
	WAYPOINTS(string sentence);
	~WAYPOINTS();

private:
	int id;
	string waypointName;
};

#endif