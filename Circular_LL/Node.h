#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;

struct FLIGHT {
	int flightNum;
	string destination;
};

struct NODE {
	FLIGHT flight;
	NODE *next;
	NODE *previous;
};

#endif //!NODE_H