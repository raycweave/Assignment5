/**************************************************************************************************/

/*
* File: main.cpp
* Author: Ray Weaver
* NetID: rayweaver
* Date: December 10, 2014
*/

/**************************************************************************************************/

/**************************************************************************************************/
/*							Assignment 5
*
*	This program searches for the optimal route to travel based on the shortest, and longest, potential travel times along a route
*
*/
/**************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

/*
* check for the correct number of command line arguments.  If incorrect
* provide a simple usage message to the assist the user
*/



int main(int argc, char *argv[]) 
{

	if (argc != 4) {
		cerr << "Usage: " << argv[0] << " start end streetMapGraphFile" << endl;
		return -1;
	}


}