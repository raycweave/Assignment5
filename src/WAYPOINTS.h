/**************************************************************************************************/

/*
* File: Waypoints.h
* Author: Ray Weaver
* NetID: rayweaver
* Date: December 10, 2014
*/

/**************************************************************************************************/



#include <vector>
#include <string>


using namespace std;

#ifndef Waypoints_H
#define Waypoints_H

#define WHITE 0
#define GRAY 1
#define BLACK 2

class Street;

#ifndef BIG_NUMBER
#define BIG_NUMBER 1e12
#endif

class Waypoint {

public:
	
	Waypoint(string sentence);
	Waypoint(int id, string name);

	//returns the id of the vertex
	int getId() const { return this->id; }

	//returns the name of the vertex
	string getName() const { return this->waypointName; }

	//add a street; returns FALSE if there is
	//already a street that is here w/ that adjVertex
	bool addStreet(Street *street);

	//each street knows who it is connected to
	vector<Street*> streets;

	double distance;
	int color;

private:

	//unique id
	int id;

	//name of our waypoint
	string waypointName;

};

#endif