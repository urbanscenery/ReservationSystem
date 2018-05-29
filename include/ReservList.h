#pragma once
#include "Reservation.h"
#include <string.h>

using namespace std;

class ReservList
{
private:
	Reservation* head;
	Reservation* tail;
	int count;

public:
	ReservList();
	~ReservList();
	int getCount();
	Reservation* getHead();
	void insertNode(char* guestID, Accomm* accomm);
	void deleteNode();
	void displayReservList();
	ReservList* searchReservation(char* guestID);
};

