#pragma once
#include <cstring>
#include "Accomm.h"
using namespace std;
#define MAX_STRING 32

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




