/**************************************************************************************************/

/*
* File: Streets.h
* Author: Ray Weaver
* NetID: rayweaver
* Date: December 10, 2014
*/

/**************************************************************************************************/

#include <iostream>
using namespace std;

#ifndef Streets_H
#define Streets_H


class Streets {

public:
	Streets();
	Streets(string sentence);
	~Streets();

private:
	int startId;
	int endId;
	float minTravelTime;
	float maxTravelTime;
};

#endif