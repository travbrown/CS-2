#include<iostream>
using namespace std;
#include "NODE.h"
class DoublyList {
public:
	DoublyList();
	void Remove(string place, int target);
	void InsertAfter(FLIGHT flight, int target, DoublyList * HUFlight, FLIGHT new_flight);
	void Append(FLIGHT flight);
	void Prepend(FLIGHT flight);
	void Print();
private:
	NODE * head = NULL;
	NODE* tail = NULL;

};
