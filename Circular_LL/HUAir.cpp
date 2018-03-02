/*
Travis Brown
@02822994
*/
#include<iostream>
#include <string>
using namespace std;
#include "NODE.h"
#include "DoublyList.cpp"


DoublyList::DoublyList() {
	this->head = nullptr;
	this->tail = nullptr;
}
void DoublyList::InsertAfter(FLIGHT flight, int target, DoublyList * HUFlight, FLIGHT new_flight) {
	NODE *newbie = new NODE;
	newbie->flight = new_flight;
	NODE* curNode = head;

	while (curNode != nullptr) {
		if (curNode->flight.destination == flight.destination) {
			target--;
			//to ensure we remove the correct instance of said destination
			//in case a single destination is in records more than once
			if (target == 0) {
				if (curNode == tail) {
					//if we have found ourselves at the tail, might as well call the Append function
					HUFlight->Append(new_flight);
					break;
				}
				else {

					newbie->next = curNode->next;//connect new node to 
					curNode->next = newbie;
					newbie->previous = curNode;
					curNode = curNode->next;
					curNode->previous = newbie;
					//connect new node nextPtr to the second node & second node's Prev Ptr to new node
					//connect indicated node nextPtr to new node &new node's PrevPtr to indicated node
					break;
				}
			}
		}
		curNode = curNode->next;
		if (curNode == head) {
			break;
			//breaks after hitting head the second time
		}
	}
}
void DoublyList::Remove(string place, int target) {

	NODE* curNode = head;
	while (curNode != nullptr) {
		// because this is a circular linked list
		if (curNode->flight.destination == place) {

			target--;
			//to ensure we remove the correct instance of said destination
			//in case a single destination is in records more than once
			if (target == 0) {
				(curNode->next)->previous = curNode->previous;
				(curNode->previous)->next = curNode->next;
				break;
				//connects previous and next node to each other
			}
			if (curNode == tail) {
				tail = curNode->previous;
				//if it is that we had removed the tail, we set it to the previous node 

			}
			else if (curNode == head) {
				head = curNode->next;
				//if it is that we had removed the head, we set it to the next node
			}
		}
		curNode = curNode->next;
		if (curNode == head) {
			break;
			//breaks after hitting head the second time
		}
	}
}
void DoublyList::Prepend(FLIGHT flight) {

	NODE *current = new NODE;
	current->flight = flight;

	if (head == NULL) {
		// if nothing in list it points head and tail to new node
		current->next = nullptr;
		head = current;
		tail = current;
	}
	else {
		current->next = head;//connect new node's next pointer to the first node in list
		head->previous = current;//connect first node's previous pointer to the new node in list
		head = current; // makes new node the head
		current->previous = tail; //connect head & tail
								  //This along with the equivalent in the Append function
								  //makes it a circular linked list, as I was personally informed by Dr. Washington to do
								  // even thought the assignment said double linked list
	}
}
void DoublyList::Append(FLIGHT flight) {
	NODE *current = new NODE;
	current->flight = flight;

	if (head == NULL) {
		// if nothing in list it points head and tail to new node
		current->next = nullptr;
		head = current;
		tail = current;
	}
	else {
		current->previous = tail;//connect new node's previous pointer to the last node in list
		tail->next = current;//connect last node's nextpointer to the new node in list
		tail = current;// makes new node the tail
		current->next = head;//connect head & tail
							 //This along with the equivalent in the Prepend function
							 //makes it a circular linked list, as I was personally informed by Dr. Washington to do
							 // even thought the assignment said double linked list
	}
}
void DoublyList::Print() {
	int count = 1;
	NODE* curNode = head;
	string first_place;
	first_place = curNode->flight.destination;
	curNode = head->next;
	cout << "Flight Records for HowardAir Flight CSCI0136:" << endl;
	while (curNode != NULL) {
		cout << count << ". " << first_place << " to " << curNode->flight.destination << endl;
		if (curNode == head) {
			break;
			//breaks after hitting head the second time
		}
		first_place = curNode->flight.destination;
		count++;
		curNode = curNode->next;//Traverses list
	}
}

int main() {
	DoublyList * HUFlight = new DoublyList;
	FLIGHT fly, fly1;
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
	fly.destination = "Houston";fly.flightNum = 0136;
	HUFlight->Append(fly);


	//Below are steps instructed to execute
	fly.destination = "Dallas";fly.flightNum = 0136;
	HUFlight->Prepend(fly);
	HUFlight->Remove("Arizona", 1);fly.flightNum = 0136;
	fly.destination = "Kansas City";fly.flightNum = 0136;
	HUFlight->Append(fly);
	fly1.destination = "Minneapolis";fly.flightNum = 0136;
	HUFlight->InsertAfter(fly, 1, HUFlight, fly1);
	HUFlight->Remove("Houston", 2);fly.flightNum = 0136;

	HUFlight->Print();
	return 0;
}
/*
Flight Records for HowardAir Flight CSCI0136:
1. Dallas to Houston
2. Houston to Chicago
3. Chicago to Baltimore
4. Baltimore to Detroit
5. Detroit to Denver
6. Denver to Kansas City
7. Kansas City to Minneapolis
8. Minneapolis to Dallas
Press any key to continue . . .
*/