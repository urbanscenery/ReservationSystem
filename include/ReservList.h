#pragma once
#include <cstring>
#include "Reservation.h"

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
	void displayReservList();
	ReservList* searchReservation(char* guestID);
};

