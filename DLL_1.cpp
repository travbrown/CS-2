//#include "stdafx.h"
#include<iostream>

#include <string>
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

class DoublyList {
public:
	DoublyList();
	void Remove(string place, int target);
	void InsertAfter(FLIGHT flight, int target, DoublyList * HUFlight, FLIGHT new_flight);
	void Append(FLIGHT flight);
	void Prepend(FLIGHT flight);
	void Print();
private:
	NODE *head = nullptr;
	NODE *tail = nullptr;

};

DoublyList::DoublyList() {
	this->head = nullptr;
	this->tail = nullptr;
}
void DoublyList::Prepend(FLIGHT flight) {

	NODE *current = new NODE;
	current->flight = flight;

	if (head == NULL) {

		current->next = nullptr;
		head = current;
		tail = current;
	}
	else {
		current->next = head;
		head->previous = current;
		head = current;
		current->previous = tail;
	}
}
void DoublyList::Remove(string place, int target) {
	
	NODE* curNode = head;
	while (curNode->next != nullptr) {
		if (curNode->flight.destination == place) {
			
			target--;
			if(target == 0){
				(curNode->next)->previous = curNode->previous;
				(curNode->previous)->next = curNode->next;
				break;
			}	
			if (curNode == tail) {
				curNode = curNode->previous;
			}
			else if (curNode == head) {
				curNode = curNode->next;
			}
		}
		curNode = curNode->next;
	}
}
void DoublyList::Append(FLIGHT flight) {

	
	NODE *current = new NODE;
	current->flight = flight;

	if (head == NULL) {
		current->next = nullptr;
		head = current;
		tail = current;
	}
	else {
		NODE *temp = tail;
		current->previous = tail;
		tail->next = current;
		tail = current;
		current->next = head;
	}
}
void DoublyList::InsertAfter(FLIGHT flight,int target, DoublyList * HUFlight, FLIGHT new_flight) {
	NODE *newbie = new NODE;
	newbie->flight = new_flight;
	NODE* curNode = head;

	while (curNode != nullptr) {
		if (curNode->flight.destination == flight.destination) {
			target--;
			if (target == 0) {
				if (curNode == tail) {
					HUFlight->Append(new_flight);
					break;
				}
				else if (curNode == head) {
					HUFlight->Prepend(new_flight);
					break;
				}else{
					newbie->next = curNode->next;
					curNode->next = newbie;
					newbie->previous = curNode;
					curNode = curNode->next;
					curNode->previous = newbie;
					break;
				}
				
			}
		}
		curNode = curNode->next;
		if (curNode == head) {
				break;
		}
	}
	
	
		
	
	
}
void DoublyList::Print(){
	int count = 1;
	NODE* curNode = head;
	string first_place;
	first_place = curNode->flight.destination;
	curNode = head->next;
	cout << "Flight records for HowardAir Flight CSCI0136:" << endl;
	while (curNode != NULL) {
		
		cout << count << ". " << first_place << " to " << curNode->flight.destination << endl;
		if (curNode == head) {
			break;
		}
		first_place = curNode->flight.destination;
		count++;
		curNode = curNode->next;
	}
	
}

int main() {
	DoublyList * HUFlight = new DoublyList;
	FLIGHT fly,fly1;
	fly.destination = "Houston";
	fly.flightNum = 0136;
	HUFlight->Append(fly);
	fly.destination = "Chicago";fly.flightNum = 0136;
	HUFlight->Append(fly);
	fly.destination = "Arizona";fly.flightNum = 0136;
	HUFlight->Append(fly);
	fly.destination = "Baltimore";fly.flightNum = 0136;
	HUFlight->Append(fly);
	fly.destination = "Detroit";fly.flightNum = 0136;
	HUFlight->Append(fly);
	fly.destination = "Denver";fly.flightNum = 0136;
	HUFlight->Append(fly);
	
	HUFlight->Print();

	cout << "\nAdjustments made to the list\n\n";


	fly.destination = "Dallas";fly.flightNum = 0136;
	HUFlight->Prepend(fly);
	
	HUFlight->Remove("Arizona",1);fly.flightNum = 0136;
	
	fly.destination = "Kansas City";fly.flightNum = 0136;
	HUFlight->Append(fly);
	
	
	fly1.destination = "Minneapolis";fly.flightNum = 0136;
	HUFlight->InsertAfter(fly,1,HUFlight,fly1);
	HUFlight->Remove("Houston", 1);fly.flightNum = 0136;
	
	HUFlight->Print();
	return 0;
}

/*
1. Houston to Chicago
2. Chicago to Arizona
3. Arizona to Baltimore
4. Baltimore to Detroit
5. Detroit to Denver
6. Denver to Houston

Adjustments made to the list

1. Dallas to Chicago
2. Chicago to Baltimore
3. Baltimore to Detroit
4. Detroit to Denver
5. Denver to Kansas City
6. Kansas City to Minneapolis
7. Minneapolis to Dallas
*/