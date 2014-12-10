/**************************************************************************************************/

/*
* File: DGraph.h
* Author: Ray Weaver
* NetID: rayweaver
* Date: December 10, 2014
*/

/**************************************************************************************************/

#include "Streets.h"
#include "Waypoints.h"
#include <vector>
#include <string>

using namespace std;

#ifndef DGraph_H
#define DGraph_H

class DGraph {
public:

	//big 4 already created

	//returns FALSE if the node already exits
	bool addWaypoint(Waypoint *node);

	//loops up the node id and creates the actual edge before adding it
	bool addStreet(int srcId, int dstId);

	vector<Waypoint*> getWaypoints() { return waypoints; }
	vector<Street*> getStreets() { return streets; }

	//returns NULL if the id doesn't exist
	Waypoint* getWaypoint(int id);

private:
	
	//bool addStreet(Waypoint *w, Street *s);

	vector<Waypoint*> waypoints; // the waypoints in the grapph

	vector<Street*> streets; // the list of streets in the graph

};

#endif