/**************************************************************************************************/

/*
* File: DGraph.cpp
* Author: Ray Weaver
* NetID: rayweaver
* Date: December 10, 2014
*/

/**************************************************************************************************/

#include "DGraph.h"
#include "Streets.h"
#include "Waypoints.h"

using namespace std;

bool DGraph::addWaypoint(Waypoint *waypoint)
{
	bool result = true;

	if (waypoint)
	{
		for (vector<Waypoint*>::iterator it = waypoints.begin(); it != waypoints.end(); it++)
		{
			Waypoint *w = *it;
			if (w->getId() == waypoint->getId())
			{
				result = false;
			}
		}
		if (result == true)
		{
			waypoints.push_back(waypoint);
		}
	}
	return result;
}
//creates a ned edge for the graph and 
//adds that edge to the graph (and the src vertex)
//to the edge list.
//returns true if successful, returns false if:
//srcID/dstId doesn't exist
//edge already exists

bool DGraph::addStreet(int srcId, int dstId)
{
	bool result = true;

	Waypoint *src = getWaypoint(srcId);
	Waypoint *dst = getWaypoint(dstId);

	if (src == NULL || dst == NULL)
	{
		result = false;
	}

	else
	{
		// if edge already exists we quit
		for (vector<Street*>::iterator it = src->streets.begin(); it != src->streets.end(); it++)
		{
			Street *s2 = *it;
			if (dstId == s2->adjWaypoint->getId())
			{
				result = false;
			}
		}
		if (result == true)
		{
			Street *s = new Street(dst);
			src->streets.push_back(s);
			this->streets.push_back(s);
		}
	}

	return result;
}

Waypoint* DGraph::getWaypoint(int id)  
{ 
	Waypoint *result = NULL;

	for (vector<Waypoint*>::iterator it = waypoints.begin(); it != waypoints.end(); it++)
	{
		if ((*it)->getId() == id)
		{
			result = *it;
		}
	}

	return result;
}