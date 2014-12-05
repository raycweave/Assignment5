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

using namespace std;

#ifndef DGraph_H
#define DGraph_H

class DGraph {
public:

	DGraph();
	~DGraph();

	void analyzeRoutes();




private:
	void determineRoutes( );

	vector<Streets*> streets; // the list of streets in the graph
	vector<Waypoints*> waypoints; // the waypoints in the grapph

};

#endif