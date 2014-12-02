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

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Waypoints::Waypoints(string sentence) {

	string junk = "";

	istringstream inSS;	
	inSS.clear();
	inSS.str(sentence);

	inSS >> id;
	inSS >> waypointName;
	

}