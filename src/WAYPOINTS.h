/**************************************************************************************************/

/*
* File: Waypoints.h
* Author: Ray Weaver
* NetID: rayweaver
* Date: December 10, 2014
*/

/**************************************************************************************************/


#include <iostream>

using namespace std;

#ifndef Waypoints_H
#define Waypoints_H

class Waypoints {

public:
	Waypoints();
	Waypoints(string sentence);
	~Waypoints();

private:
	int id;
	string waypointName;
};

#endif