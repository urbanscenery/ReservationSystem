#pragma once
#include "Accomm.h"

class Reservation
{
private:
	char hostID[MAX_STRING];
	char guestID[MAX_STRING];
	Accomm* accomm;
	Reservation* next;

public:
	Reservation();
	Reservation(char* hostID, char* guestID, Accomm* accomm);
	~Reservation();
	char* getHostID();
	char* getGuestID();
	Accomm* getAccomm();
	
	Reservation* getNext();
	void setNext(Reservation* ptr);
};




